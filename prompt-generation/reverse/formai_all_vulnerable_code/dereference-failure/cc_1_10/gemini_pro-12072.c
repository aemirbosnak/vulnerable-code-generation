//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: invasive
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

void insert_at_index(int data, int index) {
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
        return;
    }
    struct Node *temp = head;
    head = head->next;
    free(temp);
}

void delete_at_end() {
    if (head == NULL) {
        return;
    }
    struct Node *temp = head;
    if (temp->next == NULL) {
        head = NULL;
        free(temp);
        return;
    }
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    struct Node *temp2 = temp->next;
    temp->next = NULL;
    free(temp2);
}

void delete_at_index(int index) {
    if (index == 0) {
        delete_at_beginning();
    } else {
        struct Node *temp = head;
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        struct Node *temp2 = temp->next;
        temp->next = temp2->next;
        free(temp2);
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
    insert_at_beginning(1);
    insert_at_beginning(2);
    insert_at_beginning(3);
    insert_at_end(4);
    insert_at_end(5);
    insert_at_index(6, 2);
    print_list();
    delete_at_beginning();
    delete_at_end();
    delete_at_index(2);
    print_list();
    return 0;
}