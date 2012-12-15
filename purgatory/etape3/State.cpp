//
// State.cpp for hh in /home/nuts/local/hell/hell/purgatory/etape3
// 
// Made by Rivot Corentin (nuts)
// Login   <corentin.rivot@gmail.com>
// 
// Started on  Sat Dec 15 11:37:59 2012 Rivot Corentin
// Last update Sat Dec 15 12:58:31 2012 Rivot Corentin
//

#include "State.hpp"

std::list< std::string >	State::_listState;

int	State::nombre = 0;

State::State() : _endState(false)
{
}

State::State(const std::string& s) : _name(s), _endState(false)
{
}

void	State::name(const std::string& n)
{
  this->_name = n;
}

const std::string&	State::name() const
{
  return this->_name;
}

void	State::endState(bool b)
{
  this->_endState = b;
}

#include <stdio.h>
#include <sstream>

State*	State::createUniqueState(const std::string& st)
{
  std::list< std::string >::iterator	it;

  // s.clear();
  std::string s;
  s.append(1, 'S');
  std::ostringstream os;
  os << nombre;
  s += os.str();
  nombre++;
  for (it = _listState.begin(); it != _listState.end(); it++)
    {
      if ((*it) == s)
	{
	  printf("WHAT THE FUCK\n");
	  return 0;
	}
    }
  _listState.push_front(s);

  State* t = new State(s);
  return t;
}

