/*********************************************************************
 *** Program Filename: sea_otter.hpp
 * ** Author: Charlene Wang
 * ** Date: 2/15/19
 * ** Description: contains sea_otter class interface
 * ** Input: none
 * ** Output: none
 * *********************************************************************/

#ifndef SEA_OTTER_HPP
#define SEA_OTTER_HPP
#include "animal.hpp"

using namespace std;

class Sea_otter : public Animal {
public:
    Sea_otter();
    
    //getters
    double get_ofood(int basefood) { return 2 * basefood; }
};

#endif
