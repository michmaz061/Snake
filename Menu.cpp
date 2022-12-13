#include <iostream>
#include <conio.h>
#include <ctime>
#include <chrono>
#include <fstream>
#include "Menu.h"
#define MAXSNAKESIZE 1104
#define MAXFRAMEXSIZE 50
#define MAXFRAMEYSIZE 25
using namespace std;
int Menu::size;
int Menu::begin=0;
int Menu::health=0;


void Menu::Frame(){
    for (int i=0;i<MAXFRAMEXSIZE+1;i++)
        cout<<'#';
    cout<<endl;
    for (int i=0;i<MAXFRAMEYSIZE;i++)
    {
        for (int j=0;j<MAXFRAMEXSIZE;j++)
        {
            if(j == 0)
                cout<<'#';
            else
                cout<<' ';
            if(j==MAXFRAMEXSIZE-1)
                cout<<'#';
        }
        cout<<endl;
    }
    for (int i=0;i<MAXFRAMEXSIZE+1;i++)
        cout<<'#';
}
void Menu::WelcomeScreen() {
    cout<<"    Y\n"
          "  .-^-.\n"
          " /     \\      .- ~ ~ -.\n"
          "()     ()    /   _ _   `.                     _ _ _\n"
          " \\_   _/    /  /     \\   \\                . ~  _ _  ~ .\n"
          "   | |     /  /       \\   \\             .' .~       ~-. `.\n"
          "   | |    /  /         )   )           /  /             `.`.\n"
          "   \\ \\_ _/  /         /   /           /  /                `'\n"
          "    \\_ _ _.'         /   /           (  (\n"
          "                    /   /             \\  \\\n"
          "                   /   /               \\  \\\n"
          "                  /   /                 )  )\n"
          "                 (   (                 /  /\n"
          "                  `.  `.             .'  /\n"
          "                    `.   ~ - - - - ~   .'\n"
          "                       ~ . _ _ _ _ . ~"<<endl;
}
void Menu::SetHealth(int h){
    health = h;
}
void Menu::SetSize(int s){
    size=s;
}
int Menu::GetSize(){
    return size;
}
ofstream& operator<< (ofstream& os, const Menu& obj){
    return os;
}
void Menu::GameScreen(){
    if(health == 0){
        if(!begin) {

            cout << "Press any key to start\n";
            WelcomeScreen();
            getch();
            health = 1;
            begin=1;
            SetSize(1);

        }
        else{
            tt = std::chrono::system_clock::to_time_t ( now );
            file.open ("HighScore.txt",ios::out|ios::app);
            file<<"Your score was: "<<size-1<<" "<<ctime(&tt)<<endl;
            cout << "Game Over\n";
            cout << "Press any key to restart\n";
            getch();
            health = 1;
            SetSize(1);
            file.close();
        }
    }

}

