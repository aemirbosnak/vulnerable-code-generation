//FormAI DATASET v1.0 Category: Linked list operations ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insert_front(Node** head, int value) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = *head;
    *head = new_node;
}

void insert_end(Node** head, int value) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

void delete_node(Node** head, int key) {
    Node* current = *head;
    Node* prev = NULL;
    if (current != NULL && current->data == key) {
        *head = current->next;
        free(current);
        return;
    }
    while (current != NULL && current->data != key) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        return;
    }
    prev->next = current->next;
    free(current);
}

void print_list(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    insert_end(&head, 10);
    insert_end(&head, 20);
    insert_front(&head, 5);
    insert_front(&head, 2);
    printf("Initial list: ");
    print_list(head);
    delete_node(&head, 5);
    printf("List after deleting 5: ");
    print_list(head);
    return 0;
}