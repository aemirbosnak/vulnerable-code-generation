//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: random
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

void insert_at_position(int data, int position) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    if (position == 1) {
        new_node->next = head;
        head = new_node;
    } else {
        node *temp = head;
        for (int i = 1; i < position - 1; i++) {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

void delete_at_beginning() {
    if (head == NULL) {
        return;
    } else {
        node *temp = head;
        head = head->next;
        free(temp);
    }
}

void delete_at_end() {
    if (head == NULL) {
        return;
    } else if (head->next == NULL) {
        free(head);
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

void delete_at_position(int position) {
    if (head == NULL) {
        return;
    } else if (position == 1) {
        node *temp = head;
        head = head->next;
        free(temp);
    } else {
        node *temp = head;
        for (int i = 1; i < position - 1; i++) {
            temp = temp->next;
        }
        node *temp2 = temp->next;
        temp->next = temp2->next;
        free(temp2);
    }
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
    insert_at_position(30, 2);
    print_list(); // 10 30 20
    delete_at_beginning();
    print_list(); // 30 20
    delete_at_end();
    print_list(); // 30
    delete_at_position(1);
    print_list(); // Empty list
    return 0;
}