#ifndef TASK_ONE_LOGIC_HPP
#define TASK_ONE_LOGIC_HPP


class TaskOneLogic
{
public:
    TaskOneLogic();
    ~TaskOneLogic();

    void set_a(int & aOutside);
    void set_b(int & bOutside);
    void set_c(int & cOutside);

    void count_Desc();
    void count_XOne();
    void count_XTwo();
    void count_XSample();

    int get_a()     const;
    int get_b()     const;
    int get_c()     const;
    int get_desc()  const;
    float get_x1()  const;
    float get_x2()  const;
    float get_x()   const;

private:
    int a, b, c;
    int desc;
    float x1, x2, x;

};
#endif
