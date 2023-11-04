// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.2.1
// LVGL VERSION: 8.2.0
// PROJECT: rgb_control

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t * ui_Screen2;
lv_obj_t * ui_Slider1;
lv_obj_t * ui_Slider2;
lv_obj_t * ui_Slider3;
lv_obj_t * ui_Label2;
lv_obj_t * ui_Label3;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////

///////////////////// SCREENS ////////////////////
void ui_Screen2_screen_init(void)
{
    ui_Screen2 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Slider1 = lv_slider_create(ui_Screen2);
    lv_slider_set_range(ui_Slider1, 0, 255);
    lv_obj_set_width(ui_Slider1, 270);
    lv_obj_set_height(ui_Slider1, 30);
    lv_obj_set_x(ui_Slider1, 0);
    lv_obj_set_y(ui_Slider1, -60);
    lv_obj_set_align(ui_Slider1, LV_ALIGN_CENTER);
    lv_obj_set_style_radius(ui_Slider1, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Slider1, lv_color_hex(0x22242A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Slider1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_Slider1, 8, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Slider1, lv_color_hex(0xD73928), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Slider1, 255, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_Slider2 = lv_slider_create(ui_Screen2);
    lv_slider_set_range(ui_Slider2, 0, 255);
    lv_obj_set_width(ui_Slider2, 270);
    lv_obj_set_height(ui_Slider2, 30);
    lv_obj_set_x(ui_Slider2, -1);
    lv_obj_set_y(ui_Slider2, 0);
    lv_obj_set_align(ui_Slider2, LV_ALIGN_CENTER);
    lv_obj_set_style_radius(ui_Slider2, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Slider2, lv_color_hex(0x22242A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Slider2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_Slider2, 5, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_Slider2, 8, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Slider2, lv_color_hex(0x2BC225), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Slider2, 255, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_Slider3 = lv_slider_create(ui_Screen2);
    lv_slider_set_range(ui_Slider3, 0, 255);
    lv_obj_set_width(ui_Slider3, 270);
    lv_obj_set_height(ui_Slider3, 30);
    lv_obj_set_x(ui_Slider3, 0);
    lv_obj_set_y(ui_Slider3, 60);
    lv_obj_set_align(ui_Slider3, LV_ALIGN_CENTER);
    lv_obj_set_style_radius(ui_Slider3, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Slider3, lv_color_hex(0x22242A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Slider3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_Slider3, 8, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Slider3, lv_color_hex(0x312AD9), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Slider3, 255, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_Label2 = lv_label_create(ui_Screen2);
    lv_obj_set_width(ui_Label2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label2, 0);
    lv_obj_set_y(ui_Label2, -10);
    lv_obj_set_align(ui_Label2, LV_ALIGN_BOTTOM_MID);
    lv_label_set_text(ui_Label2, "");

    ui_Label3 = lv_label_create(ui_Screen2);
    lv_obj_set_width(ui_Label3, 144);
    lv_obj_set_height(ui_Label3, 22);
    lv_obj_set_x(ui_Label3, 0);
    lv_obj_set_y(ui_Label3, 5);
    lv_obj_set_align(ui_Label3, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_Label3, "");
    lv_obj_set_style_radius(ui_Label3, 10000, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Label3, lv_color_hex(0xCC3434), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Label3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

}

void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Screen2_screen_init();
    lv_disp_load_scr(ui_Screen2);
}
