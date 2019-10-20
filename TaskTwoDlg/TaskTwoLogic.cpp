#include "TaskTwoLogic.hpp"

#include <qmath.h>

TaskTwoLogic::TaskTwoLogic() : ABSide(0), ACSide(0), CornerA(0)
{}

TaskTwoLogic::~TaskTwoLogic(){}

void TaskTwoLogic::setABSide(int &ABSideTemp)
{
    ABSide = ABSideTemp;
}

void TaskTwoLogic::setACSide(int &ACSideTemp)
{
    ACSide = ACSideTemp;
}

void TaskTwoLogic::setCorner(int &CornerTemp)
{
    CornerA = CornerTemp;
}

void TaskTwoLogic::setCornerRadian(bool isRadian)
{
    cornerRadian = isRadian;
}

int TaskTwoLogic::getBCSide()
{
    return BCSide;
}


void TaskTwoLogic::CountBCSide()
{
    if(cornerRadian)
        CornerA = CornerA * (180 / 3.14);

    BCSide = qSqrt(pow(ABSide,2) + (pow(ACSide,2) - 2 * ABSide * ACSide * qCos(CornerA)));
}
