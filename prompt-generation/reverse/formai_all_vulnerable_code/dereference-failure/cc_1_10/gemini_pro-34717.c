//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: complete
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *create_node(int data) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error: malloc failed.\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_at_head(Node **head, int data) {
    Node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

void insert_at_tail(Node **head, int data) {
    Node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    Node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

void insert_at_index(Node **head, int index, int data) {
    if (index < 0) {
        printf("Error: Invalid index.\n");
        return;
    }
    if (index == 0) {
        insert_at_head(head, data);
        return;
    }
    Node *new_node = create_node(data);
    Node *current = *head;
    int i = 0;
    while (current != NULL && i < index - 1) {
        current = current->next;
        i++;
    }
    if (current == NULL) {
        printf("Error: Index out of range.\n");
        return;
    }
    new_node->next = current->next;
    current->next = new_node;
}

void delete_at_head(Node **head) {
    if (*head == NULL) {
        printf("Error: List is empty.\n");
        return;
    }
    Node *to_delete = *head;
    *head = (*head)->next;
    free(to_delete);
}

void delete_at_tail(Node **head) {
    if (*head == NULL) {
        printf("Error: List is empty.\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    Node *current = *head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    Node *to_delete = current->next;
    current->next = NULL;
    free(to_delete);
}

void delete_at_index(Node **head, int index) {
    if (index < 0) {
        printf("Error: Invalid index.\n");
        return;
    }
    if (index == 0) {
        delete_at_head(head);
        return;
    }
    Node *current = *head;
    int i = 0;
    while (current != NULL && i < index - 1) {
        current = current->next;
        i++;
    }
    if (current == NULL || current->next == NULL) {
        printf("Error: Index out of range.\n");
        return;
    }
    Node *to_delete = current->next;
    current->next = to_delete->next;
    free(to_delete);
}

void print_list(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node *head = NULL;
    insert_at_head(&head, 1);
    insert_at_tail(&head, 2);
    insert_at_index(&head, 1, 3);
    print_list(head);  // Output: 1 3 2

    delete_at_head(&head);
    delete_at_tail(&head);
    delete_at_index(&head, 0);
    print_list(head);  // Output: 3

    return 0;
}