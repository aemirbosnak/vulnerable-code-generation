//FormAI DATASET v1.0 Category: File Backup System ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXLEN 100

struct file{
    char name[MAXLEN];
    char data[MAXLEN];
};

struct node{
    char time[MAXLEN];
    struct file files[10];
    struct node *next;
};

struct node *head = NULL;

void backupFiles(char *username){
    struct node *curr = head;
    while(curr!=NULL){
        printf("\nBackup at %s by %s: ",curr->time,username);
        for(int i=0; i<10; i++){
            if(strcmp(curr->files[i].name,"")!=0)
                printf("\n%s: %s",curr->files[i].name,curr->files[i].data);
        }
        curr = curr->next;
    }
}

void addFile(char *username){
    char *filename = (char*)malloc(MAXLEN*sizeof(char));
    char *filedata = (char*)malloc(MAXLEN*sizeof(char));
    printf("\nEnter file name: ");
    scanf("%s",filename);
    printf("\nEnter file data: ");
    scanf("%s",filedata);
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    strcpy(newNode->time,"10:30 PM");
    for(int i=0; i<10; i++){
        if(strcmp(head->files[i].name,"")==0){
            strcpy(newNode->files[i].name,filename);
            strcpy(newNode->files[i].data,filedata);
            break;
        }
    }
    newNode->next = head;
    head = newNode;
    printf("File added successfully!\n");
    backupFiles(username);
}

int main(){
    char *username = (char*)malloc(MAXLEN*sizeof(char));
    printf("Enter username: ");
    scanf("%s",username);
    printf("\nWelcome %s!\n",username);
    addFile(username);
    addFile(username);
    return 0;
}