//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    int value;
    struct node* next;
} node;

node* create_node(int value) {
    node* new_node = (node*) malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

void print_list(node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    node* current = head;
    while (current!= NULL) {
        printf("Value: %d\n", current->value);
        current = current->next;
    }
}

void insert_at_beginning(node** head, int value) {
    node* new_node = create_node(value);
    new_node->next = *head;
    *head = new_node;
}

void insert_at_end(node** head, int value) {
    node* new_node = create_node(value);
    node* current = *head;
    while (current->next!= NULL) {
        current = current->next;
    }
    current->next = new_node;
}

void delete_node(node** head, int value) {
    node* current = *head;
    node* prev = NULL;
    while (current!= NULL && current->value!= value) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Node with value %d not found.\n", value);
        return;
    }
    if (prev == NULL) {
        *head = current->next;
        free(current);
        return;
    }
    prev->next = current->next;
    free(current);
}

int main() {
    node* head = NULL;
    int nums[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++) {
        insert_at_end(&head, nums[i]);
    }
    print_list(head);
    printf("\nInserting at beginning:\n");
    insert_at_beginning(&head, 0);
    print_list(head);
    printf("\nInserting at end:\n");
    insert_at_end(&head, 10);
    print_list(head);
    printf("\nDeleting node with value 5:\n");
    delete_node(&head, 5);
    print_list(head);
    return 0;
}