//FormAI DATASET v1.0 Category: Memory management ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

// Define structure for node
struct Node {
    int data;
    struct Node* next;
};

// Display the linked list
void displayList(struct Node* head) {
    struct Node* ptr = head;
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

int main() {
    // Create a linked list with three nodes
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    // Display the original linked list
    printf("Original Linked List:\n");
    displayList(head);

    // Memory Management: Free the second node and connect the first and third nodes
    struct Node* temp = second;
    head->next = third;
    free(temp);

    // Display the updated linked list
    printf("Updated Linked List:\n");
    displayList(head);

    return 0;
}