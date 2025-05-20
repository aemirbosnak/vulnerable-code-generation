//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct{
    char name[MAX_SIZE];
    char email[MAX_SIZE];
    char skills[MAX_SIZE];
    char experience[MAX_SIZE];
} Resume;

void parseResume(char* filename, Resume* resume){
    FILE* fp = fopen(filename, "r");
    char line[MAX_SIZE];
    int field = 1;

    while(fgets(line, MAX_SIZE, fp)){
        char* token = strtok(line, ":");
        switch(field){
            case 1:
                strcpy(resume->name, token);
                break;
            case 2:
                strcpy(resume->email, token);
                break;
            case 3:
                strcpy(resume->skills, token);
                break;
            case 4:
                strcpy(resume->experience, token);
                break;
        }
        field++;

        while(token = strtok(NULL, ":")){
            switch(field){
                case 3:
                    strcat(resume->skills, token);
                    strcat(resume->skills, " ");
                    break;
                case 4:
                    strcat(resume->experience, token);
                    strcat(resume->experience, " ");
                    break;
            }
        }
    }

    fclose(fp);
}

int main(){
    Resume resume;
    char* filename = "resume.txt";

    parseResume(filename, &resume);

    printf("Name: %s", resume.name);
    printf("Email: %s", resume.email);
    printf("Skills: %s", resume.skills);
    printf("Experience: %s", resume.experience);

    return 0;
}