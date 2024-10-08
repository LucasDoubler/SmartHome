// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.2
// LVGL version: 8.3.11
// Project name: SquareLine_Project

#include "../ui.h"

void ui_AirQuality_screen_init(void)
{
    ui_AirQuality = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_AirQuality, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_AirQuality, lv_color_hex(0xECF0F3), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_AirQuality, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel6 = lv_obj_create(ui_AirQuality);
    lv_obj_set_width(ui_Panel6, 204);
    lv_obj_set_height(ui_Panel6, 61);
    lv_obj_set_x(ui_Panel6, 126);
    lv_obj_set_y(ui_Panel6, -147);
    lv_obj_set_align(ui_Panel6, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel6, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Panel6, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Panel6, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Panel6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_Panel6, lv_color_hex(0xB9ECFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_Panel6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_Panel6, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_Panel6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui_Panel6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui_Panel6, 3, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label33 = lv_label_create(ui_Panel6);
    lv_obj_set_width(ui_Label33, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label33, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label33, 0);
    lv_obj_set_y(ui_Label33, -2);
    lv_obj_set_align(ui_Label33, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label33, "当前空气质量:良");
    lv_obj_set_style_text_color(ui_Label33, lv_color_hex(0x31456A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label33, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label33, &ui_font_Font1, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Container5 = lv_obj_create(ui_AirQuality);
    lv_obj_remove_style_all(ui_Container5);
    lv_obj_set_width(ui_Container5, 180);
    lv_obj_set_height(ui_Container5, 50);
    lv_obj_set_x(ui_Container5, -207);
    lv_obj_set_y(ui_Container5, -145);
    lv_obj_set_align(ui_Container5, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Container5, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Container5, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Container5, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Container5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_Container5, lv_color_hex(0xB9ECFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_Container5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_Container5, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_Container5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui_Container5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui_Container5, 3, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Water2 = lv_img_create(ui_Container5);
    lv_img_set_src(ui_Water2, &ui_img_water_png);
    lv_obj_set_width(ui_Water2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Water2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Water2, 0);
    lv_obj_set_y(ui_Water2, 2);
    lv_obj_set_align(ui_Water2, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Water2, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Water2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_TempLebal2 = lv_label_create(ui_Container5);
    lv_obj_set_width(ui_TempLebal2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_TempLebal2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_TempLebal2, -37);
    lv_obj_set_y(ui_TempLebal2, 4);
    lv_obj_set_align(ui_TempLebal2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_TempLebal2, "23 °c");
    lv_obj_set_style_text_color(ui_TempLebal2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_TempLebal2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_TempLebal2, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TempLabel2 = lv_img_create(ui_Container5);
    lv_img_set_src(ui_TempLabel2, &ui_img_temperature_png);
    lv_obj_set_width(ui_TempLabel2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_TempLabel2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_TempLabel2, -74);
    lv_obj_set_y(ui_TempLabel2, 6);
    lv_obj_set_align(ui_TempLabel2, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_TempLabel2, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_TempLabel2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_HumLabel2 = lv_label_create(ui_Container5);
    lv_obj_set_width(ui_HumLabel2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_HumLabel2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_HumLabel2, 31);
    lv_obj_set_y(ui_HumLabel2, 3);
    lv_obj_set_align(ui_HumLabel2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_HumLabel2, "32%");
    lv_obj_set_style_text_color(ui_HumLabel2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_HumLabel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_HumLabel2, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Container7 = lv_obj_create(ui_AirQuality);
    lv_obj_remove_style_all(ui_Container7);
    lv_obj_set_width(ui_Container7, 234);
    lv_obj_set_height(ui_Container7, 208);
    lv_obj_set_x(ui_Container7, -198);
    lv_obj_set_y(ui_Container7, 40);
    lv_obj_set_align(ui_Container7, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Container7, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Container7, 25, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Container7, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Container7, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_Container7, lv_color_hex(0xB9ECFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_Container7, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_Container7, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_Container7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui_Container7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui_Container7, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Arc2 = lv_arc_create(ui_Container7);
    lv_obj_set_width(ui_Arc2, 70);
    lv_obj_set_height(ui_Arc2, 70);
    lv_obj_set_x(ui_Arc2, -50);
    lv_obj_set_y(ui_Arc2, -50);
    lv_obj_set_align(ui_Arc2, LV_ALIGN_CENTER);
    lv_arc_set_range(ui_Arc2, 0, 360);
    lv_arc_set_value(ui_Arc2, 90);
    lv_arc_set_bg_angles(ui_Arc2, 0, 360);
    lv_arc_set_rotation(ui_Arc2, 280);
    lv_obj_set_style_arc_width(ui_Arc2, 15, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_arc_color(ui_Arc2, lv_color_hex(0x34D0DB), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_Arc2, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui_Arc2, 15, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Arc2, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Arc2, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_Arc3 = lv_arc_create(ui_Container7);
    lv_obj_set_width(ui_Arc3, 70);
    lv_obj_set_height(ui_Arc3, 70);
    lv_obj_set_x(ui_Arc3, 50);
    lv_obj_set_y(ui_Arc3, -50);
    lv_obj_set_align(ui_Arc3, LV_ALIGN_CENTER);
    lv_arc_set_range(ui_Arc3, 0, 360);
    lv_arc_set_value(ui_Arc3, 120);
    lv_arc_set_bg_angles(ui_Arc3, 0, 360);
    lv_arc_set_rotation(ui_Arc3, 280);
    lv_obj_set_style_arc_width(ui_Arc3, 15, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_arc_color(ui_Arc3, lv_color_hex(0x26EC7A), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_Arc3, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui_Arc3, 15, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Arc3, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Arc3, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_Arc4 = lv_arc_create(ui_Container7);
    lv_obj_set_width(ui_Arc4, 70);
    lv_obj_set_height(ui_Arc4, 70);
    lv_obj_set_x(ui_Arc4, -50);
    lv_obj_set_y(ui_Arc4, 50);
    lv_obj_set_align(ui_Arc4, LV_ALIGN_CENTER);
    lv_arc_set_range(ui_Arc4, 0, 360);
    lv_arc_set_value(ui_Arc4, 30);
    lv_arc_set_bg_angles(ui_Arc4, 0, 360);
    lv_arc_set_rotation(ui_Arc4, 280);
    lv_obj_set_style_arc_width(ui_Arc4, 15, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_arc_color(ui_Arc4, lv_color_hex(0xF1801C), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_Arc4, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui_Arc4, 15, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Arc4, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Arc4, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_Arc5 = lv_arc_create(ui_Container7);
    lv_obj_set_width(ui_Arc5, 70);
    lv_obj_set_height(ui_Arc5, 70);
    lv_obj_set_x(ui_Arc5, 50);
    lv_obj_set_y(ui_Arc5, 50);
    lv_obj_set_align(ui_Arc5, LV_ALIGN_CENTER);
    lv_arc_set_range(ui_Arc5, 0, 360);
    lv_arc_set_value(ui_Arc5, 45);
    lv_arc_set_bg_angles(ui_Arc5, 0, 360);
    lv_arc_set_rotation(ui_Arc5, 280);
    lv_obj_set_style_arc_width(ui_Arc5, 15, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_arc_color(ui_Arc5, lv_color_hex(0xB735DB), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_Arc5, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui_Arc5, 15, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Arc5, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Arc5, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_Label29 = lv_label_create(ui_Container7);
    lv_obj_set_width(ui_Label29, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label29, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label29, -90);
    lv_obj_set_y(ui_Label29, -90);
    lv_obj_set_align(ui_Label29, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label29, "PM2.5");
    lv_obj_set_style_text_color(ui_Label29, lv_color_hex(0x31456A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label29, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label29, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label30 = lv_label_create(ui_Container7);
    lv_obj_set_width(ui_Label30, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label30, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label30, 10);
    lv_obj_set_y(ui_Label30, -88);
    lv_obj_set_align(ui_Label30, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label30, "二氧化碳");
    lv_obj_set_style_text_color(ui_Label30, lv_color_hex(0x31456A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label30, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label30, &ui_font_Font2, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label31 = lv_label_create(ui_Container7);
    lv_obj_set_width(ui_Label31, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label31, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label31, -90);
    lv_obj_set_y(ui_Label31, 0);
    lv_obj_set_align(ui_Label31, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label31, "TVOC");
    lv_obj_set_style_text_color(ui_Label31, lv_color_hex(0x31456A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label31, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label31, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label32 = lv_label_create(ui_Container7);
    lv_obj_set_width(ui_Label32, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label32, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label32, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label32, "甲醛");
    lv_obj_set_style_text_color(ui_Label32, lv_color_hex(0x31456A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label32, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label32, &ui_font_Font2, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label34 = lv_label_create(ui_AirQuality);
    lv_obj_set_width(ui_Label34, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label34, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label34, -6);
    lv_obj_set_y(ui_Label34, 26);
    lv_obj_set_align(ui_Label34, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label34, "空\n气\n质\n量");
    lv_obj_set_style_text_color(ui_Label34, lv_color_hex(0x31456A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label34, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label34, &ui_font_Font1, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TabView2 = lv_tabview_create(ui_AirQuality, LV_DIR_TOP, 40);
    lv_obj_set_width(ui_TabView2, 351);
    lv_obj_set_height(ui_TabView2, 268);
    lv_obj_set_x(ui_TabView2, 197);
    lv_obj_set_y(ui_TabView2, 47);
    lv_obj_set_align(ui_TabView2, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_TabView2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_TabView2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_TabView2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_TabView2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_TabView2, &ui_font_Font1, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_text_color(lv_tabview_get_tab_btns(ui_TabView2), lv_color_hex(0x061A47),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(lv_tabview_get_tab_btns(ui_TabView2), 255,  LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(lv_tabview_get_tab_btns(ui_TabView2), lv_color_hex(0xFFFFFF),
                              LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(lv_tabview_get_tab_btns(ui_TabView2), 255,  LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_text_color(lv_tabview_get_tab_btns(ui_TabView2), lv_color_hex(0xFFFFFF),
                                LV_PART_ITEMS | LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(lv_tabview_get_tab_btns(ui_TabView2), 255,  LV_PART_ITEMS | LV_STATE_CHECKED);
    lv_obj_set_style_radius(lv_tabview_get_tab_btns(ui_TabView2), 25,  LV_PART_ITEMS | LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(lv_tabview_get_tab_btns(ui_TabView2), lv_color_hex(0x1E1E45),
                              LV_PART_ITEMS | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(lv_tabview_get_tab_btns(ui_TabView2), 255,  LV_PART_ITEMS | LV_STATE_CHECKED);
    lv_obj_set_style_border_width(lv_tabview_get_tab_btns(ui_TabView2), 0,  LV_PART_ITEMS | LV_STATE_CHECKED);

    ui_Temperature2 = lv_tabview_add_tab(ui_TabView2, "近24小时");
    lv_obj_clear_flag(ui_Temperature2, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE |
                      LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_bg_color(ui_Temperature2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Temperature2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Chart5 = lv_chart_create(ui_Temperature2);
    lv_obj_set_width(ui_Chart5, 286);
    lv_obj_set_height(ui_Chart5, 181);
    lv_obj_set_x(ui_Chart5, 15);
    lv_obj_set_y(ui_Chart5, -9);
    lv_obj_set_align(ui_Chart5, LV_ALIGN_CENTER);
    lv_chart_set_type(ui_Chart5, LV_CHART_TYPE_LINE);
    lv_chart_set_point_count(ui_Chart5, 24);
    lv_chart_set_range(ui_Chart5, LV_CHART_AXIS_PRIMARY_Y, 0, 150);
    lv_chart_set_div_line_count(ui_Chart5, 4, 0);
    lv_chart_set_zoom_x(ui_Chart5, 1024);
    lv_chart_set_zoom_y(ui_Chart5, 256);
    lv_chart_set_axis_tick(ui_Chart5, LV_CHART_AXIS_PRIMARY_X, 5, 0, 24, 1, true, 50);
    lv_chart_set_axis_tick(ui_Chart5, LV_CHART_AXIS_PRIMARY_Y, 5, 0, 4, 1, true, 50);
    lv_chart_set_axis_tick(ui_Chart5, LV_CHART_AXIS_SECONDARY_Y, 0, 0, 0, 0, false, 25);
    lv_chart_series_t * ui_Chart5_series_1 = lv_chart_add_series(ui_Chart5, lv_color_hex(0x12FADF),
                                                                 LV_CHART_AXIS_SECONDARY_Y);
    static lv_coord_t ui_Chart5_series_1_array[] = { 0, 10, 20, 40, 80, 80, 40, 20, 10, 0 };
    lv_chart_set_ext_y_array(ui_Chart5, ui_Chart5_series_1, ui_Chart5_series_1_array);
    lv_obj_set_style_line_color(ui_Chart5, lv_color_hex(0x8A88B7), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui_Chart5, 128, LV_PART_MAIN | LV_STATE_DEFAULT);


    lv_obj_set_style_size(ui_Chart5, 1, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_line_color(ui_Chart5, lv_color_hex(0xFFFFFF), LV_PART_TICKS | LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui_Chart5, 0, LV_PART_TICKS | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_Chart5, lv_color_hex(0x8A88B7), LV_PART_TICKS | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Chart5, 255, LV_PART_TICKS | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Chart5, &lv_font_montserrat_18, LV_PART_TICKS | LV_STATE_DEFAULT);

    ui_Humidity2 = lv_tabview_add_tab(ui_TabView2, "近7日");
    lv_obj_clear_flag(ui_Humidity2, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE |
                      LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags

    ui_Chart3 = lv_chart_create(ui_Humidity2);
    lv_obj_set_width(ui_Chart3, 286);
    lv_obj_set_height(ui_Chart3, 181);
    lv_obj_set_x(ui_Chart3, 15);
    lv_obj_set_y(ui_Chart3, -9);
    lv_obj_set_align(ui_Chart3, LV_ALIGN_CENTER);
    lv_chart_set_type(ui_Chart3, LV_CHART_TYPE_LINE);
    lv_chart_set_point_count(ui_Chart3, 7);
    lv_chart_set_range(ui_Chart3, LV_CHART_AXIS_PRIMARY_Y, 0, 150);
    lv_chart_set_div_line_count(ui_Chart3, 4, 0);
    lv_chart_set_zoom_x(ui_Chart3, 512);
    lv_chart_set_zoom_y(ui_Chart3, 256);
    lv_chart_set_axis_tick(ui_Chart3, LV_CHART_AXIS_PRIMARY_X, 5, 0, 7, 1, true, 50);
    lv_chart_set_axis_tick(ui_Chart3, LV_CHART_AXIS_PRIMARY_Y, 5, 0, 4, 1, true, 50);
    lv_chart_set_axis_tick(ui_Chart3, LV_CHART_AXIS_SECONDARY_Y, 0, 0, 0, 0, false, 25);
    lv_chart_series_t * ui_Chart3_series_1 = lv_chart_add_series(ui_Chart3, lv_color_hex(0x12FADF),
                                                                 LV_CHART_AXIS_SECONDARY_Y);
    static lv_coord_t ui_Chart3_series_1_array[] = { 0, 10, 20, 40, 80, 80, 40, 20, 10, 0 };
    lv_chart_set_ext_y_array(ui_Chart3, ui_Chart3_series_1, ui_Chart3_series_1_array);
    lv_obj_set_style_line_color(ui_Chart3, lv_color_hex(0x8A88B7), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui_Chart3, 128, LV_PART_MAIN | LV_STATE_DEFAULT);


    lv_obj_set_style_size(ui_Chart3, 1, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_line_color(ui_Chart3, lv_color_hex(0xFFFFFF), LV_PART_TICKS | LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui_Chart3, 0, LV_PART_TICKS | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_Chart3, lv_color_hex(0x8A88B7), LV_PART_TICKS | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Chart3, 255, LV_PART_TICKS | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Chart3, &lv_font_montserrat_18, LV_PART_TICKS | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_AirQuality, ui_event_AirQuality, LV_EVENT_ALL, NULL);

}
