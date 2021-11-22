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

const void
Layout::setup() const
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

const void
Layout::clear() const
{
  screen.clearDisplay();
}

const void
Layout::cursor(const byte x, const byte y) const
{
  screen.setCursor(x, y);
}

const void
Layout::display() const
{
  screen.display();

  if (!rotary_encoder.is_pressed()) {
    return;
  }
  
  // todo 
}

// ------ //
// Getter //
// ------ //

const byte
Layout::get_width() const
{
  return screen.width();
}

const byte
Layout::get_height() const
{
  return screen.height();
}

const unsigned short int
Layout::get_half_from_str(const String& text) const
{
  const auto half_width = get_width() / 2;
  return (half_width - (text.length() * 2)) - 12;
}

// ------ //
// Setter //
// ------ //

const void
Layout::set_text_color(const uint16_t fg_color) const
{
  screen.setTextColor(fg_color);
}

const void
Layout::set_text_color(const uint16_t fg_color, const uint16_t bg_color) const
{
  screen.setTextColor(fg_color, bg_color);
}

const void
Layout::set_text_size(const uint8_t text_size) const
{
  screen.setTextSize(text_size);
}

const void
Layout::set_selected_circle(const byte x, const byte y) const
{
  screen.fillCircle(x + 1, y + 3, 1, WHITE);
}

const void
Layout::set_selected_rect(const byte l,
                          const byte t,
                          const byte r,
                          const byte b) const
{
  screen.drawLine(l, t, r, t, WHITE);
  screen.drawLine(l, b, r, b, WHITE);
  screen.drawLine(l, t, l, b, WHITE);
  screen.drawLine(r, t, r, b, WHITE);
}

// ------- //
// Méthode //
// ------- //

const void
Layout::print(const String& text, const int when_position_is_at) const
{
  if (rotary_encoder.get_position() == when_position_is_at) {
    set_text_color(BLACK, WHITE);
  }

  screen.print(text);
  set_text_color(WHITE);
}

const void
Layout::locked_print(const String& text) const
{
  print(text, -10);
}

const void
Layout::separator() const
{
  screen.drawLine(5, 11, get_width(), 11, WHITE);
  screen.drawLine(5, 11, 5, get_height(), WHITE);
}
