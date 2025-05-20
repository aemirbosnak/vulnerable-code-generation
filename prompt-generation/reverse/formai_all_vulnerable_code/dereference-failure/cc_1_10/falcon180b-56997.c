//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void add_node(Node** head, int data) {
    Node* new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
    } else {
        Node* temp = *head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void delete_node(Node** head, int data) {
    Node* temp = *head;
    if (temp!= NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
    } else {
        while (temp!= NULL && temp->data!= data) {
            temp = temp->next;
        }
        if (temp!= NULL) {
            Node* next_node = temp->next;
            temp->next = temp->next->next;
            free(next_node);
        }
    }
}

void print_list(Node* head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    add_node(&head, 1);
    add_node(&head, 2);
    add_node(&head, 3);
    print_list(head);
    delete_node(&head, 2);
    print_list(head);
    delete_node(&head, 1);
    print_list(head);
    delete_node(&head, 3);
    print_list(head);
    return 0;
}