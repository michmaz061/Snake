#ifndef MAIN_CPP_HEAD_H
#define MAIN_CPP_HEAD_H
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>
#include <fstream>
#include <chrono>
using namespace std;

class Point
{
private:
    /// coordinate X
     int x;
    /// coordinate Y
     int y;
protected:
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
public:
    Point();
    Point(int x,int y);
    /// sets point at (x,y)
    void SetPoint(int x,int y);
    /// gets value of x
    int GetX() const;
    /// gets value of y
    /* TASK
    Point & operator++(){
        ++y;
        ++x;
        return *this;
    }
     Point & operator++(int){
        Point other(*this);
        ++y;
        ++x;
        return other;

    }
    */
    int GetY() const;
    /// moves snake upward
    void MoveUp();
    /// moves snake downward
    void MoveDown();
    /// moves snake left
    void MoveLeft();
    /// moves snake right
    void MoveRight();
    /// draws snake and fruit
    void Draw(char ch) const;
    /// copy position of head
    void CopyPos(Point * p) const;
    ///checks if head is touching body
    int Equal(Point * p) const;
    /// tells you your score
    virtual void Debug(int s);
};

#endif //MAIN_CPP_HEAD_H
