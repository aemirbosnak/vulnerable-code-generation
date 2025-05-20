//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: brave
#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node *next;
} node_t;

node_t *head = NULL;

void print_list() {
    node_t *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void insert_at_beginning(int data) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

void insert_at_end(int data) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
    } else {
        node_t *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void insert_at_index(int data, int index) {
    if (index == 0) {
        insert_at_beginning(data);
    } else {
        node_t *new_node = malloc(sizeof(node_t));
        new_node->data = data;
        node_t *current = head;
        int i = 0;
        while (i < index - 1 && current->next != NULL) {
            current = current->next;
            i++;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

void delete_at_beginning() {
    if (head != NULL) {
        node_t *temp = head;
        head = head->next;
        free(temp);
    }
}

void delete_at_end() {
    if (head != NULL) {
        if (head->next == NULL) {
            free(head);
            head = NULL;
        } else {
            node_t *current = head;
            while (current->next->next != NULL) {
                current = current->next;
            }
            free(current->next);
            current->next = NULL;
        }
    }
}

void delete_at_index(int index) {
    if (index == 0) {
        delete_at_beginning();
    } else {
        node_t *current = head;
        int i = 0;
        while (i < index - 1 && current->next != NULL) {
            current = current->next;
            i++;
        }
        if (current->next != NULL) {
            node_t *temp = current->next;
            current->next = current->next->next;
            free(temp);
        }
    }
}

int main() {
    // Create a linked list
    insert_at_beginning(1);
    insert_at_end(2);
    insert_at_index(3, 1);
    insert_at_index(4, 3);

    // Print the linked list
    printf("Linked list: ");
    print_list();

    // Delete a node at the beginning
    delete_at_beginning();

    // Print the linked list
    printf("Linked list after deleting a node at the beginning: ");
    print_list();

    // Delete a node at the end
    delete_at_end();

    // Print the linked list
    printf("Linked list after deleting a node at the end: ");
    print_list();

    // Delete a node at an index
    delete_at_index(1);

    // Print the linked list
    printf("Linked list after deleting a node at index 1: ");
    print_list();

    return 0;
}