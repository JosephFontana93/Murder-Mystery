/**************************************************************************************

This is the immplementation file for the Victim's room in the apartment complex. It is 
derived from the space class. The player can talk and investigate their surroundings. 

**************************************************************************************/
#include <iostream>
#include <string>
#include "Victim.hpp"
#include "Player.hpp"

using std::cout;
using std::endl;


/**************************************************************************************

This is investigate function. It allows the user to search the rooms for clues that may help them solve the murder

**************************************************************************************/
void Victim::investigate(Player *thePlayer){
  
  if(thePlayer->getHasDeadKeys() == false){
    cout << "It looks like this is door is locked, maybe you can find the keys somewhere." << endl;
  }

  if(thePlayer->getHasDeadKeys() == true && thePlayer->getHasLedger() == false){
    cout << "Batista: We're in." << endl;
    cout << "Diaz: This place is filthy." << endl;
    cout << "Batista: Come check this out Diaz." << endl;
    cout << "Diaz: What is it?" << endl;
    cout << "Batista: It looks like a ledger book, I think your friend here liked to gamble just like you." << endl;
    cout << "Batista: Looks like there's someone less lucky than you Diaz." << endl;
    cout << "Diaz: *grumbles to himself*" << endl;
    cout << "Batista: Or was he? Look at this!" << endl;
    cout << "Diaz : What is it?" << endl;
    cout << "Batista: This was the guy from the paper, who won the $100,000" << endl;
    cout << "Diaz: Someone must have caught wind of his big win." << endl;
    cout << "Batista: I think you're right. Let's go see the manager," << endl;
    cout << "Batista: maybe he knows of anyone who might not have liked our guy." << endl;

    cout << endl << "***You obtained the dead man's ledger***" << endl; 

    thePlayer->setLedger(true);
  }

  if(thePlayer->getHasDeadKeys() == true && thePlayer->getHasLedger() == true){
   
    cout << "I don't think there's anything else hidden in this filth." << endl;
    
  }


  
}


/**************************************************************************************

This is talk function. It allows the user to engage in conversation with the people in 
the rooms. This is a good way to learn about the murder. 

**************************************************************************************/
void Victim::talk(Player *thePlayer){

  if(thePlayer->getHasDeadKeys() == false){
    cout << "Batista: Damn, it's locked." << endl;
  }

  if(thePlayer->getHasDeadKeys() == true && thePlayer->getHasLedger() == false){
    
      cout << "Diaz: This place is giving me a headache." << endl;
      cout << "Batista: You're giving me a headache." << endl;

  }

  if(thePlayer->getHasDeadKeys() == true && thePlayer->getHasLedger() == true){
    
      cout << "Diaz: Why do you keep coming back to this pig sty?" << endl;
      cout << "Batista: Just a hunch." << endl;

  }

 
}

/**************************************************************************************

This is dispatch function. It allows the user to engage in conversation with the 
dispatch team in reference to the rooms. This is a good way to get a hint 

**************************************************************************************/
void Victim::dispatch(Player *thePlayer){

  if(thePlayer->getHasDeadKeys() == false ){
    
    cout << "Dispatch: Batista, you're going to need a key or a warrant." << endl;

  }
  else{

    cout << "Dispatch: Batista, check for any clues the killer may have left." << endl;
    cout << "Dispatch: We have CCTV footage of the killer, he's about your and Diaz's height." << endl;
    cout << "Dispatch: Be careful out there, he may still be in the building." << endl;

  }

  
    
}