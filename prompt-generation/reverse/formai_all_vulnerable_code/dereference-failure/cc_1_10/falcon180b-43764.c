//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node!= NULL) {
        new_node->data = data;
        new_node->next = NULL;
    }
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
    Node* prev = NULL;
    Node* curr = *head;
    while (curr!= NULL && curr->data!= data) {
        prev = curr;
        curr = curr->next;
    }
    if (curr!= NULL) {
        if (prev == NULL) {
            *head = curr->next;
        } else {
            prev->next = curr->next;
        }
        free(curr);
    }
}

void print_list(Node* head) {
    Node* curr = head;
    while (curr!= NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

void reverse_list(Node** head) {
    Node* curr = *head;
    Node* prev = NULL;
    while (curr!= NULL) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

int main() {
    Node* head = NULL;
    add_node(&head, 10);
    add_node(&head, 20);
    add_node(&head, 30);
    add_node(&head, 40);
    add_node(&head, 50);

    printf("Original list:\n");
    print_list(head);

    delete_node(&head, 30);

    printf("List after deleting 30:\n");
    print_list(head);

    reverse_list(&head);

    printf("List after reversing:\n");
    print_list(head);

    return 0;
}