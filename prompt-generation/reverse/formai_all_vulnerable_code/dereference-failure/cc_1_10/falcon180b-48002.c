//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: recursive
#include<stdio.h>
#include<stdlib.h>

// Structure for a node
struct node{
    int data;
    struct node* next;
};

// Function to create a new node
struct node* createNode(int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the beginning of the list
void addNodeAtBeginning(struct node** head, int data){
    struct node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to add a node at the end of the list
void addNodeAtEnd(struct node** head, int data){
    struct node* newNode = createNode(data);

    if(*head == NULL){
        *head = newNode;
        return;
    }

    struct node* temp = *head;

    while(temp->next!= NULL){
        temp = temp->next;
    }

    temp->next = newNode;
}

// Function to add a node at a specific position in the list
void addNodeAtPosition(struct node** head, int data, int position){
    struct node* newNode = createNode(data);

    if(position == 0){
        addNodeAtBeginning(head, data);
        return;
    }

    struct node* temp = *head;

    for(int i=1; i<position-1 && temp!= NULL; i++){
        temp = temp->next;
    }

    if(temp == NULL){
        printf("Invalid position\n");
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to delete a node with a specific data value
void deleteNode(struct node** head, int data){
    struct node* temp = *head;

    if(temp!= NULL && temp->data == data){
        *head = temp->next;
        free(temp);
        return;
    }

    while(temp!= NULL && temp->data!= data){
        temp = temp->next;
    }

    if(temp == NULL){
        printf("Node not found\n");
        return;
    }

    struct node* prevNode = temp->next;
    temp->next = temp->next->next;
    free(prevNode);
}

// Function to print the list
void printList(struct node* head){
    while(head!= NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Main function
int main(){
    struct node* head = NULL;

    // Adding nodes
    addNodeAtBeginning(&head, 1);
    addNodeAtEnd(&head, 2);
    addNodeAtPosition(&head, 3, 1);
    addNodeAtEnd(&head, 4);
    addNodeAtPosition(&head, 5, 3);

    // Printing the list
    printList(head);

    // Deleting a node
    deleteNode(&head, 3);

    // Printing the list after deletion
    printList(head);

    return 0;
}