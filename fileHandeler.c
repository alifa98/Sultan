#include "globheader.h"
int isExistTemp(char Name[]){
    char fname[100] = "Data\\temp\\";
    strcat(fname,Name);
    strcat(fname,".temp");
    FILE* fp = fopen(fname,"rb");
    if(fp == NULL)
        return 0;
    fclose(fp);
    return 1;
}
void deleteTemp(char Name[]){
    char fname[100] = "Data\\temp\\";
    strcat(fname,Name);
    strcat(fname,".temp");
    int stat = remove(fname);
    if(stat != 0){
        printf("\nERROR OCCURED WHEN DELETING TEMP FILE.\n");
        exit(0);
    }
}

int hasResumableGame(char Name[]){
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
void scoreSubmiter(char Name[], int score){
    struct ScoreList info;
    info.name = Name;
    info.score = score;
    char fname[] = "Data\\scores.bin";
    FILE* fp = fopen(fname,"ab")
    fwrite(&info, sizeof(info), 1, fp);
    fclose(fp);
}
