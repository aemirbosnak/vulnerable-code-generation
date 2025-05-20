//LLAMA2-13B DATASET v1.0 Category: Educational ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LENGTH 1024
#define MAGIC_NUMBER 42

typedef struct node {
    int data;
    struct node* next;
} node_t;

node_t* create_list(void) {
    node_t* head = (node_t*) malloc(sizeof(node_t));
    head->data = 0;
    head->next = NULL;
    return head;
}

void insert_node(node_t** head_ref, int data) {
    node_t* new_node = (node_t*) malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
    } else {
        (*head_ref)->next = new_node;
    }

    return;
}

void print_list(node_t* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("List contains: ");

    node_t* current = head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

int main(void) {
    node_t* head = create_list();

    insert_node(&head, 1);
    insert_node(&head, 2);
    insert_node(&head, 3);
    insert_node(&head, 4);
    insert_node(&head, 5);

    print_list(head);

    return 0;
}