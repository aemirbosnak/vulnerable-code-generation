//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAtBeginning(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
}

void insertAtPosition(struct Node** head_ref, int new_data, int position) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;

    if (position == 0) {
        new_node->next = *head_ref;
        *head_ref = new_node;
        return;
    }

    struct Node* current = *head_ref;
    for (int i = 0; i < position - 1 && current != NULL; i++)
        current = current->next;

    if (current == NULL) {
        printf("Position does not exist!\n");
        free(new_node);
        return;
    }

    new_node->next = current->next;
    current->next = new_node;
}

void deleteNode(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref, *prev = NULL;

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

void displayList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int searchNode(struct Node* head, int key) {
    int position = 0;
    while (head != NULL) {
        if (head->data == key)
            return position;
        head = head->next;
        position++;
    }
    return -1; // Not found
}

int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtBeginning(&head, 0);
    insertAtPosition(&head, 1, 1);
    printf("Linked list after insertions:\n");
    displayList(head);

    printf("Deleting node with value 1.\n");
    deleteNode(&head, 1);
    printf("Linked list after deletion:\n");
    displayList(head);

    int key = 2;
    int position = searchNode(head, key);
    if (position != -1) {
        printf("Node with value %d found at position %d.\n", key, position);
    } else {
        printf("Node with value %d not found in the list.\n", key);
    }

    // Freeing the list
    struct Node* current = head;
    struct Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    return 0;
}