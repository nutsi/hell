//
// Edge.cpp for hh in /home/nuts/local/hell/hell/purgatory/etape3
// 
// Made by Rivot Corentin (nuts)
// Login   <corentin.rivot@gmail.com>
// 
// Started on  Sat Dec 15 11:23:47 2012 Rivot Corentin

//

#include "Edge.hpp"

Edge::Edge(char c) : _c(c)
{
}

Edge::Edge(const Edge& e)
{
  this->_c - e._c;
}

bool	Edge::operator()(char c)
{
  if (this->_c == c)
    return true;
  return false;
}

