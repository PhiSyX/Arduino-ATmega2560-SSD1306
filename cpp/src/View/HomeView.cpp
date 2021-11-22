/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#include "View/HomeView.hpp"
#include "Encoder/RotaryEncoder.hpp"
#include "Layout.hpp"
#include "View.hpp"

extern Layout layout;
extern View view;
extern RotaryEncoder rotary_encoder;

// ---- //
// Page //
// ---- //

const void
HomeView::display_home() const
{
  layout.clear();

  view.title("Accueil");

  view.define_limit_lines(3);
  view.line("Choix un").on_press(Page::VIEW_ERROR);
  view.line("Choix deux").on_press(Page::VIEW_HOME_CHOICE_TWO);
  view.line("Choix trois").on_press(Page::VIEW_HOME_CHOICE_THREE);

  layout.display();
}
