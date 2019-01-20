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
        if(QListIsEmpty())
            createQuestionsLinkedList(Name, 0);

        saveTemp(Name);
        struct effect eff = printRandomQuestion();

        int temporaryVarForDecision;
        scanf("%d", &temporaryVarForDecision);

        if(temporaryVarForDecision == 1)
        {
            GlobalUserCurrentInfo.people = (GlobalUserCurrentInfo.people+eff.p1 > 100)? 100 : GlobalUserCurrentInfo.people+eff.p1;
            GlobalUserCurrentInfo.court = (GlobalUserCurrentInfo.court+eff.c1 > 100)? 100 : GlobalUserCurrentInfo.court+eff.c1;
            GlobalUserCurrentInfo.treasury = (GlobalUserCurrentInfo.treasury+eff.t1 > 100)? 100 : GlobalUserCurrentInfo.treasury+eff.t1;

            saveTemp(Name);

            if(GlobalUserCurrentInfo.people+GlobalUserCurrentInfo.court+lobalUserCurrentInfo.treasury < 30 || GlobalUserCurrentInfo.people <= 0 || GlobalUserCurrentInfo.court <= 0 || lobalUserCurrentInfo.treasury <= 0)
            {
                printf("\n**** GAME OVER **** \nDo You Want to Save This Game? 1=Yes 0=No\n");
                scanf("%d", &temporaryVarForDecision);

                if(temporaryVarForDecision)
                {
                    saveGame(Name, 0);
                    printf("*Game Saved.\n");
                }
                else
                {
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

            if(GlobalUserCurrentInfo.people+GlobalUserCurrentInfo.court+lobalUserCurrentInfo.treasury < 30 || GlobalUserCurrentInfo.people <= 0 || GlobalUserCurrentInfo.court <= 0 || lobalUserCurrentInfo.treasury <= 0)
            {
                printf("\n****GAME OVER **** \nDo You Want to Save This Game? 1=Yes 0=No\n");
                scanf("%d", &temporaryVarForDecision);

                if(temporaryVarForDecision)
                {
                    saveGame(Name, 0);
                    printf("*Game Saved.\n");
                }
                else
                {
                    printf("*Game Not Saved.\n");
                }
                break;
            }
        }
        else
        {
            printf("Do You Want to Save This Game? 1=Yes 0=No\n");
            scanf("%d", &temporaryVarForDecision);
            if(temporaryVarForDecision)
            {
                saveGame(Name, 1);
                printf("*Game Saved Successfully.\n");
            }
            else
            {
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
void printTopRecords()
{
    printf("\n TOP RECORDS : \n");
}
