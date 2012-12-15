//
// Edge.hpp for hh in /home/nuts/local/hell/hell/purgatory/etape3
// 
// Made by Rivot Corentin (nuts)
// Login   <corentin.rivot@gmail.com>
// 
// Started on  Sat Dec 15 11:21:58 2012 Rivot Corentin
// Last update Sat Dec 15 12:25:55 2012 Rivot Corentin
//

#ifndef EDGE_HPP_
#define EDGE_HPP_

class Edge
{
public:
  Edge(char c);
  Edge(const Edge&);

  // Edge	operator=(const Edge& e)
  // {
  //   _c = e._c;
  //   return this;
  // }

  bool	operator()(char c);

  bool	operator<(char c)
  {
    if (_c < c)
      return true;
    return false;
  }

  char	operator[](char) const
  {
    return _c;
  }

  char	c() const {
    return _c;
  }

private:
  char	_c;
};


#endif
