//
// Matcher.cpp for hh in /home/nuts/local/hell/hell/purgatory/etape3
// 
// Made by Rivot Corentin (nuts)
// Login   <corentin.rivot@gmail.com>
// 
// Started on  Sat Dec 15 12:38:51 2012 Rivot Corentin
// Last update Sat Dec 15 14:16:49 2012 Rivot Corentin
//

#include "Matcher.hpp"

#include <iostream>

Matcher::Matcher(Fsa &f) : _fsa(f)
{
}


bool	Matcher::find(const std::string& s)
{
  std::cout << "on recherche le pattern " << s << std::endl;

  std::string	token;

  State*	st;
  st = _fsa.initState();
  for (int i = 0; s[i]; i++)
    {
      Edge	e(s[i]);      
      std::string n = st->nextState(&e);
      if (n != "error")
	{
	  token.append(1, s[i]);
	  std::cout << token << std::endl;
	  st = _fsa[n];
	}
      else
	std::cout << "STATE_ERROR" << std::endl;
    }
}
