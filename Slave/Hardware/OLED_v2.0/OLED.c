
#include "stm32f4xx.h"
#include "OLED.h"
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdarg.h>

/**
 * 数据存储格式：
 * 纵向8点，高位在下，先从左到右，再从上到下
 * 每一个Bit对应一个像素点
 *
 *      B0 B0                  B0 B0
 *      B1 B1                  B1 B1
 *      B2 B2                  B2 B2
 *      B3 B3  ------------->  B3 B3 --
 *      B4 B4                  B4 B4  |
 *      B5 B5                  B5 B5  |
 *      B6 B6                  B6 B6  |
 *      B7 B7                  B7 B7  |
 *                                    |
 *  -----------------------------------
 *  |
 *  |   B0 B0                  B0 B0
 *  |   B1 B1                  B1 B1
 *  |   B2 B2                  B2 B2
 *  --> B3 B3  ------------->  B3 B3
 *      B4 B4                  B4 B4
 *      B5 B5                  B5 B5
 *      B6 B6                  B6 B6
 *      B7 B7                  B7 B7
 *
 * 坐标轴定义：
 * 左上角为(0, 0)点
 * 横向向右为X轴，取值范围：0-127
 * 纵向向下为Y轴，取值范围：0-63
 *
 *       0             X轴           127
 *      .------------------------------->
 *    0 |
 *      |
 *      |
 *      |
 *  Y轴 |
 *      |
 *      |
 *      |
 *   63 |
 *      v
 *
 */

/*全局变量*********************/

/**
 * OLED显存数组
 * 所有的显示函数，都只是对此显存数组进行读写
 * 随后调用OLED_Update函数或OLED_UpdateArea函数
 * 才会将显存数组的数据发送到OLED硬件，进行显示
 */
uint8_t OLED_DisplayBuf[8][128];

/*********************全局变量*/

/*引脚配置*********************/

/**
 * @brief：OLED写SCL高低电平s
 * @param 要写入SCL的电平值，范围：0/1
 * @return：无
 * @attention 当上层函数需要写SCL时，此函数会被调用
 *           用户需要根据参数传入的值，将SCL置为高电平或者低电平
 *           当参数传入0时，置SCL为低电平，当参数传入1时，置SCL为高电平
 */
void OLED_W_SCL(uint8_t BitValue)
{
    /*根据BitValue的值，将SCL置高电平或者低电平*/
    GPIO_WriteBit(GPIOB, GPIO_Pin_8, (BitAction)BitValue);

    /*如果单片机速度过快，可在此添加适量延时，以避免超出I2C通信的最大速度*/
    //...
}

/**
 * @brief：OLED写SDA高低电平
 * @param 要写入SDA的电平值，范围：0/1
 * @return：无
 * @attention 当上层函数需要写SDA时，此函数会被调用
 *           用户需要根据参数传入的值，将SDA置为高电平或者低电平
 *           当参数传入0时，置SDA为低电平，当参数传入1时，置SDA为高电平
 */



void OLED_W_SDA(uint8_t BitValue)
{
    /*根据BitValue的值，将SDA置高电平或者低电平*/
    GPIO_WriteBit(GPIOB, GPIO_Pin_9, (BitAction)BitValue);

    /*如果单片机速度过快，可在此添加适量延时，以避免超出I2C通信的最大速度*/
    //...
}

/**
 * @brief：OLED引脚初始化
 * @param 无
 * @return：无
 * @attention 当上层函数需要初始化时，此函数会被调用
 *           用户需要将SCL和SDA引脚初始化为开漏模式，并释放引脚
 */
void OLED_GPIO_Init(void)
{
    uint32_t i, j;

    /*在初始化前，加入适量延时，待OLED供电稳定*/
    for (i = 0; i < 1000; i++) {
        for (j = 0; j < 1000; j++)
            ;
    }

    /*将SCL和SDA引脚初始化为开漏模式*/
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_8;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    /*释放SCL和SDA*/
    OLED_W_SCL(1);
    OLED_W_SDA(1);
}

/*********************引脚配置*/

/*通信协议*********************/

/**
 * @brief：I2C起始
 * @param 无
 * @return：无
 */
void OLED_I2C_Start(void)
{
    OLED_W_SDA(1); // 释放SDA，确保SDA为高电平
    OLED_W_SCL(1); // 释放SCL，确保SCL为高电平
    OLED_W_SDA(0); // 在SCL高电平期间，拉低SDA，产生起始信号
    OLED_W_SCL(0); // 起始后把SCL也拉低，即为了占用总线，也为了方便总线时序的拼接
}

/**
 * @brief：I2C终止
 * @param 无
 * @return：无
 */
void OLED_I2C_Stop(void)
{
    OLED_W_SDA(0); // 拉低SDA，确保SDA为低电平
    OLED_W_SCL(1); // 释放SCL，使SCL呈现高电平
    OLED_W_SDA(1); // 在SCL高电平期间，释放SDA，产生终止信号
}

/**
 * @brief：I2C发送一个字节
 * @param Byte 要发送的一个字节数据，范围：0x00-0xFF
 * @return：无
 */
void OLED_I2C_SendByte(uint8_t Byte)
{
    uint8_t i;

    /*循环8次，主机依次发送数据的每一位*/
    for (i = 0; i < 8; i++) {
        /*使用掩码的方式取出Byte的指定一位数据并写入到SDA线*/
        /*两个!的作用是，让所有非零的值变为1*/
        OLED_W_SDA(!!(Byte & (0x80 >> i)));
        OLED_W_SCL(1); // 释放SCL，从机在SCL高电平期间读取SDA
        OLED_W_SCL(0); // 拉低SCL，主机开始发送下一位数据
    }

    OLED_W_SCL(1); // 额外的一个时钟，不处理应答信号
    OLED_W_SCL(0);
}

/**
 * @brief：OLED写命令
 * @param Command 要写入的命令值，范围：0x00-0xFF
 * @return：无
 */
void OLED_WriteCommand(uint8_t Command)
{
    OLED_I2C_Start();           // I2C起始
    OLED_I2C_SendByte(0x78);    // 发送OLED的I2C从机地址
    OLED_I2C_SendByte(0x00);    // 控制字节，给0x00，表示即将写命令
    OLED_I2C_SendByte(Command); // 写入指定的命令
    OLED_I2C_Stop();            // I2C终止
}

/**
 * @brief：OLED写数据
 * @param Data 要写入数据的起始地址
 * @param Count 要写入数据的数量
 * @return：无
 */
void OLED_WriteData(uint8_t *Data, uint8_t Count)
{
    uint8_t i;

    OLED_I2C_Start();        // I2C起始
    OLED_I2C_SendByte(0x78); // 发送OLED的I2C从机地址
    OLED_I2C_SendByte(0x40); // 控制字节，给0x40，表示即将写数据
    /*循环Count次，进行连续的数据写入*/
    for (i = 0; i < Count; i++) {
        OLED_I2C_SendByte(Data[i]); // 依次发送Data的每一个数据
    }
    OLED_I2C_Stop(); // I2C终止
}

/*********************通信协议*/

/*硬件配置*********************/

/**
 * @brief：OLED初始化
 * @param 无
 * @return：无
 * @attention 使用前，需要调用此初始化函数
 */
void OLED_Init(void)
{
    OLED_GPIO_Init(); // 先调用底层的端口初始化

    /*写入一系列的命令，对OLED进行初始化配置*/
    OLED_WriteCommand(0xAE); // 设置显示开启/关闭，0xAE关闭，0xAF开启

    OLED_WriteCommand(0xD5); // 设置显示时钟分频比/振荡器频率
    OLED_WriteCommand(0x80); // 0x00-0xFF

    OLED_WriteCommand(0xA8); // 设置多路复用率
    OLED_WriteCommand(0x3F); // 0x0E-0x3F

    OLED_WriteCommand(0xD3); // 设置显示偏移
    OLED_WriteCommand(0x00); // 0x00-0x7F

    OLED_WriteCommand(0x40); // 设置显示开始行，0x40-0x7F

    OLED_WriteCommand(0xA1); // 设置左右方向，0xA1正常，0xA0左右反置

    OLED_WriteCommand(0xC8); // 设置上下方向，0xC8正常，0xC0上下反置

    OLED_WriteCommand(0xDA); // 设置COM引脚硬件配置
    OLED_WriteCommand(0x12);

    OLED_WriteCommand(0x81); // 设置对比度
    OLED_WriteCommand(0xCF); // 0x00-0xFF

    OLED_WriteCommand(0xD9); // 设置预充电周期
    OLED_WriteCommand(0xF1);

    OLED_WriteCommand(0xDB); // 设置VCOMH取消选择级别
    OLED_WriteCommand(0x30);

    OLED_WriteCommand(0xA4); // 设置整个显示打开/关闭

    OLED_WriteCommand(0xA6); // 设置正常/反色显示，0xA6正常，0xA7反色

    OLED_WriteCommand(0x8D); // 设置充电泵
    OLED_WriteCommand(0x14);

    OLED_WriteCommand(0xAF); // 开启显示

    OLED_Clear();  // 清空显存数组
    OLED_Update(); // 更新显示，清屏，防止初始化后未显示内容时花屏
}

/**
 * @brief：OLED设置显示光标位置
 * @param Page 指定光标所在的页，范围：0-7
 * @param X 指定光标所在的X轴坐标，范围：0-127
 * @return：无
 * @attention OLED默认的Y轴，只能8个Bit为一组写入，即1页等于8个Y轴坐标
 */
void OLED_SetCursor(uint8_t Page, uint8_t X)
{
    /*如果使用此程序驱动1.3寸的OLED显示屏，则需要解除此注释*/
    /*因为1.3寸的OLED驱动芯片（SH1106）有132列*/
    /*屏幕的起始列接在了第2列，而不是第0列*/
    /*所以需要将X加2，才能正常显示*/
    //	X += 2;

    /*通过指令设置页地址和列地址*/
    OLED_WriteCommand(0xB0 | Page);              // 设置页位置
    OLED_WriteCommand(0x10 | (((X+2) & 0xF0) >> 4)); // 设置X位置高4位
    OLED_WriteCommand(0x00 | ((X+2) & 0x0F));        // 设置X位置低4位
}

/*********************硬件配置*/

/*工具函数*********************/

/*工具函数仅供内部部分函数使用*/

/**
 * @brief：次方函数
 * @param X 底数
 * @param Y 指数
 * @return：等于X的Y次方
 */
uint32_t OLED_Pow(uint32_t X, uint32_t Y)
{
    uint32_t Result = 1; // 结果默认为1
    while (Y--)          // 累乘Y次
    {
        Result *= X; // 每次把X累乘到结果上
    }
    return Result;
}

/**
 * @brief：判断指定点是否在指定多边形内部
 * @param nvert 多边形的顶点数
 * @param vertx verty 包含多边形顶点的x和y坐标的数组
 * @param testx testy 测试点的X和y坐标
 * @return：指定点是否在指定多边形内部，1：在内部，0：不在内部
 */
uint8_t OLED_pnpoly(uint8_t nvert, int16_t *vertx, int16_t *verty, int16_t testx, int16_t testy)
{
    int16_t i, j, c = 0;

    /*此算法由W. Randolph Franklin提出*/
    /*参考链接：https://wrfranklin.org/Research/Short_Notes/pnpoly.html*/
    for (i = 0, j = nvert - 1; i < nvert; j = i++) {
        if (((verty[i] > testy) != (verty[j] > testy)) &&
            (testx < (vertx[j] - vertx[i]) * (testy - verty[i]) / (verty[j] - verty[i]) + vertx[i])) {
            c = !c;
        }
    }
    return c;
}

/**
 * @brief：判断指定点是否在指定角度内部
 * @param X Y 指定点的坐标
 * @param StartAngle EndAngle 起始角度和终止角度，范围：-180-180
 *           水平向右为0度，水平向左为180度或-180度，下方为正数，上方为负数，顺时针旋转
 * @return：指定点是否在指定角度内部，1：在内部，0：不在内部
 */
uint8_t OLED_IsInAngle(int16_t X, int16_t Y, int16_t StartAngle, int16_t EndAngle)
{
    int16_t PointAngle;
    PointAngle = atan2(Y, X) / 3.14 * 180; // 计算指定点的弧度，并转换为角度表示
    if (StartAngle < EndAngle)             // 起始角度小于终止角度的情况
    {
        /*如果指定角度在起始终止角度之间，则判定指定点在指定角度*/
        if (PointAngle >= StartAngle && PointAngle <= EndAngle) {
            return 1;
        }
    } else // 起始角度大于于终止角度的情况
    {
        /*如果指定角度大于起始角度或者小于终止角度，则判定指定点在指定角度*/
        if (PointAngle >= StartAngle || PointAngle <= EndAngle) {
            return 1;
        }
    }
    return 0; // 不满足以上条件，则判断判定指定点不在指定角度
}

/*********************工具函数*/

/*功能函数*********************/

/**
 * @brief：将OLED显存数组更新到OLED屏幕
 * @param 无
 * @return：无
 * @attention 所有的显示函数，都只是对OLED显存数组进行读写
 *           随后调用OLED_Update函数或OLED_UpdateArea函数
 *           才会将显存数组的数据发送到OLED硬件，进行显示
 *           故调用显示函数后，要想真正地呈现在屏幕上，还需调用更新函数
 */
void OLED_Update(void)
{
    uint8_t j;
    /*遍历每一页*/
    for (j = 0; j < 8; j++) {
        /*设置光标位置为每一页的第一列*/
        OLED_SetCursor(j, 0);
        /*连续写入128个数据，将显存数组的数据写入到OLED硬件*/
        OLED_WriteData(OLED_DisplayBuf[j], 128);
    }
}

/**
 * @brief：将OLED显存数组部分更新到OLED屏幕
 * @param X 指定区域左上角的横坐标，范围：0-127
 * @param Y 指定区域左上角的纵坐标，范围：0-63
 * @param Width 指定区域的宽度，范围：0-128
 * @param Height 指定区域的高度，范围：0-64
 * @return：无
 * @attention 此函数会至少更新参数指定的区域
 *           如果更新区域Y轴只包含部分页，则同一页的剩余部分会跟随一起更新
 * @attention 所有的显示函数，都只是对OLED显存数组进行读写
 *           随后调用OLED_Update函数或OLED_UpdateArea函数
 *           才会将显存数组的数据发送到OLED硬件，进行显示
 *           故调用显示函数后，要想真正地呈现在屏幕上，还需调用更新函数
 */
void OLED_UpdateArea(uint8_t X, uint8_t Y, uint8_t Width, uint8_t Height)
{
    uint8_t j;

    /*参数检查，保证指定区域不会超出屏幕范围*/
    if (X > 127) { return; }
    if (Y > 63) { return; }
    if (X + Width > 128) { Width = 128 - X; }
    if (Y + Height > 64) { Height = 64 - Y; }

    /*遍历指定区域涉及的相关页*/
    /*(Y + Height - 1) / 8 + 1的目的是(Y + Height) / 8并向上取整*/
    for (j = Y / 8; j < (Y + Height - 1) / 8 + 1; j++) {
        /*设置光标位置为相关页的指定列*/
        OLED_SetCursor(j, X);
        /*连续写入Width个数据，将显存数组的数据写入到OLED硬件*/
        OLED_WriteData(&OLED_DisplayBuf[j][X], Width);
    }
}

/**
 * @brief：将OLED显存数组全部清零
 * @param 无
 * @return：无
 * @attention 调用此函数后，要想真正地呈现在屏幕上，还需调用更新函数
 */
void OLED_Clear(void)
{
    uint8_t i, j;
    for (j = 0; j < 8; j++) // 遍历8页
    {
        for (i = 0; i < 128; i++) // 遍历128列
        {
            OLED_DisplayBuf[j][i] = 0x00; // 将显存数组数据全部清零
        }
    }
}

/**
 * @brief：将OLED显存数组部分清零
 * @param X 指定区域左上角的横坐标，范围：0-127
 * @param Y 指定区域左上角的纵坐标，范围：0-63
 * @param Width 指定区域的宽度，范围：0-128
 * @param Height 指定区域的高度，范围：0-64
 * @return：无
 * @attention 调用此函数后，要想真正地呈现在屏幕上，还需调用更新函数
 */
void OLED_ClearArea(uint8_t X, uint8_t Y, uint8_t Width, uint8_t Height)
{
    uint8_t i, j;

    /*参数检查，保证指定区域不会超出屏幕范围*/
    if (X > 127) { return; }
    if (Y > 63) { return; }
    if (X + Width > 128) { Width = 128 - X; }
    if (Y + Height > 64) { Height = 64 - Y; }

    for (j = Y; j < Y + Height; j++) // 遍历指定页
    {
        for (i = X; i < X + Width; i++) // 遍历指定列
        {
            OLED_DisplayBuf[j / 8][i] &= (0x01 << (j % 8)); // 将显存数组指定数据清零
        }
    }
}

/**
 * @brief：将OLED显存数组全部取反
 * @param 无
 * @return：无
 * @attention 调用此函数后，要想真正地呈现在屏幕上，还需调用更新函数
 */
void OLED_Reverse(void)
{
    uint8_t i, j;
    for (j = 0; j < 8; j++) // 遍历8页
    {
        for (i = 0; i < 128; i++) // 遍历128列
        {
            OLED_DisplayBuf[j][i] ^= 0xFF; // 将显存数组数据全部取反
        }
    }
}

/**
 * @brief 将OLED显存数组部分取反
 * @param X 指定区域左上角的横坐标，范围：0-127
 * @param Y 指定区域左上角的纵坐标，范围：0-63
 * @param Width 指定区域的宽度，范围：0-128
 * @param Height 指定区域的高度，范围：0-64
 * @return：无
 * @attention 调用此函数后，要想真正地呈现在屏幕上，还需调用更新函数
 */
void OLED_ReverseArea(uint8_t X, uint8_t Y, uint8_t Width, uint8_t Height)
{
    uint8_t i, j;

    /*参数检查，保证指定区域不会超出屏幕范围*/
    if (X > 127) { return; }
    if (Y > 63) { return; }
    if (X + Width > 128) { Width = 128 - X; }
    if (Y + Height > 64) { Height = 64 - Y; }

    for (j = Y; j < Y + Height; j++) // 遍历指定页
    {
        for (i = X; i < X + Width; i++) // 遍历指定列
        {
            OLED_DisplayBuf[j / 8][i] ^= 0x01 << (j % 8); // 将显存数组指定数据取反
        }
    }
}

/**
 * @brief   OLED显示一个字符
 * @param   X 指定字符左上角的横坐标，范围：0-127
 * @param   Y 指定字符左上角的纵坐标，范围：0-63
 * @param   Char 指定要显示的字符，范围：ASCII码可见字符
 * @param   FontSize 指定字体大小
 *           范围：OLED_8X16		宽8像素，高16像素
 *                 OLED_6X8		宽6像素，高8像素
 * @return  无
 * @attention 调用此函数后，要想真正地呈现在屏幕上，还需调用更新函数
 */
void OLED_ShowChar(uint8_t X, uint8_t Y, char Char, uint8_t FontSize)
{
    if (FontSize == OLED_8X16) // 字体为宽8像素，高16像素
    {
        /*将ASCII字模库OLED_F8x16的指定数据以8*16的图像格式显示*/
        OLED_ShowImage(X, Y, 8, 16, OLED_F8x16[Char - ' ']);
    } else if (FontSize == OLED_6X8) // 字体为宽6像素，高8像素
    {
        /*将ASCII字模库OLED_F6x8的指定数据以6*8的图像格式显示*/
        OLED_ShowImage(X, Y, 6, 8, OLED_F6x8[Char - ' ']);
    }
    else if (FontSize==OLED_10X20)
    {
        OLED_ShowImage(X,Y,10,20, OLED_F10x20[Char - '0']);
    }
}

/**
 * @brief OLED显示字符串
 * @param X 指定字符串左上角的横坐标，范围：0-127.
 * @param Y 指定字符串左上角的纵坐标，范围：0-63.
 * @param String 指定要显示的字符串，范围：ASCII码可见字符组成的字符串。
 * @param FontSize 指定字体大小
 *           范围：OLED_8X16		宽8像素，高16像素
 *                 OLED_6X8		宽6像素，高8像素
 * @return 无
 * @attention 调用此函数后，要想真正地呈现在屏幕上，还需调用更新函数
 */
void OLED_ShowString(uint8_t X, uint8_t Y, char *String, uint8_t FontSize)
{
    uint8_t i;
    for (i = 0; String[i] != '\0'; i++) // 遍历字符串的每个字符
    {
        /*调用OLED_ShowChar函数，依次显示每个字符*/
        OLED_ShowChar(X + i * FontSize, Y, String[i], FontSize);
    }
}

/**
 * @brief   OLED显示数字（十进制，正整数）
 * @param   X 指定数字左上角的横坐标，范围：0-127
 * @param   Y 指定数字左上角的纵坐标，范围：0-63
 * @param   Number 指定要显示的数字，范围：0-4294967295
 * @param   Length 指定数字的长度，范围：0-10
 * @param   FontSize 指定字体大小
 *           范围：OLED_8X16		宽8像素，高16像素
 *                 OLED_6X8		宽6像素，高8像素
 * @return：无
 * @attention 调用此函数后，要想真正地呈现在屏幕上，还需调用更新函数
 */
void OLED_ShowNum(uint8_t X, uint8_t Y, uint32_t Number, uint8_t Length, uint8_t FontSize)
{
    uint8_t i;
    for (i = 0; i < Length; i++) // 遍历数字的每一位
    {
        /*调用OLED_ShowChar函数，依次显示每个数字*/
        /*Number / OLED_Pow(10, Length - i - 1) % 10 可以十进制提取数字的每一位*/
        /*+ '0' 可将数字转换为字符格式*/
        OLED_ShowChar(X + i * FontSize, Y, Number / OLED_Pow(10, Length - i - 1) % 10 + '0', FontSize);
    }
}

/**
 * @brief：OLED显示有符号数字（十进制，整数）
 * @param X 指定数字左上角的横坐标，范围：0-127
 * @param Y 指定数字左上角的纵坐标，范围：0-63
 * @param Number 指定要显示的数字，范围：-2147483648-2147483647
 * @param Length 指定数字的长度，范围：0-10
 * @param FontSize 指定字体大小
 *           范围：OLED_8X16		宽8像素，高16像素
 *                 OLED_6X8		宽6像素，高8像素
 * @return：无
 * @attention 调用此函数后，要想真正地呈现在屏幕上，还需调用更新函数
 */
void OLED_ShowSignedNum(uint8_t X, uint8_t Y, int32_t Number, uint8_t Length, uint8_t FontSize)
{
    uint8_t i;
    uint32_t Number1;

    if (Number >= 0) // 数字大于等于0
    {
        OLED_ShowChar(X, Y, '+', FontSize); // 显示+号
        Number1 = Number;                   // Number1直接等于Number
    } else                                  // 数字小于0
    {
        OLED_ShowChar(X, Y, '-', FontSize); // 显示-号
        Number1 = -Number;                  // Number1等于Number取负
    }

    for (i = 0; i < Length; i++) // 遍历数字的每一位
    {
        /*调用OLED_ShowChar函数，依次显示每个数字*/
        /*Number1 / OLED_Pow(10, Length - i - 1) % 10 可以十进制提取数字的每一位*/
        /*+ '0' 可将数字转换为字符格式*/
        OLED_ShowChar(X + (i + 1) * FontSize, Y, Number1 / OLED_Pow(10, Length - i - 1) % 10 + '0', FontSize);
    }
}

/**
 * @brief：OLED显示十六进制数字（十六进制，正整数）
 * @param X 指定数字左上角的横坐标，范围：0-127
 * @param Y 指定数字左上角的纵坐标，范围：0-63
 * @param Number 指定要显示的数字，范围：0x00000000-0xFFFFFFFF
 * @param Length 指定数字的长度，范围：0-8
 * @param FontSize 指定字体大小
 *           范围：OLED_8X16		宽8像素，高16像素
 *                 OLED_6X8		宽6像素，高8像素
 * @return：无
 * @attention 调用此函数后，要想真正地呈现在屏幕上，还需调用更新函数
 */
void OLED_ShowHexNum(uint8_t X, uint8_t Y, uint32_t Number, uint8_t Length, uint8_t FontSize)
{
    uint8_t i, SingleNumber;
    for (i = 0; i < Length; i++) // 遍历数字的每一位
    {
        /*以十六进制提取数字的每一位*/
        SingleNumber = Number / OLED_Pow(16, Length - i - 1) % 16;

        if (SingleNumber < 10) // 单个数字小于10
        {
            /*调用OLED_ShowChar函数，显示此数字*/
            /*+ '0' 可将数字转换为字符格式*/
            OLED_ShowChar(X + i * FontSize, Y, SingleNumber + '0', FontSize);
        } else // 单个数字大于10
        {
            /*调用OLED_ShowChar函数，显示此数字*/
            /*+ 'A' 可将数字转换为从A开始的十六进制字符*/
            OLED_ShowChar(X + i * FontSize, Y, SingleNumber - 10 + 'A', FontSize);
        }
    }
}

/**
 * @brief：OLED显示二进制数字（二进制，正整数）
 * @param X 指定数字左上角的横坐标，范围：0-127
 * @param Y 指定数字左上角的纵坐标，范围：0-63
 * @param Number 指定要显示的数字，范围：0x00000000-0xFFFFFFFF
 * @param Length 指定数字的长度，范围：0-16
 * @param FontSize 指定字体大小
 *           范围：OLED_8X16		宽8像素，高16像素
 *                 OLED_6X8		宽6像素，高8像素
 * @return：无
 * @attention 调用此函数后，要想真正地呈现在屏幕上，还需调用更新函数
 */
void OLED_ShowBinNum(uint8_t X, uint8_t Y, uint32_t Number, uint8_t Length, uint8_t FontSize)
{
    uint8_t i;
    for (i = 0; i < Length; i++) // 遍历数字的每一位
    {
        /*调用OLED_ShowChar函数，依次显示每个数字*/
        /*Number / OLED_Pow(2, Length - i - 1) % 2 可以二进制提取数字的每一位*/
        /*+ '0' 可将数字转换为字符格式*/
        OLED_ShowChar(X + i * FontSize, Y, Number / OLED_Pow(2, Length - i - 1) % 2 + '0', FontSize);
    }
}

/**
 * @brief：OLED显示浮点数字（十进制，小数）
 * @param X 指定数字左上角的横坐标，范围：0-127
 * @param Y 指定数字左上角的纵坐标，范围：0-63
 * @param Number 指定要显示的数字，范围：-4294967295.0-4294967295.0
 * @param IntLength 指定数字的整数位长度，范围：0-10
 * @param FraLength 指定数字的小数位长度，范围：0-9，小数进行四舍五入显示
 * @param FontSize 指定字体大小
 *           范围：OLED_8X16		宽8像素，高16像素
 *                 OLED_6X8		宽6像素，高8像素
 * @return：无
 * @attention 调用此函数后，要想真正地呈现在屏幕上，还需调用更新函数
 */
void OLED_ShowFloatNum(uint8_t X, uint8_t Y, double Number, uint8_t IntLength, uint8_t FraLength, uint8_t FontSize)
{
    uint32_t PowNum, IntNum, FraNum;

    if (Number >= 0) // 数字大于等于0
    {
        OLED_ShowChar(X, Y, '+', FontSize); // 显示+号
    } else                                  // 数字小于0
    {
        OLED_ShowChar(X, Y, '-', FontSize); // 显示-号
        Number = -Number;                   // Number取负
    }

    /*提取整数部分和小数部分*/
    IntNum = Number;                  // 直接赋值给整型变量，提取整数
    Number -= IntNum;                 // 将Number的整数减掉，防止之后将小数乘到整数时因数过大造成错误
    PowNum = OLED_Pow(10, FraLength); // 根据指定小数的位数，确定乘数
    FraNum = round(Number * PowNum);  // 将小数乘到整数，同时四舍五入，避免显示误差
    IntNum += FraNum / PowNum;        // 若四舍五入造成了进位，则需要再加给整数

    /*显示整数部分*/
    OLED_ShowNum(X + FontSize, Y, IntNum, IntLength, FontSize);

    /*显示小数点*/
    OLED_ShowChar(X + (IntLength + 1) * FontSize, Y, '.', FontSize);

    /*显示小数部分*/
    OLED_ShowNum(X + (IntLength + 2) * FontSize, Y, FraNum, FraLength, FontSize);
}

/**
 * @brief：OLED显示图像
 * @param X 指定图像左上角的横坐标，范围：0-127
 * @param Y 指定图像左上角的纵坐标，范围：0-63
 * @param Width 指定图像的宽度，范围：0-128
 * @param Height 指定图像的高度，范围：0-64
 * @param Image 指定要显示的图像
 * @return：无
 * @attention 调用此函数后，要想真正地呈现在屏幕上，还需调用更新函数
 */
void OLED_ShowImage(uint8_t X, uint8_t Y, uint8_t Width, uint8_t Height, const uint8_t *Image)
{
    uint8_t i, j;

    /*参数检查，保证指定图像不会超出屏幕范围*/
    if (X > 127) { return; }
    if (Y > 63) { return; }

    /*将图像所在区域清空*/
    OLED_ClearArea(X, Y, Width, Height);

    /*遍历指定图像涉及的相关页*/
    /*(Height - 1) / 8 + 1的目的是Height / 8并向上取整*/
    for (j = 0; j < (Height - 1) / 8 + 1; j++) {
        /*遍历指定图像涉及的相关列*/
        for (i = 0; i < Width; i++) {
            /*超出边界，则跳过显示*/
            if (X + i > 127) { break; }
            if (Y / 8 + j > 7) { return; }

            /*显示图像在当前页的内容*/
            OLED_DisplayBuf[Y / 8 + j][X + i] |= Image[j * Width + i] << (Y % 8);

            /*超出边界，则跳过显示*/
            /*使用continue的目的是，下一页超出边界时，上一页的后续内容还需要继续显示*/
            if (Y / 8 + j + 1 > 7) { continue; }

            /*显示图像在下一页的内容*/
            OLED_DisplayBuf[Y / 8 + j + 1][X + i] |= Image[j * Width + i] >> (8 - Y % 8);
        }
    }
}

/**
 * @brief：OLED使用printf函数打印格式化字符串
 * @param X 指定格式化字符串左上角的横坐标，范围：0-127
 * @param Y 指定格式化字符串左上角的纵坐标，范围：0-63
 * @param FontSize 指定字体大小
 *           范围：OLED_8X16		宽8像素，高16像素
 *                 OLED_6X8		宽6像素，高8像素
 * @param format 指定要显示的格式化字符串，范围：ASCII码可见字符组成的字符串
 * @param ... 格式化字符串参数列表
 * @return：无
 * @attention 调用此函数后，要想真正地呈现在屏幕上，还需调用更新函数
 */
void OLED_Printf(uint8_t X, uint8_t Y, uint8_t FontSize, char *format, ...)
{
    char String[30];                         // 定义字符数组
    va_list arg;                             // 定义可变参数列表数据类型的变量arg
    va_start(arg, format);                   // 从format开始，接收参数列表到arg变量
    vsprintf(String, format, arg);           // 使用vsprintf打印格式化字符串和参数列表到字符数组中
    va_end(arg);                             // 结束变量arg
    OLED_ShowString(X, Y, String, FontSize); // OLED显示字符数组（字符串）
}

/**
 * @brief：OLED在指定位置画一个点
 * @param X 指定点的横坐标，范围：0-127
 * @param Y 指定点的纵坐标，范围：0-63
 * @return：无
 * @attention 调用此函数后，要想真正地呈现在屏幕上，还需调用更新函数
 */
void OLED_DrawPoint(uint8_t X, uint8_t Y)
{
    /*参数检查，保证指定位置不会超出屏幕范围*/
    if (X > 127) { return; }
    if (Y > 63) { return; }

    /*将显存数组指定位置的一个Bit数据置1*/
    OLED_DisplayBuf[Y / 8][X] |= 0x01 << (Y % 8);
}

/**
 * @brief：OLED获取指定位置点的值
 * @param X 指定点的横坐标，范围：0-127
 * @param Y 指定点的纵坐标，范围：0-63
 * @return：指定位置点是否处于点亮状态，1：点亮，0：熄灭
 */
uint8_t OLED_GetPoint(uint8_t X, uint8_t Y)
{
    /*参数检查，保证指定位置不会超出屏幕范围*/
    if (X > 127) { return 0; }
    if (Y > 63) { return 0; }

    /*判断指定位置的数据*/
    if (OLED_DisplayBuf[Y / 8][X] & 0x01 << (Y % 8)) {
        return 1; // 为1，返回1
    }

    return 0; // 否则，返回0
}
