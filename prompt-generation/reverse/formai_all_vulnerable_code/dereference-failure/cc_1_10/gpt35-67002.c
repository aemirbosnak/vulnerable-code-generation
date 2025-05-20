//FormAI DATASET v1.0 Category: Memory management ; Style: retro
#include<stdio.h>
#include<stdlib.h>

// The Node structure
struct Node {
    int data;
    struct Node* next;
};

typedef struct Node* NodePtr;

// Function to print the nodes in the list
void printList(NodePtr head) {
    NodePtr curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    // Creating list of 5 nodes
    NodePtr head;
    head = (NodePtr) malloc(sizeof(struct Node));
    head->data = 1;
    head->next = (NodePtr) malloc(sizeof(struct Node));
    head->next->data = 2;
    head->next->next = (NodePtr) malloc(sizeof(struct Node));
    head->next->next->data = 3;
    head->next->next->next = (NodePtr) malloc(sizeof(struct Node));
    head->next->next->next->data = 4;
    head->next->next->next->next = (NodePtr) malloc(sizeof(struct Node));
    head->next->next->next->next->data = 5;
    head->next->next->next->next->next = NULL;

    // Printing the original list
    printf("Original List: ");
    printList(head);

    // Deleting the elements of the list and freeing their memory
    while (head != NULL) {
        NodePtr temp = head;
        head = head->next;
        free(temp);
    }

    // Creating a new list of 3 nodes
    head = (NodePtr) malloc(sizeof(struct Node));
    head->data = 10;
    head->next = (NodePtr) malloc(sizeof(struct Node));
    head->next->data = 20;
    head->next->next = (NodePtr) malloc(sizeof(struct Node));
    head->next->next->data = 30;
    head->next->next->next = NULL;

    // Printing the new list
    printf("New List: ");
    printList(head);

    // Deleting the elements of the list and freeing their memory
    while (head != NULL) {
        NodePtr temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}