//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: genius
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert_at_beginning(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

void insert_at_end(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        struct node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void insert_at_position(int data, int position) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;

    if (position == 1) {
        new_node->next = head;
        head = new_node;
    } else {
        struct node *temp = head;
        for (int i = 1; i < position - 1; i++) {
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
        struct node *temp = head;
        head = head->next;
        free(temp);
    }
}

void delete_at_end() {
    if (head == NULL) {
        printf("List is empty\n");
    } else if (head->next == NULL) {
        free(head);
        head = NULL;
    } else {
        struct node *temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void delete_at_position(int position) {
    if (head == NULL) {
        printf("List is empty\n");
    } else if (position == 1) {
        struct node *temp = head;
        head = head->next;
        free(temp);
    } else {
        struct node *temp = head;
        for (int i = 1; i < position - 1; i++) {
            temp = temp->next;
        }
        struct node *temp2 = temp->next;
        temp->next = temp2->next;
        free(temp2);
    }
}

void print_list() {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    insert_at_beginning(1);
    insert_at_end(2);
    insert_at_position(3, 2);
    print_list(); // 1 3 2

    delete_at_beginning();
    print_list(); // 3 2

    delete_at_end();
    print_list(); // 3

    delete_at_position(1);
    print_list(); // Empty list

    return 0;
}