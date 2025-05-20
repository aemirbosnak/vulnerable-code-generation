//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: light-weight
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
}

void printList(node* head){
    node* temp = head;
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void deleteNode(node** head, int data){
    node* temp = *head;
    node* prev = NULL;
    while(temp!= NULL && temp->data!= data){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        printf("Element not found!\n");
        return;
    }
    if(prev == NULL){
        *head = temp->next;
    }
    else{
        prev->next = temp->next;
    }
    free(temp);
}

void searchElement(node* head, int data){
    node* temp = head;
    while(temp!= NULL){
        if(temp->data == data){
            printf("Element found!\n");
            return;
        }
        temp = temp->next;
    }
    printf("Element not found!\n");
}

int main(){
    node* head = NULL;
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 4);
    addNode(&head, 5);
    printList(head);
    deleteNode(&head, 3);
    printList(head);
    searchElement(head, 4);
    searchElement(head, 6);
    return 0;
}