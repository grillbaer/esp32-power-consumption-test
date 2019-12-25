#include <Arduino.h>
#include "driver/rtc_io.h"
#include <esp_wifi.h>
#include <esp_bt.h>
#include <esp_bt_main.h>

#define SERIAL_BAUD 115200

#define WAKE_SECS 4
#define LIGHT_SECS 4
#define DEEP_SECS 4

#define MICROS 1000000LL

void setup()
{
  Serial.begin(SERIAL_BAUD);

  esp_wifi_stop();
  esp_bt_controller_disable();
  esp_bluedroid_disable();

  Serial.printf("Wake for %d seconds\n", WAKE_SECS);
  delayMicroseconds(WAKE_SECS * MICROS);

  Serial.printf("Light sleep for %d seconds\n", LIGHT_SECS);
  Serial.flush();
  esp_sleep_enable_timer_wakeup(LIGHT_SECS * MICROS);
  esp_light_sleep_start();

  Serial.printf("Deep sleep for %d seconds\n", DEEP_SECS);
  Serial.flush();
  esp_sleep_enable_timer_wakeup(DEEP_SECS * MICROS);
  esp_deep_sleep_start();
  // waking from deep sleep will re-run setup()
}

void loop()
{
  // won't be reached
}
