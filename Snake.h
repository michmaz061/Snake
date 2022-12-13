#ifndef HEAD_CPP_SNAKE_H
#define HEAD_CPP_SNAKE_H
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>
#include <fstream>
#include <chrono>
#include "Snake.h"
#include "Menu.h"
#include "Point.h"
#define MAXSNAKESIZE 1104
#define MAXFRAMEXSIZE 50
#define MAXFRAMEYSIZE 25
using namespace std;
class Snake:protected Menu,protected Point
{
private:
    /// array of points that represent snake
    Point * cell[MAXSNAKESIZE];
    /// current direction of snake
    static char dir;
    /// object of Point class
    Point fruit;
    /// shows how fast is snake moving
    static int speed;
public:
    Snake();
    ~Snake();
    void AddCell(int x,int y);
    /// change direction of snake upward
    static void TurnUp();
    /// change direction of snake downward
    static void TurnDown();
    /// change direction of snake left
    static void TurnLeft();
    /// change direction of snake right
    static void TurnRight();
    /// function responsible for the movement of the snake
    void Move();
    ///checks if head is touching any point of body and says if you lost
    int SelfCollision();
    /// works with another Debug() to tell your score
    void Debug();
};
#endif //HEAD_CPP_SNAKE_H
