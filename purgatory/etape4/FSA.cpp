//
// FSA.cpp for hh in /home/nuts/local/hell/hell/purgatory/etape3
// 
// Made by Rivot Corentin (nuts)
// Login   <corentin.rivot@gmail.com>
// 
// Started on  Sat Dec 15 12:31:29 2012 Rivot Corentin
// Last update Sat Dec 15 16:34:36 2012 Rivot Corentin
//

#include "FSA.hpp"

#include <iostream>

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

std::list< State* >*	Fsa::closure(State* e)
{
  std::list< State* >	*list = new std::list< State* >;
  bool	no = false;

   list->push_back(e);
  std::map< std::string, State* >::iterator	it;

  for (it = _state.begin(); it != _state.end(); it++)
    {
      std::map< Edge*, std::string >::iterator	itEdge;
      std::map< Edge*, std::string>	ed = it->second->edgeMap();

      it++;
      no = false;
      for (itEdge = ed.begin(); itEdge != ed.end(); itEdge++)
      	{
	  std::cout << itEdge->first->getLambda() << std::endl;
      	  if (it->second->isJoinable(itEdge->first))
      	    {
	      no = true;
      	      list->push_back(it->second);
	      break;
      	    }
      	}
      if (no == false)
	return list;
      it--;
    }
  return list;
}

