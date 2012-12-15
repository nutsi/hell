//
// main.cpp for hh in /home/nuts/local/hell/hell/purgatory/etape1
// 
// Made by Rivot Corentin (nuts)
// Login   <corentin.rivot@gmail.com>
// 
// Started on  Sat Dec 15 01:10:08 2012 Rivot Corentin
// Last update Sat Dec 15 11:12:54 2012 Rivot Corentin
//

#include "Machine.hpp"

#include <iostream>
#include <string>

int	main(int ac, char **av)
{
  char	searchstr[] = "mechant";

  eState	cState = S0;
  eState	oldcState = S0;

  std::string	token;

  if (ac < 2)
    goto error;

  char val;

  for (int i = 0, j = 0, z = 0; 1 ; i++, j++, z++)
    {
    begin:
      oldcState = cState;
      if (cState == STATE_ERROR)
	{
	  std::cout << "STATE_ERROR" << std::endl;
	  return 0;
	}
      if (av[1][i] == 'm')
	{
	  cState = gStateTable[cState][0];
	  val = 0;
	}
      else if (av[1][i] == 'e')
	{
	  val = 1;
	  cState = gStateTable[cState][1];
	}
      else if (av[1][i] == 'c')
	{
	  val = 2;
	  cState = gStateTable[cState][2];
	}
      else if (av[1][i] == 'h')
	{
	  val = 3;
	  cState = gStateTable[cState][3];
	}
      else if (av[1][i] == 'a')
	{
	  val = 4;
	  cState = gStateTable[cState][4];
	}
      else if (av[1][i] == 'n')
	{
	  val = 5;
	  cState = gStateTable[cState][5];
	}
      else if (av[1][i] == 't')
	{
	  val = 6;
	  cState = gStateTable[cState][6];
	}
      else if (cState == S7)
	{
	  val = 7;
	  cState = STATE_ERROR;
	}
      else
	{
	  std::cout << "STATE_ERROR" << std::endl;
	  i++;
	  cState = oldcState;
	  goto begin;
	  //	  return 0;
	}
      if (cState == STATE_ERROR && gActionTable[oldcState][val] == ACTION_ERROR)
	{
	  std::cout << "STATE_ERROR" << std::endl;
	  cState = oldcState;
	  i++;
	  goto begin;
	}
      if (gActionTable[oldcState][val] == HR)
      	goto haltreset;
      //      if (gActionTable[cState][cState]]
      if (gActionTable[oldcState][val] == MA)
      	{
      	  token.append(1, av[1][i]);
      	  std::cout << token << std::endl;
      	}
    }
 haltreset:
  std::cout << "HALT RESET" << std::endl;
  return 0;
 error:
  std::cout << "Usage: ./test_fsa [chaine a rechercher]" << std::endl;
  return 0;
}
