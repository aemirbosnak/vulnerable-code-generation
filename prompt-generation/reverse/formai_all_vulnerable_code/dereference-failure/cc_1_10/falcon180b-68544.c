//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Node structure
struct Node{
    int data;
    struct Node* next;
};

// Linked List structure
struct List{
    struct Node* head;
};

// Function to create a new node
struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the end of the list
void addNode(struct List* list, int data){
    struct Node* newNode = createNode(data);
    struct Node* temp = list->head;
    if(list->head == NULL){
        list->head = newNode;
        return;
    }
    while(temp->next!= NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to delete a node from the list
void deleteNode(struct List* list, int data){
    struct Node* temp = list->head;
    struct Node* prev = NULL;
    if(temp!= NULL && temp->data == data){
        list->head = temp->next;
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

// Function to search for a node in the list
struct Node* searchNode(struct List* list, int data){
    struct Node* temp = list->head;
    while(temp!= NULL){
        if(temp->data == data){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to print the list
void printList(struct List* list){
    struct Node* temp = list->head;
    while(temp!= NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
    struct List* warehouse = (struct List*)malloc(sizeof(struct List));
    warehouse->head = NULL;

    addNode(warehouse, 10);
    addNode(warehouse, 20);
    addNode(warehouse, 30);
    addNode(warehouse, 40);

    printList(warehouse);

    struct Node* nodeToDelete = searchNode(warehouse, 20);
    if(nodeToDelete!= NULL){
        deleteNode(warehouse, 20);
        printf("Node with data 20 deleted.\n");
    }

    printList(warehouse);

    return 0;
}