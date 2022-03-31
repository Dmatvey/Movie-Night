//File: CRandom.h

//This class chooses a random selection of  a movie title from the even stack or odd stack
//depending on whether user enters and odd or even number

#pragma once
#include <string>
#include <fstream>
#include <stack>
#include "CReadFile.h"
class CRandom
{
private:
    CReadFile* Readfile;
    std::stack<std::string> stack_random;   //This stack will be used to store movie titles temporarily
    bool isEven;    //Boolean for selecting odd or even stack
public:
    CRandom(CReadFile* readfile);   //Constructor
    void setIsEven(bool even);    //Set and get functions for isEven boolean
    bool getIsEven();
    int randomNumber(int inputNumber);    //inputNumber passed from user input, returns a random number for selections
    std::string selectTitle(int num);    //Random number from previous function used to select movie title

};

