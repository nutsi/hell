//
// Functor.hpp for hh in /home/nuts/local/hell/charon/etape1
// 
// Made by Rivot Corentin (nuts)
// Login   <corentin.rivot@gmail.com>
// 
// Started on  Fri Dec 14 18:14:20 2012 Rivot Corentin

//

#ifndef FUNCTOR_HPP_
#define FUNCTOR_HPP_


template < class T >

struct FunctionSignature
{
  typedef T	type;
};

template < class R, class U >

struct FunctionSignature< R(U) >
{
  typedef R (*type)(U);
};

template < class R, class U, class T >

struct FunctionSignature< R(U, T) >
{
  typedef R (*type)(U, T);
};

template < class R, class U, class T, class O>

struct FunctionSignature< R(U, T, O) >
{
  typedef R (*type)(U, T, O);
};

template < class R, class U, class T, class O, class I>

struct FunctionSignature< R(U, T, O, I) >
{
  typedef R (*type)(U, T, O, I);
};




#endif
