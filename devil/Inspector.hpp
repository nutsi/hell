//
// Inspector.hpp for hh in /home/nuts/local/hell/hell/devil
// 
// Made by Rivot Corentin (nuts)
// Login   <corentin.rivot@gmail.com>
// 
// Started on  Sat Dec 15 18:18:17 2012 Rivot Corentin

//

#ifndef INSPECTOR_HPP_
#define INSPECTOR_HPP_

#include <iostream>

#include <typeinfo>

#include <ostream>

template < class U, class Object >

class	IsPrintable
{
public:

  typedef struct {int tab;} Yes;
  typedef struct {int tab[2];} No;


  template < size_t i >
  struct force_int {
    typedef void*	type;
  };

  template < typename C >
  static Yes isPrintable( typeof(&C::operator<<) );

  template < typename C >
  static Yes isPrintable(typename force_int< sizeof((U&)((*(U*)(0))) << (C&)((*(C*)(0)))) >::type);

   template < typename C >
  static No isPrintable(...);


  static const bool ISPRINTABLE = (sizeof(isPrintable< Object >((Object*)0)) == sizeof(Yes));

private:

};


template < bool C, typename T = void* >

struct enable_if
{
  typedef T	type;
};

template < typename T >

struct enable_if < 0, T >
{
  //   typedef T	type;
};

template < typename T >

struct Printer
{
  template < typename U > 

  static typename enable_if< IsPrintable< std::ostream, U >::ISPRINTABLE >::type print(T& f, const U& u)
  {
    f << u << std::endl;
  }

  template < typename U > 

  static typename enable_if< !IsPrintable< std::ostream, U >::ISPRINTABLE >::type print(T& f, const U& u)
  {
    f << typeid(u).name() << std::endl;	
  }
};


template < typename T >

void	inspect(const T& t)
{
  
  //	toto;

  Printer< std::ostream >::print(std::cout, t);

}


#endif
