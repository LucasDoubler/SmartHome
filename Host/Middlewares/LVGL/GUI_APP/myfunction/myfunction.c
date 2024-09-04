#include "lvgl.h"
#include "../ui.h"

/*自定义的函数，用来实现SquareLine无法制作的功能*/

/**
 * @brief 更新标签对象的文本以显示温度值
 *
 * @param obj 标签对象，在此项目中为ui_sheshidu
 * @param value 更改的后的数值
 */
void control_temp_change(lv_obj_t *obj, uint8_t value)
{
    char tempbuffer[3];
    snprintf(tempbuffer, sizeof(tempbuffer), "%d", value);
    lv_label_set_text(obj, tempbuffer);
}

/* 按钮矩阵数组 */
static const char *num_map[] = {
    "制冷",
    "除湿",
    "\n",
    "制热",
    "省电",
    "\n",
    "自动",
    "睡眠",
    "",
};

/**
 * @brief 创建按钮矩阵，用于替代6个按钮和6个标签组件组成的空调控制部分，大幅减少性能开销
 *
 */
void Btnm_Create(void)
{
    /* 按钮矩阵（创建） */
    lv_obj_t *btnm = lv_btnmatrix_create(ui_DengGuang); /* 创建按钮矩阵 */
    lv_obj_set_size(btnm, 240, 240);                    /* 设置大小 */
    lv_btnmatrix_set_map(btnm, num_map);                /* 设置按钮 */
    lv_obj_align(btnm, LV_ALIGN_RIGHT_MID, -30, 0);     /* 设置位置 */
    lv_obj_set_style_text_font(btnm, &ui_font_Font1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(btnm, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_PART_ITEMS);
    lv_obj_set_style_bg_opa(btnm, 255, LV_PART_ITEMS);
    lv_obj_set_style_bg_opa(btnm, 0, LV_PART_MAIN);       /* 设置主体背景透明度 */
    lv_obj_set_style_border_width(btnm, 0, LV_PART_MAIN); /* 去除主体边框 */
    lv_obj_set_style_shadow_color(btnm, lv_color_hex(0xD4E0EC), LV_PART_ITEMS);
    lv_obj_set_style_shadow_opa(btnm, 255, LV_PART_ITEMS);
    lv_obj_set_style_shadow_width(btnm, 5, LV_PART_ITEMS);
    lv_obj_set_style_shadow_spread(btnm, 2, LV_PART_ITEMS);
    
} 
