/**************************************************************************************

This is the header file for the suspect's room of the apartment complex. It is 
derived from the space class.

**************************************************************************************/
#ifndef SUSPECT_HPP
#define SUSPECT_HPP

#include "Space.hpp"

class Suspect : public Space{


  public:
    void investigate(Player *thePlayer);
    void talk(Player *thePlayer);
    void dispatch(Player *thePlayer);
  

};
#endif