

#include "CRandom.h"
#include <stdlib.h>
#include <stack>

CRandom::CRandom(CReadFile* readfile)
{
    Readfile =readfile;
}

int CRandom::randomNumber(int inputNumber)
{
    int  random_number = 0, min = 1, max = 0;
    int option = 0;
    bool evenIsEmpty = false;
    bool oddIsEmpty = false;
    if(Readfile->getEvenSize() == 0)
        evenIsEmpty = true;
    if(Readfile->getOddSize() == 0)
        oddIsEmpty = true;
    if(inputNumber%2 == 0 && !evenIsEmpty )
        option = 1;
    if(inputNumber%2 == 0 && evenIsEmpty && !oddIsEmpty)
        option = 2;
    if(inputNumber%2 != 0 && !oddIsEmpty)
        option = 2;
    if(inputNumber%2 != 0 && oddIsEmpty && !evenIsEmpty)
        option = 1;
    if(inputNumber%2 == 0 && oddIsEmpty && evenIsEmpty)
        option = 3;
    if(inputNumber%2 != 0 && oddIsEmpty && evenIsEmpty)
        option = 3;
    switch(option)
    {
        case 1:
        {
            max = Readfile->getEvenSize();
            random_number = rand() % max + min;
            isEven = true;
                    break;
        }
        case 2:
        {
            max = Readfile->getOddSize();
            random_number = rand() % max + min;
            isEven = false;
            break;
        }
        case 3:
        {
            random_number = -1;
            break;
        }
    }
    return random_number;
}
std::string CRandom::selectTitle(int num)
{
    std::string chosenTitle;
    if(num != -1)
    {
        if((getIsEven() == true))
        {
            while(num != 0)
            {
                stack_random.push(Readfile->getEven());
                num--;
            }
        }
        else
        {
            while(num != 0)
            {
                stack_random.push(Readfile->getOdd());
                num--;
            }
        }
    }
    else
    {
       chosenTitle = "No other available films!";
       return chosenTitle;
    }
    chosenTitle = stack_random.top();
    stack_random.pop();
    if(getIsEven() == true)
    {
        while(!stack_random.empty())
        {
            Readfile->setEven(stack_random.top());
                    stack_random.pop();
        }
    }
    if(getIsEven() == false)
    {
        while(!stack_random.empty())
        {
            Readfile->setOdd(stack_random.top());
                    stack_random.pop();
        }
    }
    return chosenTitle;
}

void CRandom::setIsEven(bool even)
{
    isEven = even;
}
bool CRandom::getIsEven()
{
    return isEven;
}
