#include "globheader.h"

int main()
{
    //Random Seed Initialization
    srand(time(NULL));

    printf("#########################################\n#\t\t\t\t\t#\n#\tWlcome To Sultan Game.\t\t#\n#\t\t\t\t\t#\n#########################################\n");
    char name[MAX_NAME];
    printf("\nEnter Your Name : ");
    scanf("%s", &name);

    int firstMenuDic;
    while(1)
    {
        printf("1)Play Game\n2)See TOP 10\n3)Create Question\n4)exit\n");
        scanf("%d", &firstMenuDic);
        if(firstMenuDic == 2)
        {
            printTopRecords();
        }
        else if(firstMenuDic == 4)
        {
            exit(0);
        }
        else if(firstMenuDic == 3)
        {
            CreateQuestion();
        }
        else if(firstMenuDic == 1)
        {
            if(isExistTemp(name))
            {
                int tempdec;
                printf("We Detect You didn't Save Your Game Last Time...What to do with it?\n 1)Resume \n 2)throw away and Start new game :| \n");
                scanf("%d", &tempdec);

                if(tempdec == 1)
                {
                    Play(name, 1);
                }
                else if(tempdec == 2)
                {
                    deleteTemp(name);
                    Play(name, 0);
                }
                else
                {
                    exit(0);
                }

            }
            else
            {
                if(hasResumableGame(name))
                {
                    int dec;
                    printf("1)Resume Last Saved Game \n2)Start new game :| \n");
                    scanf("%d", &dec);

                    if(dec == 1)
                    {
                        Play(name, 2);
                    }
                    else if(dec == 2)
                    {
                        Play(name, 0);
                    }
                    else
                    {
                        exit(0);
                    }
                }
                else
                {
                    printf("New Game Started ...\n");
                    Play(name, 0);
                }

            }
        }
    }
}
