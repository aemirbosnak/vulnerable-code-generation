//Falcon-180B DATASET v1.0 Category: Memory management ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

struct node {
    int data;
    struct node* next;
};

void create_list(struct node** head_ref) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    struct node* temp = *head_ref;

    if (temp == NULL) {
        new_node->data = 1;
        new_node->next = NULL;
        *head_ref = new_node;
        return;
    }

    while (temp->next!= NULL) {
        temp = temp->next;
    }

    temp->next = new_node;
    new_node->data = 1;
    new_node->next = NULL;
}

void delete_list(struct node** head_ref) {
    struct node* temp = *head_ref;

    while (temp!= NULL) {
        struct node* next = temp->next;
        free(temp);
        temp = next;
    }

    *head_ref = NULL;
}

void add_node(struct node** head_ref, int data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    struct node* temp = *head_ref;

    if (temp == NULL) {
        new_node->data = data;
        new_node->next = NULL;
        *head_ref = new_node;
        return;
    }

    while (temp->next!= NULL) {
        temp = temp->next;
    }

    temp->next = new_node;
    new_node->data = data;
    new_node->next = NULL;
}

void print_list(struct node* head) {
    struct node* temp = head;

    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    struct node* head = NULL;

    create_list(&head);
    add_node(&head, 2);
    add_node(&head, 3);
    add_node(&head, 4);
    add_node(&head, 5);
    print_list(head);

    delete_list(&head);
    printf("\nList deleted.\n");

    return 0;
}