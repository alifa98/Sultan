#include "globheader.h"

struct decision *qlist = NULL;

int isExistTemp(char Name[])
{
    char fname[100] = "Data\\temp\\";
    strcat(fname,Name);
    strcat(fname,".temp");
    FILE* fp = fopen(fname,"rb");
    if(fp == NULL)
        return 0;
    fclose(fp);
    return 1;
}
void deleteTemp(char Name[])
{
    char fname[100] = "Data\\temp\\";
    strcat(fname,Name);
    strcat(fname,".temp");
    int stat = remove(fname);
    if(stat != 0)
    {
        printf("\nERROR OCCURED WHEN DELETING TEMP FILE.\n");
        exit(0);
    }
}

int hasResumableGame(char Name[])
{
    char fname[100] = "Data\\users\\";
    strcat(fname,Name);
    strcat(fname,".bin");
    FILE* fp = fopen(fname,"rb");
    if(fp == NULL)
        return 0;
    struct usersaves info;
    fread(&info, sizeof(info), 1, fp);
    fclose(fp);
    return info.resumable;
}
void createQuestionsLinkedList(char Name[MAX_NAME], int Mode)
{
    int probabilities[Q_NUMBERS];

    for(int i = 0 ; i < Q_NUMBERS; i++)
        probabilities[i]=3;

    if(Mode == 1)
    {
        struct usersaves userinfo;
        char fname[100] = "Data\\temp\\";
        strcat(fname,Name);
        strcat(fname,".temp");
        FILE* fp = fopen(fname,"rb");
        fread(&userinfo, sizeof(userinfo), 1, fp);
        for(int i = 0 ; i < Q_NUMBERS; i++)
            probabilities[i]=userinfo.prob[i];
        fclose(fp);

        GlobalUserCurrentInfo.people = userinfo.people;
        GlobalUserCurrentInfo.court = userinfo.court;
        GlobalUserCurrentInfo.treasury = userinfo.treasury;
    }
    else if(Mode == 2)
    {
        struct usersaves userinfo;
        char fname[100] = "Data\\users\\";
        strcat(fname,Name);
        strcat(fname,".bin");
        FILE* fp = fopen(fname,"rb");
        fread(&userinfo, sizeof(userinfo), 1, fp);
        for(int i = 0 ; i < Q_NUMBERS; i++)
            probabilities[i]=userinfo.prob[i];
        fclose(fp);

        GlobalUserCurrentInfo.people = userinfo.people;
        GlobalUserCurrentInfo.court = userinfo.court;
        GlobalUserCurrentInfo.treasury = userinfo.treasury;
    }

    char choicesList[Q_NUMBERS][60];
    FILE * fpc = fopen("Data\\questions\\CHOICES.txt","r");

    for(int i = 0; i < Q_NUMBERS; i++){
        if(feof(fpc)){
            printf("\n Q Number and Choices don't match.\n");
            exit(1);
        }

        fscanf(fpc, "%s", &choicesList[i]);
    }
    fclose(fpc);

    for(int i = 0; i < Q_NUMBERS; ++i)
    {
        char fname[100] = "Data\\questions\\";
        strcat(fname, choicesList[i]);
        FILE* fp = fopen(fname,"r");

        struct decision * tempdec;
        tempdec = (struct decision *)malloc(sizeof(struct decision));
        fgets(&(tempdec->q), 200, fp);
        fgets(&(tempdec->a1), 200, fp);
        fscanf(fp, "%d %d %d\n", &tempdec->a1p, &tempdec->a1c, &tempdec->a1t);
        fgets(&(tempdec->a2), 200, fp);
        fscanf(fp, "%d %d %d", &tempdec->a2p, &tempdec->a2c, &tempdec->a2t);
        tempdec->qindex = i;
        tempdec->probability = probabilities[i];
        tempdec->next = NULL;
        fclose(fp);

        #if DEBUG
        printf("index = %d %s %s %d %d %d %s %d %d %d, prob=%d\n", tempdec->qindex, tempdec->q, tempdec->a1, tempdec->alp, tempdec->a1c, tempdec->a1t, tempdec->a2, tempdec->a2p, tempdec->a2c, tempdec->a2t, probabilities[i]);
        #endif // DEBUG
        struct decision *p = qlist;

        if(p == NULL){
            qlist = tempdec;
            continue;
        }

        while(p->next != NULL)
                p = p->next;

        p->next = tempdec;

    }
}
