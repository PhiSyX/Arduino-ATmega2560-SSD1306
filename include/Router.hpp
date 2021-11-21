#ifndef ROUTER_HPP
#define ROUTER_HPP

#include "View.hpp"

class Router
{
public: // properties
    Page current_page{Page::VIEW_HOME};

public: // getters
    Page current();
};

#endif
