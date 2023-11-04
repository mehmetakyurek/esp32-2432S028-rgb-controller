#include "esp32-hal-ledc.h"
#include <lvgl.h>
#include <TFT_eSPI.h>
/*If you want to use the LVGL examples,
  make sure to install the lv_examples Arduino library
  and uncomment the following line.
*/
//#include <lv_examples.h>
#include <TFT_Touch.h>
//#include <lv_demo.h>
#include "ui.h"
#include "ui_events.h"
/*Change to your screen resolution*/

static const uint16_t screenWidth = 320;   //480;
static const uint16_t screenHeight = 240;  //320;

static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[screenWidth * screenHeight / 4];

TFT_eSPI tft = TFT_eSPI(screenWidth, screenHeight); /* TFT instance */

// These are the pins used to interface between the 2046 touch controller and Arduino Pro
#define DOUT 39 /* Data out pin (T_DO) of touch screen */
#define DIN 32  /* Data in pin (T_DIN) of touch screen */
#define DCS 33  /* Chip select pin (T_CS) of touch screen */
#define DCLK 25 /* Clock pin (T_CLK) of touch screen */

float percent = 0.10;
#define BACKLIGHT_CHANNEL 3
#define BACKLIGHT_FREQUENCY 12000
#define BACKLIGHT_RESOLUTION_BITS 8
#define TFT_LITE 21

/* Create an instance of the touch screen library */
TFT_Touch touch = TFT_Touch(DCS, DCLK, DIN, DOUT);

void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p) {
  uint32_t w = (area->x2 - area->x1 + 1);
  uint32_t h = (area->y2 - area->y1 + 1);

  tft.startWrite();
  tft.setAddrWindow(area->x1, area->y1, w, h);
  tft.pushColors((uint16_t *)&color_p->full, w * h, true);
  tft.endWrite();
  lv_disp_flush_ready(disp);
}

void my_touchpad_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data) {
  uint16_t touchX, touchY;

  bool touched = touch.Pressed();  //tft.getTouch( &touchX, &touchY, 600 );

  if (!touched) {
    data->state = LV_INDEV_STATE_REL;
  } else {
    touchX = touch.X();
    touchY = touch.Y();

    data->state = LV_INDEV_STATE_PR;

    /*Set the coordinates*/
    data->point.x = touchX;
    data->point.y = touchY;
  }
}
void setScreenBrightness(uint8_t val) {
  ledcWrite(BACKLIGHT_CHANNEL, val);
}

void ui_setup() {
  //Initialize backlight
  ledcSetup(BACKLIGHT_CHANNEL, BACKLIGHT_FREQUENCY, BACKLIGHT_RESOLUTION_BITS);
  ledcAttachPin(TFT_LITE, BACKLIGHT_CHANNEL);
  ledcWrite(TFT_LITE, 255);

  tft.begin();         /* TFT init */
  tft.setRotation(1);  //( 3 ); /* Landscape orientation, flipped */
  /*Set the touchscreen calibration data,
     the actual data for your display can be acquired using
     the Generic -> Touch_calibrate example from the TFT_eSPI library*/
  //uint16_t calData[] = { 456, 3608, 469, 272, 3625, 3582, 3518, 263,  };
  //    tft.setTouchCalibrate(calData);//
  //    uint16_t calData[5] = { 275, 3620, 264, 3532, 1 };
  //    tft.setTouch( calData );
  touch.setCal(526, 3443, 750, 3377, 320, 240, 1);
  lv_init();
  lv_disp_draw_buf_init(&draw_buf, buf, NULL, screenWidth * 10);

  /*Initialize the display*/
  static lv_disp_drv_t disp_drv;
  lv_disp_drv_init(&disp_drv);
  /*Change the following line to your display resolution*/
  disp_drv.hor_res = screenWidth;
  disp_drv.ver_res = screenHeight;
  disp_drv.flush_cb = my_disp_flush;  //刷新
  disp_drv.draw_buf = &draw_buf;
  lv_disp_drv_register(&disp_drv);

  /*Initialize the (dummy) input device driver*/
  static lv_indev_drv_t indev_drv;
  lv_indev_drv_init(&indev_drv);
  indev_drv.type = LV_INDEV_TYPE_POINTER;
  indev_drv.read_cb = my_touchpad_read;
  lv_indev_drv_register(&indev_drv);
  ui_init();
  lv_obj_add_event_cb(ui_Slider1, sliderChange, LV_EVENT_VALUE_CHANGED, NULL);
  lv_obj_add_event_cb(ui_Slider2, sliderChange, LV_EVENT_VALUE_CHANGED, NULL);
  lv_obj_add_event_cb(ui_Slider3, sliderChange, LV_EVENT_VALUE_CHANGED, NULL);
}