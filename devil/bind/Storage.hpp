//
// Storage.hpp for hh in /home/nuts/local/hell/hell/devil/bind
// 
// Made by Rivot Corentin (nuts)
// Login   <corentin.rivot@gmail.com>
// 
// Started on  Sun Dec 16 02:50:35 2012 Rivot Corentin

//

#ifndef STORAGE_HPP_
#define STORAGE_HPP_

#include "Value.hpp"

class Storage0
{
public:
  Storage0()
  {
  }
};

template < typename T1 >

class Storage1 : public Storage0
{
public:
  Storage1(T1& t1) : Storage0(), _t1(t1)
  {
  }

  //private:
  Value<T1>	_t1;  
};

template < typename T1, typename T2 >

class Storage2 : public Storage1< T1 >
{
public:
  Storage2(T1& t1, T2& t2) : Storage1< T1 >(t1), _t2(t2)
  {
  }

  //private:
  Value<T2>	_t2;
};


template < typename T1, typename T2, typename T3 >

class Storage3 : public Storage2< T1, T2 >
{
public:
  Storage3(T1& t1, T2& t2, T3& t3) : Storage2< T1, T2 >(t1, t2), _t3(t3)
  {
  }

  //private:
  Value<T3>	_t3;
};


template < typename T1, typename T2, typename T3, typename T4 >

class Storage4 : public Storage3< T1, T2, T3 >
{
public:
  Storage4(T1& t1, T2& t2, T3& t3, T4 &t4) : Storage3< T1, T2, T3 >(t1, t2, t3), _t4(t4)
  {
  }

  //private:
  T4	_t4;
};

template < typename T1, typename T2, typename T3, typename T4, typename T5 >

class Storage5 : public Storage4< T1, T2, T3, T4 >
{
public:
  Storage5(T1& t1, T2& t2, T3& t3, T4 &t4, T5 &t5) : Storage4< T1, T2, T3, T4 >(t1, t2, t3, t4), _t5(t5)
  {
  }

private:
  T5	_t5;
};

template <typename T1, typename T2, typename T3, typename T4, typename T5,
	  typename T6>
struct Storage6 : public Storage5<T1, T2, T3, T4, T5>
{
  Storage6(T1& t1, T2& t2, T3& t3, T4& t4, T5& t5, T6& t6) : Storage5<T1, T2,
								      T3, T4, T5>(t1, t2, t3, t4, t5), _t6(t6)
  {
  }
  T6 _t6;
};


#endif
