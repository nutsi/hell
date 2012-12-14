#include <iostream>


#include "FunctionSignature.hpp"

#include <string>


int	func(const std::string& toto)
{
  std::cout << toto << std::endl;
  return 0;
}

int	func2(const std::string& toto, int i)
{
  std::cout << toto << "et un int : " << i << std::endl;
  return 0;
}

int	func3(const std::string& toto, int i, const std::string& str)
{
  std::cout << toto << "et un int : " << i << str << std::endl;
  return 0;
}

int	func4(const std::string& toto, int i, const std::string& str, const std::string& str2)
{
  std::cout << toto << "et un int : " << i << str << str2 << std::endl;
  return 0;
}

int	main(int ac, char **av)
{
  FunctionSignature< int >::type t = 1;
  std::cout << t << std::endl;
  FunctionSignature< int (const std::string&) >::type toto = &func;
  FunctionSignature< int (const std::string&, int) >::type toto2 = &func2;
  FunctionSignature< int (const std::string&, int, const std::string&) >::type toto3 = &func3;
  FunctionSignature< int (const std::string&, int, const std::string&, const std::string&) >::type toto4 = &func4;

  toto("Je suis la parametre 1");
  toto2("Je prend cette chaine en parametre ", 42);
  toto3("Je prend cette chaine en parametre ", 42, " et un troisieme parametre");
  toto4("Je prend cette chaine en parametre ", 42, " et un troisieme parametre", " et enfin un 4eme parametre");
  return 0;
}
