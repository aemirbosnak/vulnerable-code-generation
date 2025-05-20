//FormAI DATASET v1.0 Category: Memory management ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node* next;
};

void insert(struct Node** head, int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = (*head);
    (*head) = node;
}

int main() {
    struct Node* first = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;
    
    // allocate memory for the nodes
    first = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    // assign data values and link nodes
    first->data = 1;
    first->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    // print list
    struct Node* current = first;
    while(current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    // insert new node at front
    insert(&first, 4);
    
    // print list after insertion
    current = first;
    while(current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    // free memory
    free(first);
    free(second);
    free(third);

    return 0;
}