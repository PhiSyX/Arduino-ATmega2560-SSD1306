/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#include <Adafruit_SSD1306.h>
#include <ArduinoJson.h>
#include <SPI.h>

// ------ //
// Header //
// ------ //

#include "Encoder/RotaryEncoder.hpp"
#include "Layout.hpp"
#include "Router.hpp"
#include "View.hpp"

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

void
setup()
{
  Serial.begin(SERIAL_BAUD_RATE);

  rotary_encoder.setup();
  layout.setup();
}

// --------- //
// Main loop //
// --------- //

void
loop()
{
  view.reset_total();

  switch (router.current()) {
    case Page::VIEW_ERROR:
      view.display_error();
      break;

    case Page::VIEW_HOME:
      view.display_home();
      break;

    default:
      break;
  }
}
