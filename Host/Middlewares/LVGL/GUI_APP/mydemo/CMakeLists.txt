SET(SOURCES screens/ui_main.c
    screens/ui_kongtiao.c
    screens/ui_DengGuang.c
    screens/ui_AirQuality.c
    ui.c
    components/ui_comp_hook.c
    ui_helpers.c
    images/ui_img_router_png.c
    images/ui_img_water_png.c
    images/ui_img_temperature_png.c
    images/ui_img_kongtiao_png.c
    images/ui_img_light_png.c
    images/ui_img_airquality_png.c
    images/ui_img_vector_png.c
    images/ui_img_alight_png.c
    images/ui_img_nowlight_png.c
    images/ui_img_rectangle_71_png.c
    images/ui_img_group_64_png.c
    images/ui_img_1light_png.c
    images/ui_img_curtain_png.c
    images/ui_img_group_39_png.c
    fonts/ui_font_Font1.c
    fonts/ui_font_Font2.c
    fonts/ui_font_Font3.c
    fonts/ui_font_jiajian.c)

add_library(ui ${SOURCES})
