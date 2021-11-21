#ifndef LAYOUT_HPP
#define LAYOUT_HPP

#include <Adafruit_SSD1306.h>

class Layout
{
public: // setup
    void setup();

public: // getters
    const byte get_width();
    const byte get_height();

public: // setters
    void set_text_color(const uint16_t fg_color);
    void set_text_color(const uint16_t fg_color, const uint16_t bg_color);
    void set_text_size(const uint8_t text_size);
    void set_selected_circle(const byte x, const byte y);
    void set_selected_rect(const byte l, const byte t, const byte r, const byte b);

public: // methods
    void clear();
    void cursor(const byte x, const byte y);
    void display();
    void print(String text, const int when_position_is_at = -1);
    void separator();
};

#endif
