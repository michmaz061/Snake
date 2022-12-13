#include <iostream>
#include <windows.h>
#include "Point.h"
#define MAXSNAKESIZE 1104
#define MAXFRAMEXSIZE 50
#define MAXFRAMEYSIZE 25
using namespace std;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;
void gotoxy(int x, int y){
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(console, CursorPosition);
}
Point::Point(){
        x=y=10;
    }
   Point::Point(int x,int y){
        this -> x=x;
        this -> y=y;
    }
    void Point::SetPoint(int x,int y)
    {
        this -> x=x;
        this -> y=y;
    }
    int Point::GetX() const{
        return x;
    }
    int Point::GetY() const{
        return y;
    }
    void Point::MoveUp()
    {
        y--;
        if(y<1)
            y=MAXFRAMEYSIZE;
    }
    void Point::MoveDown()
    {
        y++;
        if(y>MAXFRAMEYSIZE)
            y=1;
    }
    void Point::MoveLeft()
    {
        x--;
        if(x<1)
            x=MAXFRAMEXSIZE-1;
    }
    void Point::MoveRight()
    {
        x++;
        if(x>MAXFRAMEXSIZE-1)
            x=1;
    }
    void Point::Draw(char ch) const {
        gotoxy(x,y);
        cout << ch;
    }
    void Point::CopyPos(Point * p) const{
        p->x=x;
        p->y=y;

    }
    int Point::Equal(Point * p) const{
        if(p->x == x && p->y == y)
            return 1;
        return 0;
    }

     void Point::Debug(int s){
        cout<<"     Your score is: "<<s-1;
    }