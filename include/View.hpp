#ifndef VIEW_HPP
#define VIEW_HPP

#include <Arduino.h>

#include "View/HomeView.hpp"

enum Page {
  VIEW_ERROR = 0,

  VIEW_HOME = 1,
  VIEW_HOME_CHOICE_ONE = 11,
  VIEW_HOME_CHOICE_TWO = 12,
  VIEW_HOME_CHOICE_THREE = 13,
};

class View : public HomeView
{
public: // properties
  byte current_line{ 0 };
  byte limit_lines{ 5 };

public: // getters
  const short int cursor_y() const;

public: // methods
  void reset_total();

  View& line(String text, bool is_selected = false);
  const View& title(String text, bool separator = true) const;

public: // events
  void on_press(Page page);
};

#endif
