/**************************************************************************************

This is the header file for the victim's room of the apartment complex. It is 
derived from the space class.

**************************************************************************************/
#ifndef VICTIM_HPP
#define VICTIM_HPP

#include "Space.hpp"

class Victim : public Space{


  public:
    void investigate(Player *thePlayer);
    void talk(Player *thePlayer);
    void dispatch(Player *thePlayer);

};
#endif