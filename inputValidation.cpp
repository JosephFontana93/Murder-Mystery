/*********************************************************

This is the implementation file for the input validation
functions. These functions insure the user cannot enter
invalid inputs.

*********************************************************/
#include <iostream>
#include "inputValidation.hpp"

using std::cout;
using std::cin;
using std::endl;

/*********************************************************

This function validates the menu selection to make sure
it is only 1,2,3, or 4. 

//Resource used to learn about input validation:
//https://stackoverflow.com/questions/3826281/how-do-i-make-a-c-program-that-filter-out-non-integers

*********************************************************/
int mainMenuValidation(int userChoice){
  bool invalid = true;
  while(invalid == true){
    if(cin.fail() || userChoice > 2 || userChoice < 1 || cin.get()!='\n' ){
      cin.clear();
      cin.ignore(10000,'\n');
      cout<<"Please enter an integer between 1 and 2 ";
      cin>>userChoice;
    }
    else if((userChoice <= 2 && userChoice >= 1) && !cin.fail())
      invalid = false;
  }

  return userChoice;
}


/*********************************************************

This function validates the menu selection to make sure
it is only 1,2,3, or 4. 

//Resource used to learn about input validation:
//https://stackoverflow.com/questions/3826281/how-do-i-make-a-c-program-that-filter-out-non-integers

*********************************************************/
int menuSelectionValidation(int userChoice){
  bool invalid = true;
  while(invalid == true){
    if(cin.fail() || userChoice > 9 || userChoice < 1 || cin.get()!='\n' ){
      cin.clear();
      cin.ignore(10000,'\n');
      cout<<"Please enter an integer between 1 and 9 ";
      cin>>userChoice;
    }
    else if((userChoice <= 9 && userChoice >= 1) && !cin.fail())
      invalid = false;
  }

  return userChoice;
}


