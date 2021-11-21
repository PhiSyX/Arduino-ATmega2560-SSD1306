#include <Adafruit_SSD1306.h>
#include <ArduinoJson.h>
#include <SPI.h>

// ------ //
// Header //
// ------ //

#include "Encoder/RotaryEncoder.hpp"
#include "Layout.hpp"
#include "View.hpp"
#include "Router.hpp"

// --------- //
// Constante //
// --------- //

// Serial
#define SERIAL_BAUD_RATE 9600

// Configuration Écran
#define SCREEN_OLED_RESET 4
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// -------------- //
// Initialisation //
// -------------- //

Adafruit_SSD1306 screen(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, SCREEN_OLED_RESET);

Layout layout;
View view;
Router router;
RotaryEncoder rotary_encoder;

void setup()
{
    Serial.begin(SERIAL_BAUD_RATE);

    rotary_encoder.setup();
    layout.setup();
}

// --------- //
// Main loop //
// --------- //

void loop()
{
    view.reset_total();

    switch (router.current())
    {
    case Page::VIEW_ERROR:
        break;

    case Page::VIEW_HOME:
        view.display_home();
        break;

    default:
        break;
    }
}
