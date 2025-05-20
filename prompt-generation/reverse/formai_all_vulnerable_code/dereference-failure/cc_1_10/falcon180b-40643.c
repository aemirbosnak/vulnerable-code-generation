//Falcon-180B DATASET v1.0 Category: Memory management ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Node structure definition
struct node{
    int data;
    struct node *next;
};

// Function to create a new node with given data
struct node* createNode(int data){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode == NULL){
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the end of the list
void addNode(struct node **head, int data){
    struct node *newNode = createNode(data);
    struct node *temp = *head;
    if(*head == NULL){
        *head = newNode;
        return;
    }
    while(temp->next!= NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to delete a node with given data
void deleteNode(struct node **head, int data){
    struct node *temp = *head;
    struct node *prev = NULL;
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
}

// Function to search for a node with given data
struct node* searchNode(struct node *head, int data){
    struct node *temp = head;
    while(temp!= NULL){
        if(temp->data == data){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to print the list
void printList(struct node *head){
    struct node *temp = head;
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Driver program to test above functions
int main(){
    struct node *head = NULL;
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    printList(head);
    searchNode(head, 2);
    deleteNode(&head, 1);
    printList(head);
    return 0;
}