//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a data structure to represent a node in a linked list
struct Node {
    int value;
    struct Node* next;
};

// Define a function to initialize the head of the linked list
void initList(struct Node** head) {
    *head = NULL;
}

// Define a function to add a new node to the end of the linked list
void addNode(struct Node** head, int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Define a function to print the values of all nodes in the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current!= NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    initList(&head);

    addNode(head, 1);
    addNode(head, 2);
    addNode(head, 3);

    printList(head);

    return 0;
}