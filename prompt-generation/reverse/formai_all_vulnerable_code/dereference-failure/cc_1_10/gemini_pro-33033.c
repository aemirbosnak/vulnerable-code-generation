//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *create_node(int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_at_beginning(Node **head, int data) {
    Node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

void insert_at_end(Node **head, int data) {
    Node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    Node *last_node = *head;
    while (last_node->next != NULL) {
        last_node = last_node->next;
    }
    last_node->next = new_node;
}

void insert_at_index(Node **head, int data, int index) {
    if (index == 0) {
        insert_at_beginning(head, data);
        return;
    }
    Node *new_node = create_node(data);
    Node *current_node = *head;
    int i = 0;
    while (current_node != NULL && i < index - 1) {
        current_node = current_node->next;
        i++;
    }
    if (current_node == NULL || i < index - 1) {
        printf("Invalid index\n");
        return;
    }
    new_node->next = current_node->next;
    current_node->next = new_node;
}

void delete_at_beginning(Node **head) {
    if (*head == NULL) {
        return;
    }
    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void delete_at_end(Node **head) {
    if (*head == NULL) {
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    Node *current_node = *head;
    while (current_node->next->next != NULL) {
        current_node = current_node->next;
    }
    free(current_node->next);
    current_node->next = NULL;
}

void delete_at_index(Node **head, int index) {
    if (index == 0) {
        delete_at_beginning(head);
        return;
    }
    Node *current_node = *head;
    int i = 0;
    while (current_node != NULL && i < index - 1) {
        current_node = current_node->next;
        i++;
    }
    if (current_node == NULL || current_node->next == NULL || i < index - 1) {
        printf("Invalid index\n");
        return;
    }
    Node *temp = current_node->next;
    current_node->next = temp->next;
    free(temp);
}

void print_list(Node *head) {
    Node *current_node = head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

int main() {
    Node *head = NULL;

    insert_at_beginning(&head, 10);
    insert_at_end(&head, 20);
    insert_at_index(&head, 30, 1);
    insert_at_index(&head, 40, 3);

    print_list(head); // Output: 10 30 20 40

    delete_at_beginning(&head);
    delete_at_end(&head);
    delete_at_index(&head, 1);

    print_list(head); // Output: 30

    return 0;
}