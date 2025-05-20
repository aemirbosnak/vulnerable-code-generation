//GEMINI-pro DATASET v1.0 Category: Educational ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char data;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

void insert_at_beginning(char data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
    if (tail == NULL) {
        tail = new_node;
    }
}

void insert_at_end(char data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if (tail == NULL) {
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
}

void insert_after_node(struct node *node, char data) {
    if (node == NULL) {
        return;
    }
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = node->next;
    node->next = new_node;
    if (tail == node) {
        tail = new_node;
    }
}

void delete_node(struct node *node) {
    if (node == NULL) {
        return;
    }
    if (node == head) {
        head = node->next;
    } else {
        struct node *temp = head;
        while (temp->next != node) {
            temp = temp->next;
        }
        temp->next = node->next;
    }
    free(node);
}

void print_list() {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%c ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    insert_at_beginning('a');
    insert_at_end('b');
    insert_after_node(head, 'c');
    print_list();  // Output: a c b
    delete_node(head);
    print_list();  // Output: c b
    delete_node(tail);
    print_list();  // Output: c
    delete_node(head);
    print_list();  // Output: Empty list
    return 0;
}