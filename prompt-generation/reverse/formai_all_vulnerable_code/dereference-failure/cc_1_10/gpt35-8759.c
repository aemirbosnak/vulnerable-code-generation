//FormAI DATASET v1.0 Category: Linked list operations ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// define the structure of the linked list node
typedef struct LinkedListNode {
    int data;
    struct LinkedListNode* next;
} LinkedListNode;

LinkedListNode* head = NULL; // initialize the head of the linked list to NULL

// function to add an element to the beginning of the linked list
void push(int data) {
    LinkedListNode* newNode = (LinkedListNode*) malloc(sizeof(LinkedListNode));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

// function to remove the first element of the linked list
void pop() {
    if(head == NULL) {
        printf("Linked list is empty!");
        return;
    }

    LinkedListNode* nodeToDelete = head;
    head = head->next;
    free(nodeToDelete);
}

// function to print the elements of the linked list
void printList() {
    LinkedListNode* currentNode = head;
    printf("Linked list elements: ");
    while(currentNode != NULL) {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");
}

int main() {
    push(5); // add 5 to the linked list
    push(3); // add 3 to the linked list
    push(8); // add 8 to the linked list
    printList(); // print the linked list elements
    pop(); // remove the first element from the linked list
    printList(); // print the linked list elements after removal
    return 0;
}