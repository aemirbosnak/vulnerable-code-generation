//Falcon2-11B DATASET v1.0 Category: Memory management ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    char* data;
    struct node* next;
} node;

void insert_node(node** head_ref, char* data) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void delete_node(node** head_ref, char* data) {
    node* current = *head_ref;
    node* prev = NULL;
    while (current!= NULL && strcmp(current->data, data)!= 0) {
        prev = current;
        current = current->next;
    }
    if (current!= NULL && strcmp(current->data, data) == 0) {
        if (prev == NULL) {
            *head_ref = current->next;
            free(current);
        } else {
            prev->next = current->next;
            free(current);
        }
    }
}

void print_list(node* head) {
    while (head!= NULL) {
        printf("%s\n", head->data);
        head = head->next;
    }
}

int main() {
    node* head = NULL;
    insert_node(&head, "Hello");
    insert_node(&head, "World");
    insert_node(&head, "C");
    insert_node(&head, "Programming");

    print_list(head);

    delete_node(&head, "C");

    print_list(head);

    return 0;
}