//
// FSA.hpp for hh in /home/nuts/local/hell/hell/purgatory/etape3
// 
// Made by Rivot Corentin (nuts)
// Login   <corentin.rivot@gmail.com>
// 
// Started on  Sat Dec 15 12:28:29 2012 Rivot Corentin
// Last update Sat Dec 15 14:11:56 2012 Rivot Corentin
//

#ifndef FSA_HPP_
#define FSA_HPP_

#include "State.hpp"

#include <map>
#include <string>

class Fsa
{
public:
  Fsa();
  
  void	addState(State* s);
  
  void	initState(const std::string&);

  State*	initState() const {
    return _stateInit;
  }

  State*	operator[](const std::string&);

private:
  std::map< std::string, State* >	_state;
  State*	_stateInit;
};

#endif
