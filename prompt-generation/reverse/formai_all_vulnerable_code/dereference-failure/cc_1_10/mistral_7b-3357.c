//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* create_node(int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void add_node(Node** head, int data) {
    Node* new_node = create_node(data);
    Node* temp = *head;

    if (*head == NULL) {
        *head = new_node;
        new_node->next = new_node;
        new_node->prev = new_node;
    } else {
        while (temp->next != *head) {
            temp = temp->next;
        }

        new_node->next = *head;
        new_node->prev = temp;
        (*head)->prev = new_node;
        *head = new_node;
    }
}

void print_list(Node* head) {
    Node* temp = head;
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("HEAD\n");
}

void reverse_print_list(Node* head) {
    Node* temp = head;
    do {
        printf("%d <- ", temp->data);
        temp = temp->prev;
    } while (temp != head);
    printf("HEAD\n");
}

bool is_palindrome(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* reverse_head = slow->prev;
    Node* current = head;

    do {
        if (current->data != reverse_head->data) {
            return false;
        }
        current = current->next;
        reverse_head = reverse_head->prev;
    } while (current != NULL && reverse_head != NULL);

    return true;
}

int main() {
    Node* head = NULL;

    add_node(&head, 1);
    add_node(&head, 2);
    add_node(&head, 3);
    add_node(&head, 4);
    add_node(&head, 5);

    printf("Original list:\n");
    print_list(head);

    printf("\nReversed list:\n");
    reverse_print_list(head);

    printf("\nIs palindrome? %s\n", is_palindrome(head) ? "Yes" : "No");

    return 0;
}