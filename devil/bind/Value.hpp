//
// Value.hpp for hh in /home/nuts/local/hell/hell/devil/bind
// 
// Made by Rivot Corentin (nuts)
// Login   <corentin.rivot@gmail.com>
// 
// Started on  Sun Dec 16 03:08:51 2012 Rivot Corentin
// Last update Sun Dec 16 05:23:41 2012 Rivot Corentin
//

#ifndef VALUE_HPP_
#define VALUE_HPP_

template < typename T >

class Value
{
public:
  Value(const T& t) : _t(t)
  {
  }
  
  const T&	get() const {
    return _t;
  }

  T&	get()
  {
    return _t;
  }

  //private:
  T	_t;  
};

template < typename T >

class GetType
{
public:
  GetType(const T& t) : _t(t)
  {
  }

  //private:
  T	_t;
  typedef Value< T >	Type;
};

#endif
