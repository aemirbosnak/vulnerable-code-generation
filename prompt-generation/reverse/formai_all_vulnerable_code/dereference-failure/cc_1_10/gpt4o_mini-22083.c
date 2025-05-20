//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

void deleteNode(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref;
    struct Node* prev = NULL;

    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;

    // Random values for the list
    for (int i = 1; i <= 5; i++) {
        append(&head, i * 10);
    }

    printf("Original Linked List:\n");
    printList(head);

    printf("Deleting node with value 30:\n");
    deleteNode(&head, 30);
    printList(head);

    printf("Appending value 60:\n");
    append(&head, 60);
    printList(head);

    printf("Appending value 70:\n");
    append(&head, 70);
    printList(head);

    printf("Deleting node with value 10:\n");
    deleteNode(&head, 10);
    printList(head);

    // Cleanup
    freeList(head);
    head = NULL;

    printf("Linked List after cleanup:\n");
    printList(head); // Should print 'NULL'

    return 0;
}