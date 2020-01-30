/**************************************************************************************

This is the immplementation file for the hall of the apartment complex. It is derived 
from the space class. The player can talk and investigate their surroundings. 

**************************************************************************************/
#include <iostream>
#include <string>
#include "Hall.hpp"
#include "Player.hpp"

using std::cout;
using std::endl;


/**************************************************************************************

This is investigate function. It allows the user to search the rooms for clues that may help them solve the murder

**************************************************************************************/
void Hall::investigate(Player *thePlayer){
  
  cout << "Batista: I don't see anything, do you Diaz?" << endl;
  cout << "Diaz   : Looks like an empty hall to me." << endl;
  
}


/**************************************************************************************

This is talk function. It allows the user to engage in conversation with the people in 
the rooms. This is a good way to learn about the murder. 

**************************************************************************************/
void Hall::talk(Player *thePlayer){

    cout << "Batista: You watch the game last night?" << endl;
    cout << "Diaz   : Yea, what were they thinking sending Johnson in that early." << endl;
    cout << "Batista: That's the thing about them, they always try to walk it in." << endl;
    
}

/**************************************************************************************

This is dispatch function. It allows the user to engage in conversation with the 
dispatch team in reference to the rooms. This is a good way to get a hint 

**************************************************************************************/
void Hall::dispatch(Player *thePlayer){

  cout << "Dispatch: Batista, the dead man's room is to your left." << endl;
  cout << "Dispatch: That's all we have for right now. " << endl;
}