// ------ //
// Header //
// ------ //

#include "Encoder/RotaryEncoder.hpp"
#include "Layout.hpp"
#include "View.hpp"

extern Layout layout;
extern RotaryEncoder rotary_encoder;

// ------ //
// Getter //
// ------ //

short int View::cursor_y()
{
    const auto position = rotary_encoder.get_position();

    short int cy = (10 * current_line) + 4;

    if (position > limit_lines)
    {
        const auto difference = position - limit_lines;

        cy -= (10 * difference);

        if (cy < 14)
        {
            cy = -14;
        }
    }

    return cy;
}

// ------- //
// Méthode //
// ------- //

View &View::line(String text, bool is_selected)
{
    current_line++;

    const auto cy = cursor_y();
    const auto position = rotary_encoder.get_position();

    const size_t size_text = text.length();

    if (position == current_line)
    {
        layout.set_selected_circle(0, cy);
        layout.set_selected_rect(7, cy - 1, (size_text * 6 + 7) + 1, cy + 1 + 7);
    }

    if (is_selected)
    {
        layout.set_selected_rect(7, cy - 1, (size_text * 6 + 7) + 1, cy + 1 + 7);
    }

    layout.cursor(8, cy);
    layout.print(text, current_line);

    return *this;
}

View &View::title(String text, bool separator)
{
    const auto half_width = layout.get_width() / 2;
    const auto size_text_x2 = text.length() * 2;
    layout.cursor((half_width - size_text_x2) - 7, 1);
    layout.print(text);

    if (separator)
    {
        layout.separator();
    }

    return *this;
}

void View::reset_total()
{
    current_line = 0;
}

// ----- //
// Event //
// ----- //

void View::on_press(Page page)
{
}
