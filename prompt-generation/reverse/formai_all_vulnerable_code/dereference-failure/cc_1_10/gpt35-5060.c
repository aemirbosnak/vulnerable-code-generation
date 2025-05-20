//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50

typedef struct resumeFields{
    char name[MAX];
    char email[MAX];
    char phone[MAX];
    char skills[MAX][MAX];
    int numSkills;
    char education[MAX][MAX];
    int numEducation;
    char experience[MAX][MAX];
    int numExperience;
} Resume;

void parseResume(char *fileName, Resume *resume);
void printResume(Resume *resume);

int main(){
    Resume *resume = (Resume*)malloc(sizeof(Resume));
    char fileName[MAX];

    printf("Enter the name of the Resume file: ");
    scanf("%s", fileName);

    parseResume(fileName, resume);
    printResume(resume);

    free(resume);

    return 0;
}

void parseResume(char *fileName, Resume *resume){
    FILE *fp;
    char line[MAX];
    char *token;
    int i;

    fp = fopen(fileName, "r");

    if(fp == NULL){
        printf("Error opening file\n");
        exit(1);
    }

    while(fgets(line, MAX, fp)){
        token = strtok(line, "\t\n");

        while(token != NULL){
            if(strcmp(token, "Name:") == 0){
                token = strtok(NULL, "\t\n");
                strcpy(resume->name, token);
            }
            else if(strcmp(token, "Email:") == 0){
                token = strtok(NULL, "\t\n");
                strcpy(resume->email, token);
            }
            else if(strcmp(token, "Phone:") == 0){
                token = strtok(NULL, "\t\n");
                strcpy(resume->phone, token);
            }
            else if(strcmp(token, "Skills:") == 0){
                i = 0;
                token = strtok(NULL, ",\t\n");

                while(token != NULL){
                    strcpy(resume->skills[i], token);
                    i++;
                    token = strtok(NULL, ",\t\n");
                }

                resume->numSkills = i;
            }
            else if(strcmp(token, "Education:") == 0){
                i = 0;
                token = strtok(NULL, ",\t\n");

                while(token != NULL){
                    strcpy(resume->education[i], token);
                    i++;
                    token = strtok(NULL, ",\t\n");
                }

                resume->numEducation = i;
            }
            else if(strcmp(token, "Experience:") == 0){
                i = 0;
                token = strtok(NULL, ",\t\n");

                while(token != NULL){
                    strcpy(resume->experience[i], token);
                    i++;
                    token = strtok(NULL, ",\t\n");
                }

                resume->numExperience = i;
            }

            token = strtok(NULL, "\t\n");
        }
    }

    fclose(fp);
}

void printResume(Resume *resume){
    int i;

    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);

    printf("Skills:\n");
    for(i = 0; i < resume->numSkills; i++){
        printf("%s\n", resume->skills[i]);
    }

    printf("Education:\n");
    for(i = 0; i < resume->numEducation; i++){
        printf("%s\n", resume->education[i]);
    }

    printf("Experience:\n");
    for(i = 0; i < resume->numExperience; i++){
        printf("%s\n", resume->experience[i]);
    }
}