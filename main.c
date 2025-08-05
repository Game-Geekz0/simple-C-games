#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include "words.h"
//im just not gonna finish this or fix the bugs.
//TODO:re add the screen that says what the wrong answers are
//TODO: make it so it cant do the same word twice,
int quit = 0; //0 = false
int win = 0;
int i = 1;//new word (1=True)
char word[6] = "Error!";//fallback
char word2[25] = "Error";
char usrinput = 'X'; //users inpu:wt one letter at a time
char usrexit;
int j = 0;


char l1 = '_';
char l2 = '_';
char l3 = '_';
char l4 = '_';
char l5 = '_';
char l6 = '_';
//guess 1 - 10 //make this callable
char g1[2] = "_";
char g2[2] = "_";
char g3[2] = "_";
char g4[2] = "_";
char g5[2] = "_";
char g6[2] = "_";
char g7[2] = "_";
char g8[2] = "_";
char g9[2] = "_";
char g10[2] = "_";

void reset(){
    strcpy(g1, "_");
    strcpy(g2, "_");
    strcpy(g3, "_");
    strcpy(g4, "_");
    strcpy(g5, "_");
    strcpy(g6, "_");
    strcpy(g7, "_");
    strcpy(g8, "_");
    strcpy(g9, "_");
    strcpy(g10, "_");
}
int score = 0;
int length = 0;
char blanks[50] = "ERROR";
//int num = rand(); //test number
void clearscreen() { //clear screen on any os
#ifdef _WIN32
    system("cls"); // Windows
#else
    system("clear"); // Linux
#endif
}
int random_1_to_250() {//TODO: this, everything
	//srand(time(NULL));
	return (rand() % 250) + 1;
}
//int guess() {
	//printf("|              %s\n", word);
	//printf("| Please guess a letter: ");
	//scanf(" %c", &usrinput);
	//score = score + 1;
//}
int guessed(){
	//printf("|  ______________________\n");
	//printf("|  |%c %c %c %c %c %c %c %c %c %c |\n", g1[0], g2[0], g3[0], g4[0], g5[0], g6[0], g7[0], g8[0], g9[0], g10[0]);
	//printf("|  ^^^^^^^^^^^^^^^^^^^^^^\n");
}

int guess() {
	char s1, s2, s3, s4, s5, s6;
	printf("|     %c %c %c %c %c %c\n", l1, l2, l3, l4, l5, l6);
	printf("| Please guess a letter: ");
	scanf(" %c", &usrinput);	
	//add one to score if
	//if (usrinput != s1 || usrinput != s2 || usrinput != s3 || usrinput != s4 || usrinput != s5 || usrinput != s6) {
    		//score = score + 1;
	//}	
	return 0;
}

int main(){
	printf("Game is starting!\n");

	//location of each one
	l1 = '_';
	l2 = '_';
	l3 = '_';
	l4 = '_';
	l5 = '_';
	l6 = '_';
	//int c; //reset usr input incase they say like 50 w's
	//while ((c = getchar()) != '\n' && c != EOF);	
	srand(time(NULL));
	reset();
	while (quit == 0){
		int r = random_1_to_250();
		if (i == 1){//resets new word
			l1 = '_';
			l2 = '_';
			l3 = '_';
			l4 = '_';
			l5 = '_';
			l6 = '_';
			strcpy(word, wordlist[r]);//set word to random word
			reset();
			//g1[2] = '_';
			i = 0;
			score = 0;
			length = strlen(word);
			
	    		for (int w = 0; w < length; w++) {
	        		blanks[w] = '_';
	    		}
			blanks[length] = '\0';
		}
		char s1 = word[0];//spot 1
		char s2 = word[1];
		char s3 = word[2];
		char s4 = word[3];
		char s5 = word[4];
		char s6 = word[5];

		if (score == 0){
			clearscreen();
			printf("|^^^^^^^^^^^\n");
			printf("|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n");
			//printf("|  _____________________\n");
			//printf("|  |_ _ _ _ _ _ _ _ _ _|\n");
			//printf("|  ^^^^^^^^^^^^^^^^^^^^^\n");
			guess();
		}
		g1[0] = usrinput;
		if (g1[0] == s1){ l1 = s1; }
		if (g1[0] == s2){ l2 = s2; }
		if (g1[0] == s3){ l3 = s3; }
		if (g1[0] == s4){ l4 = s4; }
		if (g1[0] == s5){ l5 = s5; }
		if (g1[0] == s6){ l6 = s6; }
		if (l1 == s1 && l2 == s2 && l3 == s3 && l4 == s4 && l5 == s5 && l6 == s6){
			j = 1;
			score = 99;
		}
		if (usrinput != s1 && usrinput != s2 && usrinput != s3 && usrinput != s4 && usrinput != s5 && usrinput != s6) {
    			score = score + 1;
		}	


		if (score == 1){
			clearscreen();
			printf("|^^^^^^^^^^^|\n");
			printf("|	    |\n|\n|\n|\n|\n|\n|\n|\n|\n|\n");
			guessed();
			guess();
		}
		
		g2[0] = usrinput;
		if (g2[0] == s1){ l1 = s1; }
		if (g2[0] == s2){ l2 = s2; }
		if (g2[0] == s3){ l3 = s3; }
		if (g2[0] == s4){ l4 = s4; }
		if (g2[0] == s5){ l5 = s5; }
		if (g2[0] == s6){ l6 = s6; }
		if (l1 == s1 && l2 == s2 && l3 == s3 && l4 == s4 && l5 == s5 && l6 == s6){
			j = 2;
			score = 99;
		}
		if (usrinput != s1 && usrinput != s2 && usrinput != s3 && usrinput != s4 && usrinput != s5 && usrinput != s6) {
    			score = score + 1;
		}	
		if (score == 2){
			clearscreen();
			printf("|^^^^^^^^^^^|\n");
			printf("|	    |\n");
			printf("|         __^__  \n");
			printf("|         |0 0| \n");
			printf("|\n|\n|\n|\n|\n|\n|\n");
			guessed();
			guess();
		}
		g3[0] = usrinput;
		if (g3[0] == s1){ l1 = s1; }
		if (g3[0] == s2){ l2 = s2; }
		if (g3[0] == s3){ l3 = s3; }
		if (g3[0] == s4){ l4 = s4; }
		if (g3[0] == s5){ l5 = s5; }
		if (g3[0] == s6){ l6 = s6; }
		if (l1 == s1 && l2 == s2 && l3 == s3 && l4 == s4 && l5 == s5 && l6 == s6){
			j = 3;
			score = 99;
		}
		if (usrinput != s1 && usrinput != s2 && usrinput != s3 && usrinput != s4 && usrinput != s5 && usrinput != s6) {
    			score = score + 1;
		}	
	
		if (score == 3){
			clearscreen();
			printf("|^^^^^^^^^^^|\n");
			printf("|	    |\n");
			printf("|         __^__  \n");
			printf("|         |0 0| \n");
			printf("|         |_*_|\n");
			printf("|\n|\n|\n|\n|\n|\n");
			guessed();
			guess();
		}
		g4[0] = usrinput;
		if (g4[0] == s1){ l1 = s1; }
		if (g4[0] == s2){ l2 = s2; }
		if (g4[0] == s3){ l3 = s3; }
		if (g4[0] == s4){ l4 = s4; }
		if (g4[0] == s5){ l5 = s5; }
		if (g4[0] == s6){ l6 = s6; }
		if (l1 == s1 && l2 == s2 && l3 == s3 && l4 == s4 && l5 == s5 && l6 == s6){
			j = 4;
			score = 99;
		
		}
		if (usrinput != s1 && usrinput != s2 && usrinput != s3 && usrinput != s4 && usrinput != s5 && usrinput != s6) {
    			score = score + 1;
		}			g4[0] = usrinput;
		if (score == 4){
			clearscreen();
			printf("|^^^^^^^^^^^|\n");
			printf("|	    |\n");
			printf("|         __^__  \n");
			printf("|         |0 0| \n");
			printf("|         |_*_|\n");
			printf("|	   _|_\n");
			printf("|\n|\n|\n|\n|\n");
			guessed();
			guess();
		}
		g5[0] = usrinput;
		if (g5[0] == s1){ l1 = s1; }
		if (g5[0] == s2){ l2 = s2; }
		if (g5[0] == s3){ l3 = s3; }
		if (g5[0] == s4){ l4 = s4; }
		if (g5[0] == s5){ l5 = s5; }
		if (g5[0] == s6){ l6 = s6; }
		if (l1 == s1 && l2 == s2 && l3 == s3 && l4 == s4 && l5 == s5 && l6 == s6){
			j = 5;
			score = 99;
		}
		if (usrinput != s1 && usrinput != s2 && usrinput != s3 && usrinput != s4 && usrinput != s5 && usrinput != s6) {
    			score = score + 1;
		}	
		if (score == 5){
			clearscreen();
			printf("|^^^^^^^^^^^|\n");
			printf("|	    |\n");
			printf("|      _  __^__\n");
			printf("|       \\ |0 0|\n");
			printf("|        \\|_*_|\n");
			printf("|	  \\_|_\n");
			printf("|\n|\n|\n|\n|\n");
			guessed();
			guess();
		}	
		g6[0] = usrinput;
		if (g6[0] == s1){ l1 = s1; }
		if (g6[0] == s2){ l2 = s2; }
		if (g6[0] == s3){ l3 = s3; }
		if (g6[0] == s4){ l4 = s4; }
		if (g6[0] == s5){ l5 = s5; }
		if (g6[0] == s6){ l6 = s6; }
		if (l1 == s1 && l2 == s2 && l3 == s3 && l4 == s4 && l5 == s5 && l6 == s6){
			j = 6;
			score = 99;	
		}

		if (usrinput != s1 && usrinput != s2 && usrinput != s3 && usrinput != s4 && usrinput != s5 && usrinput != s6) {
    			score = score + 1;
		}	
		if (score == 6){
			clearscreen();
			printf("|^^^^^^^^^^^|\n");
			printf("|	    |\n");
			printf("|      _  __^__  _\n");
			printf("|       \\ |0 0| /\n");
			printf("|        \\|_*_|/\n");
			printf("|	  \\_|_/\n");
			printf("|\n|\n|\n|\n|\n");
			guessed();
			guess();
		}
		g7[0] = usrinput;
		if (g7[0] == s1){ l1 = s1; }
		if (g7[0] == s2){ l2 = s2; }
		if (g7[0] == s3){ l3 = s3; }
		if (g7[0] == s4){ l4 = s4; }
		if (g7[0] == s5){ l5 = s5; }
		if (g7[0] == s6){ l6 = s6; }
		if (l1 == s1 && l2 == s2 && l3 == s3 && l4 == s4 && l5 == s5 && l6 == s6){
			j = 7;
			score = 99;
		}
		if (usrinput != s1 && usrinput != s2 && usrinput != s3 && usrinput != s4 && usrinput != s5 && usrinput != s6) {
    			score = score + 1;
		}	
		if (score == 7){
			clearscreen();
			printf("|^^^^^^^^^^^|\n");
			printf("|	    |\n");
			printf("|      _  __^__  _\n");
			printf("|       \\ |0 0| /\n");
			printf("|        \\|_*_|/\n");
			printf("|	  \\_|_/\n");
			printf("|           |\n");
			printf("|	    |\n|\n|\n|\n");
			guessed();
			guess();
		}

		g8[0] = usrinput;
		if (g8[0] == s1){ l1 = s1; }
		if (g8[0] == s2){ l2 = s2; }
		if (g8[0] == s3){ l3 = s3; }
		if (g8[0] == s4){ l4 = s4; }
		if (g8[0] == s5){ l5 = s5; }
		if (g8[0] == s6){ l6 = s6; }
		if (l1 == s1 && l2 == s2 && l3 == s3 && l4 == s4 && l5 == s5 && l6 == s6){
			j = 8;
			score = 99;
		}
		if (usrinput != s1 && usrinput != s2 && usrinput != s3 && usrinput != s4 && usrinput != s5 && usrinput != s6) {
    			score = score + 1;
		}	

		if (score == 8){
			clearscreen();
			printf("|^^^^^^^^^^^|\n");
			printf("|	    |\n");
			printf("|      _  __^__  _\n");
			printf("|       \\ |0 0| /\n");
			printf("|        \\|_*_|/\n");
			printf("|      	  \\_|_/\n");
			printf("|           |\n");
			printf("|	    |\n");
			printf("|	   /  \n");
			printf("|         /    \n");
			printf("|      _ /     \n");
			guessed();
			guess();
		}
		g9[0] = usrinput;
		if (g9[0] == s1){ l1 = s1; }
		if (g9[0] == s2){ l2 = s2; }
		if (g9[0] == s3){ l3 = s3; }
		if (g9[0] == s4){ l4 = s4; }
		if (g9[0] == s5){ l5 = s5; }
		if (g9[0] == s6){ l6 = s6; }
		if (l1 == s1 && l2 == s2 && l3 == s3 && l4 == s4 && l5 == s5 && l6 == s6){
			j = 9;
			score = 99;
		}
		if (usrinput != s1 && usrinput != s2 && usrinput != s3 && usrinput != s4 && usrinput != s5 && usrinput != s6) {
    			score = score + 1;
		}	

		if (score == 9){
			clearscreen();
			printf("|^^^^^^^^^^^|\n");
			printf("|	    |\n");
			printf("|      _  __^__  _\n");
			printf("|       \\ |0 0| /\n");
			printf("|        \\|_*_|/\n");
			printf("|	  \\_|_/\n");
			printf("|           |\n");
			printf("|	    |\n");
			printf("|	   / \\ \n");
			printf("|         /   \\ \n");
			printf("|      _ /     \\_\n");
			guessed();
			guess();	
		}
		g10[0] = usrinput;
		if (g10[0] == s1){ l1 = s1; }
		if (g10[0] == s2){ l2 = s2; }
		if (g10[0] == s3){ l3 = s3; }
		if (g10[0] == s4){ l4 = s4; }
		if (g10[0] == s5){ l5 = s5; }
		if (g10[0] == s6){ l6 = s6; }
		if (l1 == s1 && l2 == s2 && l3 == s3 && l4 == s4 && l5 == s5 && l6 == s6){
			j = 10;
			score = 99;
		}
		if (usrinput != s1 && usrinput != s2 && usrinput != s3 && usrinput != s4 && usrinput != s5 && usrinput != s6) {
    			score = score + 1;
		}	

		if (score == 10){
			int c;
			while ((c = getchar()) != '\n' && c != EOF);
			clearscreen();
			printf("|^^^^^^^^^^^|\n");
			printf("|	    |\n");
			printf("|      _  __^__  _\n");
			printf("|       \\ |X X| /\n");
			printf("|        \\|_*_|/\n");
			printf("|	  \\_|_/\n");
			printf("|           |\n");
			printf("|	    |\n");
			printf("|	   / \\ \n");
			printf("|         /   \\ \n");
			printf("|      _ /     \\_\n");
			guessed();
			i = 1;
			printf("|      %s\n", blanks);
			printf("|      %s\n", word);
			printf("type any key to play again\n");
			printf("hit 'Q' to exit: ");
			scanf(" %c", &usrexit);
		}
		if (usrexit == 'Q' || usrexit == 'q'){
			quit = 1;
		}
		if (score == 99){
			int c;
			while ((c = getchar()) != '\n' && c != EOF);
			clearscreen();
			clearscreen();
			printf("|^^^^^^^^^^^\n");
			printf("|\n");
			printf("|      _  _____  _\n");
			printf("|       \\ |O O| /\n");
			printf("|        \\|_*_|/\n");
			printf("|	  \\_|_/\n");
			printf("|           |\n");
			printf("|	    |\n");
			printf("|	   / \\ \n");
			printf("|         /   \\ \n");
			printf("|      _ /     \\_\n");
			printf("|        YOU WIN!!\n");
			printf("| the word was %s\n", word);
			printf("type any key to play again\n");
			printf("hit 'Q' to exit: ");
			scanf(" %c", &usrexit);
			if (usrexit == 'Q' || usrexit == 'q'){
			quit = 1;
			}
			score = 0;
			i = 1;
		}
	}
	return 0;
}
