/*********************************************************************
 *** Program Filename: zoo.hpp
 * ** Author: Charlene Wang
 * ** Date: 2/15/19
 * ** Description: contains zoo class interface
 * ** Input: none
 * ** Output: none
 * *********************************************************************/
#ifndef ZOO_HPP
#define ZOO_HPP
#include <iostream>
#include <string>
#include <ctime> //for time
#include <stdio.h>
#include <iomanip>
#include <stdlib.h>
#include "monkey.hpp"
#include "sea_otter.hpp"
#include "sloth.hpp"

using namespace std;

class Zoo {
    
private:
    double revenue; //amount of revnue made a day
    double bank; //amount of money in playere's bank account
    int days; // current days/days past
    double basefood; //base cost of food
    int whichfood; //for deciding which random even occurs depending on food
    string nameofzoo; //for name of zoo
    
    Monkey* m;
    //total monkeys
    int monkeysize;
    //number of adults
    int adultMonkey;
    int numMonkeybaby;
    
    Sea_otter* se;
    //total sea otters
    int ottersize;
    //number of adults
    int adultOtter;
    int numOtterbaby;
    
    Sloth* sl;
    //total sloths
    int slothsize;
    //number of adults
    int adultSloth;
    int numSlothbaby;
    
    bool endofday; //for decing if user wants to exit and end gamew

public:
    Zoo();
    ~Zoo();
    Zoo( const Zoo& z1 );
    void operator=( const Zoo& z );
    
    //actual game
    void run();
    
    void grow_animal(); // ages animals one day
    int feed_animal(); //minus cost to feed animals from bank
    bool calculate_revenue(); //adds money to bank
    
    void random_eventregular( int whichfood ); //would run normal random event if user fed normal amount of food
    
    void random_eventcheap(); //will run one with odds of being sick higher
    void random_eventpremium(); //will run one with odds of not being sick higher
    
    //functions that edits the animal arrays
    void addmonkeyarray( int before );
    void add_monkey( int x );
    void take_monkey( int index );
    void addotterarray( int before );
    void add_otter( int x );
    void take_otter( int index );
    void addslotharray( int before );
    void add_sloth( int x );
    void take_sloth( int index );

    //all the functions that correspond to a random event
    void sick();
    void extra_revenue();
    void new_baby();
    
    //starts the game
    void welcome();
    
    //ends each day
    void startday();
    
    //for when the user asks for a certain species.
    void asking_monkey();
    void asking_otter();
    void asking_sloth();
    
    //prints out error message
    void errormessage();
    
    bool day20event();
};

#endif
