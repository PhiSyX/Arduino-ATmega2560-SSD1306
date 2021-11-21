#include "Layout.hpp"
#include "Encoder/RotaryEncoder.hpp"

// Configuration Écran
#define SCREEN_BEGIN_KEY SSD1306_SWITCHCAPVCC
#define SCREEN_BEGIN_VALUE 0x3C

extern Adafruit_SSD1306 screen;
extern RotaryEncoder rotary_encoder;

// ----- //
// Setup //
// ----- //

void Layout::setup()
{
#if (SCREEN_BEGIN_VALUE)
    screen.begin(SCREEN_BEGIN_KEY, SCREEN_BEGIN_VALUE);
#else
    screen.begin(SCREEN_BEGIN_KEY);
#endif

    set_text_color(WHITE);
    set_text_size(1);

    screen.setTextWrap(false);
}

// ------- //
// Méthode //
// ------- //

void Layout::clear()
{
    screen.clearDisplay();
}

void Layout::cursor(const byte x, const byte y)
{
    screen.setCursor(x, y);
}

void Layout::display()
{
    screen.display();
}

// ------ //
// Getter //
// ------ //

const byte Layout::get_width()
{
    return screen.width();
}

const byte Layout::get_height()
{
    return screen.height();
}

// ------ //
// Setter //
// ------ //

void Layout::set_text_color(const uint16_t fg_color)
{
    screen.setTextColor(fg_color);
}

void Layout::set_text_color(const uint16_t fg_color, const uint16_t bg_color)
{
    screen.setTextColor(fg_color, bg_color);
}

void Layout::set_text_size(const uint8_t text_size)
{
    screen.setTextSize(text_size);
}

void Layout::set_selected_circle(const byte x, const byte y)
{
    screen.fillCircle(x + 1, y + 3, 1, WHITE);
}

void Layout::set_selected_rect(const byte l, const byte t, const byte r, const byte b)
{
    screen.drawLine(l, t, r, t, WHITE);
    screen.drawLine(l, b, r, b, WHITE);
    screen.drawLine(l, t, l, b, WHITE);
    screen.drawLine(r, t, r, b, WHITE);
}

// ------- //
// Méthode //
// ------- //

void Layout::print(String text, const int when_position_is_at)
{
    if (rotary_encoder.get_position() == when_position_is_at)
    {
        set_text_color(BLACK, WHITE);
    }

    screen.print(text);
    set_text_color(WHITE);
}

void Layout::separator()
{
    screen.drawLine(5, 11, get_width(), 11, WHITE);
    screen.drawLine(5, 11, 5, get_height(), WHITE);
}
