//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: relaxed
#include <stdio.h>

typedef struct node {
    int data;
    struct node* next;
} node;

node* create_node(int data) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

node* insert_at_beginning(node** head, int data) {
    node* new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
    return *head;
}

void print_linked_list(node* head) {
    node* current = head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

node* insert_after_element(node** head, int data, int element) {
    node* new_node = create_node(data);
    node* current = *head;
    while (current!= NULL && current->data!= element) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Element not found in the list.\n");
        return NULL;
    }
    new_node->next = current->next;
    current->next = new_node;
    return *head;
}

void delete_element(node** head, int element) {
    node* current = *head;
    node* previous = NULL;
    while (current!= NULL && current->data!= element) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Element not found in the list.\n");
        return;
    }
    if (previous == NULL) {
        *head = current->next;
    } else {
        previous->next = current->next;
    }
    free(current);
}

void find_element(node* head, int element) {
    node* current = head;
    while (current!= NULL && current->data!= element) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Element not found in the list.\n");
    } else {
        printf("Element found at position %d.\n", current - head);
    }
}

int main() {
    node* head = NULL;
    insert_at_beginning(&head, 5);
    insert_at_beginning(&head, 4);
    insert_at_beginning(&head, 3);
    insert_at_beginning(&head, 2);
    insert_at_beginning(&head, 1);
    print_linked_list(head);
    printf("\n");

    delete_element(&head, 5);
    print_linked_list(head);
    printf("\n");

    insert_after_element(&head, 6, 3);
    print_linked_list(head);
    printf("\n");

    find_element(head, 3);
    printf("\n");

    return 0;
}