//
// FSA.cpp for hh in /home/nuts/local/hell/hell/purgatory/etape3
// 
// Made by Rivot Corentin (nuts)
// Login   <corentin.rivot@gmail.com>
// 
// Started on  Sat Dec 15 12:31:29 2012 Rivot Corentin
// Last update Sat Dec 15 17:51:33 2012 Rivot Corentin
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
      if (it->second->name() == e->name())
	break;
    }

  for (; it != _state.end(); it++)
    {
      std::map< Edge*, std::string >::iterator	itEdge;
      std::map< Edge*, std::string>	ed = it->second->edgeMap();
      it++;
      no = false;
      for (itEdge = ed.begin(); itEdge != ed.end(); itEdge++)
      	{
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


void	Fsa::toDotString()
{
  std::list< State *>*	l = closure(_stateInit);
  std::list< State *>::iterator	it;

  std::cout << "digraph G" << std::endl;
  std::cout << "{" << std::endl;

  bool first = true;

  for (it = l->begin(); it != l->end(); it++)
    {
      if (!first)
      	{
      	  it--;
      	  std::cout << (*it++)->name() << " -> ";
	  std::cout << (*it)->name() << " [dir=forward]" << std::endl;
      	}
      first = false;
      std::cout<< (*it)->name();
      if ((*it)->endState())
	std::cout << "[color=red]";
      it++;
      if (it == l->end())
	{
	  break;
	}
      std::cout << " -> " << (*it)->name() << " [dir=forward]" << std::endl;
    }
  std::cout << std::endl;
  std::cout << "}" << std::endl;
}
