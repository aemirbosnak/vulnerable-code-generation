//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char* name;
    char* education;
    char* skill1;
    char* skill2;
    char* skill3;
} Resume;

int main(){

    FILE* fp;
    char line[100];

    fp = fopen("resume.txt", "r");

    // check if file exists
    if (fp == NULL) {
        printf("Error: File does not exist.\n");
        return 1;
    }
    // parse resume
    Resume* resume = (Resume*)malloc(sizeof(Resume));
    int count = 0;

    while (fgets(line, sizeof(line), fp)) {
        char* token = strtok(line, ":");
        char* info = strtok(NULL, "\n");

        switch(count) {
            case 0:
                resume->name = (char*)malloc(strlen(info) + 1);
                strcpy(resume->name, info);
                break;
            case 1:
                resume->education = (char*)malloc(strlen(info) + 1);
                strcpy(resume->education, info);
                break;
            case 2:
                resume->skill1 = (char*)malloc(strlen(info) + 1);
                strcpy(resume->skill1, info);
                break;
            case 3:
                resume->skill2 = (char*)malloc(strlen(info) + 1);
                strcpy(resume->skill2, info);
                break;
            case 4:
                resume->skill3 = (char*)malloc(strlen(info) + 1);
                strcpy(resume->skill3, info);
                break;
            default:
                break;
        }
        count++;
    }

    // print resume
    printf("----- Resume -----\n");
    printf("Name:\t%s\n", resume->name);
    printf("Education:\t%s\n", resume->education);
    printf("Skills:\t%s, %s, %s\n", resume->skill1, resume->skill2, resume->skill3);

    // free memory
    free(resume->name);
    free(resume->education);
    free(resume->skill1);
    free(resume->skill2);
    free(resume->skill3);
    fclose(fp);
    return 0;
}