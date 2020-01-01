# ESP32 Power Consumption Comparison 

The following table shows the power supply current that various ESP32 boards require in different operating modes. These milli- and micro-amperes decide whether the board is well suited for battery operation:

| Board                | Voltage [V] | Awake [mA] | Light Sleep [mA] | Deep Sleep [mA] |
| -------------------- | :---------: | :--------: | :--------------: | :-------------: |
| EzSBC ESP32-01       |         3.7 |       52.6 |              1.6 |         < 0.012 |
| EzSBC ESP32-01       |     **5.0** |       53.1 |              1.6 |       **0.012** |
| EzSBC ESP32-01       |        12.0 |       53.4 |              1.8 |           0.016 |
| LILYGO ESP32 OLED    |     **5.0** |       64.5 |             10.8 |         **9.4** |
| NodeMCU ESP-32S V1.1 |     **5.0** |       64.6 |             13.8 |         **4.7** |
| WEMOS LOLIN32 V1.0.0 |         3.7 |       55.7 |              2.0 |            0.13 |
| WEMOS LOLIN32 V1.0.0 |     **5.0** |       57.3 |              3.1 |         **1.2** |

## Test Setup

The test setup was powered with a lab power supply at 5.0 V, optionally at 3.7 V for rechargeable Li-ion batteries, or 12 V if the board supports it. The current was measured both with a UNI-T UT61E multimeter in the mA range in series and with an oscillosope at an 1.00 &#937; series resistor. The voltage loss at the multimeter and the resistor is below 100 mV.
The oscilloscope view helps to see current spikes and noise, mainly from the voltage regulators.

No external peripherals were connected to the boards during the test. Note that these may severely influence the power consumption in real applications during deep sleep. GPIOs are not automatically of high impedence while sleeping, pull-up or -down and output may still be active and the behavior is not equal for all GPIOs. For the subset of RTC GPIOs, you may control their behavior using `rtc_gpio_isolate(gpio)`, `rtc_gpio_hold_en(gpio)` and `rtc_gpio_hold_dis(gpio)` and some other `rtc_gpio_...()` functions in [ESP-IDF](https://docs.espressif.com/projects/esp-idf/en/latest/api-reference/peripherals/gpio.html). For battery life optimization, you always will need to measure your own circuit. It may be far off the minimum values from the table.

## Test Cycle

The program performs the following test cycle in `startup()`. It will be repeated infinitely:
* 4 seconds awake in `delayMicroseconds()` (WiFi/Bluetooth off)
* 4 seconds in light sleep
* 4 seconds in deep sleep

## Board Details

The oscilloscope shows 10 mA per division on Y, zero is at the bottom grid line. This cheap thing has a minor offset error of about +1.5 mA in the used 10 mV range on this channel which cannot be calibrated any better.

### EzSBC ESP32-01

This board is optimized for low power consumption while maintaining the ease-of-use of a development/breakout board with USB connector. The deep sleep current can even be more reduced as described on [EzSBC ESP32-01 Product Description](https://www.ezsbc.com/index.php/featured-products-list-home-page/wifi01-35.html#.XgMr_iHQhEY). 
It has reset and flash push buttons, but also supports auto-download. It also has a freely usable RGB LED. The other LED shows Tx/Rx (red/green), blue is connected to another GPIO. It is narrow and therefore breadboard friendly. Good quality from the USA.

**Note** that these LEDs are *always* connected to +3.3 V with series resistors, a fact that may ruin your deep sleep current when their GPIOs are used to connect peripherals in your battery operated application!

<img src="doc/EzSBC_ESP32-01_board.jpg" width=510>

3.7 V

<img src="doc/EzSBC_ESP32-01_osc_3.7V.png" width=400>

5.0 V

<img src="doc/EzSBC_ESP32-01_osc_5V.png" width=400>

12 V

<img src="doc/EzSBC_ESP32-01_osc_12V.png" width=400>

### LILYGO ESP32 OLED

A very useful board for development when a 128x64 pixel OLED display with SSD1306 controller is required.

<img src="doc/LILYGO_ESP32_OLED_board.jpg" width=550>

5 V

<img src="doc/LILYGO_ESP32_OLED_osc_5V.png" width=400>

### NodeMCU ESP-32S V1.1

An older small board.

<img src="doc/NodeMCU_ESP-32S_V1.1_board.jpg" width=440>

5 V

<img src="doc/NodeMCU_ESP-32S_V1.1_osc_5V.png" width=400>

### WEMOS LOLIN32 V1.0.0

A solid older board with good low power characteristics and recharchable Li-ion battery support.

<img src="doc/WEMOS_LOLIN32_V1.0.0_board.jpg" width=500>

3.7 V

<img src="doc/WEMOS_LOLIN32_V1.0.0_osc_3.3V.png" width=400>

5 V

<img src="doc/WEMOS_LOLIN32_V1.0.0_osc_5V.png" width=400>
