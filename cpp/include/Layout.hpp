/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#ifndef LAYOUT_HPP
#define LAYOUT_HPP

#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

class Layout
{
public: // setup
  const void setup() const;

public: // getters
  const byte get_width() const;
  const byte get_height() const;
  const unsigned short int get_half_from_str(const String& str) const;

public: // setters
  const void set_text_color(const uint16_t fg_color) const;
  const void set_text_color(const uint16_t fg_color,
                            const uint16_t bg_color) const;
  const void set_text_size(const uint8_t text_size) const;
  const void set_selected_circle(const byte x, const byte y) const;
  const void set_selected_rect(const byte l,
                               const byte t,
                               const byte r,
                               const byte b) const;

public: // methods
  const void clear() const;
  const void cursor(const byte x, const byte y) const;
  const void display() const;
  const void print(const String& text,
                   const int when_position_is_at = -1) const;
  const void locked_print(const String& text) const;
  const void separator() const;
};

#endif
