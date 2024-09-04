// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.2
// LVGL version: 8.3.11
// Project name: SquareLine_Project

#include "ui.h"
#include "ui_helpers.h"
#include "lvgl_demo.h"
#include "FreeRTOS.h"
#include "queue.h"

///////////////////// VARIABLES ////////////////////

extern QueueHandle_t bluetoothQueue;

// SCREEN: ui_main
void ui_main_screen_init(void);
lv_obj_t *ui_main;
lv_obj_t *ui_Container4;
lv_obj_t *ui_Image4;
lv_obj_t *ui_Label4;
lv_obj_t *ui_TabView3;
lv_obj_t *ui_Temperature;
lv_obj_t *ui_Chart1;
lv_obj_t *ui_Humidity;
lv_obj_t *ui_Chart2;
lv_obj_t *ui_Label5;
lv_obj_t *ui_Label6;
lv_obj_t *ui_Panel1;
lv_obj_t *ui_Dropdown1;
lv_obj_t *ui_Water;
lv_obj_t *ui_Temp;
lv_obj_t *ui_HumLebal;
lv_obj_t *ui_TempLebal;
void ui_event_Button11(lv_event_t *e);
lv_obj_t *ui_Button11;
lv_obj_t *ui_Image1;
lv_obj_t *ui_Label1;
void ui_event_Button12(lv_event_t *e);
lv_obj_t *ui_Button12;
lv_obj_t *ui_Image7;
lv_obj_t *ui_Label18;
void ui_event_Button13(lv_event_t *e);
lv_obj_t *ui_Button13;
lv_obj_t *ui_Image3;
lv_obj_t *ui_Label3;

// SCREEN: ui_kongtiao
void ui_kongtiao_screen_init(void);
void ui_event_kongtiao(lv_event_t *e);
lv_obj_t *ui_kongtiao;
lv_obj_t *ui_Container1;
lv_obj_t *ui_Label10;
lv_obj_t *ui_Label11;
lv_obj_t *ui_Label9;
lv_obj_t *ui_sheshidu;
lv_obj_t *ui_Label7;
lv_obj_t *ui_Arc1;
lv_obj_t *ui_chushi;
lv_obj_t *ui_Label12;
lv_obj_t *ui_shengdian;
lv_obj_t *ui_Label14;
lv_obj_t *ui_zhileng;
lv_obj_t *ui_Label15;
lv_obj_t *ui_zhire;
lv_obj_t *ui_Label16;
lv_obj_t *ui_zidong;
lv_obj_t *ui_Label21;
lv_obj_t *ui_shuimian;
lv_obj_t *ui_Label22;
lv_obj_t *ui_Panel3;
lv_obj_t *ui_Image5;
lv_obj_t *ui_Dropdown3;
void ui_event_Button21(lv_event_t *e);
lv_obj_t *ui_Button21;
lv_obj_t *ui_Label8;
void ui_event_Button22(lv_event_t *e);
lv_obj_t *ui_Button22;
lv_obj_t *ui_Label13;
lv_obj_t *ui_Panel2;
lv_obj_t *ui_moshi;
lv_obj_t *ui_fengsu;
lv_obj_t *ui_fengxiang;
lv_obj_t *ui_moshiNum;
lv_obj_t *ui_Roller1;
lv_obj_t *ui_Roller3;

// SCREEN: ui_DengGuang
void ui_DengGuang_screen_init(void);
void ui_event_DengGuang(lv_event_t *e);
lv_obj_t *ui_DengGuang;
lv_obj_t *ui_Panel5;
lv_obj_t *ui_Image8;
lv_obj_t *ui_Dropdown4;
lv_obj_t *ui_Button2;
lv_obj_t *ui_Label24;
lv_obj_t *ui_Button3;
lv_obj_t *ui_Label20;
lv_obj_t *ui_Container2;
lv_obj_t *ui_Label2;
lv_obj_t *ui_Image6;
lv_obj_t *ui_Label23;
lv_obj_t *ui_Switch1;
lv_obj_t *ui_Label25;
lv_obj_t *ui_Container3;
lv_obj_t *ui_Image9;
lv_obj_t *ui_Slider1;
lv_obj_t *ui_Image10;
lv_obj_t *ui_Label19;
lv_obj_t *ui_Image2;
lv_obj_t *ui_Label17;
lv_obj_t *ui_Container6;
lv_obj_t *ui_Image14;
lv_obj_t *ui_Slider3;
lv_obj_t *ui_Image11;
lv_obj_t *ui_Label27;
lv_obj_t *ui_Image12;
lv_obj_t *ui_Label28;
lv_obj_t *ui_Panel4;
lv_obj_t *ui_Label26;

// SCREEN: ui_AirQuality
void ui_AirQuality_screen_init(void);
void ui_event_AirQuality(lv_event_t *e);
lv_obj_t *ui_AirQuality;
lv_obj_t *ui_Panel6;
lv_obj_t *ui_Label33;
lv_obj_t *ui_Container5;
lv_obj_t *ui_Water2;
lv_obj_t *ui_TempLebal2;
lv_obj_t *ui_TempLabel2;
lv_obj_t *ui_HumLabel2;
lv_obj_t *ui_Container7;
lv_obj_t *ui_Arc2;
lv_obj_t *ui_Arc3;
lv_obj_t *ui_Arc4;
lv_obj_t *ui_Arc5;
lv_obj_t *ui_Label29;
lv_obj_t *ui_Label30;
lv_obj_t *ui_Label31;
lv_obj_t *ui_Label32;
lv_obj_t *ui_Label34;
lv_obj_t *ui_TabView2;
lv_obj_t *ui_Temperature2;
lv_obj_t *ui_Chart5;
lv_obj_t *ui_Humidity2;
lv_obj_t *ui_Chart3;
lv_obj_t *ui____initial_actions0;
const lv_img_dsc_t *ui_imgset_group_[2] = {&ui_img_group_39_png, &ui_img_group_64_png};
const lv_img_dsc_t *ui_imgset_rectangle_[1] = {&ui_img_rectangle_71_png};

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
#error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP != 0
#error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////
void ui_event_Button11(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        _ui_screen_change(&ui_kongtiao, LV_SCR_LOAD_ANIM_MOVE_TOP, 300, 50, &ui_kongtiao_screen_init);
    }
}
void ui_event_Button12(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        _ui_screen_change(&ui_DengGuang, LV_SCR_LOAD_ANIM_MOVE_TOP, 300, 50, &ui_DengGuang_screen_init);
    }
}
void ui_event_Button13(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        _ui_screen_change(&ui_AirQuality, LV_SCR_LOAD_ANIM_MOVE_TOP, 300, 0, &ui_AirQuality_screen_init);
    }
}
void ui_event_kongtiao(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_BOTTOM)
    {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_main, LV_SCR_LOAD_ANIM_MOVE_BOTTOM, 300, 50, &ui_main_screen_init);
    }
}
// 对应按钮：温度升高
void ui_event_Button21(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    uint8_t command;
    command = COMMAND_INCREASE_TEMP;
    if (event_code == LV_EVENT_CLICKED)
    {
        _ui_arc_increment(ui_Arc1, 9);
        // 将指令发送到蓝牙任务队列
        xQueueSend(bluetoothQueue, &command, portMAX_DELAY);
    }
}
// 对应按钮：温度降低
void ui_event_Button22(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    uint8_t command;
    command = COMMAND_INCREASE_TEMP;
    if (event_code == LV_EVENT_CLICKED)
    {
        _ui_arc_increment(ui_Arc1, -9);
        xQueueSend(bluetoothQueue, &command, portMAX_DELAY);
    }
}
void ui_event_Zhileng(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    uint8_t command;
    command = COMMAND_COOLING;
    if (event_code == LV_EVENT_CLICKED)
    {
        xQueueSend(bluetoothQueue, &command, portMAX_DELAY);   
    }
}


void ui_event_DengGuang(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_BOTTOM)
    {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_main, LV_SCR_LOAD_ANIM_MOVE_BOTTOM, 300, 25, &ui_main_screen_init);
    }
}
void ui_event_AirQuality(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_BOTTOM)
    {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_main, LV_SCR_LOAD_ANIM_MOVE_BOTTOM, 300, 25, &ui_main_screen_init);
    }
}

///////////////////// SCREENS ////////////////////

void ui_init(void)
{
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                              false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_main_screen_init();
    ui_kongtiao_screen_init();
    ui_DengGuang_screen_init();
    ui_AirQuality_screen_init();
    ui____initial_actions0 = lv_obj_create(NULL);
    lv_disp_load_scr(ui_main);
}
