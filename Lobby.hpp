/**************************************************************************************

This is the header file for the lobby of the apartment complex. It is 
derived from the space class.

**************************************************************************************/
#ifndef LOBBY_HPP
#define LOBBY_HPP

#include "Space.hpp"

class Lobby : public Space{


  public:
    void investigate(Player *thePlayer);
    void talk(Player *thePlayer);
    void dispatch(Player *thePlayer);
  

};
#endif