//File: CReadFile.h

//This class opens the input file and reads in the list of films into 2
//seperate stacks, an even stack and an odd stack depending on the
//order in the file.


#pragma once
#include <string>
#include <fstream>
#include <stack>
#include <QFile>
#include <QString>
#include <QDebug>

class CReadFile
{
private:
    std::stack<std::string> stack_even;  //Stack for storing even movie titles
    std::stack<std::string> stack_odd;   //Stack for storing odd movie titles
public:
    void setEven(std::string title);    //Set and get functions for stacks
	void setOdd(std::string title);
    std::string getEven();
    std::string getOdd();
    void readTitles(QString filename); //Reads titles into stacks with filename passed
    int getEvenSize();         //These 2 functions return size of stack, returns 0 if empty
    int getOddSize();
};

