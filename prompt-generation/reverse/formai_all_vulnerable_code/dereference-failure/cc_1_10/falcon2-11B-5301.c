//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Linked List structure
typedef struct list {
    Node* head;
} List;

// Function to print a linked list
void printList(List* list) {
    if (list == NULL) {
        printf("The list is empty.\n");
        return;
    }

    Node* current = list->head;
    printf("The linked list is:\n");
    while (current!= NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    // Create a new linked list
    List* myList = (List*)malloc(sizeof(List));
    myList->head = NULL;

    // Add nodes to the linked list
    Node* node1 = (Node*)malloc(sizeof(Node));
    node1->data = 1;
    node1->next = NULL;
    myList->head = node1;

    Node* node2 = (Node*)malloc(sizeof(Node));
    node2->data = 2;
    node2->next = NULL;
    myList->head->next = node2;

    Node* node3 = (Node*)malloc(sizeof(Node));
    node3->data = 3;
    node3->next = NULL;
    myList->head->next->next = node3;

    // Print the linked list
    printList(myList);

    // Free memory
    free(node1);
    free(node2);
    free(node3);
    free(myList);

    return 0;
}