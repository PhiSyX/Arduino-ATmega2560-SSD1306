#ifndef VIEW_HPP
#define VIEW_HPP

#include <Arduino.h>

#include "View/ErrorView.hpp"
#include "View/HomeView.hpp"

enum Page
{
  VIEW_UNKNOWN = -1,

  VIEW_ERROR = 0,

  VIEW_HOME = 1,
  VIEW_HOME_CHOICE_ONE = 11,
  VIEW_HOME_CHOICE_TWO = 12,
  VIEW_HOME_CHOICE_THREE = 13,
};

struct Line
{
  const String text;
  Page on_press;
};

class View
  : public ErrorView
  , public HomeView
{
public: // properties
  byte current_line{ 0 };
  byte limit_lines{ 5 };
  int total_press{ 0 };

public: // getters
  const short int cursor_y() const;

public: // setters
  void define_limit_lines(const byte limit);

public: // methods
  void reset_total();

  View& line(const String& text, bool is_selected = false);
  const View& title(const String& text, bool separator = true) const;

public: // events
  void on_press(const Page page);
};

#endif
