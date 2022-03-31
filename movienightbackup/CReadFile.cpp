//File: CReadFile.cpp

#include <fstream>
#include <iostream>
#include <QFile>
#include <QString>
#include <QDebug>
#include <stdlib.h>
#include "CReadFile.h"

void CReadFile::setEven(std::string title)
{
	stack_even.push(title);
}

void CReadFile::setOdd(std::string title)
{
	stack_odd.push(title);
}

void CReadFile::readTitles(QString filename)
{
    int count = 0;
    QFile mFile(filename); //File directory passed to mFile
    if (!mFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
       qDebug() << "Could not open file for reading!";
       return;
    }
    QTextStream in(&mFile);
    while(!in.atEnd())  //Loop continues until at end of file
    {
        QString DataAsString = in.readLine();  //File read in line by line
        count++;    //counter variable determines if title is read into even or odd stack
        if(count%2 == 0)   //Even stack
        {
            setEven(DataAsString.toStdString());
        }
        else               //Odd stack
        {
            setOdd(DataAsString.toStdString());
        }
    }
    mFile.close();
}

std::string CReadFile::getEven()
{
    std::string pop = stack_even.top();  //Returns title from stack
	stack_even.pop();
	return pop;
}

std::string CReadFile::getOdd()
{
    std::string pop = stack_odd.top();    //Returns title from stack
	stack_odd.pop();
	return pop;
}
int CReadFile::getEvenSize()    //Returns size of stack, 0 if empty
{
    if(!stack_even.empty())
        return stack_even.size();
    else
        return 0;
}
int CReadFile::getOddSize()     //Returns size of stack, 0 if empty
{
    if(!stack_odd.empty())
        return stack_odd.size();
    else
        return 0;
}

