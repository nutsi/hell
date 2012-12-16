//
// Caller.hpp for hh in /home/nuts/local/hell/hell/devil/bind
// 
// Made by Rivot Corentin (nuts)
// Login   <corentin.rivot@gmail.com>
// 
// Started on  Sun Dec 16 03:30:15 2012 Rivot Corentin
// Last update Sun Dec 16 05:50:54 2012 Rivot Corentin
//

#ifndef CALLER_HPP_
#define CALLER_HPP_

#include <iostream>

#include "TypeList.hpp"

template < typename ReturnType, typename Callable, typename List >

class Caller
{
public:
  Caller(Callable c, const List& l) : _callable(c), _list(l)
  {
  }

  Caller(const Caller< ReturnType, Callable, List >& te) : _callable(te._callable), _list(te._list)
  {
    
  }

  ReturnType	operator()()
  {
    TypeTraits< ReturnType >	t;
    return _list.operator()(t, _callable, _list);
  }

  ReturnType	operator()(int i)
  {
    std::cout << "WTF" << std::endl;
    TypeTraits< ReturnType >	t;
    TypeList1<int>	l(i);
    return _list.operator()(t, _callable, l);
  }

  

private:
  Callable	_callable;
  List		_list;

};

////////////// bind

template < typename ReturnType >

Caller < ReturnType, ReturnType(*)(), typename Traits0::type >
bind(ReturnType(*f)())
{
  TypeList0	l;
  return Caller < ReturnType, ReturnType(*)(), TypeList0 >(f, l);
}

template < typename ReturnType, typename X1, typename Param1 >

Caller < ReturnType, ReturnType(*)(X1), TypeList1< Param1 > >
bind(ReturnType(*f)(X1), Param1 p1)
{
  TypeList1< Param1 >	l(p1);
  return Caller < ReturnType, ReturnType(*)(X1), TypeList1< Param1 > >(f, l);
}

// template < typename ReturnType, typename X1, typename Param1 >

// Caller < ReturnType, ReturnType(*)(X1), typename TypeTraits1< Param1 >::Type >
// bind(ReturnType(*f)(X1), Param1 p1)
// {
//   TypeList1< Param1 >	l(p1);
//   return Caller < ReturnType, ReturnType(*)(X1), TypeList1< Param1 > >(f, l);
// }



#endif
