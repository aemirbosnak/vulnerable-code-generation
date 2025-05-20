//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: light-weight
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

void insert_at_index(int index, int data) {
    if (index == 0) {
        insert_at_beginning(data);
    } else {
        node_t *new_node = (node_t *)malloc(sizeof(node_t));
        new_node->data = data;
        node_t *current_node = head;
        int i = 0;
        while (current_node != NULL && i < index - 1) {
            current_node = current_node->next;
            i++;
        }
        if (current_node == NULL) {
            printf("Index out of bounds!\n");
        } else {
            new_node->next = current_node->next;
            current_node->next = new_node;
        }
    }
}

void delete_at_beginning() {
    if (head == NULL) {
        printf("List is empty!\n");
    } else {
        node_t *temp = head;
        head = head->next;
        free(temp);
    }
}

void delete_at_end() {
    if (head == NULL) {
        printf("List is empty!\n");
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

void delete_at_index(int index) {
    if (index == 0) {
        delete_at_beginning();
    } else {
        node_t *current_node = head;
        int i = 0;
        while (current_node != NULL && i < index - 1) {
            current_node = current_node->next;
            i++;
        }
        if (current_node == NULL || current_node->next == NULL) {
            printf("Index out of bounds!\n");
        } else {
            node_t *temp = current_node->next;
            current_node->next = temp->next;
            free(temp);
        }
    }
}

void display() {
    node_t *current_node = head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

int main() {
    insert_at_beginning(10);
    insert_at_end(20);
    insert_at_index(1, 15);
    display(); // Output: 10 15 20
    delete_at_beginning();
    display(); // Output: 15 20
    delete_at_end();
    display(); // Output: 15
    delete_at_index(0);
    display(); // Output: Empty list!
    return 0;
}