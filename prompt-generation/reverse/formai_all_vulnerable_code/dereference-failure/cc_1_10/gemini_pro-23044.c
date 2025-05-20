//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: complex
#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *head = NULL;

Node *create_node(int data) {
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error: Out of memory.\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_at_beginning(int data) {
    Node *new_node = create_node(data);
    new_node->next = head;
    head = new_node;
}

void insert_at_end(int data) {
    Node *new_node = create_node(data);
    if (head == NULL) {
        head = new_node;
        return;
    }
    Node *current_node = head;
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }
    current_node->next = new_node;
}

void insert_at_position(int data, int position) {
    if (position == 0) {
        insert_at_beginning(data);
        return;
    }
    Node *new_node = create_node(data);
    Node *current_node = head;
    for (int i = 0; i < position - 1; i++) {
        if (current_node == NULL) {
            printf("Error: Invalid position.\n");
            free(new_node);
            return;
        }
        current_node = current_node->next;
    }
    new_node->next = current_node->next;
    current_node->next = new_node;
}

void delete_at_beginning() {
    if (head == NULL) {
        printf("Error: List is empty.\n");
        return;
    }
    Node *temp = head;
    head = head->next;
    free(temp);
}

void delete_at_end() {
    if (head == NULL) {
        printf("Error: List is empty.\n");
        return;
    }
    Node *current_node = head;
    Node *previous_node = NULL;
    while (current_node->next != NULL) {
        previous_node = current_node;
        current_node = current_node->next;
    }
    if (previous_node == NULL) {
        head = NULL;
    } else {
        previous_node->next = NULL;
    }
    free(current_node);
}

void delete_at_position(int position) {
    if (position == 0) {
        delete_at_beginning();
        return;
    }
    Node *current_node = head;
    Node *previous_node = NULL;
    for (int i = 0; i < position; i++) {
        if (current_node == NULL) {
            printf("Error: Invalid position.\n");
            return;
        }
        previous_node = current_node;
        current_node = current_node->next;
    }
    if (previous_node == NULL) {
        head = head->next;
    } else {
        previous_node->next = current_node->next;
    }
    free(current_node);
}

void print_list() {
    Node *current_node = head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

int main() {
    insert_at_beginning(10);
    insert_at_end(20);
    insert_at_position(30, 1);
    print_list(); // Output: 10 30 20
    delete_at_beginning();
    delete_at_end();
    delete_at_position(0);
    print_list(); // Output: 30
    return 0;
}