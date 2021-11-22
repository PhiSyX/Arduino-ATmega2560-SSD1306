/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

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
