/**************************************************************************************

This is the immplementation file for Space class. It uses 4 pointers to point to the 
spaces in each cardinal direction (NORTH, SOUTH, EAST, WEST) as well as the name of 
each room. If the direciton is NULL it means you cannot go in that direction. There 
are also three functions that allow the user to investigate, talk and speak with 
dispatch about clues. 

**************************************************************************************/
#include <iostream>
#include <string>
#include "Space.hpp"
#include "Player.hpp"

using std::cout;
using std::endl;
using std::string;


/**************************************************************************************

This is the default constructor for the Space object. It sets all the directions to null and provides a generic room name for the object.

**************************************************************************************/
Space::Space(){

    north = NULL;
    south = NULL;
    west = NULL;
    east = NULL;
    spaceName = "Generic Space";
}


/**************************************************************************************

This is the constructor, it takes four space pointers as a string and sets them to the cardinal directions that would point to the next room or NULL if it points to nothing. 

**************************************************************************************/
Space::Space(Space *forward, Space *backward, Space *right, Space *left, string name){
    north = forward;
    south = backward;
    west = left;
    east = right;
    spaceName = name;
    
}


/**************************************************************************************

This is the destructor

**************************************************************************************/
Space::~Space(){

}


/**************************************************************************************

This function returns the pointer in the north direction of the current space. It will also return NULL if it points to nothing.

**************************************************************************************/
Space* Space::getNorth(){
  if(north != NULL){
    return north;
  }
  else{
    return NULL;
  }
}


/**************************************************************************************

This function returns the pointer in the south direction of the current space. It will also return NULL if it points to nothing.

**************************************************************************************/
Space* Space::getSouth(){
  if(south != NULL){
    return south;
  }
  else{
    return NULL;
  }
}


/**************************************************************************************

This function returns the pointer in the west direction of the current space. It will also return NULL if it points to nothing.

**************************************************************************************/
Space* Space::getWest(){
  if(west != NULL){
    return west;
  }
  else{
    return NULL;
  }
}


/**************************************************************************************

This function returns the pointer in the east direction of the current space. It will also return NULL if it points to nothing.

**************************************************************************************/
Space* Space::getEast(){
  if(east != NULL){
    return east;
  }
  else{
    return NULL;
  }
}


/**************************************************************************************

This function returns the name of the room as a string.

**************************************************************************************/
string Space::getName(){
  return spaceName;
}


/**************************************************************************************

This function sets the pointers of the space object as well as the name of the room.

**************************************************************************************/
void Space::connectSpaces(Space *forward, Space *backward, Space *right, Space *left, string name){
  
    north = forward;
    south = backward;
    west = left;
    east = right;
    spaceName = name;
}


/**************************************************************************************

This is a virtual function that takes a player object and allows the player to investigate the space for clues.

**************************************************************************************/
void Space::investigate(Player *thePlayer){
  cout << "It's an empty space" << std::endl;
}


/**************************************************************************************

This is a virtual function that takes a player object and allows the player to talk to anyone in the space.

**************************************************************************************/
void Space::talk(Player *thePlayer){
  cout << "Howdy" << endl;
}


/**************************************************************************************

This is a virtual function that takes a player object and allows the player to talk to the dispatch in reference to the space.

**************************************************************************************/
void Space::dispatch(Player *thePlayer){
  cout << "This is dispatch, how can we help?" << endl;
}

