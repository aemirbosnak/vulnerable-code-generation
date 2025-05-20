//FormAI DATASET v1.0 Category: Data structures visualization ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void printLinkedList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node *head = NULL;
    struct Node *second = NULL;
    struct Node *third = NULL;

    head = (struct Node*) malloc(sizeof (struct Node));
    second = (struct Node*) malloc(sizeof (struct Node));
    third = (struct Node*) malloc(sizeof (struct Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    printf("Initial Linked List: ");
    printLinkedList(head);

    // Inserting a Node at the Beginning
    struct Node *new_node = (struct Node*) malloc(sizeof (struct Node));
    new_node->data = 0;
    new_node->next = head;
    head = new_node;

    printf("Linked List after Inserting at the Beginning: ");
    printLinkedList(head);

    // Inserting a Node at the End
    struct Node *last_node = (struct Node*) malloc(sizeof (struct Node));
    last_node->data = 4;
    last_node->next = NULL;

    struct Node *temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = last_node;

    printf("Linked List after Inserting at the End: ");
    printLinkedList(head);

    // Inserting a Node in the Middle
    struct Node *middle_node = (struct Node*) malloc(sizeof (struct Node));
    middle_node->data = 2.5;

    temp = head;
    while(temp->next->data != 3) {
        temp = temp->next;
    }
    middle_node->next = temp->next;
    temp->next = middle_node;

    printf("Linked List after Inserting in the Middle: ");
    printLinkedList(head);

    // Deleting a Node from the Beginning
    struct Node *delete_node = head;
    head = head->next;
    free(delete_node);

    printf("Linked List after Deleting from the Beginning: ");
    printLinkedList(head);

    // Deleting a Node from the End
    delete_node = head;
    while(delete_node->next->next != NULL) {
        delete_node = delete_node->next;
    }
    free(delete_node->next);
    delete_node->next = NULL;

    printf("Linked List after Deleting from the End: ");
    printLinkedList(head);

    // Deleting a Node from the Middle
    delete_node = head;
    temp = NULL;
    while(delete_node->data != 2) {
        temp = delete_node;
        delete_node = delete_node->next;
    }
    temp->next = delete_node->next;
    free(delete_node);

    printf("Linked List after Deleting from the Middle: ");
    printLinkedList(head);

    return 0;
}