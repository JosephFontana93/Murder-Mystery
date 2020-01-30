/**************************************************************************************

This is the immplementation file for the fire escape of the apartment complex. It is derived from the space class. The player can talk and investigate their surroundings. 

**************************************************************************************/
#include <iostream>
#include <string>
#include "inputValidation.hpp"
#include "Fire.hpp"
#include "Player.hpp"

using std::cout;
using std::endl;
using std::cin;

/**************************************************************************************

This is investigate function. It allows the user to search the rooms for clues that may help them solve the murder. 

In this room, if you have the final key and you have not concluded that your partner is
the killer, you will have to decide if you will shoot them or not.

**************************************************************************************/
void Fire::investigate(Player *thePlayer){

  if(thePlayer->getHasBatteries() == false){
    
    cout << "It's pitch black, you'll need some light before you can look around" << endl;
  }

  if(thePlayer->getHasBatteries() == true){

    //find the rabbit foot. belonging to Diaz
    thePlayer->setLuckyFoot(true);
    
    cout << "Batista:Now, we can see in here, look around Diaz." << endl;
    cout << "Diaz: Sure thing..." << endl;
    cout << "Batista: Diaz, I think I got something!" << endl;
    cout << "Diaz: What is it?" << endl;
    cout << "Batista: *picks up what appears to be a lucky rabbit's foot*" << endl;
    cout << endl << "Should you talk to Diaz or should you call for dispatch and put him under arrest?" << endl;
    cout << "The choice is yours." << endl;

    
  }
  
}


/**************************************************************************************

This is talk function. It allows the user to engage in conversation with the people in 
the rooms. This is a good way to learn about the murder. 

**************************************************************************************/
void Fire::talk(Player *thePlayer){

  if(thePlayer->getHasBatteries() == false){

    cout << "Diaz: Batista, I can't see a thing, we need to get some batteries first." << endl;

  }

  if(thePlayer->getHasLuckyFoot() == false){
    cout << "Batista: You see any clues Diaz?" << endl;
  }

  if(thePlayer->getHasLuckyFoot() == true){

    cout << "Batista: *Begins to turn around* Diaz, don't you have one of the--" << endl;
    cout << "Batista turns around and Diaz is pointing a gun at you (Batista)" << endl;
    cout << "Batista: It was you...why Diaz?" << endl;
    cout << "Diaz: *sobbing* If my daughter is going to live, she's going to need treatment" << endl;
    cout << "Batista:...there's other ways Di-" << endl;
    cout << "Diaz: There is no other way...and now that you know I have no choice" << endl;
    cout << endl << endl << "Diaz is pointing his gun at you, if you don't shoot him he will kill you" << endl;
    cout << "1.)Shoot" << endl;
    cout << "2.)Don't shoot" << endl;
    int shoot;
    cin >> shoot; //Validate

    shoot = mainMenuValidation(shoot);

    if(shoot == 1){
      cout << "BANG" << endl;
      cout <<"Diaz's body falls to the floor" << endl;
      cout << "Batitsa goes into shock and passes out" << endl;
      thePlayer->setHasShotFired(1);
    }
    else if(shoot == 2){
      cout << "Diaz: You should have killed me when you had the chance" << endl;
      cout << "BANG" << endl;
      cout << "Everything goes dark" << endl;
      thePlayer->setHasShotFired(2);
    }
  }

    
}


/**************************************************************************************

This is dispatch function. It allows the user to engage in conversation with the 
dispatch team in reference to the rooms. This is a good way to get a hint 

**************************************************************************************/
void Fire::dispatch(Player *thePlayer){

  if(thePlayer->getHasBatteries() == false){

    cout << "Dispatch: We can't help you here Diaz, you'll need to find a light source." << endl;

  }

  if(thePlayer->getHasBatteries() == true && thePlayer->getHasLuckyFoot() == false){

    cout << "Dispatch: Batista be careful, the killer may still be in the building." << endl;

  }

  if(thePlayer->getHasLuckyFoot() == true){
    //YOU WIN
    cout << "Batista: Diaz, your're under arrest, put your hands behind your back." << endl;
    cout << "Batista: I need all squad cars to the Sunny town apartments, now." << endl;
    cout << "Dispatch: All units proceed to Sunny town apartments." << endl;

    thePlayer->setHasShotFired(1);
  }
    
}

