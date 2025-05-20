//FormAI DATASET v1.0 Category: Data structures visualization ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

/* Struct for a node in a linked list */
struct Node {
    int data;           // Data stored in the node
    struct Node* next;  // Pointer to next node in the list
};

/* Function to create a new node and return the pointer to it */
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/* Function to print the linked list starting from a given node */
void printList(struct Node* head) {
    printf("List contents: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    /* Initialize a linked list with three nodes */
    struct Node* listHead = createNode(1);
    struct Node* node2 = createNode(2);
    struct Node* node3 = createNode(3);
    listHead->next = node2;
    node2->next = node3;

    /* Print the contents of the list before modifications */
    printList(listHead);

    /* Insert a new node at the beginning of the list */
    struct Node* newHead = createNode(0);
    newHead->next = listHead;
    listHead = newHead;
    printList(listHead);

    /* Insert a new node after the second node in the list */
    struct Node* newNode = createNode(5);
    newNode->next = node3;
    node2->next = newNode;
    printList(listHead);

    /* Delete the last node in the list */
    struct Node* currNode = listHead;
    while (currNode->next->next != NULL) {
        currNode = currNode->next;
    }
    free(currNode->next);
    currNode->next = NULL;
    printList(listHead);

    /* Free memory allocated for the list */
    while (listHead != NULL) {
        currNode = listHead;
        listHead = listHead->next;
        free(currNode);
    }

    return 0;
}