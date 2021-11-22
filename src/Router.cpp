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
