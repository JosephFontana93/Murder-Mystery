/**************************************************************************************

This is the header file for Space class. It uses 4 pointers to point to the 
spaces in each cardinal direction (NORTH, SOUTH, EAST, WEST) as well as the name of 
each room. If the direciton is NULL it means you cannot go in that direction. There 
are also three functions that allow the user to investigate, talk and speak with 
dispatch about clues. 

**************************************************************************************/
#ifndef SPACE_HPP
#define SPACE_HPP

#include <string>

using std::string;

/*
Forward Declaration since Player and Space both use each other in each class.
Source: https://stackoverflow.com/questions/9119236/c-class-forward-declaration
*/
class Player;


/**************************************************************************************

This is the Space class. It contains 4 pointers that point in all cardinal directions to any rooms that are in those directions. It also contains a string which identifies the room's name.

**************************************************************************************/
class Space{

  protected:

    Space *north;
    Space *south;
    Space *west;
    Space *east;
    string spaceName;
    

  public:

  Space(); //Default constructor

  //The constructor
  Space(Space *forward, Space *backward, Space *right, Space *left, string name);
  
  //The destructor
  virtual ~Space();

  //Getters for the directions and the name
  Space* getNorth();
  Space* getSouth();
  Space* getWest();
  Space* getEast();
  string getName();

  //Connects the rooms via pointers and sets the name of the room
  void connectSpaces(Space *forward, Space *backward, Space *right, Space *left, string name);


  //Virtual function to investigate a room
  virtual void investigate(Player *thePlayer);

  //Virtual function to talk to people within the room
  virtual void talk(Player *thePlayer);

  //Virtual function to talk to dispatch for clues
  virtual void dispatch(Player *thePlayer);
 



};
#endif