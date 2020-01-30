/**************************************************************************************

This is the immplementation file for the main lobby of the apartment complex. It is derived 
from the space class. The player can talk and investigate their surroundings. 

**************************************************************************************/
#include <iostream>
#include <string>
#include "Lobby.hpp"
#include "Player.hpp"

using std::cout;
using std::endl;



/**************************************************************************************

This is investigate function. It allows the user to search the rooms for clues that may help them solve the murder

**************************************************************************************/
void Lobby::investigate(Player *thePlayer){

  cout << "Batista: I don't see any murder clues in here." << endl;
  
}


/**************************************************************************************

This is talk function. It allows the user to engage in conversation with the people in 
the rooms. This is a good way to learn about the murder. 

**************************************************************************************/
void Lobby::talk(Player *thePlayer){

  //The final statement from the manager
  if(thePlayer->getHasLedger() == true && thePlayer->getHasManagerKey() == true){
  
    cout << "Manager: I'm afraid that's all the info I have for you." << endl;
    
  }  
  //The last key from the managers
  if(thePlayer->getHasLedger() == true && thePlayer->getHasManagerKey() == false){
    cout << "Batista: Can you tell us if anyone would want to hurt our victim?" << endl;
    cout << "Manager: Well, he would always yell at the guy to the right of the" << endl;
    cout << "Manager: coffee station. They would argue because he would play" << endl;
    cout << "Manager: really loud music." << endl;
    cout << "Batista: Do you think we could inspect his apartment?" << endl;
    cout << "Manager: Sure, here is the key!" << endl;
    cout << "Batista: Thank you!" << endl;
    cout << "***You obtained the key to the suspect's apartment***" << endl;

    thePlayer->setManagerKey(true);
  }

  //A hint from the manager to check the pool
  if(thePlayer->getHasLedger() == false && thePlayer->getHasPoolKey() == true){

      cout << "Manager: Let me know what you find at the pool." << endl;

  }
  //Getting the pool key from the manager
  if(thePlayer->getHasCoffee() == true && thePlayer->getHasPoolKey() == false){
    cout << "Batista: Ok, now that I've had my coffee, tell me more about this case." << endl;
    cout << "Manager: The tenant's body is at the pool. You'll need a key to get to it. " << endl;
    cout << "Manager: Here, I have an extra one." << endl;
    cout << "Batista: Thank you." << endl;
    cout << "***You obtained the key to the pool***" << endl;

    thePlayer->setHasPoolKey(true);
  }
  //Getting the map from the manager
  if(thePlayer->getHasCoffee() == false){
    cout << "Manager: I'm glad you're he-" << endl;
    cout << "Batista: Sorry, I need to get some coffee to wake me up for this." << endl;
    cout << "Manager: Of course, it's just past the hall, straight ahead." << endl;
    cout << "Manager: Come see me when you're ready." << endl;
    cout << "Manager: Here is a map in case you get lost." << endl;
    cout << "***You obtained the map of the apartment***" << endl;

    thePlayer->setHasMap(true);


  }


 
}

/**************************************************************************************

This is dispatch function. It allows the user to engage in conversation with the 
dispatch team in reference to the rooms. This is a good way to get a hint 

**************************************************************************************/
void Lobby::dispatch(Player *thePlayer){


  cout << "Dispatch: Batista, talk to the manager he should be able to help you." << endl;
  
}