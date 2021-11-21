#ifndef ROTARY_ENCODER_HPP
#define ROTARY_ENCODER_HPP

#include <Encoder.h>

class RotaryEncoder
{
private: // properties
    unsigned long btn_state_ms{0};
    long encoder_last_position{0};
    bool btn_last_state{false};
    int total_count{0};

public: // setup
    void setup();

public: // getters
    bool is_pressed();
    int get_position();

public: // setters
    void set_position(const int position);
    void define_total(const int total);

private: // methods
    long read_encoder();
    bool read_btn_press();
};

#endif
