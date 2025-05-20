//Falcon-180B DATASET v1.0 Category: Educational ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Node structure for singly linked list
struct node{
    int data;
    struct node* next;
};

//Function to create a new node
struct node* createNode(int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//Function to insert a new node at the end of the list
void insert(struct node** head, int data){
    struct node* newNode = createNode(data);
    struct node* temp = *head;

    if(*head == NULL){
        newNode->next = NULL;
        *head = newNode;
        return;
    }

    while(temp->next!= NULL){
        temp = temp->next;
    }

    temp->next = newNode;
}

//Function to delete a node with given data
void deleteNode(struct node** head, int data){
    struct node* temp = *head;
    struct node* prev = NULL;

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

//Function to print the list
void printList(struct node* head){
    struct node* temp = head;
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

//Main function
int main(){
    struct node* head = NULL;

    //Inserting nodes
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);

    //Printing list
    printf("Original list: ");
    printList(head);

    //Deleting node with data 3
    deleteNode(&head, 3);

    //Printing list after deletion
    printf("\nList after deleting node with data 3: ");
    printList(head);

    //Deleting node with data 1
    deleteNode(&head, 1);

    //Printing list after deletion
    printf("\nList after deleting node with data 1: ");
    printList(head);

    return 0;
}