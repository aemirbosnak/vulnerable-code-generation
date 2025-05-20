//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head = NULL;

void insert_at_beginning(int data) {
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

void insert_at_end(int data) {
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
    } else {
        Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void insert_at_index(int index, int data) {
    if (index == 0) {
        insert_at_beginning(data);
        return;
    }

    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    Node *temp = head;
    for (int i = 0; i < index - 1; i++) {
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

void delete_at_beginning() {
    if (head == NULL) {
        return;
    }
    Node *temp = head;
    head = head->next;
    free(temp);
}

void delete_at_end() {
    if (head == NULL) {
        return;
    }
    Node *temp = head;
    Node *prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    if (prev == NULL) {
        head = NULL;
    } else {
        prev->next = NULL;
    }
    free(temp);
}

void delete_at_index(int index) {
    if (index == 0) {
        delete_at_beginning();
        return;
    }

    Node *temp = head;
    Node *prev = NULL;
    for (int i = 0; i < index; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (prev == NULL) {
        head = head->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
}

void print_list() {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    insert_at_beginning(1);
    insert_at_end(2);
    insert_at_index(1, 3);
    printf("Linked list: ");
    print_list();
    delete_at_beginning();
    printf("Linked list after deleting at beginning: ");
    print_list();
    delete_at_end();
    printf("Linked list after deleting at end: ");
    print_list();
    delete_at_index(1);
    printf("Linked list after deleting at index 1: ");
    print_list();
    return 0;
}