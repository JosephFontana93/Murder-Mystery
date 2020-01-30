/**************************************************************************************

This is the header file for the hall of the apartment complex. It is 
derived from the space class.

**************************************************************************************/
#ifndef HALL_HPP
#define HALL_HPP

#include "Space.hpp"

class Hall : public Space{


  public:
    void investigate(Player *thePlayer);
    void talk(Player *thePlayer);
    void dispatch(Player *thePlayer);

};
#endif