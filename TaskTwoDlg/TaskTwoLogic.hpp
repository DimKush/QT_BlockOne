#ifndef TASK_TWO_LOGIC_HPP
#define TASK_TWO_LOGIC_HPP


class TaskTwoLogic
{
public:
     TaskTwoLogic();
    ~TaskTwoLogic();

     void setABSide(int &);
     void setACSide(int &);
     void setCorner(int &);
     void setCornerRadian(bool isRadian);

     int getBCSide();

     void CountBCSide();

private:
     float ABSide, ACSide, BCSide;
     float CornerA;
     bool cornerRadian;
};



#endif
