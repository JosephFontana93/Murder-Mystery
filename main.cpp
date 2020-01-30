/**************************************************************************************
Author: Joseph Fontana
Date  : 3/21/19
Description: This following program is a murder mystery game. You play as Officer
             Batista of the Seattle Police Department. You will move from room to
             room collecting keys and clues to learn about the murderer and the victim
             as well as making ethical choices.


Order of events to win: 
  1.Talk to the manager to get a map of the building
  2.Follow the map to the coffee area and get coffee
  3.Go back to the manager and get a key to the poolMap
  4.Go to the pool and find the dead man - get his keys
  5.Go to the dead man's room and investigate his room, get his ledger
  6.Talk to the manager about the dead man, he will point you to your next
    suspect and provide you the key to his room
  7.Talk to the suspect and you will clear him by checking his alibi. He will give you
    batteries for your flashlight to see in the escape room.
  8.Go to the escape room and find Diaz's rabbit's foot

  BREAK - You have a few options. If you find the rabbit's foot you can talk to Diaz afterwards which will begin an end sequence in which you have two options, kill Diaz or he will kill you in which you lose. Alternatively, you can call dispatch after finding the lucky charm and you will arrest Diaz and still win the game. 
**************************************************************************************/
#include <iostream>
#include <string>
#include "inputValidation.hpp"
#include "Player.hpp"
#include "Space.hpp"
#include "Lobby.hpp"
#include "Coffee.hpp"
#include "Fire.hpp"
#include "Hall.hpp"
#include "Pool.hpp"
#include "Suspect.hpp"
#include "Victim.hpp"



using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {

  //Control for multiple game plays
  int keepPlaying = 1;
 
  do{
    //Create instance of the Character
    Player *player = new Player;

    //Create instance of each map area
    Coffee *coffeeMap = new Coffee;
    Fire *fireMap = new Fire;
    Hall *hallMap = new Hall;
    Lobby *lobbyMap = new Lobby;
    Pool *poolMap = new Pool;
    Suspect *suspectMap = new Suspect;
    Victim *victimMap = new Victim;

    //Connect all the rooms to each other
    coffeeMap->connectSpaces(poolMap,hallMap,suspectMap,fireMap, "Coffee Station");
    fireMap->connectSpaces(NULL,NULL,NULL,coffeeMap, "Fire Escape");
    hallMap->connectSpaces(coffeeMap,lobbyMap,NULL,victimMap,"Hall");
    lobbyMap->connectSpaces(hallMap,NULL,NULL,NULL, "Lobby");
    poolMap->connectSpaces(NULL,coffeeMap,NULL,NULL, "Pool");
    suspectMap->connectSpaces(NULL,NULL,NULL,coffeeMap, "Suspect's Room");
    victimMap->connectSpaces(NULL,NULL,hallMap,NULL, "Dead Man's Room");

    cout << "Are you ready to go to work?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    int userChoice;
    cin >> userChoice;

    userChoice = mainMenuValidation(userChoice);

    if(userChoice == 1){
        //Basic story background
        cout << "You are Officer Batista of the SPD." << endl;
        cout << "It's 5AM Monday morning in Seattle." << endl;
        cout << "The rain pours down on your squad car." << endl;
        cout << "You can hear the static from the radio crackle." << endl; 
        cout << "Your partner Diaz sits in the other seat." << endl;
        cout << "You're reading the daily news, the headlines read: " << endl << endl;
        cout << "-----------SEATTLE ENQUIRER-----------" << endl;
        cout << "Unions push back on Amazon" << endl;
        cout << "Is Seattle in a drought?" << endl;
        cout << "Local man wins $100,000 on horse race" << endl;
        cout << "Graphene is finally useful " << endl;
        cout << "Cure for cancer...but it's not cheap" << endl;
        cout << "--------------------------------------" << endl << endl;
        cout << "Batista: Diaz, it says here they might actually have a cure for cancer." << endl << endl;
        cout << "Diaz gazes out into the rain" << endl << endl;
        cout << "Diaz: It won't do my daughter any good if I can't afford it." << endl;
        cout << "Batista: And you wont' do her any good gambling your life away at the races..." << endl << endl << endl;
        cout << "The static from the radio turns to audible noise:" << endl;
        cout << "Dispatch: SQUAD CAR 142, REPORT TO THE SUNNY TOWN APARTMENTS." << endl;
        cout << "Dispatch : We have a code 5150, potential killer at large." << endl;
        cout << "Dispatch : Be on look out." << endl;
        cout << "Dispatch : If the suspect isn't caught in the next 24 hours...it's gameover." << endl << endl;

        cout << "Batista: 142 to Dispatch, we're on route." << endl;

        cout << endl << endl << endl;

        //This gameclock limits the number of steps the player can take.
        //After 100 steps, the game is ended.
        int gameClock = 0; 
        
        //Start the player in the lobby
        player->changeLocation(lobbyMap);
        
        
        while(gameClock < 100 && player->getHasShotFired() == 0){
          
          //Print the number of turns left and the player menu
          cout << "Steps left: " << 100 - gameClock << endl << endl;
        
          cout << "You are in the " << player->getCurrentLocation()->getName() << endl;
          cout << "What would you like to do?" << endl;
          cout << "1. View Inventory" << endl;
          cout << "2. Investigate" << endl;
          cout << "3. Talk" << endl;
          cout << "4. Dispatch" << endl;
          cout << "5. View Map" << endl;
          cout << "6. Move Forward" << endl;
          cout << "7. Move Backward" << endl;
          cout << "8. Move Left" << endl;
          cout << "9. Move Right" << endl;
          int selection;
          cin >> selection; // VALIDATE

          selection = menuSelectionValidation(selection);

          if(selection == 1){
            //view Inventory
            player->printInventory();
          }
          else if(selection == 2){
            //Investigate
            player->getCurrentLocation()->investigate(player);
          }
          else if(selection == 3){
            //talk
            player->getCurrentLocation()->talk(player);
          }
          else if(selection == 4){
            player->getCurrentLocation()->dispatch(player);
            
          }
          else if(selection == 5){
            player->printMap();
            
          }
          else if(selection == 6){
            //forward
            if(player->getCurrentLocation()->getNorth() != NULL){
              player->changeLocation(player->getCurrentLocation()->getNorth());
              gameClock++;
            
            }
            else{
              cout << "Er...you can't go that way." << endl;
            }
              
          }
          else if(selection == 7){
             //backward
             if(player->getCurrentLocation()->getSouth() != NULL){
              player->changeLocation(player->getCurrentLocation()->getSouth());
              gameClock++;
            }
            else{
              cout << "Er...you can't go that way." << endl;
            }
            
          }
          else if(selection == 8){
            //left
             if(player->getCurrentLocation()->getWest() != NULL){
              player->changeLocation(player->getCurrentLocation()->getWest());
              gameClock++;
            }
            else{
              cout << "Er...you can't go that way." << endl;
            }
          
          }
          else if(selection == 9){
            //right
             if(player->getCurrentLocation()->getEast() != NULL){
              player->changeLocation(player->getCurrentLocation()->getEast());
              gameClock++;
            }
            else{
              cout << "Er...you can't go that way." << endl;
            }
            
          }

        }

        //There are 3 end scenarios. If you kill your partner
        //in self-defense you still win. 
        if(player->getHasShotFired() == 1){
          cout << "Captain Rogers: You saved the day Batista." << endl;
          cout << "Batista: All part of a day's work captain." << endl;
          cout << "YOU WIN" << endl;
          keepPlaying = 2;
        }
        //If you don't kill you partner and you do not arrest him, you lose
        else{
          cout << "Batista: Where am I? Why is it so sunny here?" << endl;
          cout << "God:..." << endl;
          cout << "GAMEOVER" << endl;
          cout << "Play again?" << endl;
          cout << "1. Yes" << endl;
          cout << "2. No" << endl;
          cin >> keepPlaying;

          keepPlaying = mainMenuValidation(keepPlaying);
        }


    }
    else if(userChoice == 2){
      cout << "It's probably best you stayed home today anyway..." << endl;
      keepPlaying = 2;
    }

    //Free memory
    delete player;
    delete coffeeMap;
    delete fireMap;
    delete hallMap;
    delete lobbyMap;
    delete poolMap;
    delete suspectMap;
    delete victimMap;


  }while(keepPlaying == 1);
  
}