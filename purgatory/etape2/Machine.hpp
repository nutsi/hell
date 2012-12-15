//
// Machine.hpp for hh in /home/nuts/local/hell/hell/purgatory/etape1
// 
// Made by Rivot Corentin (nuts)
// Login   <corentin.rivot@gmail.com>
// 
// Started on  Sat Dec 15 00:43:45 2012 Rivot Corentin
// Last update Sat Dec 15 10:43:47 2012 Rivot Corentin
//

#ifndef MACHINE_HPP_
#define MACHINE_HPP_

enum eState
  {
    S0,
    S1,
    S2,
    S3,
    S4,
    S5,
    S6,
    S7,
    STATE_ERROR
  };

enum eAction
  {
    MA,
    HR,
    ACTION_ERROR
  };

// #define STATE_MAX	STATE_ERROR
// #define EDGE_MAX	STATE_ERROR

const int	STATE_MAX = STATE_ERROR;
const int	EDGE_MAX = 8;

extern eState	gStateTable[STATE_MAX][STATE_MAX];
extern eAction	gActionTable[EDGE_MAX][EDGE_MAX];

#endif
