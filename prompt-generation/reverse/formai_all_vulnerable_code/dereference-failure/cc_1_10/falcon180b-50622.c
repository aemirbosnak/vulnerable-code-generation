//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

// Node structure definition
struct Node {
    int data;
    struct Node* next;
};

void append(struct Node** head_ref, int new_data);
void printList(struct Node* node);

int main() {
    struct Node* head = NULL;

    // Append 7 to the empty list
    append(&head, 7);

    // Append 1 to the list
    append(&head, 1);

    // Append 6 to the list
    append(&head, 6);

    // Print the list
    printList(head);

    return 0;
}

void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node* last = *head_ref;

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        new_node->next = new_node;
        *head_ref = new_node;
    } else {
        while (last->next!= *head_ref) {
            last = last->next;
        }
        last->next = new_node;
        new_node->next = *head_ref;
    }
}

void printList(struct Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}