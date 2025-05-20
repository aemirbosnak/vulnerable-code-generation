//Falcon-180B DATASET v1.0 Category: Educational ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// function to create a linked list node
struct Node {
    int data;
    struct Node* next;
};

// function to insert a node at the end of the linked list
void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        new_node->next = new_node;
        *head_ref = new_node;
    } else {
        struct Node* last_node = *head_ref;
        while (last_node->next!= *head_ref) {
            last_node = last_node->next;
        }
        last_node->next = new_node;
        new_node->next = *head_ref;
    }
}

// function to print the linked list
void printList(struct Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

// main function
int main() {
    struct Node* head = NULL;

    // insert nodes
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);

    // print the linked list
    printf("Linked List: ");
    printList(head);

    return 0;
}