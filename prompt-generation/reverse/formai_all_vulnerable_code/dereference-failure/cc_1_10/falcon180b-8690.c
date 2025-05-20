//Falcon-180B DATASET v1.0 Category: Memory management ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct Node{
    int data;
    struct Node* next;
};

void createList(struct Node** head){
    int i;
    struct Node* newNode, *temp = NULL;
    for(i=0; i<SIZE; i++){
        newNode = (struct Node*)malloc(sizeof(struct Node));
        if(newNode == NULL){
            printf("Memory Error\n");
            exit(0);
        }
        newNode->data = i;
        newNode->next = NULL;
        if(*head == NULL){
            *head = newNode;
            temp = newNode;
        }
        else{
            temp->next = newNode;
            temp = temp->next;
        }
    }
}

void displayList(struct Node* head){
    struct Node* temp = head;
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void deleteList(struct Node** head){
    struct Node* temp = *head;
    while(temp!= NULL){
        *head = temp->next;
        free(temp);
        temp = *head;
    }
}

int main(){
    struct Node* head = NULL;
    createList(&head);
    displayList(head);
    deleteList(&head);
    return 0;
}