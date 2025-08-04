///Sammy Hummel
//jul 28 2025
//maze game? movement? idk, grid with moving char
#include <stdio.h>
#include <stdlib.h>
#include <time.h> //for rnd
#ifdef _WIN32
#include <conio.h>
char getch() {
    return _getch();
}
#else
#include <termios.h>
#include <unistd.h>
#include <sys/select.h>
int speed = 170000; // microseconds, gets smaller (faster) as you eat apples
char getch() {
    struct termios oldt, newt;
    char ch = 0;
    struct timeval tv;
    fd_set readfds;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);
    tv.tv_sec = 0;
    tv.tv_usec = speed; // this is the only part that matters

   if (select(STDIN_FILENO + 1, &readfds, NULL, NULL, &tv) > 0) {
        read(STDIN_FILENO, &ch, 1);
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}
#endif
const int sizex = 20; //set word size! (keep plus 1
const int sizey = sizex + sizex + 1; //size y (2X sizex)
void clearscreen() { //clear screen on any os
#ifdef _WIN32
    system("cls"); // Windows
#else
    system("clear"); // Linux and macOS
#endif
}
int mov = 4; // player movement direction
int posX = 1;//zero out position
int posY = 0;
int i = 0;
int x = 0;
int y = 0;
int score = 0;
int applx = 0;
int apply = 0;
int newapple = 1; // 1 = true, 0 = false(keep 1)
#define MAX_LENGTH 1000

int snakeX[MAX_LENGTH];
int snakeY[MAX_LENGTH];
int snakeLength = 1; // start length 1 (just head)

int main(){
	srand(time(NULL)); //for rnd, moved outside loop
	snakeX[0] = posX;
	snakeY[0] = posY;

	while(i<500){

      	if (newapple == 1){ //make a new apple
		 applx = rand() % (sizey - 1); 
   	         apply = rand() % sizex; 
	         newapple = 0;
	}		
	char input = getch(); //there should be a easier way
		
	if (input == 'q' || input == 'Q'){
		break; // to quit
	}
	//detect movement
	if (input == 'W' || input == 'w'){
		if (mov != 2){
			mov = 1;
		}
	}
	else if (input == 'S' || input == 's'){
		if (mov != 1){
		mov = 2;
		}
	}
	else if (input == 'A' || input == 'a'){
		if (mov != 4){
		mov = 3;
		}
	}
	else if (input == 'D' || input == 'd'){
		if (mov != 3){
		mov = 4;
		}
	}
	
	// Move body segments to follow the head
	for (int k = snakeLength - 1; k > 0; k--) {
    	snakeX[k] = snakeX[k - 1];
    	snakeY[k] = snakeY[k - 1];
}
	clearscreen();
	if (mov == 1){
		posY = posY - 1;
	}
	else if (mov == 2){
		posY = posY + 1;
	}
	else if (mov == 3){
		posX = posX - 1;
	}
	else if (mov == 4){
		posX = posX + 1;
	}

	snakeX[0] = posX;
	snakeY[0] = posY;

	// Check self collision: head vs body segments (skip k=0 since that's the head itself)
	for (int k = 1; k < snakeLength; k++) {
    		if (snakeX[0] == snakeX[k] && snakeY[0] == snakeY[k]) {
        	clearscreen();
        	printf("Game Over! You ran into yourself.\n");
        	printf("Final score: %d\n", score);
        	return 0;
    		}
	}

	if (posX > sizey - 1){
		clearscreen();
		printf("Game_Over!\n");
		printf("Final score: %d\n", score);
		return 0;
	}
	else if (posX < 0){
		clearscreen();
		printf("Game_Over!\n");
		printf("Final score: %d\n", score);
		return 0;
	}
	else if (posY < 0){
		clearscreen();
		printf("Game_Over!\n");
		printf("Final score: %d\n", score);
		return 0;
	
	}
	else if (posY > sizex - 1){
		clearscreen();
		printf("Game_Over!\n");
		printf("Final score: %d\n", score);
		return 0;
	}

	int isSnake = 0;  // flag to check if current spot is snake
	y = 0;            // start top row	
	while (y < sizex) {
    		x = 0;        // start left
    		while (x < sizey) {
        		isSnake = 0;  // reset flag for this spot

        	// check if (x,y) is any part of the snake body
        	for (int k = 0; k < snakeLength; k++) {
            		if (snakeX[k] == x && snakeY[k] == y) {
                	isSnake = 1;
                	break;
            }
        }

        if (isSnake) {
            printf("#");
        } else if (x == applx && y == apply) {
            printf("@");
        } else if (x == sizey - 1) {
            printf("|");
        } else {
            printf(" ");
        }
        x = x + 1;
    }
    printf("\n");
    y = y + 1;
}

	if (posX == applx && posY == apply){
		newapple = 1;
		score = score + 1;
		if (speed > 70000) speed -= 10000;
		if (snakeLength < MAX_LENGTH) {
        	snakeLength = snakeLength + 1;
    }
	}
	printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	printf("score: %d", score);
	fflush(stdout);

      	}
      	printf("\n");
	return 0;
}	
