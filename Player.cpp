/**************************************************************************************

This is the immplementation file for the player class. It contains the player's 
current room location as well as all the items they can obtain throughout the game.
It will also detemine if they have shot anybody in the game. 

**************************************************************************************/
#include <iostream>
#include "Player.hpp"
#include "Space.hpp"



using std::cout;
using std::endl;

Player::Player(){
    
    
     hasCoffee = false; //Check if Batista has had coffee
     hasDeadKeys = false; //Check if Batista got the keys from the dead man
     hasLuckyFoot = false; //Check if Batista found the final clue
     hasLedger = false; //Check if Batista found the dead man's ledger
     hasManagerKey = false; //Check if Batista has the key to the Suspect's room
     hasBatteries = false; //Check if Batista recieved flashlight batteries
     hasPoolKey = false; //Check if Batista has pool access
     hasMap = false; //Check if Batista has a map fo the complex
    
    //Put the items in a container
    items[0] = hasCoffee;
    items[1] = hasDeadKeys;
    items[2] = hasLuckyFoot;
    items[3] = hasLedger;
    items[4] = hasManagerKey;
    items[5] = hasBatteries;
    items[6] = hasPoolKey;
    items[7] = hasMap;


     shotFired = 0; //0 = no shots, 1 means he killed Diaz, 2, means Diaz killed you
     
     currentLocation = NULL; //The current location of the player


}

/**************************************************************************************

This function returns if the player has had coffee yet.

**************************************************************************************/
bool Player::getHasCoffee(){
  //return hasCoffee;
  return  items[0];
}


/**************************************************************************************

This function returns if the player has the dead man's keys

**************************************************************************************/
bool Player::getHasDeadKeys(){
  //return hasDeadKeys;
  return  items[1];
}


/**************************************************************************************

This function returns if the player has Diaz's rabbits foot.

**************************************************************************************/
bool Player::getHasLuckyFoot(){
  //return hasLuckyFoot;
  return  items[2];
}


/**************************************************************************************

This function returns if the player has the dead man's ledger.

**************************************************************************************/
bool Player::getHasLedger(){
  //return hasLedger;
  return  items[3];
}


/**************************************************************************************

This function returns if the player has the key to the Suspect's room.

**************************************************************************************/
bool Player::getHasManagerKey(){
  //return hasManagerKey;
  return  items[4];
}


/**************************************************************************************

This function returns if the player has got the batteries from the tenant.

**************************************************************************************/
bool Player::getHasBatteries(){
  //return hasBatteries;
  return  items[5];
}


/**************************************************************************************

This function returns if the player has pool access.

**************************************************************************************/
bool Player::getHasPoolKey(){
  //return hasPoolKey;
  return  items[6];
}


/**************************************************************************************

This function returns if the player has the map of the complex.

**************************************************************************************/
bool Player::getHasMap(){
  //return hasMap;
  return  items[7];
}


/**************************************************************************************

This function returns if the player has fired their weapon.

**************************************************************************************/
int Player::getHasShotFired(){
  return shotFired;
}


/**************************************************************************************

This function returns the pointer to the current location in the complex.

**************************************************************************************/
Space* Player::getCurrentLocation(){
  return currentLocation;
}


/**************************************************************************************

This function sets to true if the user has coffee.

**************************************************************************************/
void Player::setCoffee(bool coffee){
  items[0] = coffee;
}


/**************************************************************************************

This function sets to true if the user has the keys to the dead man's room.

**************************************************************************************/
void Player::setDeadKeys(bool deadKeys){
  items[1] = deadKeys;
}


/**************************************************************************************

This function sets to true if the user find's Diaz's foot.

**************************************************************************************/
void Player::setLuckyFoot(bool luckyFoot){
  items[2] = luckyFoot;
}


/**************************************************************************************

This function sets to true if the user finds the dead man's ledger.

**************************************************************************************/
void Player::setLedger(bool ledger){
  items[3] = ledger;
}


/**************************************************************************************

This function sets to true if the user gets the key to the Suspect's room.

**************************************************************************************/
void Player::setManagerKey(bool managerKeys){
  items[4] = managerKeys;
}


/**************************************************************************************

This function sets to true if the user gets batteries from the tenant.

**************************************************************************************/
void Player::setBatteries(bool batteries){
  items[5] = batteries;
}


/**************************************************************************************

This function sets to true if the user gets the pool key.

**************************************************************************************/
void Player::setHasPoolKey(bool pool){
  items[6] = pool;
}


/**************************************************************************************

This function sets to true if the user gets the map of the apartment complex.

**************************************************************************************/
void Player::setHasMap(bool map){
  items[7] = map;
}


/**************************************************************************************

This function sets to an integer value depending on the scenario that occurs.

0 - no shots fired yet
1 - Batitsa shoots Diaz
2-  Diaz shoots Batista

**************************************************************************************/
void Player::setHasShotFired(int shot){
  shotFired = shot;
}


/**************************************************************************************

This function sets player's current location to the next room they got to. 

**************************************************************************************/
void Player::changeLocation(Space *nextLocation){
  currentLocation = nextLocation;
}


/**************************************************************************************

This function prints the inventory Batitsta has on him.

**************************************************************************************/
void Player::printInventory(){

  cout <<"-------INVENTORY--------" << endl;

  if(getHasMap() == true){
    cout << "Map" << endl;
  }

  if(getHasCoffee() == true){
    cout << "Coffee" << endl;
  }

  if(getHasPoolKey() == true){
    cout << "Pool Key" << endl;
  }

  if(getHasDeadKeys() == true){
    cout << "Dead Man's Key" << endl;
  }

  if(getHasLedger() == true){
    cout << "Ledger" << endl;
  }

  if(getHasManagerKey() == true){
    cout << "Key to Suspect's Room" << endl;
  }

  if(getHasBatteries() == true){
    cout << "Batteries" << endl;
  }
  
  if(getHasLuckyFoot() == true){
    cout << "Lucky Rabbit's Foot" << endl;
  }

  cout << "-----END INVENTORY------" << endl << endl;

}


/**************************************************************************************

This function prints the map of the complex if the user has access.

**************************************************************************************/
void Player::printMap(){
  if(getHasMap() == false){
    cout << "You don't have a map" << endl;
  }

  if(getHasMap() == true){
    cout << endl << endl;
    cout << "          POOL        " << endl;
    cout << "           |             " << endl;
    cout << "FIRE-----COFFEE------TENANT" << endl;
    cout << "ESCAPE     |               " << endl;
    cout << "           |               " << endl;
    cout << "TENANT----HALL              " << endl;
    cout << "           |               " << endl;
    cout << "         LOBBY             " << endl;
    cout << endl << endl;
  }
}