//FormAI DATASET v1.0 Category: Linked list operations ; Style: active
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void display(struct node *head) {
    struct node *ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void insert_at_beginning(struct node **head, int value) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = *head;
    *head = new_node;
}

void insert_at_end(struct node **head, int value) {
    struct node *new_node = malloc(sizeof(struct node));
    struct node *last = *head;
    new_node->data = value;
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

void delete_node(struct node **head, int value) {
    struct node *temp = *head, *prev;
    if (temp != NULL && temp->data == value) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void reverse_list(struct node **head) {
    struct node *prev = NULL;
    struct node *current = *head;
    struct node *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

int main() {
    struct node *head = NULL;
    insert_at_end(&head, 1);
    insert_at_end(&head, 2);
    insert_at_beginning(&head, 3);
    display(head);
    delete_node(&head, 2);
    display(head);
    reverse_list(&head);
    display(head);
    return 0;
}