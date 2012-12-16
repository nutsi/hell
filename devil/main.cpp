//
// main.cpp for hh in /home/nuts/local/hell/hell/devil
// 
// Made by Rivot Corentin (nuts)
// Login   <corentin.rivot@gmail.com>
// 
// Started on  Sat Dec 15 18:13:11 2012 Rivot Corentin
// Last update Sun Dec 16 00:59:16 2012 Rivot Corentin
//

#include <iostream>

#include "Inspector.hpp"

struct test{
};

struct A {

  int a;
  std::ostream& operator<<(const A&);

};

struct lol{};

#include <ostream>

#include <fstream>

std::ostream& operator<<(std::ostream& out, const lol&)
{
  out << "Lol instance given" ;
  return out;
}

int main(int, char**)
{
    std::cout << " operator<< present (0) ? "
    	      << IsPrintable< std::ostream, test >::ISPRINTABLE
    	      << std::endl;


    std::cout << " operator<< present (1) ? "
    	      << IsPrintable< std::ostream, lol >::ISPRINTABLE
    	      << std::endl;    
    std::cout << " operator<< present (1) ? "
    	      << IsPrintable< std::ostream, A >::ISPRINTABLE
    	      << std::endl;
  return 0;
}


