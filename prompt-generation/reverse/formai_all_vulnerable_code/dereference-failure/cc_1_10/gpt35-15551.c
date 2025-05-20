//FormAI DATASET v1.0 Category: Data structures visualization ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

// define a structure called Node that stores integer data and a pointer to the next node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// function to add a new node to the front of the linked list
Node* addNode(Node* head, int data) {
    // create a new node and allocate memory for it
    Node* newNode = (Node*) malloc(sizeof(Node));
    // set the data of the new node
    newNode->data = data;
    // link the new node to the current head of the linked list
    newNode->next = head;
    // set the head of the linked list to the new node
    head = newNode;
    // return the new head of the linked list
    return head;
}

// function to print out the values of the nodes in the linked list
void printList(Node* head) {
    // loop through all the nodes in the linked list
    while(head != NULL) {
        // print out the data of the current node
        printf("%d --> ", head->data);
        // move to the next node in the linked list
        head = head->next;
    }
    // print out the end of the linked list
    printf("NULL\n");
}

int main() {
    // create a new linked list with no nodes
    Node* head = NULL;
    // add some nodes to the linked list
    head = addNode(head, 5);
    head = addNode(head, 3);
    head = addNode(head, 7);
    head = addNode(head, 1);
    head = addNode(head, 9);
    // print out the contents of the linked list
    printList(head);
    // return 0 to indicate successful execution
    return 0;
}