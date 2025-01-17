/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#ifndef ROTARY_ENCODER_HPP
#define ROTARY_ENCODER_HPP

#include <Encoder.h>

class RotaryEncoder
{
private: // properties
  unsigned long btn_state_ms{ 0 };
  long encoder_last_position{ 0 };
  bool btn_last_state{ false };
  int total_count{ 0 };

public: // setup
  const void setup() const;

public: // getters
  bool is_pressed();
  int get_position();

public: // setters
  void set_position(const int position);
  void define_total(const int total);

public: // methods
  const long read_encoder() const;
  const bool read_btn_press() const;
};

#endif
