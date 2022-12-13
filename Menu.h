#ifndef HEAD_CPP_MENU_H
#define HEAD_CPP_MENU_H
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>
#include <fstream>
#include <chrono>
#define MAXSNAKESIZE 1104
#define MAXFRAMEXSIZE 50
#define MAXFRAMEYSIZE 25
using namespace std;
class Menu
{
private:
    /// current size of snake
    static int size;
    /// shows if you are playing or not
    static int begin;
    /// shows if snake is dead or alive
    static int health;
protected:
    fstream file;
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    std::time_t tt;
public:
    friend ofstream & operator<< (ofstream & os, Menu & obj);
    /// draws a frame around the board
    static void Frame();
    /// setting state of game
    static void SetHealth(int h);
    /// setting size of snake
    static void SetSize(int s);
    /// gets size of snake
    static int GetSize();
    /// checking is it start or game over
    void GameScreen();
    /// draws a snake made from ascii at start
    static void WelcomeScreen();
};
#endif //HEAD_CPP_MENU_H
