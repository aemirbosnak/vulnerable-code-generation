//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: safe
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *create_node(int data) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

Node *insert_node(Node *head, int data) {
    Node *new_node = create_node(data);
    new_node->next = head;
    return new_node;
}

Node *delete_node(Node *head, int data) {
    Node *temp = head;
    if (temp!= NULL && temp->data == data) {
        head = temp->next;
        free(temp);
        return head;
    }
    while (temp!= NULL && temp->data!= data) {
        temp = temp->next;
    }
    if (temp == NULL) {
        return head;
    }
    Node *next_node = temp->next;
    free(temp);
    return next_node;
}

void display_list(Node *head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node *head = NULL;
    head = insert_node(head, 1);
    head = insert_node(head, 2);
    head = insert_node(head, 3);
    head = insert_node(head, 4);
    display_list(head);
    head = delete_node(head, 2);
    display_list(head);
    head = delete_node(head, 1);
    display_list(head);
    head = delete_node(head, 4);
    display_list(head);
    head = delete_node(head, 3);
    display_list(head);
    return 0;
}