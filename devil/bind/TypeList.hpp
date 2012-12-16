//
// TypeList.hpp for hh in /home/nuts/local/hell/hell/devil/bind
// 
// Made by Rivot Corentin (nuts)
// Login   <corentin.rivot@gmail.com>
// 
// Started on  Sun Dec 16 03:50:07 2012 Rivot Corentin

//

#ifndef TYPELIST_HPP_
#define TYPELIST_HPP_

//#include "Value.hpp"

#include "Storage.hpp"

struct TypeList0 : private Storage0
{
  typedef Storage0	BaseClass;
  
  TypeList0() : BaseClass()
  {
  }

  template < typename T >
  T&	operator[](Value< T >& v)
  {
    // useless
  }

  template < typename ReturnType, typename Caller, typename List >
  ReturnType	operator()(TypeTraits< ReturnType > q, Caller& caller, List& list)
  {
    return caller();
  }
};

template < typename P1 >

struct TypeList1 : private Storage1< P1 >
{
  typedef Storage1< P1 >	BaseClass;
  
  TypeList1(P1 p1) : BaseClass(p1)
  {
  }

  template < typename T >
  T&	operator[](Value< T >& v)
  {
    return v.get();
    // useless
  }

  template < typename ReturnType, typename Caller, typename List >
  ReturnType	operator()(TypeTraits< ReturnType >, Caller& caller, List& list)
  {
    return caller(list.operator[](BaseClass::_t1));
  }
};


template <typename P1, typename P2, typename P3>
struct TypeList3 : private Storage3<P1, P2, P3>
{
  typedef Storage3<P1, P2, P3> BaseClass;
  TypeList3(P1 p1, P2 p2, P3 p3) : BaseClass(p1, p2, p3)
  {
  }
  template <typename T>
  T& operator[](Value<T>& value)
  {
    return value.get();
    // ....
  }
  template <typename ReturnType, typename Caller, typename List>
  ReturnType operator()(TypeTraits<ReturnType>, Caller& caller, List& list)
  {
    return caller(list[BaseClass::_t1],
		  list[BaseClass::_t2],
		  list[BaseClass::_t3]
		  );
  }
};


template <typename P1, typename P2, typename P3, typename P4 >
struct TypeList4 : private Storage4<P1, P2, P3, P4>
{
  typedef Storage4<P1, P2, P3, P4> BaseClass;
  TypeList4(P1 p1, P2 p2, P3 p3, P4 p4) : BaseClass(p1, p2, p3, p4)
  {
  }
  template <typename T>
  T& operator[](Value<T>& value)
  {
    return value.get();
    // ....
  }
  template <typename ReturnType, typename Caller, typename List>
  ReturnType operator()(TypeTraits<ReturnType>, Caller& caller, List& list)
  {
    return caller(list[BaseClass::_t1],
		  list[BaseClass::_t2],
		  list[BaseClass::_t3],
		  list[BaseClass::_t4]
		  );
  }
};


#endif
