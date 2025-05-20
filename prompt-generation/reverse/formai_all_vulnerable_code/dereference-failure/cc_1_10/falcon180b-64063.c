//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: complete
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

node* create_node(int data) {
    node* new_node = (node*) malloc(sizeof(node));

    if (new_node == NULL) {
        printf("Memory error\n");
        exit(0);
    }

    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

void print_list(node* head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int search_list(node* head, int value) {
    node* current = head;

    while (current!= NULL) {
        if (current->data == value) {
            return 1;
        }
        current = current->next;
    }

    return 0;
}

void insert_node(node** head, int data) {
    node* new_node = create_node(data);

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    node* current = *head;

    while (current->next!= NULL) {
        current = current->next;
    }

    current->next = new_node;
}

void delete_node(node** head, int value) {
    node* current = *head;
    node* previous = NULL;

    if (current!= NULL && current->data == value) {
        *head = current->next;
        free(current);
        return;
    }

    while (current!= NULL && current->data!= value) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        return;
    }

    previous->next = current->next;
    free(current);
}

int main() {
    node* head = NULL;

    insert_node(&head, 1);
    insert_node(&head, 2);
    insert_node(&head, 3);

    printf("List: ");
    print_list(head);
    printf("\n");

    int value = 2;

    if (search_list(head, value)) {
        printf("Value found\n");
    } else {
        printf("Value not found\n");
    }

    delete_node(&head, value);

    printf("List after deletion: ");
    print_list(head);
    printf("\n");

    return 0;
}