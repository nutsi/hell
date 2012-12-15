//
// Matcher.cpp for hh in /home/nuts/local/hell/hell/purgatory/etape3
// 
// Made by Rivot Corentin (nuts)
// Login   <corentin.rivot@gmail.com>
// 
// Started on  Sat Dec 15 12:38:51 2012 Rivot Corentin
// Last update Sat Dec 15 14:43:20 2012 Rivot Corentin
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
  for (int i = 0; s[i] && !st->endState(); i++)
    {
      Edge	e(s[i]);      
      std::string n = st->nextState(&e);
      if (n != "error")
	{
	  token.append(1, s[i]);
	  std::cout << "Ce qui a deja ete lu " << token << std::endl;
	  st = _fsa[n];
	}
      else
	std::cout << "STATE_ERROR (ignore juste le caractere et on continue le traitement" << std::endl;
    }
  if (st->endState())
    {
      std::cout << "Le pattern match avec la machine a etat" << std::endl;
      return true;
    }
  std::cout << "la chaine a ete consommer mais n'a pas repondu aux exigences de la machine a etat" << std::endl;
  return false;
}

bool	Matcher::find(const std::string& s, int &nmatch)
{
  std::cout << "on recherche le pattern " << s << std::endl;

  std::string	token;

  nmatch = 0;
  State*	st;
  st = _fsa.initState();
  for (int i = 0; s[i] /*&& !st->endState() */; i++)
    {
      Edge	e(s[i]);      
      std::string n = st->nextState(&e);
      if (n != "error")
	{
	  token.append(1, s[i]);
	  std::cout << "Ce qui a deja ete lu " << token << std::endl;
	  st = _fsa[n];
	}
      else
	std::cout << "STATE_ERROR (ignore juste le caractere et on continue le traitement" << std::endl;
      if (st->endState())
	{
	  st = _fsa.initState();
	  nmatch++;
	}
    }
  if (nmatch > 0)
    return true;
  return false;
}
