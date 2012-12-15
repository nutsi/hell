//
// FSA.cpp for hh in /home/nuts/local/hell/hell/purgatory/etape3
// 
// Made by Rivot Corentin (nuts)
// Login   <corentin.rivot@gmail.com>
// 
// Started on  Sat Dec 15 12:31:29 2012 Rivot Corentin
// Last update Sat Dec 15 12:37:29 2012 Rivot Corentin
//

#include "FSA.hpp"

Fsa::Fsa()
{
}

void	Fsa::addState(State* s)
{
  _state[s->name()] = s;
}

void	Fsa::initState(const std::string& n)
{
  _stateInit = _state[n];
}

State*	Fsa::operator[](const std::string& s)
{
  return _state[s];
}
