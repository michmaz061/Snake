#include <iostream>
#include <windows.h>
#include "Snake.h"
#define MAXSNAKESIZE 1104
#define MAXFRAMEXSIZE 50
#define MAXFRAMEYSIZE 25
using namespace std;
char Snake::dir;
int Snake::speed=100;

Snake::Snake(){
    cell[0]= new Point(20,20);
    for(int i=1;i<MAXSNAKESIZE;i++){
        cell[i]=nullptr;
    }
    fruit.SetPoint(1+(rand()%((MAXFRAMEXSIZE)-2)),1+(rand()%((MAXFRAMEYSIZE)-2)));
}
Snake::~Snake(){
    delete cell[0];
}
void Snake::AddCell(int x,int y){
    int size = GetSize();
    cell[size++]=new Point(x,y);
    SetSize(size);
}
void Snake::TurnUp(){
    if(dir != 's')
        dir='w';
}
void Snake::TurnDown(){
    if(dir != 'w')
        dir='s';
}
void Snake::TurnLeft(){
    if(dir != 'd')
        dir='a';
}
void Snake::TurnRight(){
    if(dir != 'a')
        dir='d';
}
void Snake::Move(){
    system("cls");
    GameScreen();
    for(int i=GetSize()-1;i>0;i--){
        cell[i-1]->CopyPos(cell[i]);
    }
    SetConsoleTextAttribute(console,9);
    Frame();
    SetConsoleTextAttribute(console,10);
    Debug();
    switch(dir){
        case 'w':
            cell[0]->MoveUp();
            break;
        case 's':
            cell[0]->MoveDown();
            break;
        case 'a':
            cell[0]->MoveLeft();
            break;
        case 'd':
            cell[0]->MoveRight();
            break;
        default:
            break;
    }

    if (SelfCollision())
        SetHealth(0);

    if(fruit.GetX() == cell[0]->GetX() && fruit.GetY() == cell[0]->GetY()){
        AddCell(-1,0);
        fruit.SetPoint(1+(rand()%((MAXFRAMEXSIZE)-2)),1+(rand()%((MAXFRAMEYSIZE)-2)));
        if(speed!=0)
            speed -= 1;
    }
    for(int i=0;i<GetSize();i++)
        cell[i]->Draw('0');
    SetConsoleTextAttribute(console,12);
    fruit.Draw('@');
    Sleep(speed);
}
int Snake::SelfCollision(){
    for(int i=1;i<GetSize();i++)
        if (cell[0]->Equal(cell[i]))
            return 1;
    return 0;

}

void Snake::Debug(){
    cell[0]->Debug(GetSize());
}

