//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: portable
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

node_t *head = NULL;

void insert_at_beginning(int data) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

void insert_at_end(int data) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
    } else {
        node_t *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void insert_at_index(int data, int index) {
    if (index == 0) {
        insert_at_beginning(data);
    } else {
        node_t *new_node = malloc(sizeof(node_t));
        new_node->data = data;
        node_t *current = head;
        int i = 0;
        while (current != NULL && i < index - 1) {
            current = current->next;
            i++;
        }
        if (current != NULL) {
            new_node->next = current->next;
            current->next = new_node;
        } else {
            printf("Index out of bounds\n");
            free(new_node);
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
        node_t *current = head;
        node_t *prev = NULL;
        while (current->next != NULL) {
            prev = current;
            current = current->next;
        }
        if (prev != NULL) {
            prev->next = NULL;
            free(current);
        } else {
            head = NULL;
            free(current);
        }
    }
}

void delete_at_index(int index) {
    if (index == 0) {
        delete_at_beginning();
    } else {
        node_t *current = head;
        node_t *prev = NULL;
        int i = 0;
        while (current != NULL && i < index) {
            prev = current;
            current = current->next;
            i++;
        }
        if (current != NULL) {
            if (prev != NULL) {
                prev->next = current->next;
            } else {
                head = current->next;
            }
            free(current);
        } else {
            printf("Index out of bounds\n");
        }
    }
}

void print_list() {
    node_t *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    insert_at_beginning(1);
    insert_at_end(2);
    insert_at_index(3, 1);
    print_list(); // 1 3 2
    delete_at_beginning();
    delete_at_end();
    delete_at_index(1);
    print_list(); // 3
    return 0;
}