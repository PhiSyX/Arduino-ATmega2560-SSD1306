/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

// ------ //
// Header //
// ------ //

#include "Router.hpp"
#include "Encoder/RotaryEncoder.hpp"
#include "View.hpp"

extern RotaryEncoder rotary_encoder;

// ------ //
// Getter //
// ------ //

const bool
Router::has_back() const
{
  return back_page > Page::VIEW_ERROR;
}

const bool
Router::has_next() const
{
  return next_page > Page::VIEW_ERROR;
}

const Page
Router::current() const
{
  return current_page;
}

// ------- //
// Méthode //
// ------- //

Router&
Router::go(const Page page, const int encoder)
{
  current_page = page;
  rotary_encoder.set_position(encoder);
  return *this;
}
