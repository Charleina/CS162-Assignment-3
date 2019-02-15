/*********************************************************************
 *** Program Filename: monkey.hpp
 * ** Author: Charlene Wang
 * ** Date: 2/15/19
 * ** Description: contains monkey class interface
 * ** Input: none
 * ** Output: none
 * *********************************************************************/
#ifndef MONKEY_HPP
#define MONKEY_HPP
#include <ctime> //for time
#include <stdio.h>
#include <iomanip>
#include <stdlib.h>
#include "animal.hpp"
using namespace std;

class Monkey : public Animal {
public:
    Monkey();
    
    double extrarevenue();
    
    //getter
    double get_mfood(int basefood) { return 4 * basefood; }
};

#endif
