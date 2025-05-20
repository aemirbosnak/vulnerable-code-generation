//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char data;
    struct node* next;
} Node;

Node* create_node(char data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void add_node(Node** head, char data) {
    Node* new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    Node* temp = *head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void delete_node(Node** head, char data) {
    Node* temp = *head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    if (temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp->next!= NULL && temp->next->data!= data) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        printf("Element not found\n");
        return;
    }
    Node* node_to_delete = temp->next;
    temp->next = temp->next->next;
    free(node_to_delete);
}

void print_list(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = head;
    while (temp!= NULL) {
        printf("%c -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    add_node(&head, 'a');
    add_node(&head, 'b');
    add_node(&head, 'c');
    print_list(head);
    delete_node(&head, 'b');
    print_list(head);
    delete_node(&head, 'a');
    print_list(head);
    delete_node(&head, 'c');
    print_list(head);
    return 0;
}