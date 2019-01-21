#include "globheader.h"
struct usersaves GlobalUserCurrentInfo;

void Play(char Name[MAX_NAME], int Mode)
{
    GlobalUserCurrentInfo.people = 50;
    GlobalUserCurrentInfo.court = 50;
    GlobalUserCurrentInfo.treasury = 50;

    if(Mode == 1)
    {
        createQuestionsLinkedList(Name, Mode);
    }
    else if(Mode == 2)
    {
        createQuestionsLinkedList(Name, Mode);
    }
    else
    {
        createQuestionsLinkedList(Name, Mode);
    }
    deleteZeroProbabilityQuestions();

    while(1)
    {
        deleteZeroProbabilityQuestions();
        if(QListIsEmpty()){
            createQuestionsLinkedList(Name, 0);
        }


        RandomAdvance();
        saveTemp(Name);
        printf("Your State : People=%d%%, Court=%d%%, Treasury=%d%%.\n",GlobalUserCurrentInfo.people, GlobalUserCurrentInfo.court, GlobalUserCurrentInfo.treasury);
        struct effect eff = printRandomQuestion();

        int temporaryVarForDecision;
        scanf("%d", &temporaryVarForDecision);

        if(temporaryVarForDecision == 1)
        {
            GlobalUserCurrentInfo.people = (GlobalUserCurrentInfo.people+eff.p1 > 100)? 100 : GlobalUserCurrentInfo.people+eff.p1;
            GlobalUserCurrentInfo.court = (GlobalUserCurrentInfo.court+eff.c1 > 100)? 100 : GlobalUserCurrentInfo.court+eff.c1;
            GlobalUserCurrentInfo.treasury = (GlobalUserCurrentInfo.treasury+eff.t1 > 100)? 100 : GlobalUserCurrentInfo.treasury+eff.t1;

            saveTemp(Name);

            if(GlobalUserCurrentInfo.people+GlobalUserCurrentInfo.court+GlobalUserCurrentInfo.treasury < 30 || GlobalUserCurrentInfo.people <= 0 || GlobalUserCurrentInfo.court <= 0 || GlobalUserCurrentInfo.treasury <= 0)
            {
                printf("Your State : People=%d%%, Court=%d%%, Treasury=%d%%.\n",GlobalUserCurrentInfo.people, GlobalUserCurrentInfo.court, GlobalUserCurrentInfo.treasury);
                printf("\n**** GAME OVER **** \nDo You Want to Save This Game? 1=Yes 0=No\n");
                scanf("%d", &temporaryVarForDecision);

                if(temporaryVarForDecision)
                {
                    saveGame(Name, 0);
                    printf("*Game Saved.\n");
                }
                else
                {
                    deleteTemp(Name);
                    printf("*Game Not Saved.\n");
                }
                break;
            }

        }
        else if(temporaryVarForDecision == 2)
        {
            GlobalUserCurrentInfo.people = (GlobalUserCurrentInfo.people+eff.p2 > 100)? 100 : GlobalUserCurrentInfo.people+eff.p2;
            GlobalUserCurrentInfo.court = (GlobalUserCurrentInfo.court+eff.c2 > 100)? 100 : GlobalUserCurrentInfo.court+eff.c2;
            GlobalUserCurrentInfo.treasury = (GlobalUserCurrentInfo.treasury+eff.t2 > 100)? 100 : GlobalUserCurrentInfo.treasury+eff.t2;

            saveTemp(Name);

            if(GlobalUserCurrentInfo.people+GlobalUserCurrentInfo.court+GlobalUserCurrentInfo.treasury < 30 || GlobalUserCurrentInfo.people <= 0 || GlobalUserCurrentInfo.court <= 0 || GlobalUserCurrentInfo.treasury <= 0)
            {
                printf("Your State : People=%d%%, Court=%d%%, Treasury=%d%%.\n",GlobalUserCurrentInfo.people, GlobalUserCurrentInfo.court, GlobalUserCurrentInfo.treasury);
                printf("\n****GAME OVER **** \nDo You Want to Save This Game? 1=Yes 0=No\n");
                scanf("%d", &temporaryVarForDecision);

                if(temporaryVarForDecision)
                {
                    saveGame(Name, 0);
                    printf("*Game Saved.\n");
                }
                else
                {
                    deleteTemp(Name);
                    printf("*Game Not Saved.\n");
                }
                break;
            }
        }
        else
        {
            printf("Your State : People=%d%%, Court=%d%%, Treasury=%d%%.\n",GlobalUserCurrentInfo.people, GlobalUserCurrentInfo.court, GlobalUserCurrentInfo.treasury);
            printf("Do You Want to Save This Game? 1=Yes 0=No\n");
            scanf("%d", &temporaryVarForDecision);
            if(temporaryVarForDecision)
            {
                saveGame(Name, 1);
                printf("*Game Saved Successfully.\n");
            }
            else
            {
                deleteTemp(Name);
                printf("*Game Not Saved.\n");
            }
            break;
        }
    }
}
int QListIsEmpty()
{
    if(qlist == NULL)
        return 1;
    return 0;
}
void deleteZeroProbabilityQuestions()
{
    struct decision * ptempo;
    while(1)
    {
        if(qlist->probability == 0)
        {
            ptempo = qlist->next;
            free(qlist);
            qlist = ptempo;
            if(qlist == NULL)
                break;
        }
        else
        {
            break;
        }
    }
    ptempo = qlist;

    while(ptempo != NULL && ptempo->next != NULL)
    {
        if(ptempo->next->probability == 0)
        {
            ptempo->next = ptempo->next->next;
            continue;
        }
        ptempo = ptempo->next;
    }

}
int getProbByIndex(int index)
{
    struct decision * p = qlist;
    if(p != NULL)
    {
        if(p->qindex == index)
            return p->probability;
        p = p->next;
    }
    return 0;
}

int swapable(struct ScoreList a, struct ScoreList b)
{
    if (a.p < b.p)
        return 1;
    else if(a.p == b.p && a.c < b.c)
        return 1;
    else if( a.p == b.p && a.c == b.c && a.t < b.t )
        return 1;

        return 0;
}
void printTopRecords()
{
    printf("\n********************* TOP 10 RECORDS *********************\n");
    struct ScoreList* arr = NULL;
    FILE* fp = fopen("Data\\TopRec.bin","rb");
    if(fp == NULL)
    {
        printf("Unable To Open Records File.\n");
        exit(-1);
    }
    int n = 0;

    while(1)
    {
        struct ScoreList te;
        fread(&te, sizeof(struct ScoreList), 1, fp);
        if(feof(fp)){
            break;
        }
        arr = (struct ScoreList*)realloc(arr, sizeof(struct ScoreList)*(n+1) );
        arr[n] = te;
        n++;
    }
    fclose(fp);
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
        {
            if( swapable(arr[j], arr[j+1]) )
            {
                struct ScoreList m = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = m;
            }
        }
    printf("\n# | Name - People - Court - treasury\n");
    for(int i=0; i < 10 && i < n ; ++i)
        printf("%-2d| %s - %d - %d - %d\n",i+1,arr[i].name, arr[i].p, arr[i].c, arr[i].t);
    free(arr);
    printf("\n");
}

struct effect printRandomQuestion()
{
    int nodeNumber = 0;
    struct decision * p = qlist;
    while(p != NULL)
    {
        nodeNumber++;
        p = p->next;
    }

    int randomNodeIndex = rand() % nodeNumber;

    p = qlist;
    for(int i=0; i < randomNodeIndex; i++)
    {
        p = p->next;
    }

    printf("\n%s",p->q);
    printf("1 ) %s",p->a1);
    printf("2 ) %s",p->a2);

    p->probability = (p->probability) -1;

    struct effect effOfQues;
    effOfQues.p1 = p->a1p;
    effOfQues.c1 = p->a1c;
    effOfQues.t1 = p->a1t;
    effOfQues.p2 = p->a2p;
    effOfQues.c2 = p->a2c;
    effOfQues.t2 = p->a2t;

    return effOfQues;
}
void RandomAdvance()
{
    int r1 = rand() % 100;
    if(r1 <= 7)
    {
        int r2 = rand() % 3;

        switch(r2)
        {
        case 0:
            printf("\nBAD NEWS :: Unfortunately thieves attacked the treasury.\n");
            GlobalUserCurrentInfo.treasury = GlobalUserCurrentInfo.treasury -10;
            GlobalUserCurrentInfo.court = GlobalUserCurrentInfo.court +5;
            break;
        case 1:
            printf("\nGOOD NEWS :: A treasure was found in the northern hills.\n");
            GlobalUserCurrentInfo.treasury = GlobalUserCurrentInfo.treasury +10;
            GlobalUserCurrentInfo.people = GlobalUserCurrentInfo.people -5;
            break;
        case 2:
            printf("\nImportant NEWS :: Today the court's food was not good.\n");
            GlobalUserCurrentInfo.people = GlobalUserCurrentInfo.people +5;
            GlobalUserCurrentInfo.court = GlobalUserCurrentInfo.court -5;
            break;
        }
    }
}
