//
// Function.hpp for hh in /home/nuts/local/hell/charon/etape2
// 
// Made by Rivot Corentin (nuts)
// Login   <corentin.rivot@gmail.com>
// 
// Started on  Fri Dec 14 20:38:29 2012 Rivot Corentin
// Last update Sat Dec 15 00:19:41 2012 Rivot Corentin
//

#ifndef FUNCTION_HPP_
#define FUNCTION_HPP_


template < class T >

class Function;

template < class T, class U >

class Function < T(U) >
{
private:
  typedef T (*type)(U);
  type	_func;

public:
  Function() : _other(0) { }

  Function(T (*p)(U)) : _func(p), _other(0) { }

  ~Function() { if (_other) delete _other; }

  Function(Function< T >& f) { this = f; }

  Function	operator=(T (*t)(U)) {
    _func = t;
    return this;
  }

  class Herited
  {
  public:
    virtual T	operator()(const U& t) = 0;
    virtual ~Herited() { }
  };

  template < class I >

  class Stock : public Herited
  {
  public:
    Stock(const I& obj) : _obj(new I(obj)) { }
    ~Stock() { if (_obj) delete _obj; }

    // virtual ~Stock() { if (_obj) delete _obj; }

    virtual T operator()(const U& t)
    {
      if (_obj)
      	return _obj->operator()(t);
    }

  private:

    I *_obj;
  };

  template < class I >

  Function(const I& obj)
  {
    _other = new Stock< I >(obj);
  }

  T	operator()(U t){
    if (_other)
      return _other->operator()(t);
    return _func(t);
  }

  
private:
  Herited	*_other;

};

#endif
