//
// TypeTraits.hpp for hh in /home/nuts/local/hell/hell/devil/bind
// 
// Made by Rivot Corentin (nuts)
// Login   <corentin.rivot@gmail.com>
// 
// Started on  Sun Dec 16 03:23:52 2012 Rivot Corentin
// Last update Sun Dec 16 05:39:12 2012 Rivot Corentin
//

#ifndef TYPETRAITS_HPP_
#define TYPETRAITS_HPP_

//#include "TypeList.hpp"

template < typename T >

struct TypeTraits
{
  typedef T	type;
};

struct TypeList0;

struct Traits0
{
  typedef TypeList0	type;
};

template < typename P1 >

struct TypeList1;

template < typename P1 >

struct TypeTraits1
{
  typedef typename GetType < P1 >::Type Type_Parameter_1;
  typedef TypeList1 < Type_Parameter_1 >	Type;
};

#include "TypeList.hpp"

#endif
