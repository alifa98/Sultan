#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX_NAME 50
#define Q_NUMBERS 8
#define DEBUG 0
//Structures
struct usersaves
{
    int resumable;
    int prob[Q_NUMBERS];
    int people;
    int court;
    int treasury;
};
struct decision
{
    int qindex;
    char q[200];
    char a1[200];
    int a1p;
    int a1c;
    int a1t;
    char a2[200];
    int a2p;
    int a2c;
    int a2t;
    int probability;
    struct decision * next;
};
struct ScoreList
{
    char name[MAX_NAME];
    int p;
    int c;
    int t;
};
struct effect
{
    int p1;
    int c1;
    int t1;
    int p2;
    int c2;
    int t2;
};
extern struct decision *qlist;
extern struct usersaves GlobalUserCurrentInfo;

//Functions
void Play(char Name[MAX_NAME], int Mode); // 1 = whit temp file , 2 = with saved file , 0 = New Game;
int isExistUser(char Name[MAX_NAME]);
void createUser(char Name[MAX_NAME]);
void deleteZeroProbabilityQuestions();
struct effect printRandomQuestion(); //this decrease probability of question for next time.
int QListIsEmpty();
void printSortedUsers(); //fetch score.bin and advance sort.
int getProbByIndex(int index);
void printTopRecords();
void RandomAdvance();
void CreateQuestion();

//Saver
void saveGame(char Name[MAX_NAME], int State);
void saveTemp(char Name[MAX_NAME]);
void scoreSubmiter(char Name[], int p, int c, int t);

//File Handel
void createQuestionsLinkedList(char Name[MAX_NAME], int Mode); //1 means create from temp file ,  2 means saved file and 0 means new game
int hasResumableGame(char Name[MAX_NAME]);
int isExistTemp(char Name[MAX_NAME]);
void deleteTemp(char Name[MAX_NAME]);
