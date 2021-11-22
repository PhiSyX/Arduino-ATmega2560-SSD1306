#ifndef ROUTER_HPP
#define ROUTER_HPP

#include "View.hpp"

class Router
{
public: // properties
  Page back_page{ Page::VIEW_UNKNOWN };
  Page current_page{ Page::VIEW_HOME };
  Page next_page{ Page::VIEW_UNKNOWN };

public: // getters
  const Page current() const;
  const bool has_back() const;
  const bool has_next() const;

public: // methods
  Router& go(const Page page, const int encoder = 1);
};

#endif
