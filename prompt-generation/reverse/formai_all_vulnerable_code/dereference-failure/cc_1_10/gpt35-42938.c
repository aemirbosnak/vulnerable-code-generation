//FormAI DATASET v1.0 Category: Digital Diary ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char date[11];
    char entry[1000];
    struct Node* next;
} Node;

Node* HEAD = NULL;

void addEntry(){
    Node* newnode = (Node*)malloc(sizeof(Node));
    printf("\nEnter the date (DD/MM/YYYY): ");
    scanf("%s", newnode->date);
    printf("Enter the diary entry (Max 1000 characters): ");
    getchar();
    fgets(newnode->entry, 1000, stdin);
    newnode->next = HEAD;
    HEAD = newnode;
}

void viewEntries(){
    Node* temp = HEAD;
    printf("\nDIARY ENTRIES");
    printf("\n------------------------------");
    while(temp!=NULL){
        printf("\nDate: %s\n%s", temp->date, temp->entry);
        printf("\n------------------------------");
        temp = temp->next;
    }
}

void searchEntry(){
    char date[11];
    printf("\nEnter the date (DD/MM/YYYY): ");
    scanf("%s", date);
    Node* temp = HEAD;
    while(temp!=NULL){
        if(strcmp(temp->date, date) == 0){
            printf("\nENTRY FOUND\n");
            printf("\nDate: %s\n%s", temp->date, temp->entry);
            printf("\n------------------------------");
            return;
        }
        temp = temp->next;
    }
    printf("\nENTRY NOT FOUND\n");
}

void deleteEntry(){
    char date[11];
    printf("\nEnter the date (DD/MM/YYYY): ");
    scanf("%s", date);
    Node* temp = HEAD;
    Node* prev = NULL;
    while(temp!=NULL){
        if(strcmp(temp->date, date) == 0){
            if(prev==NULL){
                HEAD = HEAD->next;
            }else{
                prev->next = temp->next;
            }
            free(temp);
            printf("\nENTRY DELETED\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("\nENTRY NOT FOUND\n");
}

int main(){
    int ch;
    do{
        printf("\nDIGITAL DIARY\n");
        printf("\n1. Add Entry");
        printf("\n2. View Entries");
        printf("\n3. Search Entry");
        printf("\n4. Delete Entry");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch){
            case 1: addEntry(); break;
            case 2: viewEntries(); break;
            case 3: searchEntry(); break;
            case 4: deleteEntry(); break;
            case 5: printf("\nExiting Digital Diary"); break;
            default: printf("\nInvalid Choice!"); break;
        }
    }while(ch!=5);
    return 0;
}