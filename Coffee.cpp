/**************************************************************************************

This is the immplementation file for the Coffee Station room of the apartment complex. It is derived from the space class. The player can talk and investigate their surroundings. 

**************************************************************************************/
#include <iostream>
#include <string>
#include "Coffee.hpp"
#include "Player.hpp"

using std::cout;
using std::endl;


/**************************************************************************************

This is investigate function. It allows the user to search the rooms for clues that may help them solve the murder

**************************************************************************************/
void Coffee::investigate(Player *thePlayer){

  //If the player has not had their coffee yet...
  if(thePlayer->getHasCoffee() == false){
    cout << "Batista: There's the coffee pot!" << endl;
    cout << "Batista: Now that I got my cup of Joe" << endl;
    cout << "Batista: let's go talk to the building manager Diaz." << endl;

    thePlayer->setCoffee(true);
  }

  //If the player has had the coffee remind them to stop checking this room
  if(thePlayer->getHasCoffee() == true){
    cout << "Batista: I don't think there's anything murder related in here." << endl;

  }

  
}



/**************************************************************************************

This is talk function. It allows the user to engage in conversation with the people in 
the rooms. This is a good way to learn about the murder. 

**************************************************************************************/
void Coffee::talk(Player *thePlayer){

  //If the player has their coffee
  if(thePlayer->getHasCoffee() == true){
    cout << "Batista: I think I've had enough coffee for today." << endl;

  }

  //If the player does not have their coffee
  if(thePlayer->getHasCoffee() == false){
    cout << "Batista: Diaz, where's that damn coffee pot he was talking about?" << endl;
    cout << "Diaz : Maybe you should open your eyes and look around." << endl;
  }
    
}

/**************************************************************************************

This is dispatch function. It allows the user to engage in conversation with the 
dispatch team in reference to the rooms. This is a good way to get a hint 

**************************************************************************************/
void Coffee::dispatch(Player *thePlayer){

  cout << "Dispatch: Batista, I don't think you need help getting your own coffee" << endl;
    
}
