//
// main.cpp for hh in /home/nuts/local/hell/hell/purgatory/etape1
// 
// Made by Rivot Corentin (nuts)
// Login   <corentin.rivot@gmail.com>
// 
// Started on  Sat Dec 15 01:10:08 2012 Rivot Corentin
// Last update Sat Dec 15 01:36:41 2012 Rivot Corentin
//

#include "Machine.hpp"

#include <iostream>
#include <string>


int	main(int ac, char **av)
{
  char	searchstr[] = "mechant";

  eState	cState = S0;

  std::string	token;

  if (ac < 2)
    goto error;


  for (int i = 0, j = 0, z = 0; gActionTable[j][z] != eAction::HR ; i++, j++, z++)
    {
      if (av[1][i] == searchstr[i])
	{
	  cState = gStateTable[cState][cState];
	}
      else
	{
	  std::cout << "STATE ERROR" << std::endl;
	  return 0;
	}
      token.append(1, av[1][i]);
      std::cout << token << std::endl;
    }
  std::cout << "HALT RESET" << std::endl;
  return 0;
 error:
  std::cout << "Usage: ./test_fsa [chaine a rechercher]" << std::endl;
  return 0;
}
