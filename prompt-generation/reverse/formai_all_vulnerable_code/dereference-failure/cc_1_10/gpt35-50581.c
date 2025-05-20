//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LENGTH 1000

struct Resume{
    char name[MAX_LENGTH];
    char email[MAX_LENGTH];
    char phone[MAX_LENGTH];
    char education[MAX_LENGTH];
    char experience[MAX_LENGTH];
};

void parseResume(char* fileName){
    struct Resume resume;
    FILE* fp = fopen(fileName,"r");
    char line[MAX_LENGTH];
    char* tokenizer;
    
    if(fp == NULL){
        printf("File not found!\n");
        return;
    }
    
    while(fgets(line,MAX_LENGTH,fp)){
        tokenizer = strtok(line,":");
        
        if(strcmp(tokenizer,"Name")==0){
            tokenizer = strtok(NULL,"\n");
            strcpy(resume.name,tokenizer);
        }else if(strcmp(tokenizer,"Email")==0){
            tokenizer = strtok(NULL,"\n");
            strcpy(resume.email,tokenizer);
        }else if(strcmp(tokenizer,"Phone")==0){
            tokenizer = strtok(NULL,"\n");
            strcpy(resume.phone,tokenizer);
        }else if(strcmp(tokenizer,"Education")==0){
            tokenizer = strtok(NULL,"\n");
            strcpy(resume.education,tokenizer);
        }else if(strcmp(tokenizer,"Experience")==0){
            tokenizer = strtok(NULL,"\n");
            strcpy(resume.experience,tokenizer);
        }
    }
    
    fclose(fp);
    
    //Printing the Parsed Resume Data
    printf("\nName : %s\n",resume.name);
    printf("Email : %s\n",resume.email);
    printf("Phone : %s\n",resume.phone);
    printf("Education : %s\n",resume.education);
    printf("Experience : %s\n",resume.experience);
}

int main(){
    char* fileName = "resume.txt";
    parseResume(fileName);
    return 0;
}