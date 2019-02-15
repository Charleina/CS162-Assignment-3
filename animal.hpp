/*********************************************************************
 *** Program Filename: animal.hpp
 * ** Author: Charlene Wang
 * ** Date: 2/15/19
 * ** Description: contains animal class interface
 * ** Input: none
 * ** Output: none
 * *********************************************************************/
#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class Animal {
protected:
    int age;
    int cost; //cost of one animal
    
public:
    Animal();
    
    //setters
    void set_age(int x) { age = x; }
    void set_cost(int x) { cost = x; }
    //void set_baby(int x) { baby = x; }
    
    //getters
    int get_age() { return age; }
    int get_cost() { return cost; }
    //int get_baby() { return baby; }
    
    
};

#endif
