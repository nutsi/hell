//
// main.cpp for hh in /home/nuts/local/hell/hell/purgatory/etape1
// 
// Made by Rivot Corentin (nuts)
// Login   <corentin.rivot@gmail.com>
// 
// Started on  Sat Dec 15 01:10:08 2012 Rivot Corentin
// Last update Sat Dec 15 01:53:45 2012 Rivot Corentin
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
      if (cState == STATE_ERROR)
	{
	  std::cout << "STATE_ERROR" << std::endl;
	  return 0;
	}
      if (av[1][i] == 'm' && cState == S0)
	cState = S1;
      else if (av[1][i] == 'e' && cState == S1)
	cState = S2;
      else if (av[1][i] == 'c' && cState == S2)
	cState = S3;
      else if (av[1][i] == 'h' && cState == S3)
	cState = S4;
      else if (av[1][i] == 'a' && cState == S4)
	cState = S5;
      else if (av[1][i] == 'n' && cState == S5)
	cState = S6;
      else if (av[1][i] == 't' && cState == S6)
	cState = S7;
      else if (cState == S7)
	cState = STATE_ERROR;
      else
	{
	  std::cout << "STATE_ERROR" << std::endl;
	  return 0;
	}
      
      //      if (gActionTable[cState][cState]]
      token.append(1, av[1][i]);
      std::cout << token << std::endl;
    }
  std::cout << "HALT RESET" << std::endl;
  return 0;
 error:
  std::cout << "Usage: ./test_fsa [chaine a rechercher]" << std::endl;
  return 0;
}
