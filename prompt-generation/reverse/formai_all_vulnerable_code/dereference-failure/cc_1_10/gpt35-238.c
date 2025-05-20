//FormAI DATASET v1.0 Category: Digital Diary ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAXCHAR 1000

int main(){

    FILE *fp;
    char filePath[MAXCHAR];
    char diaryEntry[MAXCHAR];
    char option[MAXCHAR];
    char timeStamp[26];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    printf("Welcome to your digital diary!\n\n");

    snprintf(filePath, sizeof filePath, "diary_%d-%d-%d.txt", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

    printf("Today's date is %d/%d/%d.\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    printf("Your diary for today will be saved in %s.\n\n", filePath);

    printf("What would you like to do? \n");
    printf("1 - Read previous entries \n");
    printf("2 - Write a new entry \n");
    printf("3 - Quit \n");

    fgets(option, MAXCHAR, stdin);

    while(strcmp(option, "3\n") != 0){

        if(strcmp(option, "1\n") == 0){
            fp = fopen(filePath, "r");

            if(fp == NULL){
                printf("No entries found.\n");
            }
            else{
                printf("\nPrevious entries:\n");
                while(fgets(diaryEntry, MAXCHAR, fp) != NULL)
                    printf("%s", diaryEntry);
            }

            fclose(fp);
        }

        else if(strcmp(option, "2\n") == 0){
            fp = fopen(filePath, "a");

            printf("\nEnter your diary entry:\n");
            fgets(diaryEntry, MAXCHAR, stdin);

            strftime(timeStamp, sizeof(timeStamp), "%Y-%m-%d %H:%M:%S", &tm);

            fprintf(fp, "%s - %s\n", timeStamp, diaryEntry);

            printf("\nEntry saved.\n");

            fclose(fp);
        }

        else{
            printf("\nInvalid option.\n");
        }

        printf("\nWhat would you like to do? \n");
        printf("1 - Read previous entries \n");
        printf("2 - Write a new entry \n");
        printf("3 - Quit \n");

        fgets(option, MAXCHAR, stdin);
    }

    printf("\nThank you for using your digital diary!\n");

    return 0;
}