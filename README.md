# ESP32 Power Consumption Test

## Test Setup

The test setup was powered with a lab power supply at 5.0 V and optionally 3.7 V, if the boards supports rechargeable li-ion batteries. The current was measured both with a UNI-T UT61E multimeter in the mA range and with an oscillosope at an 1.00 &#937; series resistor. The voltage loss at the multimeter and the resistor is below 100 mV.

## Test Cycle

The program performs the following test cycle in `startup()`. It will be repeated infinitely:
* 4 seconds awake in `delayMicroseconds()` (WiFi/Bluetooth off)
* 4 seconds in light sleep
* 4 seconds in deep sleep

## Summary

| Board                | Voltage [V] | Awake [mA] | Light Sleep [mA] | Deep Sleep [mA] |
| -------------------- | :---------: | :--------: | :--------------: | :-------------: |
| NodeMCU ESP-32S V1.1 |         5.0 |       64.6 |             13.8 |             4.7 |
| WEMOS LOLIN32 V1.0.0 |         5.0 |       57.3 |              3.1 |             1.2 |
| WEMOS LOLIN32 V1.0.0 |         3.7 |       55.7 |              2.0 |            0.13 |
| LILYGO ESP32 OLED    |         5.0 |       64.5 |             10.8 |             9.4 |

## Board Details

The oscilloscope shows 10 mA per division on Y, zero is at the bottom grid line. This cheap thing has a minor offset error of about +1.5 mA in the used 10 mV range on this channel which cannot be calibrated any better.

### NodeMCU ESP-32S V1.1

5 V
<img src="doc/NodeMCU_ESP-32S_V1.1_osc_5V.png" width=600>

### WEMOS LOLIN32 V1.0.0

5 V
<img src="doc/WEMOS_LOLIN32_V1.0.0_osc_5V.png" width=600>

3.7 V
<img src="doc/WEMOS_LOLIN32_V1.0.0_osc_3.3V.png" width=600>

### LILYGO ESP32 OLED

5 V
<img src="doc/LILYGO_ESP32_OLED_osc_5V.png" width=600>
