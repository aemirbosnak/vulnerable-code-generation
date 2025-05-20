//FormAI DATASET v1.0 Category: Linked list operations ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertAtBeginning(int data){

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode -> data = data;
    newNode -> next = head;
    head = newNode;

}

void insertAtEnd(int data){

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode -> data = data;
    newNode -> next = NULL;

    if(head == NULL){
        head = newNode;
        return;
    }

    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp = head;

    while(temp -> next != NULL){
        temp = temp -> next;
    }

    temp -> next = newNode;

}

void insertAtPosition(int data, int position){

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode -> data = data;
    newNode -> next = NULL;

    if(position == 1){
        newNode -> next = head;
        head = newNode;
        return;
    }

    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp = head;

    for(int i=1;i<position-1;i++){
        temp = temp -> next;
    }

    newNode -> next = temp -> next;
    temp -> next = newNode;

}

void deleteFromBeginning(){

    if(head == NULL){
        printf("\nList is already empty");
        return;
    }

    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp = head;
    head = head -> next;
    free(temp);

}

void deleteFromEnd(){

    if(head == NULL){
        printf("\nList is already empty");
        return;
    }

    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    struct Node *prev = (struct Node*)malloc(sizeof(struct Node));
    temp = head;
    prev = NULL;

    while(temp -> next != NULL){
        prev = temp;
        temp = temp -> next;
    }

    free(temp);
    prev -> next = NULL;

}

void deleteFromPosition(int position){

    if(head == NULL){
        printf("\nList is already empty");
        return;
    }

    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    struct Node *prev = (struct Node*)malloc(sizeof(struct Node));
    temp = head;
    prev = NULL;
    int count = 1;

    while(temp != NULL && count != position){
        prev = temp;
        temp = temp -> next;
        count++;
    }

    if(temp == NULL){
        printf("\nPosition does not exist");
        return;
    }

    prev -> next = temp -> next;
    free(temp);

}

void displayList(){

    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp = head;

    printf("\nList is: ");

    while(temp != NULL){
        printf("%d ", temp -> data);
        temp = temp -> next;
    }

}

int main(){

    insertAtEnd(10);
    insertAtEnd(20);
    insertAtBeginning(30);
    insertAtPosition(40, 2);

    printf("After Insertion: \n");
    displayList();

    deleteFromBeginning();
    deleteFromEnd();
    deleteFromPosition(2);

    printf("\nAfter Deletion: \n");
    displayList();

    return 0;
}