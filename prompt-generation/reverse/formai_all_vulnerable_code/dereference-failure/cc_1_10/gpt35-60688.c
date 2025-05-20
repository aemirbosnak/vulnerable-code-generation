//FormAI DATASET v1.0 Category: Data structures visualization ; Style: happy
#include <stdio.h>
#include <stdlib.h>

//A happy linked list data structure visualization program

typedef struct Node{
    int data;
    struct Node* next;
}Node;

void printList(Node* head){
    Node* current = head;
    printf("Happiness is adding new nodes to this linked list!\n");
    while(current != NULL){
        printf("%d\n", current->data);
        current = current->next;
    }
    printf("The list brought you so much joy!\n");
}

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* addToEnd(Node* head, int data){
    Node* newNode = createNode(data);
    if(head == NULL){
        return newNode;
    }
    Node* current = head;
    while(current->next != NULL){
        current = current->next;
    }
    current->next = newNode;
    return head;
}

Node* addToBeginning(Node* head, int data){
    Node* newNode = createNode(data);
    if(head == NULL){
        return newNode;
    }
    newNode->next = head;
    return newNode;
}

Node* removeFromBeginning(Node* head){
    if(head == NULL){
        printf("The list is already empty :(\n");
        return head;
    }
    printf("Happiness is removing a node from the beginning of this linked list!\n");
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

Node* removeFromEnd(Node* head){
    if(head == NULL){
        printf("The list is already empty :(\n");
        return head;
    }
    printf("Happiness is removing a node from the end of this linked list!\n");
    Node* current = head;
    Node* previous = NULL;
    while(current->next != NULL){
        previous = current;
        current = current->next;
    }
    free(current);
    if(previous == NULL){
        head = NULL;
        return head;
    }
    previous->next = NULL;
    return head;
}

int main(){
    Node* head = NULL;

    head = addToEnd(head, 5);
    head = addToEnd(head, 10);
    head = addToBeginning(head, 1);
    printList(head);
    head = removeFromBeginning(head);
    head = removeFromEnd(head);
    printList(head);

    printf("Isn't this the happiest linked list you've ever seen? :D\n");
    return 0;
}