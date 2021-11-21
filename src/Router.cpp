#include "Router.hpp"
#include "View.hpp"

// ------ //
// Getter //
// ------ //

const Page
Router::current() const
{
  return current_page;
}
