int r = 0;
int g = 0;
int b = 0;

static void sliderChange(lv_event_t* event) {
  if (lv_event_get_target(event) == ui_Slider1) r = lv_slider_get_value(ui_Slider1);
  else if (lv_event_get_target(event) == ui_Slider2) g = lv_slider_get_value(ui_Slider2);
  else if (lv_event_get_target(event) == ui_Slider3) b = lv_slider_get_value(ui_Slider3);
  lv_label_set_text(ui_Label2, (String(r) + " " + String(g) + " " + String(b)).c_str());
  setColor(r, g, b);
  lv_obj_set_style_bg_color(ui_Label3, lv_color_make(r, g, b), LV_PART_MAIN | LV_STATE_DEFAULT);
}