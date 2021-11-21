#include "Encoder/RotaryEncoder.hpp"

#define ROTARY_ENCODER_PIN_L 3
#define ROTARY_ENCODER_PIN_R 2
#define ROTARY_ENCODER_PIN_P 4

Encoder encoder(ROTARY_ENCODER_PIN_L, ROTARY_ENCODER_PIN_R);

// ----- //
// Setup //
// ----- //

void RotaryEncoder::setup()
{
    pinMode(ROTARY_ENCODER_PIN_P, INPUT_PULLUP);
}

// ------ //
// Getter //
// ------ //

int RotaryEncoder::get_position()
{
    auto position{read_encoder()};

    if (position < 0)
    {
        set_position(total_count);
        position = total_count;
    }

    if (position > total_count)
    {
        set_position(0);
        position = 0;
    }

    return position;
}

// ------ //
// Setter //
// ------ //

void RotaryEncoder::set_position(int pos)
{
    encoder_last_position = pos;
    encoder.write(encoder_last_position * 4);
}

void RotaryEncoder::define_total(const int total)
{
    total_count = total;
}

// ------- //
// Méthode //
// ------- //

bool RotaryEncoder::read_btn_press()
{
    return !digitalRead(ROTARY_ENCODER_PIN_P);
}

long RotaryEncoder::read_encoder()
{
    return encoder.read() / 4;
}

// ----- //
// Event //
// ----- //

bool RotaryEncoder::on_pressed()
{
    const unsigned long now{millis()};

    bool ret{false};

    if (read_btn_press() != btn_last_state && (now - btn_state_ms) > 500)
    {
        ret = true;
        btn_state_ms = now;
    }

    btn_last_state = read_btn_press();

    return ret;
}
