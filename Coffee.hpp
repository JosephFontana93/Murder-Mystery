/**************************************************************************************

This is the header file for the Coffee Station room of the apartment complex. It is 
derived from the space class.

**************************************************************************************/
#ifndef COFFEE_HPP
#define COFFEE_HPP

#include "Space.hpp"

class Coffee : public Space{


  public:
    void investigate(Player *thePlayer);
    void talk(Player *thePlayer);
    void dispatch(Player *thePlayer);

  

};
#endif