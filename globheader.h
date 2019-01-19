#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_NAME 50

//Functions
void Play(int Mode); // 1 = whit temp file , 2 = with saved file , 0 = New Game;
int isExistUser(char Name[MAX_NAME]);
int hasResumableGame(char Name[MAX_NAME]);
void createUser(char Name[MAX_NAME]);
void deleteZeroProbabilityQuestions();
void printRandomQuestion(); //this decrease probability of question for next time.
int QListIsEmpty();
void printSortedUsers(); //fetch score.bin and advance sort.

//Saver
void saveGame(char Name[MAX_NAME]);
void saveTemp(char Name[MAX_NAME]);

//File Handel
void createQuestionsLinkedList();
void isExistTemp(char Name[MAX_NAME]);
void deleteTemp(char Name[MAX_NAME]);
