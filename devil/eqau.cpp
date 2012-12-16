#include <iostream>

#include <fstream>

struct A
{
  int  a;

  std::ostream& operator<<(const A&);
};

// std::ostream& operator<<(std::ostream&, const A&);

template < typename T >

// detect a method member d'une structure classe etc...

struct opEqualExists
{
  struct yes{ char a[1]; };
  struct no { char a[2]; };

  template < int i >
  struct toto
  {
    typedef void type;
  };

  template <typename C> static yes test( typeof(&C::operator<<) );
  template <typename C> static no test(...);

  enum { value = (sizeof(test<T>(0)) == sizeof(yes)) };
};

int main()
{
  std::cout<<(int)opEqualExists<A>::value<<std::endl;
  //  std::cout<<CHECK::opEqualExists<A>::value<<std::endl;
}
