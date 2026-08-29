
## Guition 480x480 Touchscreen display template for LVGL
I struggled getting this display working on SquareLine, so I used created a stripped down version of rzeldent's [esp32-smartdisplay](https://github.com/rzeldent/esp32-smartdisplay) that applies to the $15 [display](https://www.aliexpress.us/item/3256808028364930.html) in question. Unlike CYD's, this is a very pretty display with convenient JST/2.54mm IO on the back and has speaker, touch, battery, and antenna built in.
## Installation
 
1. This applies to [VSCode](https://code.visualstudio.com/download?) with the [Platform IDE](https://platformio.org/install/ide?install=vscode) extension installed
2. `git clone https://github.com/dc336/4848S040CIY1-Guititon-Template.git`
3. `cd 4848S040CIY1-Guititon-Template`
4. Build + Upload (`pio run --target upload`)

## Resources

[Aliexpress store page](https://www.aliexpress.us/item/3256808028364930.html)

[Official Page](https://www.guition.com/esp32-display-module/4-inch-esp32s3-display-module)

[Official 'Datasheet'](https://www.guition.com/icms/upload/fb081940d6fc11f09850077a33e1404f/file/productmanager-productfile/f0887f400ae446099120cad1eef1c7f4/Directory/ESP32-4848S040%20Specifications-EN_1776827882586.pdf)

[ESP Chip](https://fccid.io/m/be729405d0b0e6411fd7e01e69acec34184d17a9e57c43ec413389783c890f71.pdf)
 -ESP32-S3R8 / 240MHz / 512KB SRAM / 384KB ROM / 8MB PSRAM / 16MB FLASH
