#include "Router.hpp"
#include "Encoder/RotaryEncoder.hpp"
#include "View.hpp"

extern RotaryEncoder rotary_encoder;

// ------ //
// Getter //
// ------ //

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
