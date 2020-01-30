/**************************************************************************************

This is the header file for the pool of the apartment complex. It is 
derived from the space class.

**************************************************************************************/
#ifndef POOL_HPP
#define POOL_HPP

#include "Space.hpp"

class Pool : public Space{


  public:
    void investigate(Player *thePlayer);
    void talk(Player *thePlayer);
    void dispatch(Player *thePlayer);
  

};
#endif