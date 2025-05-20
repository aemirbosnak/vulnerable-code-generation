//FormAI DATASET v1.0 Category: Linked list operations ; Style: distributed
#include <stdlib.h>
#include <stdio.h>

struct node{
    int data;
    struct node* next;
};

typedef struct node* nodeptr;

//Function prototypes 
nodeptr createNode(int data);
void deleteNode(nodeptr node);
void insertNode(nodeptr* head, int data);
void deleteList(nodeptr* head);

void distributedInsert(nodeptr* head, int data){
    //In a distributed system, each node maintains its own list
    //So we will insert the data to the local list
    insertNode(head, data);
}

int main(){
    nodeptr head = NULL;
    distributedInsert(&head, 5); //Node 1
    distributedInsert(&head, 7); //Node 2
    distributedInsert(&head, 10); //Node 3

    //Printing distributed list
    printf("Distributed Linked List:\n");
    nodeptr curr = head;
    while(curr != NULL){
        printf("%d ", curr->data);
        curr = curr->next;
    }

    //Delete distributed list
    deleteList(&head);
    printf("\nDistributed Linked List deleted successfully.\n");
    return 0;
}

nodeptr createNode(int data){
    nodeptr newNode = (nodeptr)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void deleteNode(nodeptr node){
    free(node);
}

void insertNode(nodeptr* head, int data){
    nodeptr newNode = createNode(data); //Create a new node
    newNode->next = *head; //new node points to head node
    *head = newNode; //head points to new node
}

void deleteList(nodeptr* head){
    nodeptr curr = *head;
    nodeptr next;
    while(curr != NULL){
        next = curr->next;
        deleteNode(curr);
        curr = next;
    }
    *head = NULL;
}