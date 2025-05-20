//FormAI DATASET v1.0 Category: Linked list operations ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

// Function to insert a new node at the beginning of the list
void insertAtBeginning(struct node** head, int data){
    
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
    
    printf("Node inserted at beginning: %d\n", data);
}

// Function to insert a new node after a given node
void insertAfterNode(struct node* prevNode, int data){

    if (prevNode == NULL){
        printf("Previous node cannot be null\n");
        return;
    }

    struct node* newNode = (struct node*) malloc(sizeof(struct node));

    newNode->data = data;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    
    printf("Node inserted after given node: %d\n", data);
}

// Function to insert a new node at the end of the list
void insertAtEnd(struct node** head, int data){

    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    struct node* last = *head;

    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL){
        *head = newNode;
        printf("Node inserted at end: %d\n", data);
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = newNode;
    
    printf("Node inserted at end: %d\n", data);
}

// Function to delete a node with a given key
void deleteNode(struct node** head, int key){

    struct node* temp = *head;
    struct node* prevNode = NULL;

    if (temp != NULL && temp->data == key){
        *head = temp->next;
        free(temp);
        printf("Node with key value %d removed from the list\n", key);
        return;
    }

    while (temp != NULL && temp->data != key){
        prevNode = temp;
        temp = temp->next;
    }

    if (temp == NULL){
        printf("Node with key value %d not found in the list\n", key);
        return;
    }

    prevNode->next = temp->next;
    free(temp);
    printf("Node with key value %d removed from the list\n", key);
}

// Function to print the list
void printList(struct node* head){

    printf("List elements: ");

    while (head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }

    printf("\n");
}

int main(){

    struct node* head = NULL;

    insertAtEnd(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtEnd(&head, 3);
    insertAfterNode(head->next, 4);
    deleteNode(&head, 2);
    printList(head);

    return 0;
}