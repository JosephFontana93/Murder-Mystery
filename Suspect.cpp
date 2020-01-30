/**************************************************************************************

This is the immplementation file for the Suspect's room in the apartment complex. It is derived from the space class. The player can talk and investigate their surroundings. 

**************************************************************************************/
#include <iostream>
#include <string>
#include "Suspect.hpp"
#include "Player.hpp"

using std::cout;
using std::endl;


/**************************************************************************************

This is investigate function. It allows the user to search the rooms for clues that may help them solve the murder

**************************************************************************************/
void Suspect::investigate(Player *thePlayer){

  if(thePlayer->getHasManagerKey() == false){
    cout << "It's locked, maybe the manager has a key?" << endl;
  }

  if(thePlayer->getHasManagerKey() == true && thePlayer->getHasBatteries() == false){

    cout << "Batista: *Opens the door* Police, nobody move." << endl;
    cout << "Suspect: What the hell man." << endl;
    cout << "Diaz: Calm down man, we just want to ask some questions" << endl;
    cout << "Suspect:...I didn't do anything " << endl;
    cout << "Diaz: The place is clear, this guy didn't do it." << endl;

  }

  if(thePlayer->getHasManagerKey() == true && thePlayer->getHasBatteries() == true){

    cout << "You already checked his apartment, maybe you should leave him alone now?" << endl;

  }




}



/**************************************************************************************

This is talk function. It allows the user to engage in conversation with the people in 
the rooms. This is a good way to learn about the murder. 

**************************************************************************************/
void Suspect::talk(Player *thePlayer){

  if(thePlayer->getHasManagerKey() == false){
    cout << "Batista: Damn, it's locked and without the key we don't have permission." << endl;
    cout << "Diaz: Maybe the building manager has a key?" << endl;
  }

  if(thePlayer->getHasManagerKey() == true && thePlayer->getHasBatteries() == true){

        cout << "Suspect: I don't have any more batteries, man" << endl;
    
  }

  if(thePlayer->getHasManagerKey() == true && thePlayer->getHasBatteries() == false){
      cout << "Batista: Do you have any info that could help us?" << endl;
      cout << "Suspect: Well, some of the other tenants said they saw a strange guy." << endl;
      cout << "Batista: What did he look like?" << endl;
      cout << "Suspect: Not sure, but they said they heard a loud bang in the fire escape." << endl;
      cout << "Suspect: It's to the left of the coffee station, but it's pretty dark in there." << endl;
      cout << "Diaz: Damn, my flashlight just died this morning. We can come back later." << endl;
      cout << "Suspect: No it's okay, I have some extra batteries, here." << endl;
      cout << "Batista: Thank you." << endl;

      thePlayer->setBatteries(true);
      
      cout << endl << "***You obtained the batteries from the former suspect***" << endl;

  } 

  
  
    
}


/**************************************************************************************

This is dispatch function. It allows the user to engage in conversation with the 
dispatch team in reference to the rooms. This is a good way to get a hint 

**************************************************************************************/
void Suspect::dispatch(Player *thePlayer){

  if(thePlayer->getHasManagerKey() == false ){
    
    cout << "Dispatch: Batista, you need to get the key first." << endl;
    cout << "Dispatch : Maybe the manager has one?" << endl;
  }
  else{

    cout << "Dispatch: Batista, you don't have a warrant you'll need to find another way." << endl;
    cout << "Dispatch: Try seeing if the manager will give you a key." << endl;
  }

  
    
}
