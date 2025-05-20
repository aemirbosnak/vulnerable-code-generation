//FormAI DATASET v1.0 Category: Linked list operations ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAtBeginning(struct Node** head, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head);
    (*head) = new_node;
    printf("Node with data %d inserted at beginning\n", new_data);
}

void insertAfter(struct Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    printf("Node with data %d inserted after node with data %d\n", new_data, prev_node->data);
}

void insertAtEnd(struct Node** head, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node* last = *head;

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        printf("Node with data %d inserted at end\n", new_data);
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
    printf("Node with data %d inserted at end\n", new_data);
}

void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head, *prev;

    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        printf("Node with data %d deleted\n", key);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node with data %d not found\n", key);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Node with data %d deleted\n", key);
}

void printList(struct Node* node) {
    printf("The linked list is: ");
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtBeginning(&head, 15);
    insertAtEnd(&head, 12);
    insertAfter(head->next, 18);
    insertAtBeginning(&head, 20);
    printList(head);
    deleteNode(&head, 20);
    printList(head);
    deleteNode(&head, 18);
    printList(head);

    return 0;
}