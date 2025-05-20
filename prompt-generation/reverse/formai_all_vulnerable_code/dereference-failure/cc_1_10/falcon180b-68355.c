//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: irregular
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

void addNode(node** head, int data){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    if(*head == NULL){
        *head = newNode;
        return;
    }
    node* temp = *head;
    while(temp->next!= NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    return;
}

void deleteNode(node** head, int data){
    node* temp = *head;
    node* prev = NULL;
    if(temp!= NULL && temp->data == data){
        *head = temp->next;
        free(temp);
        return;
    }
    while(temp!= NULL && temp->data!= data){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        return;
    }
    prev->next = temp->next;
    free(temp);
    return;
}

void displayList(node* head){
    node* temp = head;
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return;
}

void reverseList(node** head){
    node* prev = NULL;
    node* curr = *head;
    while(curr!= NULL){
        node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
    return;
}

int main(){
    node* head = NULL;
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 4);
    displayList(head);
    reverseList(&head);
    displayList(head);
    deleteNode(&head, 3);
    displayList(head);
    return 0;
}