/*********************************************************************
 *** Program Filename: zootycoon.cpp
 * ** Author: Charlene Wang
 * ** Date: 2/15/19
 * ** Description: contains main function
 * ** Input: none
 * ** Output: runs game
 * *********************************************************************/
#include <iostream>
#include <time.h> //for time
#include <ctime>
#include <stdio.h>
#include <iomanip>
#include <string>
#include <stdlib.h>

#include "zoo.hpp"
#include "animal.hpp"
#include "monkey.hpp"
#include "sea_otter.hpp"
#include "sloth.hpp"

using namespace std;

int main(){
    //random seed
    srand(time(0));
    
    //zoo object.
    Zoo z;
    
    //runs the game.
    z.run();
    
    return 0;
}
