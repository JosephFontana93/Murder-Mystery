#ifndef FIRE_HPP
#define FIRE_HPP

#include "Space.hpp"

class Fire : public Space{


  public:
    void investigate(Player *thePlayer);
    void talk(Player *thePlayer);
    void dispatch(Player *thePlayer);


};
#endif