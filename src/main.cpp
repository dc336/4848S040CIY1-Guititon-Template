#include <Arduino.h>
#include <esp32_smartdisplay.h>
#include <stdlib.h>
#include <WiFi.h>
#include "secrets.h"

static lv_obj_t *screen = nullptr;
static constexpr unsigned int BG_COLOR = 0x101820;

// Circle demo
static constexpr unsigned int MAX_CIRCLES = 100;
static unsigned int circle_count = 0;

static void make_circle(const lv_point_t &point)
{
    if (screen == nullptr || circle_count >= MAX_CIRCLES) // Check if screen didn't init and if there's too many circles
    {
        return;
    }

    lv_obj_t *circle = lv_obj_create(screen);
    if (circle == nullptr)
    {
        Serial.println("Failed to create circle");
        return;
    }

    lv_obj_clear_flag(circle, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_clear_flag(circle, LV_OBJ_FLAG_CLICKABLE);

    int CIRCLE_SIZE = (rand() % 100) + 20; // Random size between 20 and 120 pixels

    lv_obj_set_size(circle, CIRCLE_SIZE, CIRCLE_SIZE);
    lv_obj_set_pos(
        circle,
        point.x - (CIRCLE_SIZE / 2),
        point.y - (CIRCLE_SIZE / 2)); // Get the center of circle so your tap is where the circle is

    lv_obj_set_style_radius(circle, LV_RADIUS_CIRCLE, LV_PART_MAIN);

    lv_obj_set_style_bg_color(
        circle,
        lv_color_hex(((rand() % 16777215) + 1)), // 0xFFFFFF as decimmal. Simple random color generator
        LV_PART_MAIN);
    lv_obj_set_style_bg_opa(circle, LV_OPA_COVER, LV_PART_MAIN);
    lv_obj_set_style_border_width(circle, 0, LV_PART_MAIN);

    ++circle_count;
}

static void screen_touched(lv_event_t *event)
{
    (void)event;

    lv_indev_t *input = lv_indev_active();
    if (input == nullptr)
    {
        return;
    }

    lv_point_t point{};
    lv_indev_get_point(input, &point);
    make_circle(point);
}

static void calibrate_touch()
{
    touch_calibration_data.valid = true;
    touch_calibration_data.alphaX = 1085.0F / 480.0F;
    touch_calibration_data.betaX = 0.0F;
    touch_calibration_data.deltaX = 0.0F;
    touch_calibration_data.alphaY = 0.0F;
    touch_calibration_data.betaY = 600.0F / 480.0F;
    touch_calibration_data.deltaY = 0.0F;
}

static void wifiEvent(WiFiEvent_t event, WiFiEventInfo_t info)
{
    switch (event) {
        case ARDUINO_EVENT_WIFI_STA_GOT_IP:
            Serial.print("IP: ");
            Serial.println(WiFi.localIP());
            break;

        case ARDUINO_EVENT_WIFI_STA_DISCONNECTED:
            Serial.print("WiFi disconnected, reason: ");
            Serial.println(info.wifi_sta_disconnected.reason);
            break;

        default:
            break;
    }
}

void static connectWifi()
{
    WiFi.onEvent(wifiEvent);
    WiFi.mode(WIFI_STA);
    WiFi.setAutoReconnect(true);
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
}

void setup()
{
    Serial.begin(115200);
    delay(500);
    Serial.println("Starting LVGL");

    smartdisplay_init();
    calibrate_touch();
    smartdisplay_lcd_set_backlight(1.0F);

    screen = lv_screen_active();
    if (screen == nullptr)
    {
        Serial.println("Failed to obtain the active LVGL screen");
        return;
    }

    connectWifi();

    lv_obj_clear_flag(screen, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_add_flag(screen, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_set_style_bg_color(
        screen,
        lv_color_hex(BG_COLOR),
        LV_PART_MAIN);

    lv_obj_add_event_cb(
        screen,
        screen_touched,
        LV_EVENT_PRESSING,
        nullptr);
}

void loop()
{
    static unsigned long previous_tick = millis();
    const unsigned long now = millis();

    lv_tick_inc(now - previous_tick);
    previous_tick = now;

    lv_timer_handler();
    delay(5);
}