//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Details{
    char name[30];
    int age;
    char address[200];
    char skills[500];
};

int main(){
    struct Details profile;
    char buffer[500], *token;
    FILE *fp;

    fp = fopen("resume.txt", "r"); //opening file in read mode

    if(fp == NULL){
        printf("File cannot be opened\n"); //if file pointer is null
        return 0;
    }

    while(fgets(buffer, 500, fp)){ //reading contents of file line by line
        token = strtok(buffer, ":"); //splitting the line on the basis of ":"
        if(strcmp(token, "Name") == 0){ //if token is Name
            token = strtok(NULL, ":");
            strcpy(profile.name, token); //storing the value in profile.name
        }
        else if(strcmp(token, "Age") == 0){ //if token is Age
            token = strtok(NULL, ":");
            profile.age = atoi(token); //converting string to integer and storing the value in profile.age
        }
        else if(strcmp(token, "Address") == 0){ //if token is Address
            token = strtok(NULL, ":");
            strcpy(profile.address, token); //storing the value in profile.address
        }
        else if(strcmp(token, "Skills") == 0){ //if token is Skills
            token = strtok(NULL, ":");
            strcpy(profile.skills, token); //storing the value in profile.skills
        }
    }

    fclose(fp); //closing file pointer

    //printing the details extracted from the file
    printf("Name: %s\nAge: %d\nAddress: %s\nSkills: %s", profile.name, profile.age, profile.address, profile.skills);

    return 0;
}