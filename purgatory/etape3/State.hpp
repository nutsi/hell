//
// State.hpp for hh in /home/nuts/local/hell/hell/purgatory/etape3
// 
// Made by Rivot Corentin (nuts)
// Login   <corentin.rivot@gmail.com>
// 
// Started on  Sat Dec 15 11:30:30 2012 Rivot Corentin
// Last update Sat Dec 15 14:27:16 2012 Rivot Corentin
//

#ifndef STATE_HPP_
#define STATE_HPP_


#include <string>

#include <list>

#include <map>

#include "Edge.hpp"

class State
{
public:
  State();
  State(const std::string&);
  
  void	name(const std::string& n);
  const std::string&	name() const;

  void	endState(bool);
  bool	endState() const {
    return _endState;
  }


  std::string	nextState(Edge* e)
  {
    std::map< Edge*, std::string >::iterator	it;
    // std::map< Edge*, std::string >::iterator	it2;

    for (it = _edge.begin(); it != _edge.end(); it++)
      {
	if (it->first->c() == e->c())
	  return it->second;
      }
    return "error";
  }

  static State*	createUniqueState(const std::string&s = "");

  // void	nextState();

  void	addLink(Edge* e, const std::string& s)
  {
    // _edge[s] = e;
    _edge[e] = s;
  }

private:
  std::string	_name;
  bool		_endState;
  static std::list< std::string >	_listState;
  static int	nombre;  
  std::map< Edge*, std::string >	_edge;
};


#endif
