//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *create_node(int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void push(node **head, int data) {
    node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

void pop(node **head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void insert_after(node *prev, int data) {
    if (prev == NULL) {
        printf("Previous node cannot be NULL!\n");
        return;
    }
    node *new_node = create_node(data);
    new_node->next = prev->next;
    prev->next = new_node;
}

void delete_node(node **head, node *del) {
    if (*head == NULL || del == NULL) {
        printf("List or node to be deleted cannot be NULL!\n");
        return;
    }
    if (*head == del) {
        *head = (*head)->next;
        free(del);
        return;
    }
    node *temp = *head;
    while (temp->next != del) {
        temp = temp->next;
        if (temp == NULL) {
            printf("Node to be deleted not found!\n");
            return;
        }
    }
    temp->next = del->next;
    free(del);
}

void print_list(node *head) {
    printf("List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    node *head = NULL;
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    push(&head, 40);
    push(&head, 50);
    print_list(head);
    pop(&head);
    print_list(head);
    insert_after(head->next, 15);
    print_list(head);
    delete_node(&head, head->next->next);
    print_list(head);
    return 0;
}