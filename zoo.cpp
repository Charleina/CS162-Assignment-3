/*********************************************************************
 *** Program Filename: zoo.cpp
 * ** Author: Charlene Wang
 * ** Date: 2/15/19
 * ** Description: contains zoo class implementation
 * ** Input: none
 * ** Output: none
 * *********************************************************************/
#include "zoo.hpp"

/*********************************************************************
 ** Function: Zoo
 ** Description: constructor
 ** Parameters: none
 ** Pre-Conditions:  needs to be called
 ** Post-Conditions: intializes certain variables
 *********************************************************************/
Zoo :: Zoo(){
    this->bank = 100000;
    this->days = 1;
    this->revenue = 0;
    this->basefood = 50;
    this->whichfood = 0;
    this->nameofzoo = "";
    
    this->monkeysize = 0;
    this->m = new Monkey[this->monkeysize];
    this->adultMonkey = 0;
    this->numMonkeybaby = 0;
    this->ottersize = 0;
    this->se = new Sea_otter[this->ottersize];
    this->adultOtter;
    this->numOtterbaby = 0;
    this->slothsize = 0;
    this->sl = new Sloth[this->slothsize];
    this->adultSloth = 0;
    this->numSlothbaby = 0;
    
    
    this->endofday=true;
    
}

/*********************************************************************
 ** Function: ~Zoo
 ** Description: deconstructor
 ** Parameters: none
 ** Pre-Conditions: variable needs to exist
 ** Post-Conditions: frees up memory
 *********************************************************************/
Zoo :: ~Zoo(){
    delete [] this->m;
    delete [] this->se;
    delete [] this->sl;
}

/*********************************************************************
 ** Function: Zoo
 ** Description: copy constructor
 ** Parameters: const Zoo& z1
 ** Pre-Conditions: variable needs to exist
 ** Post-Conditions:
 *********************************************************************/
Zoo :: Zoo(const Zoo& z1){
    this->bank = z1.bank;
    this->days = z1.days;
    this->revenue = z1.revenue;
    this->basefood= z1.basefood;
    this->whichfood = z1.whichfood;
    this->nameofzoo = z1.nameofzoo;
    
    this->monkeysize = z1.monkeysize;
    this->m = new Monkey[z1.monkeysize];
    this->adultMonkey = z1.adultMonkey;
    this->numMonkeybaby = z1.numMonkeybaby;
    this->ottersize = z1.ottersize;
    this->se = new Sea_otter[z1.ottersize];
    this->adultOtter = z1.adultOtter;
    this->numOtterbaby = z1.numOtterbaby;
    this->slothsize = z1.slothsize;
    this->sl = new Sloth[z1.slothsize];
    this->adultSloth = z1.adultSloth;
    this->numSlothbaby = z1.numSlothbaby;
    
    this->endofday = z1.endofday;
    
}

/*********************************************************************
 ** Function: operator=
 ** Description: overload operator
 ** Parameters: const Zoo& z
 ** Pre-Conditions: variable needs to exist
 ** Post-Conditions:
 *********************************************************************/
void Zoo :: operator=(const Zoo& z){
    this->bank = z.bank;
    this->days = z.days;
    this->revenue = z.revenue;
    this->basefood = z.basefood;
    this->whichfood = z.whichfood;
    this->nameofzoo = z.nameofzoo;
    
    this->monkeysize = z.monkeysize;
    this->m = new Monkey[z.monkeysize] ();
    this->adultMonkey = z.adultMonkey;
    this->numMonkeybaby = z.numMonkeybaby;
    this->ottersize = z.ottersize;
    this->se = new Sea_otter[z.ottersize] ();
    this->adultOtter = z.adultOtter;
    this->numOtterbaby = z.numOtterbaby;
    this->slothsize = z.slothsize;
    this->sl = new Sloth[z.slothsize] ();
    this->adultSloth = z.adultSloth;
    this->numSlothbaby = z.numSlothbaby;
    
    
    this->endofday = z.endofday;
    
}

/*********************************************************************
 ** Function: run
 ** Description: runs the entire game
 ** Parameters: none
 ** Pre-Conditions: all the classes used need to exist
 ** Post-Conditions: runs and finishes game
 *********************************************************************/
void Zoo :: run(){
    
    // will print welcome message and ask user for new animals.
    welcome();
    
    /* will run through all functions written and stop when endday
     * function produces a false which means player wants to end
     * game. Otherwise the game will continue.
     */
    do
    {
        grow_animal();
        this->whichfood = feed_animal();
        calculate_revenue();
        random_event1( whichfood );
        endofday = endday();
        //this will up the days so that when program continues day will be different.
        set_days(this->days + 1);
        
    } while( this->endofday );
    
    cout << "Thanks for playing!" << endl;
}

/*********************************************************************
 ** Function: grow_animal
 ** Description: will age all animals one day older
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void Zoo :: grow_animal(){
    
    // Monkeys
    if( monkeysize != 0 )
    {
        for(int i = 0; i < monkeysize; i++)
        {
            //storing new age first
            int age = m[i].get_age() + 1;
            this->m[i].set_age(age);
        }
    }
    
    // Sea Otters
    if( ottersize != 0 )
    {
        for(int i = 0; i < ottersize; i++)
        {
            //storing new age first
            int age = se[i].get_age() + 1;
            this->se[i].set_age(age);
        }
    }
    
    // Sloths
    if( slothsize != 0 )
    {
        for(int i = 0; i < slothsize; i++)
        {
            //storing new age first
            int age = sl[i].get_age() + 1;
            this->sl[i].set_age(age);
        }
    }
    cout << "Animals have been aged!" << endl << endl;
}

/*********************************************************************
 ** Function: feed_animal
 ** Description: will change basefood to a random base cost of 75%-125% of the basefood from the day before.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: returns int for which food the user asked for.
 *********************************************************************/
int Zoo :: feed_animal(){
    
    //first day basefood cost should be 50 which is what its intialized to
    if( this->days == 1 )
    {
        basefood = basefood;
    }
    
    //after fist day it should be random
    else
    {
        //randomizing base food from day before
        int random = rand() % 50 + 75;
        
        //converts it into a decimal
        double randpercent = (float)random / 100;
        
        //new base cost for the day
        this->basefood = basefood * randpercent;
    }
    
    //for checking if user input 1 2 or 3
    bool validinput = true;
    
    do
    {
        cout << "Would you like to feed your animal regular version (base price is: $" << basefood << " , premium version (double the cost of normal but lower the chance of animals getting sick), or the cheap version (half the cost of normal and ups the chance of animals getting sick) of food? (regular: 1, premium: 2, cheap: 3)" << endl;
        
        //for userinput
        int answer = 0;
        cin >> answer;
        
        //so when it circles back it will set this back to true
        validinput = true;
        
        //for regular food
        if( answer == 1)
        {
            // feed monkey
            if( monkeysize !=0 )
            {
                //will find the actual cost to feed specifically monkey
                double monkeyfood = m[0].get_mfood(basefood);
                bank -= monkeysize * monkeyfood;
            }
            //feed sea otters
            if( ottersize != 0)
            {
                double otterfood = se[0].get_ofood(basefood);
                bank -= ottersize * otterfood;
            }
            //feed sloths
            if( slothsize != 0)
            {
                bank -= slothsize * basefood;
            }
            cout << "Animals have been fed!" << endl << endl;
            return 1;
        }
        
        //premium
        else if( answer == 2)
        {
            basefood = 2 * basefood;
            // feed monkey
            if( monkeysize !=0 )
            {
                //will find the actual cost to feed specifically monkey
                double monkeyfood = m[0].get_mfood(basefood);
                bank -= monkeysize * monkeyfood;
            }
            //feed sea otters
            if( ottersize != 0)
            {
                double otterfood = se[0].get_ofood(basefood);
                bank -= ottersize * otterfood;
            }
            //feed sloths
            if( slothsize != 0)
            {
                bank -= slothsize * basefood;
            }
            cout << "Animals have been fed!" << endl << endl;
            return 2;
        }
        
        //cheap
        else if( answer == 3)
        {
            basefood = 0.5 * basefood;
            // feed monkey
            if( monkeysize !=0 )
            {
                //will find the actual cost to feed specifically monkey
                double monkeyfood = m[0].get_mfood(basefood);
                bank -= monkeysize * monkeyfood;
            }
            //feed sea otters
            if( ottersize != 0)
            {
                double otterfood = se[0].get_ofood(basefood);
                bank -= ottersize * otterfood;
            }
            //feed sloths
            if( slothsize != 0)
            {
                bank -= slothsize * basefood;
            }
            cout << "Animals have been fed!" << endl << endl;
            return 3;
        }
        else
        {
            errormessage();
            validinput = false;
        }
    } while( !validinput );
    
}

/*********************************************************************
 ** Function: calculate_revenue
 ** Description: will add any revenue made from any animal of that day
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void Zoo :: calculate_revenue(){
    //will hold age number
    int age = 0;
    
    // feed monkey
    if( monkeysize !=0 )
    {
        //monkeys make 10% of their initial cost
        double monkeycost = m[0].get_cost() * 0.1;
        
        //will circle through the array and add their revenue to bank
        for(int i = 0; i < monkeysize; i++)
        {
            //puts age of current animal into age
            age = m[i].get_age();
            
            if( age >= 30 )
            {
                bank += monkeycost;
            }
            
            //babies make twice as much
            else
            {
                bank += 2 * monkeycost;
            }
        }
    }
    
    //feed sea otters
    if( ottersize != 0)
    {
        //sea otters make 5% of their initial cost
        double ottercost = se[0].get_cost() * 0.05;
        
        //will circle through the array and add their revenue to bank
        for(int i = 0; i < ottersize; i++)
        {
            //puts age of current animal into age
            age = se[i].get_age();
            
            if( age >= 30 )
            {
                bank += ottercost;
            }
            
            //babies make twice as much
            else
            {
                bank += 2 * ottercost;
            }
        }
    }
    
    //feed sloths
    if( slothsize != 0)
    {
        //slotth make 5% of their initial cost
        double slothcost = sl[0].get_cost() * 0.05;
        
        //will circle through the array and add their revenue to bank depending on age
        for(int i = 0; i < slothsize; i++)
        {
            //puts age of current animal into age
            age = sl[i].get_age();
            
            if( age >= 30 )
            {
                bank += slothcost;
            }
            
            //babies make twice as much
            else
            {
                bank += 2 * slothcost;
            }
        }
    }
    //cout << "added revenue" << endl << endl;
}

/*********************************************************************
 ** Function: random_event
 ** Description: chooses a random event
 ** Parameters: int whichfood
 ** Pre-Conditions: functions need to exist
 ** Post-Conditions: none
 *********************************************************************/
void Zoo :: random_event1(int whichfood){
    
    //regular food random event
    if( whichfood == 1)
    {
        cout << "Today something special or horrible might happen!" << endl;
        //random number the fourth one is for nothing special to happen
        int random = rand() % 4 + 1;
        cout << random << endl;
        //a random animal gets sick
        if(random == 1)
        {
            sick();
        }
        
        //random adult animal gets has (a) baby(ies)
        else if(random == 2)
        {
            new_baby();
        }
        
        //boom in attendance
        else if(random == 3)
        {
            extra_revenue();
        }
        else
            cout << "Nothing special or horrible happened! Consider yourself lucky.... or not." << endl;
    }
    //premium food random event
    else if(whichfood == 2)
    {
        random_eventpremium();
    }
    //cheap food random event
    else
    {
        random_eventcheap();
    }
}

/*********************************************************************
 ** Function: random_eventcheeap
 ** Description: chooses a random event
 ** Parameters: none
 ** Pre-Conditions: functions need to exist
 ** Post-Conditions: none
 *********************************************************************/
void Zoo :: random_eventcheap(){
    cout << "Today something special or horrible might happen!" << endl;
    //random number the fourth one is for nothing special to happen
    int random = rand() % 6 + 1;
    cout << random << endl;
    //a random animal gets sick
    if(random == 1 || random == 4 || random == 5)
    {
        sick();
    }
    
    //random adult animal gets has (a) baby(ies)
    else if(random == 2)
    {
        new_baby();
    }
    
    //boom in attendance
    else if(random == 3)
    {
        extra_revenue();
    }
    //if random is 6
    else
        cout << "Nothing special or horrible happened! Consider yourself lucky.... or not." << endl;
}

/*********************************************************************
 ** Function: random_eventpremium
 ** Description: chooses a random event
 ** Parameters: none
 ** Pre-Conditions: functions need to exist
 ** Post-Conditions: none
 *********************************************************************/
void Zoo :: random_eventpremium(){
    cout << "Today something special or horrible might happen!" << endl;
    //random number the fourth one is for nothing special to happen
    int random = rand() % 8 + 1;
    cout << random << endl;
    //a random animal gets sick
    if(random == 1)
    {
        sick();
    }
    
    //random adult animal gets has (a) baby(ies)
    else if(random == 2 || random == 4 || random == 6)
    {
        new_baby();
    }
    
    //boom in attendance
    else if(random == 3 || random == 5)
    {
        extra_revenue();
    }
    
    //if random was 7 or 8
    else
        cout << "Nothing special or horrible happened! Consider yourself lucky.... or not." << endl;
}

/*********************************************************************
 ** Function: addmonkeyarray
 ** Description: increases monkey array x amt
 ** Parameters: int before
 ** Pre-Conditions: variable needs to exist
 ** Post-Conditions: none
 *********************************************************************/
void Zoo :: addmonkeyarray(int before){
    
    //creates a dynamically allocated array to store ages.
    Monkey * temp = new Monkey[monkeysize];
    
    //will circle through the arrays to store each monkeys information into age array
    for(int i = 0; i < before; i++)
    {
        temp[i] = m[i];
    }
    
    //first clears the monkey array
    delete[] m;
    
    //sets it equal to a new array of this size
    this->m = temp;
    
}

/*********************************************************************
 ** Function: add_monkey
 ** Description: adds x amt of monkeys to monkey array
 ** Parameters: int x
 ** Pre-Conditions: variable needs to exist
 ** Post-Conditions: none
 *********************************************************************/
void Zoo :: add_monkey(int x){
    //cout << " monkey size right now : " << this->monkeysize << endl;
    //gets the current size and places it in this int
    int before = this->get_monkeysize();
    
    //changes the size
    this->set_monkeysize(before + x);
    
    //changes the size of array which also adds a new animal
    this->addmonkeyarray(before);
    
    //cout << "new monkey size is: " << this->monkeysize << endl;
}

/*********************************************************************
 ** Function: take_monkey
 ** Description: takes 1 monkey from monkey array
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void Zoo :: take_monkey(int index){
    //gets the current size and places it in this int
    int before = this->get_monkeysize();
    
    //changes the size
    this->set_monkeysize(before - 1);
    
    //creates a dynamically allocated array to store monkeys.
    Monkey * temp = new Monkey[monkeysize];
    
    //index for the original monkey array
    int k = 0;
    
    //will circle through the arrays to store each monkey into temp
    for(int i = 0; i < before; i++)
    {
        if( i != index)
        {
            temp[k] = m[i];
            k++;
        }
    }
    
    //first clears the monkey array
    delete[] m;
    
    //sets it equal to a new array of this size
    this->m = temp;
    
    cout << "One of the monkeys has been removed from the zoo at age: " << m[index].get_age() << endl;
}

/*********************************************************************
 ** Function: addmonkeyarray
 ** Description: increases monkey array x amt
 ** Parameters: int before
 ** Pre-Conditions: variable needs to exist
 ** Post-Conditions: none
 *********************************************************************/
void Zoo :: addotterarray(int before){
    //creates a dynamically allocated array to store ages.
    Sea_otter * temp = new Sea_otter[ottersize];
    
    //will circle through the arrays to store each sea otters age into age array
    for(int i = 0; i < before; i++)
    {
        temp[i] = se[i];
    }
    
    //first clears the sea otter array
    delete[] se;
    
    //sets it equal to a new array of this size
    this->se = temp;
    
}

/*********************************************************************
 ** Function: add_otter
 ** Description: will add otter to otter array
 ** Parameters: int x
 ** Pre-Conditions: variable needs to exist
 ** Post-Conditions: none
 *********************************************************************/
void Zoo :: add_otter(int x){
    //cout << " otter size rn: " << this->ottersize << endl;;
    
    //gets the current size and places it in this int
    int before = this->get_ottersize();
    
    //changes the size
    this->set_ottersize(before + x);
    
    //changes the size of array which also adds a new animal
    this->addotterarray(before);
    
    //cout << "new otter size is: " << this->ottersize << endl;
}

/*********************************************************************
 ** Function: take_otter
 ** Description: takes one otter out
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void Zoo :: take_otter(int index){
    //gets the current size and places it in this int
    int before = this->get_ottersize();
    
    //changes the size
    this->set_ottersize(before - 1);
    
    //creates a dynamically allocated array to store otters.
    Sea_otter * temp = new Sea_otter[ottersize];
    
    //index for the original sea otter array
    int k = 0;
    
    //will circle through the arrays to store each sea otters into temp
    for(int i = 0; i < before; i++)
    {
        if( i != index)
        {
            temp[k] = se[i];
            k++;
        }
    }
    
    //first clears the sea otter array
    delete[] se;
    
    //sets it equal to a new array of this size
    this->se = temp;
    
    
    cout << "One of the Sea otters has been removed from the zoo at age: " << sl[index].get_age() << endl;
}

/*********************************************************************
 ** Function: addslotharray
 ** Description: increases monkey array x amt
 ** Parameters: int before
 ** Pre-Conditions: variable needs to exist
 ** Post-Conditions: none
 *********************************************************************/
void Zoo :: addslotharray(int before){
    //creates a dynamically allocated array to store ages.
    Sloth * temp = new Sloth[slothsize];
    
    //will circle through the arrays to store each sloths age into age array
    for(int i = 0; i < before; i++)
    {
        temp[i] = sl[i];
    }
    
    //first clears the sloth array
    delete[] sl;
    
    //sets it equal to a new array of this size
    this->sl = temp;
    
}

/*********************************************************************
 ** Function: add_sloth
 ** Description: will add a sloth to the sloth array
 ** Parameters: int x
 ** Pre-Conditions: variable needs to exist
 ** Post-Conditions: none
 *********************************************************************/
void Zoo :: add_sloth(int x){
    cout << " sloth size right now : " << this->slothsize << endl;
    
    //gets the current size and places it in this int
    int before = this->get_slothsize();
    
    //changes the size
    this->set_slothsize(before + x);
    
    //changes the size of array which also adds a new animal
    this->addslotharray(before);
    
    cout << "new sloth size is: " << this->slothsize << endl;
}

/*********************************************************************
 ** Function: add_sloth
 ** Description: takes one sloth
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void Zoo :: take_sloth(int index){
    //gets the current size and places it in this int
    int before = this->get_slothsize();
    
    //changes the size
    this->set_slothsize(before - 1);
    
    //creates a dynamically allocated array to store sloths.
    Sloth * temp = new Sloth[slothsize];
    
    //index for the original sloth array
    int k = 0;
    
    //will circle through the arrays to store each Sloth into temp
    for(int i = 0; i < before; i++)
    {
        if( i != index)
        {
            temp[k] = sl[i];
            k++;
        }
    }
    
    //first clears the sloth array
    delete[] sl;
    
    //sets it equal to a new array of this size
    this->sl = temp;
    
    cout << "One of the Sloths has been removed from the zoo at age: " << sl[index].get_age() << endl;
}


/*********************************************************************
 ** Function: sick
 ** Description: will choose a random animal to make 'sick' and then print out the cost and check if user has enough money in.
 ** Parameters: none
 ** Pre-Conditions: functions need to exist
 ** Post-Conditions: none
 *********************************************************************/
void Zoo :: sick(){
    //chooses a random species
    int randomspecies = rand() % 3 + 1;
    //will store age of animal i am checking
    int age;
    //will store random number for random index of animal
    int randomanimal = 0;
    
    //a monkey gets sick
    if(randomspecies == 1)
    {
        
        if(monkeysize > 0)
        {
            randomanimal = rand() % monkeysize;
            //gets the age of this animal
            age = m[randomanimal].get_age();
            if(age >= 30)
            {
                cout << "Oh no... one of your monkeys has become ill!" << endl << endl;
                cout << "A fee of $7,500 will be charged to your account, if your account does not have enough money to pay the $7,500 then this monkey will be removed from the zoo." << endl;
                if( get_bank() >= 7500 )
                {
                    this->bank -= 7500;
                    cout << "your bank account balance is now $" << bank << " after curing this monkey of sickness." << endl;
                }
                else
                {
                    take_monkey(randomanimal);
                    adultMonkey--;
                }
                
            }
            else
            {
                cout << "Oh no... one of your baby monkeys has become ill!" << endl << endl;
                cout << "A fee of $15,000 will be charged to your account, if your account does not have enough money to pay the $15,000 then this baby monkey will be removed from the zoo." << endl;
                
                if( get_bank() >= 15000 )
                {
                    this->bank -= 15000;
                    cout << "Your bank account balance is now $" << bank << " after curing this monkey of sickness." << endl;
                }
                else
                {
                    take_monkey(randomanimal);
                    numMonkeybaby--;
                }
                
            }
        }
        else
        {
            cout << "Lucky you today a random monkey was going to get sick but you don't have any monkeys!" << endl;
        }
    }
    
    //sea otter
    else if(randomspecies == 2)
    {
        if(ottersize > 0 )
        {
            randomanimal = rand() % ottersize;
            //gets the age of this animal
            age = se[randomanimal].get_age();
            if(age >= 30)
            {
                cout << "Oh no... one of your Sea otters has become ill!" << endl << endl;
                cout << "A fee of $2,500 will be charged to your account, if your account does not have enough money to pay the $2,500 then this sea otter will be removed from the zoo." << endl;
                
                if( get_bank() >= 2500 )
                {
                    this->bank -= 2500;
                    cout << "your bank account balance is now $" << bank << " after curing this sea otter of sickness." << endl;
                }
                else
                {
                    take_otter(randomanimal);
                    adultOtter--;
                }
                
            }
            else
            {
                cout << "Oh no... one of your baby Sea otters has become ill!" << endl << endl;
                cout << "A fee of $5,000 will be charged to your account, if your account does not have enough money to pay the $5,000 then this baby sea otter will be removed from the zoo." << endl;
                
                if( get_bank() >= 5000 )
                {
                    this->bank -= 5000;
                    cout << "your bank account balance is now $" << bank << " after curing this sea otter of sickness." << endl;
                }
                else
                {
                    take_otter(randomanimal);
                    numOtterbaby--;
                }
                
            }
        }
        else
            cout << "Lucky you today a random sea otter was going to get sick but you don't have any sea otters!" << endl;
    }
    //sloths
    else
    {
        if( slothsize > 0 )
        {
            randomanimal = rand() % slothsize;
            //gets the age of this animal
            age = sl[randomanimal].get_age();
            
            if(age >= 30)
            {
                cout << "Oh no... one of your sloths has become ill!" << endl << endl;
                cout << "A fee of $1,000 will be charged to your account, if your account does not have enough money to pay the $1,000 then this sloth will be removed from the zoo." << endl;
                
                if( get_bank() >= 1000 )
                {
                    this->bank -= 1000;
                    cout << "your bank account balance is now $" << bank << " after curing this sloth of sickness." << endl;
                }
                else
                {
                    take_sloth(randomanimal);
                    adultSloth--;
                }
                
            }
            else
            {
                cout << "Oh no... one of your baby sloths has become ill!" << endl << endl;
                cout << "A fee of $2,000 will be charged to your account, if your account does not have enough money to pay the $2,000 then this baby sloth will be removed from the zoo." << endl;
                if( get_bank() >= 2000 )
                {
                    this->bank -= 2000;
                    cout << "your bank account balance is now $" << bank << " after curing this sloth of sickness." << endl;
                }
                else
                {
                    take_sloth(randomanimal);
                    numSlothbaby--;
                }
                
            }
        }
        else
            cout << "Lucky you today a random sloth was going to get sick but you don't have any sloths!" << endl;
    }
    
}

/*********************************************************************
 ** Function: extra_revenue
 ** Description: will add random extra revenue per monkey
 ** Parameters: none
 ** Pre-Conditions: monkeys need to exist
 ** Post-Conditions: none
 *********************************************************************/
void Zoo :: extra_revenue(){
    cout << "There was a boom in attendance at the zoo today!! You made some extra money!" << endl << endl;
    
    cout << "Each monkey you have will make an extra amount between $250 to $500." << endl;
    //will add up total amount of extra money made
    int total = 0;
    
    //will hold temp amount of money per iteration
    int temp = 0;
    
    //checks if monkeys exist
    if(monkeysize > 0){
        //will circle through the monkey array
        for(int i = 0; i < monkeysize; i++)
        {
            temp = m[i].extrarevenue();
            total += temp;
            bank += temp;
        }
    }
    cout << "The total amount of extra revenue you made today was: $" << total << endl << endl;
}

/*********************************************************************
 ** Function: new_baby
 ** Description: will randomly choose a species and check for adults in that species and then add a new animal (or more depending on which species) of that species.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: new baby species added
 *********************************************************************/
void Zoo :: new_baby(){
    //stores a random number from 1-3 for the different species
    int randomspecies = rand() % 3 + 1;
    
    //is goin to store age of random animal
    int age;
    
    //index to circle through array to find monkey
    int i = 0;
    
    //will be set true when adult animal is found
    bool adultspecies = false;
    
    //monkey has baby
    if( randomspecies == 1 )
    {
        if( monkeysize > 0 )
        {
            while( !adultspecies && i < monkeysize ){
                //gets the age of this animal
                age = m[i].get_age();
                
                if(age >= 1095)
                {
                    adultspecies = true;
                    
                    cout << "Congratulations! A new Monkey has been born!" << endl;
                    cout << "A baby animal will eventually grow up and become an adult but thats not going to happen for a while..." << endl << endl;
                    //adds a new mokey
                    this->add_monkey(1);
                    //getting the index of last monkey in array which would be the new monkey
                    int index = get_monkeysize()-1;
                    //upping the amount of babies
                    this->numMonkeybaby++;
                    //maaking new monkey into baby
                    m[index].set_age(0);
                }
                i++;
            }
        }
        else
            cout << "Unlucky you! Baby monkeys could have been born today but you currently have no monkeys or no adult monkeys in your zoo... oh well." << endl << endl;
    }
    // sea otter has two babies.
    else if( randomspecies == 2 )
    {
        if( ottersize >0)
        {
            while( !adultspecies && i < ottersize ){
                //gets the age of this animal
                age = se[i].get_age();
                
                if(age >= 1095)
                {
                    adultspecies = true;
                    
                    cout << "Congratulations! Two new Sea otters has been born!" << endl << endl;
                    cout << "A baby animal will eventually grow up and become an adult but thats not going to happen for a while..." << endl << endl;
                    //addings two new otters
                    this->add_otter(2);
                    //just the index of the last animal.
                    int index = get_ottersize()-1;
                    //upping the amount of babies
                    this->numOtterbaby += 2;
                    //making new sea otters into babies.
                    se[index].set_age(0);
                    se[index-1].set_age(0);
                }
                i++;
            }
        }
        else
            cout << "Unlucky you! Baby sea otters could have been born today but you currently have no sea otters or no adult sea otters in your zoo... oh well." << endl << endl;
    }
    //sloth has three babiies.
    else
    {
        if( slothsize > 0)
        {
            while( !adultspecies && i < slothsize ){
                //gets the age of this animal
                age = sl[i].get_age();
                
                if(age >= 1095)
                {
                    adultspecies = true;
                    
                    cout << "Congratulations! Three new Sloths has been born!" << endl << endl;
                    cout << "A baby animal will eventually grow up and become an adult but thats not going to happen for a while..." << endl << endl;
                    //adding three new sloths
                    this->add_sloth(3);
                    //just the index of the last animal
                    int index = get_slothsize() - 1;
                    //upping amount of babies
                    this->numSlothbaby += 3;
                    //making he new sloths into babies.
                    sl[index].set_age(0);
                    sl[index-1].set_age(0);
                    sl[index-2].set_age(0);
                }
                i++;
            }
        }
        else
            cout << "Unlucky you! Baby sloths could have been born today but you currently have no sloths or no adult sloths in your zoo... oh well." << endl << endl;
    }
    
}

/*********************************************************************
 ** Function: welcome
 ** Description: is called in the beginning and starts the game.
 ** Parameters: none
 ** Pre-Conditions: variable needs to exist
 ** Post-Conditions: creates the game
 *********************************************************************/
void Zoo :: welcome(){
    //welcoming user
    cout << "Welcome to the Zoo! You are now in pocession of an emoty zoo with a Monkey exhibit, Sea otter exhibit, and Sloth exhibit. You will have exaclty $100,000 dollars in your bank account!" << endl << endl;
    
    //explaining what happens each day
    cout << "In this game, everyday your animals will grow one day in age, in the beginning of the day they will be fed food, and at the end they will have made revenue (which goes into your bank account)." << endl << endl;
    
    //explaining the food costs.
    cout << "There are three different types of food. First being the regular type which costs the same as the basefood per day. The base food cost changes randomly to a number 75% to 125% of the cost from the day before. On the first day the base food will start out as $50. Second is the premium type which costs twice as much as regular food for all animals, but it reduces the probability of sickness by half. Third being the cheap type which costs half as much as regular food for all animals, but it doubles the probability that an animal will get sick. " << endl << endl;
    
    //starting the day
    cout << "Today is the first day!" << endl << endl;
    
    cout << "Name your Zoo below: " << endl;
    
    //will hold user input of name of zoo
    string nameofzoo = "";
    cin >> nameofzoo;
    
    cout << "That name is interesting! Your zoo will now be called " << this->nameofzoo << endl;
    
    cout << "monkey: " << this->monkeysize << " sloth: " << this->slothsize << " otter: " << this->ottersize << endl;
    
    /* created a boolean so i can circle back to the first if statement if the input
     * is wrong
     */
    bool validinput = true;
    
    //will circle through the if's again if the boolean error returns false
    do
    {
        cout << "Would you like to buy any new animals today? (y or n)" << endl;
        
        //for when it circles through again to make sure the variable changes to true.
        validinput = true;
        
        //created a string to take a y or n for whether or not user wants new animals.
        string newanimal = "";
        cin >> newanimal;
        
        if( newanimal == "y")
        {
            
            /* created a boolean so i can circle back to the first if statement if the
             * input was wrong.
             */
            bool error = true;
            
            //will circle through the if's again if the boolean error returns false
            do
            {
                cout << "You can choose one species of animals ( Monkeys $15,000, Sea otters $5,000, or Sloths $2,000) and buy 1 or 2 animals of that species. Please type in which species you want to buy from: ('Monkey'/'Otter'/'Sloth') " << endl;
                
                //for when the code circles through again due to bad input
                error = true;
                
                //created a string to take user input for what kind of species they want
                string species = "";
                cin >> species;
                
                if ( species == "Monkeys" || species == "monkeys" || species == "monkey"  || species == "Monkey" )
                    this->asking_monkey();
                
                else if( species == "otter" || species == "otters" || species == "Otters" || species == "Otter" )
                    this->asking_otter();
                
                else if( species == "Sloth" || species == "sloth" || species == "sloths" || species == "Sloths" )
                    this->asking_sloth();
                
                else
                {
                    errormessage();
                    error = false;
                }
                
            } while( !error );
            //end of 2nd do
        }
        else if( newanimal == "n")
            cout << "You have chosen to not add any new animals today." << endl << endl;
        else
        {
            validinput = false;
            errormessage();
        }
    } while( !validinput );
    //end of 1st do
    
    cout << "Have fun! Don't go bankrupt or else the game will end!" << endl << endl;
}

/*********************************************************************
 ** Function: endday
 ** Description: will end each day and return a boolean that is true is the user wants to continue and false if the user wants to quit
 ** Parameters: none
 ** Pre-Conditions: functions need to exist
 ** Post-Conditions: none
 *********************************************************************/
bool Zoo :: endday(){
    cout << "Day " << this->days << " of " << this->nameofzoo << endl;
    cout << endl;
    cout << setprecision(2) << fixed;
    cout << "Balance in Bank: $" << this->bank << endl;
    
    cout << "Monkey Population: (adult(age 1095+ days)/baby(age 0 - 30 days)) " << this->adultMonkey << "/" << this->numMonkeybaby << endl;
    cout << "Sea otter Population: (adult(age 1095+ days)/baby(age 0 - 30 days)) " << this->adultOtter << "/" << this->numOtterbaby << endl;
    cout << "Sloth Population: (adult(age 1095+ days)/baby(age 0 - 30 days)) " << this->adultSloth << "/" << this->numSlothbaby << endl;
    cout << "Total number of animals in zoo "<< monkeysize + ottersize + slothsize << endl << endl;
    
    cout << "monkey: " << this->monkeysize << " sloth: " << this->slothsize << " otter: " << this->ottersize << endl;
    
    /* created a boolean so i can circle back to the first if statement if the input
     * is wrong
     */
    bool validinput = true;
    
    //will circle through the if's again if the boolean error returns false
    do
    {
        cout << "Would you like to buy any new animals today? (y or n)" << endl;
        //for when it circles through again to make sure the variable changes to true.
        validinput = true;
        
        //created a string to take a y or n for whether or not user wants new animals.
        string newanimal = "";
        cin >> newanimal;
        
        if( newanimal == "y")
        {
            
            /* created a boolean so i can circle back to the first if statement if the
             * input was wrong.
             */
            bool error = true;
            
            //will circle through the if's again if the boolean error returns false
            do
            {
                cout << "You can choose one species of animals ( Monkeys $15,000, Sea otters $5,000, or Sloths $2,000) and buy 1 or 2 animals of that species. Please type in which species you want to buy from: ('Monkey'/'Otter'/'Sloth') " << endl;
                
                //for when the code circles through again due to bad input
                error = true;
                
                //created a string to take user input for what kind of species they want
                string species = "";
                cin >> species;
                
                if ( species == "Monkeys" || species == "monkeys" || species == "monkey"  || species == "Monkey" )
                    this->asking_monkey();
                
                else if( species == "otter" || species == "otters" || species == "Otters" || species == "Otter" )
                    this->asking_otter();
                
                else if( species == "Sloth" || species == "sloth" || species == "sloths" || species == "Sloths" )
                    this->asking_sloth();
                
                else
                {
                    errormessage();
                    error = false;
                }
                
            } while( !error );
            //end of 2nd do
        }
        else if( newanimal == "n")
            cout << "You have chosen to not add any new animals today." << endl << endl;
        else
        {
            validinput = false;
            errormessage();
        }
    } while( !validinput );
    //end of 1st do
    
    //reusing the boolean from before
    validinput = true;
    
    do
    {
        cout << "Would you like to continue playing? (y/n)" << endl;
        
        //for when the code circles through again due to bad input
        validinput = true;
        
        
        //created a string to hold user input
        string answer;
        cin >> answer;
        
        if(answer == "y")
            return true;
        else if( answer == "n")
            return false;
        else
        {
            errormessage();
            validinput = false;
        }
    } while( !validinput );
    
}

/*********************************************************************
 ** Function: asking_monkey
 ** Description: is called when the user inputs they want monkeys in welcome or endday
 ** Parameters: none
 ** Pre-Conditions: functions need to exist
 ** Post-Conditions: add monkeys to zoo
 *********************************************************************/
void Zoo :: asking_monkey(){
    /* created boolean so i can circle through the if statements again if
     * the user inputs an int that isnt 1 or 2 so they can reenter it.
     */
    bool error2 = true;
    
    //will circle through the if's again if the boolean error returns false
    do
    {
        cout << "You have chosen Monkey, how many monkeys would you like? Remember that Monkeys normal food cost would be 4 times the basefood cost and if and when a monkey gets sick it would cost half of its intial cost to nurse back ($7,500). A monkey makes 10% of its intial cost in revenue per day ($1,500). Please enter 1 or 2: " << endl;
        //for when the code circles through again due to bad input
        error2 = true;
        
        //created int to let user choose how many animals they want
        int howmany = 0;
        cin >> howmany;
        
        if( howmany == 1)
        {
            this->add_monkey(1);
            
            //ups the adult amount
            this->adultMonkey++;
            
            //minuses the cost
            this->bank -= m[0].get_cost();
        }
        else if(howmany == 2)
        {
            this->add_monkey(2);
            
            //ups the adult amount
            this->adultMonkey += 2;
            
            //minuses the cost
            this->bank -= m[0].get_cost() * 2;
        }
        else
        {
            errormessage();
            error2 = false;
        }
    } while( !error2 );
    //end of the do
}

/*********************************************************************
 ** Function: asking_otter
 ** Description: is called when user asks for otters
 ** Parameters: none
 ** Pre-Conditions: functions needs to exist
 ** Post-Conditions: adds otters to zoo
 *********************************************************************/
void Zoo :: asking_otter(){
    /* created boolean so i can circle through the if statements again if
     * the user inputs an int that isnt 1 or 2 so they can reenter it.
     */
    bool error2 = true;
    
    //will circle through the if's again if the boolean error returns false
    do
    {
        cout << "You have chosen Sea otters, how many sea otters would you like? Remember that Sea otters normal food cost would be 2 times the basefood cost and if and when a sea otter gets sick it would cost half of its intial cost to nurse back ($2,500). A sea otter makes 5% of its intial cost in revenue per day ($250). Please enter 1 or 2: " << endl;
        //for when the code circles through again due to bad input
        error2 = true;
        
        //created int to let user choose how many animals they want
        int howmany = 0;
        cin >> howmany;
        
        if( howmany == 1)
        {
            this->add_otter(1);
            
            //ups the adult amount
            this->adultOtter++;
            
            //minuses the cost
            this->bank -= se[0].get_cost();
        }
        else if(howmany == 2)
        {
            this->add_otter(2);
            
            //ups the adult amount
            this->adultOtter += 2;
            
            //minuses the cost
            this->bank -= se[0].get_cost() * 2;
        }
        else
        {
            errormessage();
            error2 = false;
        }
    } while( !error2 );
    //end of the do
}

/*********************************************************************
 ** Function: asking_sloth
 ** Description: is called when user asks for sloths
 ** Parameters: none
 ** Pre-Conditions: functions needs to exist
 ** Post-Conditions: adds sloths to zoo
 *********************************************************************/
void Zoo :: asking_sloth(){
    /* created boolean so i can circle through the if statements again if
     * the user inputs an int that isnt 1 or 2 so they can reenter it.
     */
    bool error2 = true;
    
    //will circle through the if's again if the boolean error returns false
    do
    {
        cout << "You have chosen Sloth, how many sloths would you like? Remember that Sloths normal food cost would be the basefood cost and if and when a sloth gets sick it would cost half of its intial cost to nurse back ($1,000). A sloth makes 5% of its intial cost in revenue per day ($100). Please enter 1 or 2: " << endl;
        
        //for when the code circles through again due to bad input
        error2 = true;
        
        //created int to let user choose how many animals they want
        int howmany = 0;
        cin >> howmany;
        
        if( howmany == 1)
        {
            this->add_sloth(1);
            
            //ups the adult amount
            this->adultSloth++;
            
            //minuses the cost
            this->bank -= se[0].get_cost();
        }
        else if(howmany == 2)
        {
            this->add_sloth(2);
            
            //ups the adult amount
            this->adultSloth += 2;
            
            //minuses the cost
            this->bank -= se[0].get_cost() * 2;
        }
        else
        {
            errormessage();
            error2 = false;
        }
    } while( !error2 );
    //end of do
}


/*********************************************************************
 ** Function: erorr
 ** Description: prints out error message when called
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void Zoo :: errormessage(){
    cout << "What you have entered is incorrect please try again." << endl << endl;
}

/*bool Zoo :: validinputstring(string in){
 if( in == ""){
 return false;
 }
 for( char c : in)
 {
 int ascii = int(c);
 if( ascii < 48 || ascii > 57)
 {
 return false;
 }
 }
 return true;
 }
 */
