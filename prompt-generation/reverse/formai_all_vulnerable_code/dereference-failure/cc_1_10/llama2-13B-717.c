//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: genius
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Node {
    int data;
    struct Node *next;
};

struct Node* initList(void) {
    struct Node* head = malloc(sizeof(struct Node));
    head->data = 1;
    head->next = NULL;
    return head;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void insertAtBeginning(struct Node** head_ref, int data) {
    struct Node* new_node = malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void insertAtEnd(struct Node** head_ref, int data) {
    struct Node* current = *head_ref;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = malloc(sizeof(struct Node));
    current->next->data = data;
}

void deleteAtBeginning(struct Node** head_ref) {
    if (*head_ref == NULL) {
        return;
    }
    free(*head_ref);
    *head_ref = (*head_ref)->next;
}

void deleteAtEnd(struct Node** head_ref) {
    struct Node* current = *head_ref;
    struct Node* previous = NULL;
    while (current != NULL) {
        if (current->next == NULL) {
            break;
        }
        previous = current;
        current = current->next;
    }
    if (previous != NULL) {
        previous->next = NULL;
    }
}

int main() {
    struct Node* head = initList();
    insertAtBeginning(&head, 2);
    insertAtEnd(&head, 3);
    deleteAtBeginning(&head);
    deleteAtEnd(&head);
    printList(head);
    return 0;
}