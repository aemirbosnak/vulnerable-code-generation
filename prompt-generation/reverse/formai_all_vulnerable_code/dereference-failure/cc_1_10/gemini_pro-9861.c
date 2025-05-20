//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: protected
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
    if (position == 0) {
        insert_at_beginning(data);
    } else {
        node_t *new_node = (node_t *)malloc(sizeof(node_t));
        new_node->data = data;
        new_node->next = NULL;
        node_t *current_node = head;
        int count = 0;
        while (current_node != NULL && count < position - 1) {
            current_node = current_node->next;
            count++;
        }
        if (current_node != NULL) {
            new_node->next = current_node->next;
            current_node->next = new_node;
        } else {
            printf("Invalid position\n");
        }
    }
}

void delete_from_beginning() {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        node_t *temp = head;
        head = head->next;
        free(temp);
    }
}

void delete_from_end() {
    if (head == NULL) {
        printf("List is empty\n");
    } else if (head->next == NULL) {
        free(head);
        head = NULL;
    } else {
        node_t *current_node = head;
        while (current_node->next->next != NULL) {
            current_node = current_node->next;
        }
        free(current_node->next);
        current_node->next = NULL;
    }
}

void delete_from_position(int position) {
    if (head == NULL) {
        printf("List is empty\n");
    } else if (position == 0) {
        delete_from_beginning();
    } else {
        node_t *current_node = head;
        int count = 0;
        while (current_node != NULL && count < position - 1) {
            current_node = current_node->next;
            count++;
        }
        if (current_node != NULL && current_node->next != NULL) {
            node_t *temp = current_node->next;
            current_node->next = temp->next;
            free(temp);
        } else {
            printf("Invalid position\n");
        }
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
    insert_at_beginning(1);
    insert_at_beginning(2);
    insert_at_beginning(3);
    insert_at_end(4);
    insert_at_end(5);
    insert_at_end(6);
    insert_at_position(7, 3);
    print_list();
    delete_from_beginning();
    delete_from_end();
    delete_from_position(2);
    print_list();
    return 0;
}