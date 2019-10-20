#include "TaskOneLogic.hpp"
#include <QtMath>


TaskOneLogic::TaskOneLogic() : a(0), b(0), c(0), desc(0), x1(0), x2(0), x(0){}

TaskOneLogic::~TaskOneLogic(){}


// setters
void TaskOneLogic::set_a(int & aOutside)
{
    a = aOutside;
}

void TaskOneLogic::set_b(int & bOutside)
{
    b = bOutside;
}

void TaskOneLogic::set_c(int & cOutside)
{
    c = cOutside;
}

// counts

void TaskOneLogic::count_Desc()
{
    desc = qPow(b,2) - 4 * a * c;
}

void TaskOneLogic::count_XOne()
{
    x1 = (-b + qSqrt(desc)) / (2 * a);
}

void TaskOneLogic::count_XTwo()
{
    x2 = (-b - qSqrt(desc)) / (2 * a);
}

void TaskOneLogic::count_XSample()
{
    x = -b / (2 * a);
}

// getters

int TaskOneLogic::get_a() const
{
    return a;
}

int TaskOneLogic::get_b()  const
{
    return b;
}

int TaskOneLogic::get_c()  const
{
    return c;
}

int TaskOneLogic::get_desc() const
{
    return desc;
}

float TaskOneLogic::get_x1() const
{
    return x1;
}

float TaskOneLogic::get_x2() const
{
    return x2;
}

float TaskOneLogic::get_x()  const
{
    return x;
}
