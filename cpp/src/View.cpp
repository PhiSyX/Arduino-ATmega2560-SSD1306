/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

// ------ //
// Header //
// ------ //

#include "View.hpp"
#include "Encoder/RotaryEncoder.hpp"
#include "Layout.hpp"
#include "Router.hpp"

extern RotaryEncoder rotary_encoder;
extern Layout layout;
extern Router router;

// ------ //
// Getter //
// ------ //

const short int
View::cursor_y() const
{
  const auto position = rotary_encoder.get_position();

  short int cy = (10 * current_line) + 4;

  if (position > limit_lines) {
    const auto difference = position - limit_lines;

    cy -= (10 * difference);

    if (cy < 14) {
      cy = -14;
    }
  }

  return cy;
}

// ------ //
// Setter //
// ------ //

void
View::define_limit_lines(const byte limit)
{
  limit_lines = limit;
  rotary_encoder.define_total(limit_lines);
}

// ------- //
// Méthode //
// ------- //

View&
View::line(const String& text, bool is_selected)
{
  current_line++;

  Line line{ text };

  const auto cy = cursor_y();
  const auto position = rotary_encoder.get_position();

  const size_t size_text = text.length();

  if (position == current_line) {
    layout.set_selected_circle(0, cy);
    layout.set_selected_rect(7, cy - 1, (size_text * 6 + 7) + 1, cy + 1 + 7);
  }

  if (is_selected) {
    layout.set_selected_rect(7, cy - 1, (size_text * 6 + 7) + 1, cy + 1 + 7);
  }

  layout.cursor(8, cy);
  layout.print(text, current_line);

  return *this;
}

const View&
View::title(const String& text, bool separator) const
{
  const auto half_width = layout.get_width() / 2;
  const auto size_text_x2 = text.length() * 2;
  layout.cursor((half_width - size_text_x2) - 7, 1);
  layout.print(text);

  if (separator) {
    layout.separator();
  }

  return *this;
}

void
View::reset_total()
{
  current_line = 0;
}

// ----- //
// Event //
// ----- //

void
View::on_press(Page page)
{
  if (total_press == 0 && !router.has_back()) {
    total_press++;
  }

  if (rotary_encoder.get_position() == total_press) {
    router.go(page);
  }

  total_press++;
}
