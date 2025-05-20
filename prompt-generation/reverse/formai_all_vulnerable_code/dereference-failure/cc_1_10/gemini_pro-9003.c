//GEMINI-pro DATASET v1.0 Category: Educational ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *create_node(int data) {
    node *new_node = malloc(sizeof(node));
    assert(new_node != NULL);
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_at_head(node **head, int data) {
    node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

void insert_at_tail(node **head, int data) {
    node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void insert_at_index(node **head, int data, int index) {
    if (index == 0) {
        insert_at_head(head, data);
        return;
    }
    node *new_node = create_node(data);
    node *temp = *head;
    for (int i = 0; i < index - 1; i++) {
        assert(temp != NULL);
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

void delete_node(node **head, int data) {
    if (*head == NULL) {
        return;
    }
    if ((*head)->data == data) {
        *head = (*head)->next;
        return;
    }
    node *temp = *head;
    while (temp->next != NULL) {
        if (temp->next->data == data) {
            temp->next = temp->next->next;
            return;
        }
        temp = temp->next;
    }
}

void print_list(node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    node *head = NULL;
    insert_at_head(&head, 1);
    insert_at_tail(&head, 2);
    insert_at_index(&head, 3, 1);
    insert_at_tail(&head, 4);
    print_list(head);
    delete_node(&head, 2);
    print_list(head);
    return 0;
}