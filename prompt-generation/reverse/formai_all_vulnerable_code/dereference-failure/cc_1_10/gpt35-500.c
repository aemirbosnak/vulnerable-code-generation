//FormAI DATASET v1.0 Category: Data structures visualization ; Style: future-proof
// This program demonstrates a unique visualization of C Data structures using ASCII art.
// It creates a linked list with three nodes and displays it using ASCII art.
// Future-Proof Style: using C standard functions and modern syntax.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void displayList(struct Node* head) {
    while (head != NULL) {
        printf(" %d -->", head->data);
        head = head->next;
    }
    printf(" NULL\n");
}

int main() {
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    // allocate 3 nodes in the heap
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    // set the data and next pointers of nodes
    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    // print the list using ASCII art
    printf("Linked List Visualization\n");
    printf("------------------------\n");
    printf("   ______    ______    ______\n");
    printf("  |      |->|      |->|      |\n");
    printf("  |  %d  |  |  %d  |  |  %d  |\n", head->data, second->data, third->data);
    printf("  |______|  |______|  |______|\n");
    printf("\n");
    printf("List traversal:\n");
    displayList(head);

    return 0;
}