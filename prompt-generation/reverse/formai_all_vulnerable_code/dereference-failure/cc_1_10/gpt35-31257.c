//FormAI DATASET v1.0 Category: Linked list operations ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void printList(struct Node* n) {
    printf("Linked List: ");
    while (n != NULL) {
        printf("%d ", n->data);
        n = n->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
    printf("%d added to the beginning of the list\n", new_data);
}

void insertAfter(struct Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("Previous node can't be NULL\n");
        return;
    }
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    printf("%d added after the previous node\n", new_data);
}

void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        printf("%d added to the end of the empty list\n", new_data);
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    printf("%d added to the end of the list\n", new_data);
}

void deleteNode(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref, *prev;
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        printf("%d deleted from the list\n", key);
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("%d not found in the list\n", key);
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("%d deleted from the list\n", key);
}

int main() {
    struct Node* head = NULL;
    push(&head, 1);
    append(&head, 2);
    append(&head, 3);
    insertAfter(head->next, 4);
    printList(head);
    deleteNode(&head, 2);
    printList(head);
    return 0;
}