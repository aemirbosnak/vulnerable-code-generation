//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *create_node(int data) {
    Node *new_node = (Node *) malloc(sizeof(Node));

    if (new_node == NULL) {
        printf("Memory error\n");
        exit(1);
    }

    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

void add_node(Node **head, int data) {
    Node *new_node = create_node(data);
    Node *temp = *head;

    if (*head == NULL) {
        new_node->next = NULL;
        *head = new_node;
        return;
    }

    while (temp->next!= NULL) {
        temp = temp->next;
    }

    temp->next = new_node;
    new_node->next = NULL;
}

void delete_node(Node **head, int data) {
    Node *temp = *head;
    Node *prev = NULL;

    if (temp!= NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void print_list(Node *head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int search_node(Node *head, int data) {
    Node *temp = head;

    while (temp!= NULL) {
        if (temp->data == data) {
            return TRUE;
        }
        temp = temp->next;
    }

    return FALSE;
}

int main() {
    Node *head = NULL;

    add_node(&head, 5);
    add_node(&head, 10);
    add_node(&head, 15);

    printf("Original list: ");
    print_list(head);

    delete_node(&head, 10);

    printf("\nList after deleting 10: ");
    print_list(head);

    int search_data = 15;
    if (search_node(head, search_data)) {
        printf("\n%d found in the list.\n", search_data);
    } else {
        printf("\n%d not found in the list.\n", search_data);
    }

    return 0;
}