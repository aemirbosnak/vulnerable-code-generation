//FormAI DATASET v1.0 Category: Linked list operations ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

// define node structure
typedef struct node{
    int data;
    struct node *next;
} Node;

// function to add new node to beginning of linked list
void addNode(Node **head, int newData){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = newData;
    newNode->next = *head;
    *head = newNode;
}

// function to remove node from linked list
void removeNode(Node **head, int key){
    Node *temp = *head, *prev;

    if(temp != NULL && temp->data == key){
        *head = temp->next;
        free(temp);
        return;
    }

    while(temp != NULL && temp->data != key){
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL){
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// function to print linked list
void printList(Node *node){
    while(node != NULL){
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main(){
    Node *head = NULL;
    addNode(&head, 5);
    addNode(&head, 3);
    addNode(&head, 7);
    addNode(&head, 1);
    addNode(&head, 9);

    // initial linked list
    printf("Initial linked list: ");
    printList(head);

    // player 1 removes node
    printf("Player 1 removes node 7.\n");
    removeNode(&head, 7);
    printList(head);

    // player 2 adds node
    printf("Player 2 adds node 2 to beginning.\n");
    addNode(&head, 2);
    printList(head);

    // player 3 removes node
    printf("Player 3 removes node 1.\n");
    removeNode(&head, 1);
    printList(head);

    // player 1 adds node
    printf("Player 1 adds node 4 to beginning.\n");
    addNode(&head, 4);
    printList(head);

    // player 2 removes node
    printf("Player 2 removes node 3.\n");
    removeNode(&head, 3);
    printList(head);

    // player 3 adds node
    printf("Player 3 adds node 8 to beginning.\n");
    addNode(&head, 8);
    printList(head);

    return 0;
}