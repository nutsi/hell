//
// main.cpp for hh in /home/nuts/local/hell/hell/purgatory/etape3
// 
// Made by Rivot Corentin (nuts)
// Login   <corentin.rivot@gmail.com>
// 
// Started on  Sat Dec 15 11:29:15 2012 Rivot Corentin
//

#include "Edge.hpp"
#include "State.hpp"

#include <vector>
#include <iostream>

#include "FSA.hpp"

#include "Matcher.hpp"

int	main(int ac, char **av)
{
  if (ac < 2)
    {
      std::cout << "Usage : ./test_dynamic_fsa [Chaine a rechercher]" << std::endl;
      return 0;
    }

  Edge	e0('m');
  Edge	e1('e');
  Edge	e2('c');
  Edge	e3('h', 1);
  Edge	e4('a', 1);
  Edge	e5('n', 1);
  Edge	e6('t', 1);

  Fsa	fsa;

  State*	s0 = State::createUniqueState();
  State*	s1 = State::createUniqueState();
  State*	s2 = State::createUniqueState();
  State*	s3 = State::createUniqueState();
  State*	s4 = State::createUniqueState();
  State*	s5 = State::createUniqueState();
  State*	s6 = State::createUniqueState();
  State*	s7 = State::createUniqueState();
  State*	sf = State::createUniqueState();

  sf->endState(true);
  s7->endState(true);


  s0->addLink(&e0, "S1");
  s1->addLink(&e1, "S2");
  s2->addLink(&e2, "S3");
  //  s2->addLink(&e1, "S2");
  s3->addLink(&e3, "S4");
  s4->addLink(&e4, "S5");
  s5->addLink(&e5, "S6");
  s6->addLink(&e6, "S7");
  // s6->addLink(&e5, "S6");
  
  std::cout << s0->name() << std::endl;
  std::cout << s1->name() << std::endl;
  std::cout << s2->name() << std::endl;
  std::cout << s3->name() << std::endl;
  std::cout << s4->name() << std::endl;
  std::cout << s5->name() << std::endl;
  std::cout << s6->name() << std::endl;
  std::cout << s7->name() << std::endl;
  std::cout << sf->name() << std::endl;
  

  fsa.addState(s0);
  fsa.addState(s1);
  fsa.addState(s2);
  fsa.addState(s3);
  fsa.addState(s4);
  fsa.addState(s5);
  fsa.addState(s6);
  fsa.addState(s7);
  fsa.addState(sf);

  fsa.initState("S0");


  Matcher	match(fsa);

  match.find(av[1]);

  std::cout << "Liste des etats joignable :" << std::endl;

  std::list< State * >	*l = fsa.closure(s0);

  std::list< State * >::iterator it;
  for (it = l->begin(); it != l->end(); it++)
    {
      std::cout << (*it)->name() << std::endl;
    }

  // std::string	st(av[1]);
  // st += av[1];

  // int	l;
  // match.find(st, l);

  // std::cout << "La seconde instance de find a matcher " << l << " fois" << std::endl;

  return 0;
}
