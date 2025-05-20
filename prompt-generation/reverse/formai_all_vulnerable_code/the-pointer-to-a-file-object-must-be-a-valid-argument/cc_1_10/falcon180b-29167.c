//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

typedef struct resume{
    char name[100];
    char address[200];
    char phone[20];
    char email[100];
    char education[200];
    char experience[200];
}resume;

void addResume(resume *r){
    FILE *file = fopen("resumes.txt","a");
    fprintf(file,"Name: %s\n",r->name);
    fprintf(file,"Address: %s\n",r->address);
    fprintf(file,"Phone: %s\n",r->phone);
    fprintf(file,"Email: %s\n",r->email);
    fprintf(file,"Education: %s\n",r->education);
    fprintf(file,"Experience: %s\n",r->experience);
    fprintf(file,"\n");
    fclose(file);
}

int main(){
    FILE *file = fopen("resumes.txt","r");
    char line[1000];
    resume r;
    while(fgets(line,sizeof(line),file)!=NULL){
        if(strstr(line,"Name:")!=NULL){
            strcpy(r.name,strtok(line," "));
        }
        else if(strstr(line,"Address:")!=NULL){
            strcpy(r.address,strtok(line," "));
        }
        else if(strstr(line,"Phone:")!=NULL){
            strcpy(r.phone,strtok(line," "));
        }
        else if(strstr(line,"Email:")!=NULL){
            strcpy(r.email,strtok(line," "));
        }
        else if(strstr(line,"Education:")!=NULL){
            strcpy(r.education,strtok(line," "));
        }
        else if(strstr(line,"Experience:")!=NULL){
            strcpy(r.experience,strtok(line," "));
        }
    }
    addResume(&r);
    fclose(file);
    return 0;
}