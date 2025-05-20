//Falcon-180B DATASET v1.0 Category: Memory management ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

void print_list(Node *head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

Node *create_node(int data) {
    Node *node = (Node *) malloc(sizeof(Node));
    if (node == NULL) {
        printf("Error: Memory allocation failed!\n");
        exit(1);
    }
    node->data = data;
    node->next = NULL;
    return node;
}

Node *insert_node(Node *head, int data) {
    Node *node = create_node(data);
    if (head == NULL) {
        head = node;
        return head;
    }
    Node *temp = head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = node;
    return head;
}

void delete_node(Node **head, int data) {
    Node *temp = *head;
    if (temp!= NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp!= NULL && temp->data!= data) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Error: Node not found!\n");
        return;
    }
    Node *prev = temp;
    while (temp->next!= NULL) {
        temp = temp->next;
        prev = prev->next;
    }
    prev->next = temp->next;
    free(temp);
}

void search_node(Node *head, int data) {
    Node *temp = head;
    while (temp!= NULL) {
        if (temp->data == data) {
            printf("Node found!\n");
            return;
        }
        temp = temp->next;
    }
    printf("Node not found!\n");
}

int main() {
    Node *head = NULL;
    head = insert_node(head, 1);
    head = insert_node(head, 2);
    head = insert_node(head, 3);
    head = insert_node(head, 4);
    head = insert_node(head, 5);
    print_list(head);
    search_node(head, 3);
    delete_node(&head, 3);
    print_list(head);
    return 0;
}