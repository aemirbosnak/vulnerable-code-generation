//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: systematic
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

void insert_at_index(int index, int data) {
    if (index == 0) {
        insert_at_beginning(data);
    } else {
        struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = data;
        struct Node *temp = head;
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
        struct Node *temp = head;
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
        struct Node *temp = head;
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
    } else if (head == NULL) {
        printf("List is empty\n");
    } else {
        struct Node *temp = head;
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        struct Node *to_be_deleted = temp->next;
        temp->next = temp->next->next;
        free(to_be_deleted);
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
    insert_at_beginning(20);
    insert_at_end(30);
    insert_at_end(40);
    insert_at_index(2, 50);
    print_list();
    delete_at_beginning();
    delete_at_end();
    delete_at_index(1);
    print_list();
    return 0;
}