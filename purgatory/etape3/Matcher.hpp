//
// Matcher.hpp for hh in /home/nuts/local/hell/hell/purgatory/etape3
// 
// Made by Rivot Corentin (nuts)
// Login   <corentin.rivot@gmail.com>
// 
// Started on  Sat Dec 15 12:37:55 2012 Rivot Corentin
// Last update Sat Dec 15 12:41:23 2012 Rivot Corentin
//


#ifndef MATCHER_HPP_
#define MATCHER_HPP_

#include "FSA.hpp"

class Matcher
{
public:
  Matcher(Fsa & f);

  bool	find(const std::string&);
  bool	find(const std::string&, int&);

private:
  Fsa	&_fsa;

};

#endif
