#include "led.h"
#include "ui_init.h"

void setup() {
  Serial.begin(115200);
  ledSetup();
  ui_setup();
  setColor(0,0,0);
  setScreenBrightness(255);
}

void loop() {
  lv_timer_handler();
  delay(5);
}