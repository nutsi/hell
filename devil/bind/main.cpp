//
// main.cpp for hh in /home/nuts/local/hell/hell/devil/bind
// 
// Made by Rivot Corentin (nuts)
// Login   <corentin.rivot@gmail.com>
// 
// Started on  Sun Dec 16 02:57:28 2012 Rivot Corentin
// Last update Sun Dec 16 06:21:47 2012 Rivot Corentin
//

#include "Storage.hpp"

#include "Value.hpp"

#include "TypeTraits.hpp"

#include "Caller.hpp"

//#include "TypeList.hpp"

#include <iostream>

#include <string>

int	func()
{
  std::cout << "Je susi uen fonction sans parametre" << std::endl;

  return 0;
}

int	func1(std::string s)
{
  std::cout << s << std::endl;

  return 0;
}

struct Toto
{
  Toto() { }

  int	operator()() {
    std::cout << "objet callable" << std::endl;
    return 0;
  }
};


int	main()
{
  Toto t;

  Caller<int, int(*)(), Traits0::type >	toto = bind(&func);
  //  Caller<int, Toto, Traits0::type > obj = bind(t);


  Caller< int, int(*)(std::string), TypeList1< std::string > >	toto2 = bind(&func1, std::string("Coucou je suis en string"));

  toto();
  toto2(9);
}
