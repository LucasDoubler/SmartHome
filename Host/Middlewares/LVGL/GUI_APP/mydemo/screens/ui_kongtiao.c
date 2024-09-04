// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.2
// LVGL version: 8.3.11
// Project name: SquareLine_Project

#include "../ui.h"

void ui_kongtiao_screen_init(void)
{
    ui_kongtiao = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_kongtiao, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM);     /// Flags
    lv_obj_set_style_bg_color(ui_kongtiao, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_kongtiao, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Container1 = lv_obj_create(ui_kongtiao);
    lv_obj_remove_style_all(ui_Container1);
    lv_obj_set_width(ui_Container1, 360);
    lv_obj_set_height(ui_Container1, 290);
    lv_obj_set_x(ui_Container1, -164);
    lv_obj_set_y(ui_Container1, 32);
    lv_obj_set_align(ui_Container1, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Container1, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Container1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Container1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label10 = lv_label_create(ui_Container1);
    lv_obj_set_width(ui_Label10, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label10, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label10, 150);
    lv_obj_set_y(ui_Label10, 21);
    lv_obj_set_align(ui_Label10, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label10, "30°c");
    lv_obj_set_style_text_color(ui_Label10, lv_color_hex(0xFF4C00), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label10, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label10, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label11 = lv_label_create(ui_Container1);
    lv_obj_set_width(ui_Label11, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label11, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label11, -150);
    lv_obj_set_y(ui_Label11, 21);
    lv_obj_set_align(ui_Label11, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label11, "10°c");
    lv_obj_set_style_text_color(ui_Label11, lv_color_hex(0x00C5FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label11, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label11, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label9 = lv_label_create(ui_Container1);
    lv_obj_set_width(ui_Label9, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label9, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label9, 0);
    lv_obj_set_y(ui_Label9, -121);
    lv_obj_set_align(ui_Label9, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label9, "20°c");
    lv_obj_set_style_text_color(ui_Label9, lv_color_hex(0xA600FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label9, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label9, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_sheshidu = lv_label_create(ui_Container1);
    lv_obj_set_width(ui_sheshidu, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_sheshidu, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_sheshidu, 0);
    lv_obj_set_y(ui_sheshidu, 16);
    lv_obj_set_align(ui_sheshidu, LV_ALIGN_CENTER);
    lv_label_set_text(ui_sheshidu, "25");
    lv_obj_set_style_text_font(ui_sheshidu, &lv_font_montserrat_34, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label7 = lv_label_create(ui_Container1);
    lv_obj_set_width(ui_Label7, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label7, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label7, 0);
    lv_obj_set_y(ui_Label7, 49);
    lv_obj_set_align(ui_Label7, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label7, "摄氏度");
    lv_obj_set_style_text_color(ui_Label7, lv_color_hex(0x8A88B7), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label7, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label7, &ui_font_Font2, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Arc1 = lv_arc_create(ui_Container1);
    lv_obj_set_width(ui_Arc1, 230);
    lv_obj_set_height(ui_Arc1, 230);
    lv_obj_set_x(ui_Arc1, 0);
    lv_obj_set_y(ui_Arc1, 20);
    lv_obj_set_align(ui_Arc1, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Arc1, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE |
                      LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_scrollbar_mode(ui_Arc1, LV_SCROLLBAR_MODE_OFF);
    lv_arc_set_range(ui_Arc1, 0, 180);
    lv_arc_set_value(ui_Arc1, 90);
    lv_arc_set_bg_angles(ui_Arc1, 180, 0);
    lv_obj_set_style_bg_color(ui_Arc1, lv_color_hex(0x151526), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Arc1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui_Arc1, 12, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Arc1, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Arc1, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui_Arc1, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui_Arc1, lv_color_hex(0x3479B9), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_Arc1, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui_Arc1, 12, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Arc1, lv_color_hex(0xF55945), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Arc1, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Arc1, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Arc1, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Arc1, 5, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_chushi = lv_btn_create(ui_kongtiao);
    lv_obj_set_width(ui_chushi, 100);
    lv_obj_set_height(ui_chushi, 60);
    lv_obj_set_x(ui_chushi, 283);
    lv_obj_set_y(ui_chushi, -101);
    lv_obj_set_align(ui_chushi, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_chushi, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_chushi, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_chushi, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_chushi, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_chushi, lv_color_hex(0xD4E0EC), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_chushi, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_chushi, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_chushi, 2, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label12 = lv_label_create(ui_chushi);
    lv_obj_set_width(ui_Label12, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label12, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label12, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label12, "除湿");
    lv_obj_set_style_text_color(ui_Label12, lv_color_hex(0x061A47), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label12, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label12, &ui_font_Font1, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_shengdian = lv_btn_create(ui_kongtiao);
    lv_obj_set_width(ui_shengdian, 100);
    lv_obj_set_height(ui_shengdian, 60);
    lv_obj_set_x(ui_shengdian, 286);
    lv_obj_set_y(ui_shengdian, -14);
    lv_obj_set_align(ui_shengdian, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_shengdian, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_shengdian, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_shengdian, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_shengdian, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_shengdian, lv_color_hex(0xD4E0EC), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_shengdian, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_shengdian, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_shengdian, 2, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label14 = lv_label_create(ui_shengdian);
    lv_obj_set_width(ui_Label14, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label14, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label14, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label14, "省电");
    lv_obj_set_style_text_color(ui_Label14, lv_color_hex(0x061A47), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label14, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label14, &ui_font_Font1, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_zhileng = lv_btn_create(ui_kongtiao);
    lv_obj_set_width(ui_zhileng, 100);
    lv_obj_set_height(ui_zhileng, 60);
    lv_obj_set_x(ui_zhileng, 159);
    lv_obj_set_y(ui_zhileng, -102);
    lv_obj_set_align(ui_zhileng, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_zhileng, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_zhileng, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_zhileng, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_zhileng, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_zhileng, lv_color_hex(0xD4E0EC), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_zhileng, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_zhileng, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_zhileng, 2, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label15 = lv_label_create(ui_zhileng);
    lv_obj_set_width(ui_Label15, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label15, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label15, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label15, "制冷");
    lv_obj_set_style_text_color(ui_Label15, lv_color_hex(0x061A47), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label15, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label15, &ui_font_Font1, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_zhire = lv_btn_create(ui_kongtiao);
    lv_obj_set_width(ui_zhire, 100);
    lv_obj_set_height(ui_zhire, 60);
    lv_obj_set_x(ui_zhire, 159);
    lv_obj_set_y(ui_zhire, -16);
    lv_obj_set_align(ui_zhire, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_zhire, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_zhire, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_zhire, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_zhire, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_zhire, lv_color_hex(0xD4E0EC), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_zhire, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_zhire, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_zhire, 2, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label16 = lv_label_create(ui_zhire);
    lv_obj_set_width(ui_Label16, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label16, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label16, -2);
    lv_obj_set_y(ui_Label16, 1);
    lv_obj_set_align(ui_Label16, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label16, "制热");
    lv_obj_set_style_text_color(ui_Label16, lv_color_hex(0x061A47), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label16, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label16, &ui_font_Font1, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_zidong = lv_btn_create(ui_kongtiao);
    lv_obj_set_width(ui_zidong, 100);
    lv_obj_set_height(ui_zidong, 60);
    lv_obj_set_x(ui_zidong, 158);
    lv_obj_set_y(ui_zidong, 70);
    lv_obj_set_align(ui_zidong, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_zidong, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_zidong, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_zidong, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_zidong, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_zidong, lv_color_hex(0xD4E0EC), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_zidong, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_zidong, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_zidong, 2, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label21 = lv_label_create(ui_zidong);
    lv_obj_set_width(ui_Label21, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label21, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label21, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label21, "自动");
    lv_obj_set_style_text_color(ui_Label21, lv_color_hex(0x061A47), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label21, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label21, &ui_font_Font1, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_shuimian = lv_btn_create(ui_kongtiao);
    lv_obj_set_width(ui_shuimian, 100);
    lv_obj_set_height(ui_shuimian, 60);
    lv_obj_set_x(ui_shuimian, 285);
    lv_obj_set_y(ui_shuimian, 68);
    lv_obj_set_align(ui_shuimian, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_shuimian, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_shuimian, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_shuimian, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_shuimian, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_shuimian, lv_color_hex(0xD4E0EC), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_shuimian, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_shuimian, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_shuimian, 2, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label22 = lv_label_create(ui_shuimian);
    lv_obj_set_width(ui_Label22, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label22, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label22, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label22, "睡眠");
    lv_obj_set_style_text_color(ui_Label22, lv_color_hex(0x061A47), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label22, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label22, &ui_font_Font1, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel3 = lv_obj_create(ui_kongtiao);
    lv_obj_set_width(ui_Panel3, 200);
    lv_obj_set_height(ui_Panel3, 68);
    lv_obj_set_x(ui_Panel3, -243);
    lv_obj_set_y(ui_Panel3, -186);
    lv_obj_set_align(ui_Panel3, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Panel3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Panel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_Panel3, lv_color_hex(0xD4E0EC), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_Panel3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_Panel3, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_Panel3, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui_Panel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui_Panel3, 2, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Image5 = lv_img_create(ui_Panel3);
    lv_img_set_src(ui_Image5, &ui_img_vector_png);
    lv_obj_set_width(ui_Image5, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Image5, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Image5, -44);
    lv_obj_set_y(ui_Image5, 0);
    lv_obj_set_align(ui_Image5, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Image5, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Image5, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Dropdown3 = lv_dropdown_create(ui_Panel3);
    lv_dropdown_set_options(ui_Dropdown3, "客厅\n厨房\n卧室");
    lv_obj_set_width(ui_Dropdown3, 95);
    lv_obj_set_height(ui_Dropdown3, 33);
    lv_obj_set_x(ui_Dropdown3, 35);
    lv_obj_set_y(ui_Dropdown3, -5);
    lv_obj_set_align(ui_Dropdown3, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Dropdown3, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_text_color(ui_Dropdown3, lv_color_hex(0x061A47), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Dropdown3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Dropdown3, &ui_font_Font1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Dropdown3, lv_color_hex(0xE22B4C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Dropdown3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Dropdown3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_text_color(ui_Dropdown3, lv_color_hex(0x061A47), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Dropdown3, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Dropdown3, &lv_font_montserrat_16, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_text_color(lv_dropdown_get_list(ui_Dropdown3), lv_color_hex(0x061A47),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(lv_dropdown_get_list(ui_Dropdown3), 255,  LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(lv_dropdown_get_list(ui_Dropdown3), &ui_font_Font1,  LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(lv_dropdown_get_list(ui_Dropdown3), lv_color_hex(0xFFFFFF),  LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(lv_dropdown_get_list(ui_Dropdown3), 255,  LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(lv_dropdown_get_list(ui_Dropdown3), lv_color_hex(0x2D3554),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(lv_dropdown_get_list(ui_Dropdown3), 255,  LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(lv_dropdown_get_list(ui_Dropdown3), 1,  LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_text_color(lv_dropdown_get_list(ui_Dropdown3), lv_color_hex(0xFFFFFF),
                                LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(lv_dropdown_get_list(ui_Dropdown3), 255,  LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(lv_dropdown_get_list(ui_Dropdown3), lv_color_hex(0x4C6386),
                              LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(lv_dropdown_get_list(ui_Dropdown3), 255,  LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(lv_dropdown_get_list(ui_Dropdown3), lv_color_hex(0xFFFFFF),
                                LV_PART_SELECTED | LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(lv_dropdown_get_list(ui_Dropdown3), 255,  LV_PART_SELECTED | LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(lv_dropdown_get_list(ui_Dropdown3), lv_color_hex(0x0048B5),
                              LV_PART_SELECTED | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(lv_dropdown_get_list(ui_Dropdown3), 255,  LV_PART_SELECTED | LV_STATE_CHECKED);

    ui_TempIncrease = lv_btn_create(ui_kongtiao);
    lv_obj_set_width(ui_TempIncrease, 45);
    lv_obj_set_height(ui_TempIncrease, 40);
    lv_obj_set_x(ui_TempIncrease, 47);
    lv_obj_set_y(ui_TempIncrease, 53);
    lv_obj_set_align(ui_TempIncrease, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_TempIncrease, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_TempIncrease, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_TempIncrease, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_TempIncrease, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_TempIncrease, lv_color_hex(0xD4E0EC), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_TempIncrease, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_TempIncrease, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_TempIncrease, 2, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label8 = lv_label_create(ui_TempIncrease);
    lv_obj_set_width(ui_Label8, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label8, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label8, 0);
    lv_obj_set_y(ui_Label8, 1);
    lv_obj_set_align(ui_Label8, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label8, "+");
    lv_obj_set_style_text_color(ui_Label8, lv_color_hex(0x061A47), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label8, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label8, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TempDecrease = lv_btn_create(ui_kongtiao);
    lv_obj_set_width(ui_TempDecrease, 45);
    lv_obj_set_height(ui_TempDecrease, 40);
    lv_obj_set_x(ui_TempDecrease, -369);
    lv_obj_set_y(ui_TempDecrease, 50);
    lv_obj_set_align(ui_TempDecrease, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_TempDecrease, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_TempDecrease, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_TempDecrease, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_TempDecrease, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_TempDecrease, lv_color_hex(0xD4E0EC), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_TempDecrease, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_TempDecrease, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_TempDecrease, 2, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label13 = lv_label_create(ui_TempDecrease);
    lv_obj_set_width(ui_Label13, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label13, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label13, -1);
    lv_obj_set_y(ui_Label13, 0);
    lv_obj_set_align(ui_Label13, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label13, "-");
    lv_obj_set_style_text_color(ui_Label13, lv_color_hex(0x061A47), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label13, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label13, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel2 = lv_obj_create(ui_kongtiao);
    lv_obj_set_width(ui_Panel2, 319);
    lv_obj_set_height(ui_Panel2, 88);
    lv_obj_set_x(ui_Panel2, -159);
    lv_obj_set_y(ui_Panel2, 157);
    lv_obj_set_align(ui_Panel2, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Panel2, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Panel2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Panel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_Panel2, lv_color_hex(0xD4E0EC), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_Panel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_Panel2, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_Panel2, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui_Panel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui_Panel2, 2, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_moshi = lv_label_create(ui_Panel2);
    lv_obj_set_width(ui_moshi, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_moshi, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_moshi, -113);
    lv_obj_set_y(ui_moshi, 23);
    lv_obj_set_align(ui_moshi, LV_ALIGN_CENTER);
    lv_label_set_text(ui_moshi, "模式");
    lv_obj_set_style_text_color(ui_moshi, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_moshi, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_moshi, &ui_font_Font2, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_fengsu = lv_label_create(ui_Panel2);
    lv_obj_set_width(ui_fengsu, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_fengsu, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_fengsu, 0);
    lv_obj_set_y(ui_fengsu, 25);
    lv_obj_set_align(ui_fengsu, LV_ALIGN_CENTER);
    lv_label_set_text(ui_fengsu, "风速");
    lv_obj_set_style_text_color(ui_fengsu, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_fengsu, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_fengsu, &ui_font_Font2, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_fengxiang = lv_label_create(ui_Panel2);
    lv_obj_set_width(ui_fengxiang, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_fengxiang, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_fengxiang, 106);
    lv_obj_set_y(ui_fengxiang, 25);
    lv_obj_set_align(ui_fengxiang, LV_ALIGN_CENTER);
    lv_label_set_text(ui_fengxiang, "风向");
    lv_obj_set_style_text_color(ui_fengxiang, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_fengxiang, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_fengxiang, &ui_font_Font2, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_moshiNum = lv_label_create(ui_Panel2);
    lv_obj_set_width(ui_moshiNum, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_moshiNum, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_moshiNum, -111);
    lv_obj_set_y(ui_moshiNum, -4);
    lv_obj_set_align(ui_moshiNum, LV_ALIGN_CENTER);
    lv_label_set_text(ui_moshiNum, "自动");
    lv_obj_set_style_text_font(ui_moshiNum, &ui_font_Font3, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Roller1 = lv_roller_create(ui_kongtiao);
    lv_roller_set_options(ui_Roller1, "1\n2\n3", LV_ROLLER_MODE_NORMAL);
    lv_obj_set_height(ui_Roller1, 30);
    lv_obj_set_width(ui_Roller1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_x(ui_Roller1, -161);
    lv_obj_set_y(ui_Roller1, 156);
    lv_obj_set_align(ui_Roller1, LV_ALIGN_CENTER);
    lv_obj_set_style_text_color(ui_Roller1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Roller1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_Roller1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Roller1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_text_color(ui_Roller1, lv_color_hex(0x000000), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Roller1, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Roller1, &ui_font_Font3, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Roller1, lv_color_hex(0xFFFFFF), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Roller1, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);

    ui_Roller3 = lv_roller_create(ui_kongtiao);
    lv_roller_set_options(ui_Roller3, "上\n中\n下", LV_ROLLER_MODE_NORMAL);
    lv_obj_set_width(ui_Roller3, 67);
    lv_obj_set_height(ui_Roller3, 25);
    lv_obj_set_x(ui_Roller3, -52);
    lv_obj_set_y(ui_Roller3, 156);
    lv_obj_set_align(ui_Roller3, LV_ALIGN_CENTER);
    lv_obj_set_style_text_color(ui_Roller3, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Roller3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_Roller3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Roller3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_text_color(ui_Roller3, lv_color_hex(0x000000), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Roller3, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Roller3, &ui_font_Font3, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Roller3, lv_color_hex(0xFFFFFF), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Roller3, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_chushi, ui_event_chushi, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_shengdian, ui_event_shengdian, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_zhileng, ui_event_zhileng, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_zhire, ui_event_zhire, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_zidong, ui_event_zidong, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_shuimian, ui_event_shuimian, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_TempIncrease, ui_event_TempIncrease, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_TempDecrease, ui_event_TempDecrease, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_kongtiao, ui_event_kongtiao, LV_EVENT_ALL, NULL);

}
