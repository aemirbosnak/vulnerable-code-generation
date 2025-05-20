//Falcon-180B DATASET v1.0 Category: Memory management ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void add_node(Node* head, int data) {
    Node* new_node = create_node(data);
    if (head == NULL) {
        head = new_node;
        return;
    }
    Node* temp = head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void delete_node(Node* head, int data) {
    if (head == NULL) {
        printf("Error: List is empty.\n");
        return;
    }
    if (head->data == data) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return;
    }
    Node* temp = head;
    while (temp->next!= NULL && temp->next->data!= data) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        printf("Error: Node not found.\n");
        return;
    }
    Node* node_to_delete = temp->next;
    temp->next = temp->next->next;
    free(node_to_delete);
}

void print_list(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = head;
    while (temp!= NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    add_node(head, 1);
    add_node(head, 2);
    add_node(head, 3);
    print_list(head);
    delete_node(head, 2);
    print_list(head);
    return 0;
}