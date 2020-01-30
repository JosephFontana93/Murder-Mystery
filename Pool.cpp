/**************************************************************************************

This is the immplementation file for the pool of the apartment complex. It is derived 
from the space class. The player can talk and investigate their surroundings. 

**************************************************************************************/
#include <iostream>
#include <string>
#include "Pool.hpp"
#include "Player.hpp"

using std::cout;
using std::endl;


/**************************************************************************************

This is investigate function. It allows the user to search the rooms for clues that may help them solve the murder

**************************************************************************************/
void Pool::investigate(Player *thePlayer){
  
  if(thePlayer->getHasPoolKey() == false ){
    
    cout << "Batista: It's locked, maybe we can see if the manager has a key." << endl;

  }

  if(thePlayer->getHasPoolKey() == true && thePlayer->getHasDeadKeys() == true){

      cout << "Diaz: What are we doing here again?" << endl;
      cout << "Batista: I'm not sure, let's go check out some other rooms." << endl;
      

  }

  if(thePlayer->getHasPoolKey() == true && thePlayer->getHasDeadKeys() == false){

      cout << "Diaz: Jesus, it's a blood bath in here." << endl;
      cout << "Batista: You can say that again." << endl;
      cout << "Diaz: Search his body, maybe he has something on him." << endl;
      cout << "Batista: I got his wallet and his keys, lets bag it for forensics." << endl;
      cout << "Diaz: Maybe we can use the key to search his apartment for more clues?" << endl;
      cout << "Batista: Hmm...we should wait for forensics Diaz." << endl;
      cout << "Diaz: Don't you want to catch this guy?" << endl;
      cout << "Batista: Alright, let's do this." << endl;
      cout << "***You obtained the dead man's keys***" << endl;

      thePlayer->setDeadKeys(true);

  }

  
  
}


/**************************************************************************************

This is talk function. It allows the user to engage in conversation with the people in 
the rooms. This is a good way to learn about the murder. 

**************************************************************************************/
void Pool::talk(Player *thePlayer){

  if(thePlayer->getHasPoolKey() == true && thePlayer->getHasDeadKeys() == true){

      cout << "Diaz: Batista, I don't think he needs his wallet back." << endl;
      cout << "Batista: I just wanted to check this out again" << endl;
      
  }
  if(thePlayer->getHasPoolKey() == false ){
    
    cout << "Diaz: Trying to go for a swim Batista?" << endl;
    cout << "Batista: Good one Diaz...it's locked" << endl;
  }

  if(thePlayer->getHasPoolKey() == true && thePlayer->getHasDeadKeys() == false){

      cout << "Diaz: You think that's blood or cherry kool-aid?" << endl;
      cout << "Batista: ..." << endl;
      
  }


    
}

/**************************************************************************************

This is dispatch function. It allows the user to engage in conversation with the 
dispatch team in reference to the rooms. This is a good way to get a hint 

**************************************************************************************/
void Pool::dispatch(Player *thePlayer){

  if(thePlayer->getHasPoolKey() == false ){
    
    cout << "Dispatch: Batista, you need to get the key first." << endl;
    cout << "Dispatch : Maybe the manager has one?" << endl;
  }
  else{

    cout << "Dispatch: Make sure you bag all evidence. The backup is coming shortly" << endl;

  }

  
    
}