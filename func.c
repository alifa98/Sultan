#include "globheader.h"
Play(char Name[MAX_NAME], int Mode)
{
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
}
int QListIsEmpty(){
    if(qlist == NULL)
        return 1;
    return 0;
}
