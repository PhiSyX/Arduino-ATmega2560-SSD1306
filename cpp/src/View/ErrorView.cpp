/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#include <Arduino.h>

#include "Encoder/RotaryEncoder.hpp"
#include "Layout.hpp"
#include "Router.hpp"
#include "View/ErrorView.hpp"

extern Layout layout;
extern RotaryEncoder rotary_encoder;
extern Router router;

const void
ErrorView::display_error() const
{
  const byte half_height = layout.get_height() / 2;
  layout.clear();

  rotary_encoder.define_total(1);

  layout.cursor(2, half_height - 10);
  layout.locked_print("ERREUR:");

  layout.cursor(2, half_height);
  layout.locked_print("Raison de l'erreur");

  const String ok = "Je comprends";
  layout.cursor(layout.get_half_from_str(ok), half_height + 15);
  layout.print(ok, rotary_encoder.read_encoder());

  layout.display();

  if (rotary_encoder.is_pressed()) {
    router.go(Page::VIEW_HOME);
  }
}
