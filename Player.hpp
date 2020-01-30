/**************************************************************************************

This is the header file for the player class. It contains the player's 
current room location as well as all the items they can obtain throughout the game.
It will also detemine if they have shot anybody in the game. 

**************************************************************************************/
#ifndef PLAYER_HPP
#define PLAYER_HPP

/*
Forward Declaration since Player and Space both use each other in each class.
Source: https://stackoverflow.com/questions/9119236/c-class-forward-declaration
*/
class Space;



/**************************************************************************************

This is the Player class. In this game it reprsents you as you play as Batista. It has a container of 8 items which you obtain through out the game as well a pointer to a space which controls your current location. It also tracks if you have fired your weapon.

**************************************************************************************/
class Player{

  protected:
    //Items
    bool items[8];
    
    bool hasCoffee; //Check if you have coffee
    bool hasDeadKeys; //Check if you have the dead man's keys
    bool hasLuckyFoot; //Check if you have Diaz's foot
    bool hasLedger; //Check if you have the dead man's ledger
    bool hasManagerKey; //Check if you have the master key to the tenant's rooms
    bool hasBatteries; //Check if you have flashlight batteries
    bool hasPoolKey; //Check if you have a pool key
    bool hasMap; //Check if you have a map
    
    int shotFired; //Check if you fired your weapon. Integer for multiple scenarios.
   
    Space *currentLocation; //A pointer to your current location on the map

  public:

    Player(); //Default constructor

    //Getters
    bool getHasCoffee(); //Returns if you had your coffee yet
    bool getHasDeadKeys(); //Returns if you have the dead mans keys
    bool getHasLuckyFoot(); //Returns if you have Diaz's lucky rabbit foot
    bool getHasLedger(); //Returns if you have the dead man's ledger
    bool getHasManagerKey(); //Returns if you have the key to he Suspect's room
    bool getHasBatteries(); //Returns if you have the batteries for the flashlight
    bool getHasPoolKey(); //Retuns if yoi have the pool key
    bool getHasMap(); //Returns if you have the map

    int getHasShotFired(); //Returns the integer representing the scenario in which you have used your weapon.

    Space *getCurrentLocation(); //Retuns a pointer to your current location

    //Setters
    void setCoffee(bool coffee);
    void setDeadKeys(bool deadKeys);
    void setLuckyFoot(bool luckyFoot);
    void setLedger(bool ledger);
    void setManagerKey(bool managerKeys);
    void setBatteries(bool batteries);
    void setHasPoolKey(bool pool);
    void setHasShotFired(int shot);
    void setHasMap(bool map);
    void changeLocation(Space *nextLocation);

    //Print the Inventory
    void printInventory();

    //Print the map
    void printMap();

    //Give access to the room spaces to access the player variables for modification
    friend class Space;
    friend class Coffee;
    friend class Fire;
    friend class Hall;
    friend class Lobby;
    friend class Pool;
    friend class Suspect;
    friend class Victim;

};

#endif