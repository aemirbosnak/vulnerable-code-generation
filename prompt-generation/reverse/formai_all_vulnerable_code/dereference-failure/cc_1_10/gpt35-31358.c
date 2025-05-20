//FormAI DATASET v1.0 Category: Data structures visualization ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

void print_list(Node *head) {
    printf("List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void insert_front(Node **head, int data) {
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void insert_end(Node **head, int data) {
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    }
    else {
        Node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void delete_node(Node **head, int data) {
    if (*head == NULL) {
        return;
    }

    Node *temp = *head;
    Node *prev = NULL;

    if (temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return;
    }

    prev->next = temp->next;
    free(temp);
}

int main() {
    Node *head = NULL;

    insert_front(&head, 5);
    insert_front(&head, 10);
    insert_end(&head, 20);
    print_list(head);

    delete_node(&head, 10);
    print_list(head);

    insert_end(&head, 30);
    print_list(head);

    delete_node(&head, 20);
    print_list(head);

    return 0;
}