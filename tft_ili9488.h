#ifndef TFT_ILI9488_H_
#define TFT_ILI9488_H_

#include "main.h"
#include <stdint.h>
#include "stm32f4xx_hal.h"

#define ILI9488_BLACK 0x000000     // R=0,   G=0,   B=0
#define ILI9488_NAVY 0x000080      // R=0,   G=0,   B=128
#define ILI9488_DARKGREEN 0x008000 // R=0,   G=128, B=0
#define ILI9488_DARKCYAN 0x008080  // R=0,   G=128, B=128
#define ILI9488_MAROON 0x800000    // R=128, G=0,   B=0
#define ILI9488_PURPLE 0x800080    // R=128, G=0,   B=128
#define ILI9488_OLIVE 0x808000     // R=128, G=128, B=0
#define ILI9488_LIGHTGREY 0xC6C6C6 // R=198, G=198, B=198
#define ILI9488_DARKGREY 0x7BEF7B  // (variant dark grey)
#define ILI9488_BLUE 0x0000FF      // R=0,   G=0,   B=255
#define ILI9488_GREEN 0x00FF00     // R=0,   G=255, B=0
#define ILI9488_CYAN 0x00FFFF      // R=0,   G=255, B=255
#define ILI9488_RED 0xFF0000       // R=255, G=0,   B=0
#define ILI9488_MAGENTA 0xFF00FF   // R=255, G=0,   B=255
#define ILI9488_YELLOW 0xFFFF00    // R=255, G=255, B=0
#define ILI9488_WHITE 0xFFFFFF     // R=255, G=255, B=255
#define ILI9488_ORANGE 0xFFA500    // R=255, G=165, B=0
#define ILI9488_PINK 0xFFC0CB      // R=255, G=192, B=203
#define ILI9488_SKYBLUE 0x87CEEB   // R=135, G=206, B=235
#define ILI9488_VIOLET 0x8A2BE2    // R=138, G=43,  B=226

// Common ILI9488 commands
#define ILI9488_NOP 0x00
#define ILI9488_SOFTWARE_RESET 0x01
#define ILI9488_READ_DISPLAY_ID 0x04
#define ILI9488_READ_DISPLAY_STATUS 0x09
#define ILI9488_READ_POWER_MODE 0x0A
#define ILI9488_READ_MADCTL 0x0B
#define ILI9488_READ_PIXEL_FORMAT 0x0C
#define ILI9488_READ_IMAGE_MODE 0x0D
#define ILI9488_READ_SIGNAL_MODE 0x0E
#define ILI9488_SLEEP_IN 0x10
#define ILI9488_SLEEP_OUT 0x11
#define ILI9488_PARTIAL_MODE_ON 0x12
#define ILI9488_NORMAL_MODE_ON 0x13
#define ILI9488_DISPLAY_INVERSION_OFF 0x20
#define ILI9488_DISPLAY_INVERSION_ON 0x21
#define ILI9488_DISPLAY_OFF 0x28
#define ILI9488_DISPLAY_ON 0x29
#define ILI9488_COLUMN_ADDR_SET 0x2A
#define ILI9488_ROW_ADDR_SET 0x2B
#define ILI9488_MEMORY_WRITE 0x2C
#define ILI9488_COLOR_SET 0x2D
#define ILI9488_MEMORY_READ 0x2E
#define ILI9488_PARTIAL_AREA 0x30
#define ILI9488_VERTICAL_SCROLL 0x33
#define ILI9488_TEARING_EFFECT_LINE 0x35
#define ILI9488_MEMORY_ACCESS_CONTROL 0x36
#define ILI9488_VERTICAL_SCROLL_ADDR 0x37
#define ILI9488_IDLE_MODE_OFF 0x38
#define ILI9488_IDLE_MODE_ON 0x39
#define ILI9488_PIXEL_FORMAT_SET 0x3A
#define ILI9488_WRITE_MEMORY_CONTINUE 0x3C
#define ILI9488_READ_MEMORY_CONTINUE 0x3E
#define ILI9488_SET_TEAR_SCANLINE 0x44
#define ILI9488_GET_SCANLINE 0x45
#define ILI9488_WRITE_DISPLAY_BRIGHT 0x51
#define ILI9488_READ_DISPLAY_BRIGHT 0x52
#define ILI9488_WRITE_CTRL_DISPLAY 0x53
#define ILI9488_READ_CTRL_DISPLAY 0x54
#define ILI9488_WRITE_CONTENT_ADAPT 0x55
#define ILI9488_READ_CONTENT_ADAPT 0x56
#define ILI9488_WRITE_CABC_MIN_BRIGHT 0x5E
#define ILI9488_READ_CABC_MIN_BRIGHT 0x5F

#define ILI9488_INTERFACE_MODE_CTRL 0xB0
#define ILI9488_FRAME_RATE_CTRL 0xB1
#define ILI9488_DISPLAY_INV_CTRL 0xB4
#define ILI9488_BLANKING_PORCH_CTRL 0xB5
#define ILI9488_DISPLAY_FUNCTION_CTRL 0xB6
#define ILI9488_ENTRY_MODE_SET 0xB7
#define ILI9488_BACKLIGHT_CTRL1 0xB8
#define ILI9488_BACKLIGHT_CTRL2 0xB9
#define ILI9488_BACKLIGHT_CTRL3 0xBA
#define ILI9488_BACKLIGHT_CTRL4 0xBB
#define ILI9488_BACKLIGHT_CTRL5 0xBC
#define ILI9488_BACKLIGHT_CTRL7 0xBE
#define ILI9488_BACKLIGHT_CTRL8 0xBF

#define ILI9488_POWER_CTRL_1 0xC0
#define ILI9488_POWER_CTRL_2 0xC1
#define ILI9488_VCOM_CTRL_1 0xC5

#define ILI9488_NVMEM_WRITE 0xD0
#define ILI9488_NVMEM_PROTECT_KEY 0xD1
#define ILI9488_NVMEM_STATUS_READ 0xD2
#define ILI9488_READ_ID4 0xD3

#define ILI9488_POSITIVE_GAMMA_CORR 0xE0
#define ILI9488_NEGATIVE_GAMMA_CORR 0xE1
#define ILI9488_DIGITAL_GAMMA_CTRL1 0xE2
#define ILI9488_DIGITAL_GAMMA_CTRL2 0xE3

#define ILI9488_SET_IMAGE_FUNC 0xE9
#define ILI9488_ADJUST_CTRL3 0xF7

#define ILI9488_DATA() (HAL_GPIO_WritePin(TFT_DC_GPIO_Port, TFT_DC_Pin, GPIO_PIN_SET))
#define ILI9488_COMM() (HAL_GPIO_WritePin(TFT_DC_GPIO_Port, TFT_DC_Pin, GPIO_PIN_RESET))

#define ILI9488_SSL() (HAL_GPIO_WritePin(TFT_CS_GPIO_Port, TFT_CS_Pin, GPIO_PIN_RESET))
#define ILI9488_SSH() (HAL_GPIO_WritePin(TFT_CS_GPIO_Port, TFT_CS_Pin, GPIO_PIN_SET))

#define ILI9488_RSTL() (HAL_GPIO_WritePin(TFT_RESET_GPIO_Port, TFT_RESET_Pin, GPIO_PIN_RESET))
#define ILI9488_RSTH() (HAL_GPIO_WritePin(TFT_RESET_GPIO_Port, TFT_RESET_Pin, GPIO_PIN_SET))

typedef struct ili9488
{
    uint16_t width;
    uint16_t height;

    // Low-level hardware interface (implemented by user)
    void (*send_command)(uint8_t cmd);
    void (*send_data8)(uint8_t data);
    void (*send_data16)(uint16_t data);
    void (*send_buffer)(const uint8_t *data, uint16_t len);
    void (*ili9488_rst)(uint8_t state);
    void (*delay)(uint32_t ms);

} ili9488_t;

void ili9488_init(ili9488_t *disp);
void ili9488_set_address_window(ili9488_t *disp, uint16_t x0, uint16_t x1, uint16_t y0, uint16_t y1);
void ili9488_fill_screen(ili9488_t *disp, uint32_t color);
void ili9488_draw_rect(ili9488_t *disp, uint16_t x, uint16_t y, uint16_t height, uint16_t width, uint32_t color);
void ili9488_test_display(ili9488_t *disp);
void ili9488_draw_char(ili9488_t *disp, int x, int y, char c, uint32_t color, uint32_t bg);
void ili9488_draw_string(ili9488_t *disp, int x, int y, const char *str, uint32_t color, uint32_t bg);
void ili9488_draw_image(ili9488_t *disp, int x, int y, const uint8_t *bitmap, int width, int height);


#endif // TFT_ILI9488_H_