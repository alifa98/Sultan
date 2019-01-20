#include "globheader.h"
void saveTemp(int Name)
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

void saveTemp(int Name)
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
    strcat(SD,".temp");

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
