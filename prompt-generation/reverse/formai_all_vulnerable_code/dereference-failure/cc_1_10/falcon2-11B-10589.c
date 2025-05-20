//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void print_list(struct node* head) {
    struct node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void append_element(struct node** head_ref, int element) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = element;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    struct node* temp = *head_ref;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void insert_element(struct node** head_ref, int position, int element) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = element;
    new_node->next = NULL;

    if (position == 1) {
        new_node->next = *head_ref;
        *head_ref = new_node;
        return;
    }

    struct node* temp = *head_ref;
    int count = 1;
    while (temp->next!= NULL && count < position) {
        temp = temp->next;
        count++;
    }

    new_node->next = temp->next;
    temp->next = new_node;
}

void delete_element(struct node** head_ref, int position) {
    if (*head_ref == NULL) {
        return;
    }

    if (position == 1) {
        *head_ref = (*head_ref)->next;
        return;
    }

    struct node* temp = *head_ref;
    int count = 1;
    while (temp->next!= NULL && count < position) {
        temp = temp->next;
        count++;
    }

    temp->next = temp->next->next;
}

void reverse_list(struct node** head_ref) {
    struct node* prev = NULL;
    struct node* current = *head_ref;
    struct node* next = NULL;

    while (current!= NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head_ref = prev;
}

int main() {
    struct node* head = NULL;

    append_element(&head, 10);
    append_element(&head, 20);
    append_element(&head, 30);

    printf("Original list: ");
    print_list(head);

    insert_element(&head, 2, 15);
    printf("\nList after inserting 15 at position 2: ");
    print_list(head);

    delete_element(&head, 2);
    printf("\nList after deleting element at position 2: ");
    print_list(head);

    reverse_list(&head);
    printf("\nList after reversing: ");
    print_list(head);

    return 0;
}