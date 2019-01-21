#include "globheader.h"
void saveTemp(char Name[MAX_NAME])
{

    char fname[100] = "Data\\temp\\";
    strcat(fname,Name);
    strcat(fname,".temp");
    FILE* fp = fopen(fname,"wb");
    if(fp == NULL)
    {
        printf("ERROR TO SAVE .TEMP FILE.");
        exit(-1);
    }
    struct usersaves mytempuser;
    mytempuser.resumable = 1;
    mytempuser.people = GlobalUserCurrentInfo.people;
    mytempuser.court = GlobalUserCurrentInfo.court;
    mytempuser.treasury = GlobalUserCurrentInfo.treasury;
    for(int i=0; i < Q_NUMBERS; ++i)
        mytempuser.prob[i] = getProbByIndex(i);
    fwrite(&mytempuser, sizeof(mytempuser), 1, fp);
    fclose(fp);
}

void saveGame(char Name[MAX_NAME], int State)
{

    char fname[100] = "Data\\temp\\";
    strcat(fname,Name);
    strcat(fname,".temp");
    FILE* fpt = fopen(fname,"rb");
    if(fpt == NULL)
    {
        printf("ERROR TO OPEN TEMP FILE.");
        exit(-1);
    }

    char SD[100] = "Data\\users\\";
    strcat(SD,Name);
    strcat(SD,".bin");
    FILE* fp = fopen(SD,"wb");
    if(fp == NULL)
    {
        printf("ERROR TO OPEN SAVE BINARY FILE.");
        exit(-1);
    }

    struct usersaves mytempuser;
    fread(&mytempuser, sizeof(mytempuser), 1, fpt);
    mytempuser.resumable = State;
    fwrite(&mytempuser, sizeof(mytempuser), 1, fp);
    fclose(fp);
    fclose(fpt);
    deleteTemp(Name);
    if(State == 1)
        scoreSubmiter(Name, mytempuser.people, mytempuser.court, mytempuser.treasury);
}

void scoreSubmiter(char Name[], int p, int c, int t){
    FILE* fp = fopen("Data\\TopRec.bin","ab");
    if(fp == NULL)
    {
        printf("ERROR TO OPEN Top Records Binary FILE.");
        exit(-1);
    }
    struct ScoreList m;
    strcpy(m.name,Name);
    m.p = p;
    m.c = c;
    m.t = t;
    fwrite(&m, sizeof(struct ScoreList), 1, fp);
    fclose(fp);
}
