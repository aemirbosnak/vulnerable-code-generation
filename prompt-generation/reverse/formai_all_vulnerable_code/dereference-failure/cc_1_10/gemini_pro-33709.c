//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insert_at_beginning(int data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

void insert_at_end(int data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void insert_after_node(int data, int after_data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    struct Node *temp = head;
    while (temp != NULL && temp->data != after_data) {
        temp = temp->next;
    }

    if (temp != NULL) {
        new_node->next = temp->next;
        temp->next = new_node;
    } else {
        printf("Node not found.\n");
    }
}

void delete_at_beginning() {
    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }
}

void delete_at_end() {
    if (head == NULL) {
        printf("List is empty.\n");
    } else if (head->next == NULL) {
        free(head);
        head = NULL;
    } else {
        struct Node *temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void delete_after_node(int after_data) {
    struct Node *temp = head;
    while (temp != NULL && temp->data != after_data) {
        temp = temp->next;
    }

    if (temp != NULL && temp->next != NULL) {
        struct Node *to_be_deleted = temp->next;
        temp->next = temp->next->next;
        free(to_be_deleted);
    } else {
        printf("Node not found.\n");
    }
}

void print_list() {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    insert_at_beginning(10);
    insert_at_end(20);
    insert_after_node(30, 10);
    print_list(); // 10 30 20

    delete_at_beginning();
    print_list(); // 30 20

    delete_at_end();
    print_list(); // 30

    delete_after_node(30);
    print_list(); // empty list

    return 0;
}