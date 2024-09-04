#include "stm32f4xx.h"
#include "GUI.h"
#include "GUI_ImageData.h"
#include "OLED.h"
#include "DHT22.h"

/**
 * @brief 主页面静态页面1
 * @attention 只显示温湿度及单位符号，不显示变化的数值
 */
void DHT22_MainPage()
{
 
  OLED_ShowImage(0,0,128,64,gImage_DHT22Main);
  OLED_Update();
  OLED_Clear();
}
/**
 * @brief 显示主页面1的动态/实时更改内容，主要为温湿度数据
 * @attention oled显示的其实x坐标为59
 */
void mainPage_1_Dynamic()
{

}
/**
 * @brief MQ7选项页面，在该页面按确定键，可进入CO浓度及设置界面
 *
 */
void MQ7_ChoicePage()
{
    OLED_ShowImage(0, 0, 128, 64, gImage_MQ7Choice);
    OLED_Update();
    OLED_Clear();
}

/**
 * @brief MQ7传感器设置界面，显示当前一氧化碳浓度，及预警值
 *
 */
void MQ7_MainPage()
{
    OLED_ShowImage(0, 0, 64, 64, gImage_MQSeries_Main);
    OLED_Update();
    OLED_Clear();
}

/**
 * @brief MQ6选项页面，在该页面按确定键，可进入可燃气体浓度及设置界面
 *
 */
void MQ6_ChoicePage()
{
    OLED_ShowImage(0, 0, 128, 64, gImage_MQ6Choice);
    OLED_Update();
    OLED_Clear();
}
/**
 * @brief MQ6传感器检测界面，显示当前对LPG，丁烷，丙烷，LNG的总浓度及预警值
 *
 */
void MQ6_MainPage()
{
    OLED_ShowImage(0, 0, 64, 64, gImage_MQSeries_Main);
    OLED_Update();
    OLED_Clear();
}

/**
 * @brief MQ135选项页面，在该页面按确定键，可进入空气质量及设置界面
 *
 */
void MQ135_ChoicePage()
{
    OLED_ShowImage(0, 0, 128, 64, gImage_MQ135Choice);
    OLED_Update();
    OLED_Clear();
}
/**
 * @brief MQ135传感器检测界面，显示当前空气质量
 *
 */
void MQ135_MainPage()
{
    OLED_ShowImage(0, 0, 64, 64, gImage_MQSeries_Main);
    OLED_Update();
    OLED_Clear();
}
/**
 * @brief 秒表界面，在该界面可以进行秒表的定时操作，页面上的时间会精确到秒，实时变化
 *
 */
void CLOCK_Page()
{
}
void WIFI_Page()
{
    OLED_ShowImage(32, 0, 64, 64, gImage_wifiANDword);
    OLED_Update();
    OLED_Clear();
}