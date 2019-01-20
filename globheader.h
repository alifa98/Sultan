#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX_NAME 50
#define Q_NUMBERS 7

//Structures
struct usersaves{
    int resumable;
    int prob[Q_NUMBERS];
    int people;
    int court;
    int treasury;
};
struct decision{
    int qindex;
    char q[200];
    char a1[200];
    int alp;
    int a1c;
    int a1t;
    char a2[200];
    int a2p;
    int a2c;
    int a2t;
    int probability;
    struct decision * next;
};
struct ScoreList{
    char name[MAX_NAME];
    int score;
};
//Functions
void Play(char Name[MAX_NAME], int Mode); // 1 = whit temp file , 2 = with saved file , 0 = New Game;
int isExistUser(char Name[MAX_NAME]);
void createUser(char Name[MAX_NAME]);
void deleteZeroProbabilityQuestions();
void printRandomQuestion(); //this decrease probability of question for next time.
int QListIsEmpty();
void printSortedUsers(); //fetch score.bin and advance sort.

//Saver
void saveGame(char Name[MAX_NAME]);
void saveTemp(char Name[MAX_NAME]);

//File Handel
void createQuestionsLinkedList(int Mode); //1 means create from temp file ,  2 means saved file and 0 means new game
int hasResumableGame(char Name[MAX_NAME]);
int isExistTemp(char Name[MAX_NAME]);
void deleteTemp(char Name[MAX_NAME]);
void scoreSubmiter(char Name[], int score);
