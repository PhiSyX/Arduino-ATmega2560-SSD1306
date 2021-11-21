#ifndef VIEW_HPP
#define VIEW_HPP

#include <Arduino.h>

#include "View/HomeView.hpp"

enum Page
{
    VIEW_ERROR = 0,

    VIEW_HOME = 1,
};

class View : public HomeView
{
private: // properties
    byte limit{5};
    byte total_lines{0};

public: // getters
    short int cursor_y();

public: // methods
    void line(String text, bool is_selected = false);
    void reset_total();
    void title(String text, bool separator = true);
};

#endif
