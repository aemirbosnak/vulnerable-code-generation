//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: paranoid
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *head = NULL;

void insert_at_beginning(int data) {
    node *new_node = (node *)malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Error allocating memory.\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

void insert_at_end(int data) {
    node *new_node = (node *)malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Error allocating memory.\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
    } else {
        node *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void insert_at_position(int data, int position) {
    if (position == 1) {
        insert_at_beginning(data);
        return;
    }
    node *new_node = (node *)malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Error allocating memory.\n");
        exit(1);
    }
    new_node->data = data;
    node *current = head;
    int i = 1;
    while (current != NULL && i < position - 1) {
        current = current->next;
        i++;
    }
    if (current == NULL) {
        printf("Invalid position.\n");
        free(new_node);
        return;
    }
    new_node->next = current->next;
    current->next = new_node;
}

void delete_at_beginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    node *temp = head;
    head = head->next;
    free(temp);
}

void delete_at_end() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    node *current = head;
    node *previous = NULL;
    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }
    if (previous == NULL) {
        head = NULL;
    } else {
        previous->next = NULL;
    }
    free(current);
}

void delete_at_position(int position) {
    if (position == 1) {
        delete_at_beginning();
        return;
    }
    node *current = head;
    node *previous = NULL;
    int i = 1;
    while (current != NULL && i < position) {
        previous = current;
        current = current->next;
        i++;
    }
    if (current == NULL) {
        printf("Invalid position.\n");
        return;
    }
    if (previous == NULL) {
        head = head->next;
    } else {
        previous->next = current->next;
    }
    free(current);
}

void print_list() {
    node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    insert_at_beginning(10);
    insert_at_end(20);
    insert_at_position(30, 2);
    print_list();
    delete_at_beginning();
    delete_at_end();
    delete_at_position(2);
    print_list();
    return 0;
}