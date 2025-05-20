//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *head = NULL;

void insert_at_beginning(int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

void insert_at_end(int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
    } else {
        node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void insert_at_index(int index, int data) {
    if (index == 0) {
        insert_at_beginning(data);
    } else {
        node *new_node = (node *)malloc(sizeof(node));
        new_node->data = data;
        node *temp = head;
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

void delete_at_beginning() {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        node *temp = head;
        head = head->next;
        free(temp);
    }
}

void delete_at_end() {
    if (head == NULL) {
        printf("List is empty\n");
    } else if (head->next == NULL) {
        head = NULL;
    } else {
        node *temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void delete_at_index(int index) {
    if (index == 0) {
        delete_at_beginning();
    } else {
        node *temp = head;
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        node *to_delete = temp->next;
        temp->next = to_delete->next;
        free(to_delete);
    }
}

void reverse_list() {
    node *prev = NULL;
    node *current = head;
    node *next;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void print_list() {
    node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    insert_at_beginning(10);
    insert_at_end(20);
    insert_at_index(1, 15);
    print_list();  // Output: 10 15 20
    delete_at_beginning();
    delete_at_end();
    delete_at_index(0);
    print_list();  // Output: 15
    reverse_list();
    print_list();  // Output: 15
    return 0;
}