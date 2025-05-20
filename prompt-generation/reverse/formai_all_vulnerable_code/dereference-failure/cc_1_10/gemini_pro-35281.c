//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: decentralized
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
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    if (position == 0) {
        new_node->next = head;
        head = new_node;
    } else {
        node_t *current_node = head;
        int current_position = 0;
        while (current_node != NULL && current_position < position - 1) {
            current_node = current_node->next;
            current_position++;
        }
        if (current_node != NULL) {
            new_node->next = current_node->next;
            current_node->next = new_node;
        }
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
            node_t *current_node = head;
            while (current_node->next->next != NULL) {
                current_node = current_node->next;
            }
            free(current_node->next);
            current_node->next = NULL;
        }
    }
}

void delete_at_position(int position) {
    if (head != NULL) {
        if (position == 0) {
            node_t *temp = head;
            head = head->next;
            free(temp);
        } else {
            node_t *current_node = head;
            int current_position = 0;
            while (current_node != NULL && current_position < position - 1) {
                current_node = current_node->next;
                current_position++;
            }
            if (current_node != NULL && current_node->next != NULL) {
                node_t *temp = current_node->next;
                current_node->next = current_node->next->next;
                free(temp);
            }
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
    insert_at_end(2);
    insert_at_position(3, 1);
    insert_at_position(4, 3);
    print_list(); // 1 3 2 4
    delete_at_beginning();
    delete_at_end();
    delete_at_position(1);
    print_list(); // 3
    return 0;
}