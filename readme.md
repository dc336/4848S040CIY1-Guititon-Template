# Guition 480×480 Touchscreen Template for LVGL

I struggled getting this display working with SquareLine Studio, so I put together a stripped down version of rzeldent’s [esp32-smartdisplay](https://github.com/rzeldent/esp32-smartdisplay) library specifically for this roughly $15 [Guition display](https://www.aliexpress.us/item/3256808028364930.html).

Compared to typical CYD boards, it’s a pretty display with convenient JST/2.54mm IO on the back. It also includes a speaker, touch, battery, and an antenna.

## Installation

1. Install [Visual Studio Code](https://code.visualstudio.com/download) and the [PlatformIO IDE extension](https://platformio.org/install/ide?install=vscode).

2. Clone the repository:

   ```bash
   git clone https://github.com/dc336/4848S040CIY1-Guititon-Template.git
   ```

3. Open the project directory:

   ```bash
   cd 4848S040CIY1-Guititon-Template
   ```

4. Build and upload:

   ```bash
   pio run --target upload
   ```

## Resources

* [AliExpress product page](https://www.aliexpress.us/item/3256808028364930.html)
* [Official product page](https://www.guition.com/esp32-display-module/4-inch-esp32s3-display-module)
* [Official datasheet](https://www.guition.com/icms/upload/fb081940d6fc11f09850077a33e1404f/file/productmanager-productfile/f0887f400ae446099120cad1eef1c7f4/Directory/ESP32-4848S040%20Specifications-EN_1776827882586.pdf)
* [ESP32-S3 documentation](https://fccid.io/m/be729405d0b0e6411fd7e01e69acec34184d17a9e57c43ec413389783c890f71.pdf)

## Hardware

* ESP32-S3R8
* 240 MHz
* 512 KB SRAM
* 384 KB ROM
* 8 MB PSRAM
* 16 MB flash
