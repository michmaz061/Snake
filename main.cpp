#include <conio.h>
#include <windows.h>
#include <ctime>
#include "Point.h"
#include "Snake.h"
using namespace std;
int main()
{
    SetConsoleTitleA( "Snake The Game" );
    srand((unsigned)time(nullptr));
    Snake snake;
    char op = '1';
	do{
	    if(kbhit()){
	        op=getch();
	    }

	    switch(op){
	        case 'w':
	        case 'W':
            Snake::TurnUp();
            break;

	        case 's':
	        case 'S':
                Snake::TurnDown();
                break;

	        case 'a':
	        case 'A':
                Snake::TurnLeft();
                break;

	        case 'd':
	        case 'D':
                Snake::TurnRight();
                break;
	        default:
                break;
	   }
        snake.Move();

	}while(op != 'e');
	
	return 0;
}