#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
//#include <string.h>
//#include <conio.h> //not gonna even try to make anything here work with windows
int usr_score = 0;
int ai_score = 0;
int win = 5;
int i = 0;
char usrinput = 'X';
int ai_action = 5;
int usr_action = 5;
char *what_happened;
char *usr;
char *ai;
int getinput(){
	scanf(" %c", &usrinput);
}
int main() {
	while (true){
		if (i == 0){
			printf("\e[1;1H\e[2J");
			i = 1;
		}
		printf("Please pick a number 1-3\n(1) Rock\n(2) Paper \n(3) Scissors: "); 
		getinput();
		printf("\e[1;1H\e[2J");	
		//0 = rock 1 = paper 2 = scissors
		if (usrinput == '1'){
			usr_action = 0;
			usr = "Rock";
		}
		if (usrinput == '2'){
			usr_action = 1;
			usr = "Paper";
		}
		if (usrinput == '3'){
			usr_action = 2;
			usr = "Scissors";
		}
		if (usrinput == '5'){
			printf("Please say a number 1-3");
				win = 5;
		}
		

		srand(time(NULL));//rnd based of time
		//dont loop once in same second
		int value = rand() % (2 + 1);//rnd num 0-3
	
		if (value == 0){
			ai_action = 0;
			ai = "Rock";
		}
		if (value == 1){
			ai_action = 1;
			ai = "Paper";
		}
		if (value == 2){
			ai_action = 2;
			ai = "Scissors";
		}
		//who wins? 0 = tie 1 = usr 2 = "ai"
		if (usr_action == 0 && ai_action == 0){
			win = 0;
			what_happened = "Tied With";
		}
		if (usr_action == 0 && ai_action == 1){
			win = 2;
			what_happened = "Lost To";
		}
		if (usr_action == 0 && ai_action == 2){
			win = 1;
			what_happened = "Beat";
		}
		if (usr_action == 1 && ai_action == 0){
			win = 1;
			what_happened = "Beat";
		}
		if (usr_action == 1 && ai_action == 1){
			win = 0;
			what_happened = "Tied With";
		}
		if (usr_action == 1 && ai_action == 2){
			win = 2;
			what_happened = "Lost To";
		}
		if (usr_action == 2 && ai_action == 0){
			win = 2;
			what_happened = "Lost To";
		}
		if (usr_action == 2 && ai_action == 1){
			win = 1;
			what_happened = "Beat";
		}
		if (usr_action == 2 && ai_action == 2){
			win = 0;
			what_happened = "Tied With";
		}
		if (win == 1){
			usr_score = usr_score + 1;
		}
		if (win == 2){
			ai_score = ai_score + 1;
		}


		printf("Your %s %s the AI's %s\n", usr, what_happened, ai);
		printf("Your Score is %i to the AI's %i\n", usr_score, ai_score);
		if (usr_score > 5){
			printf("YOU WIN! %i to %i\n", usr_score, ai_score);

			break;
		}	
		if (ai_score > 5){
			printf("You Lost %i to %i\n", usr_score, ai_score);
			break;
		};
		usrinput = '5';

	}
	return 0;
}
