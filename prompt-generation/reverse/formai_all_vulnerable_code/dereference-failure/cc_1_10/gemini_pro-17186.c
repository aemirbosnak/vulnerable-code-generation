//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: automated
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

node_t *head = NULL;

void insert_at_beginning(int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

void insert_at_end(int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        node_t *current_node = head;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
}

void insert_at_position(int data, int position) {
    if (position == 1) {
        insert_at_beginning(data);
        return;
    }

    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;

    int current_position = 1;
    node_t *current_node = head;
    while (current_node != NULL && current_position < position - 1) {
        current_node = current_node->next;
        current_position++;
    }

    if (current_node != NULL) {
        new_node->next = current_node->next;
        current_node->next = new_node;
    } else {
        printf("Invalid position!\n");
        free(new_node);
    }
}

void delete_at_beginning() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    node_t *temp_node = head;
    head = head->next;
    free(temp_node);
}

void delete_at_end() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (head->next == NULL) {
        head = NULL;
        return;
    }

    node_t *current_node = head;
    while (current_node->next->next != NULL) {
        current_node = current_node->next;
    }

    node_t *temp_node = current_node->next;
    current_node->next = NULL;
    free(temp_node);
}

void delete_at_position(int position) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (position == 1) {
        delete_at_beginning();
        return;
    }

    int current_position = 1;
    node_t *current_node = head;
    while (current_node != NULL && current_position < position - 1) {
        current_node = current_node->next;
        current_position++;
    }

    if (current_node != NULL && current_node->next != NULL) {
        node_t *temp_node = current_node->next;
        current_node->next = current_node->next->next;
        free(temp_node);
    } else {
        printf("Invalid position!\n");
    }
}

void print_list() {
    node_t *current_node = head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

int main() {
    // Insert at beginning
    insert_at_beginning(10);
    insert_at_beginning(20);

    // Insert at end
    insert_at_end(30);
    insert_at_end(40);

    // Insert at position
    insert_at_position(50, 3);

    // Print the list
    printf("Linked list: ");
    print_list();

    // Delete at beginning
    delete_at_beginning();

    // Delete at end
    delete_at_end();

    // Delete at position
    delete_at_position(2);

    // Print the list again
    printf("Linked list after deletions: ");
    print_list();

    return 0;
}