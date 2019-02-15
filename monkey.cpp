/*********************************************************************
 *** Program Filename: monkey.cpp
 * ** Author: Charlene Wang
 * ** Date: 2/15/19
 * ** Description: contains monkey class implementation
 * ** Input: none
 * ** Output: none
 * *********************************************************************/
#include "monkey.hpp"

/*********************************************************************
 ** Function: Monkey
 ** Description: constructor
 ** Parameters: none
 ** Pre-Conditions: needs to be called
 ** Post-Conditions: intializes certain variables
 *********************************************************************/
Monkey :: Monkey(){
    this->cost = 15000;
}

/*********************************************************************
 ** Function: extrarevenue
 ** Description: randomly generates a number between 250-500 for random event
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
double Monkey :: extrarevenue(){
    
    //randomizing extra revenue
    int extrarevenue = rand() % 250 + 250;
    
    return extrarevenue;
}
