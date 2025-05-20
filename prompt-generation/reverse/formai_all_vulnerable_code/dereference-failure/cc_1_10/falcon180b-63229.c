//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Node structure definition
typedef struct node {
    int data;
    struct node *next;
} Node;

Node *head = NULL;

void push(int data) {
    Node *new_node = (Node*) malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    new_node->data = data;
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
    } else {
        Node *temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void pop() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node *temp = head;
    head = head->next;
    free(temp);
}

void print_list() {
    Node *temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void reverse_list() {
    Node *prev = NULL;
    Node *current = head;
    while (current!= NULL) {
        Node *next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void sort_list() {
    Node *temp1 = head;
    Node *temp2 = head->next;
    int temp_data;
    while (temp2!= NULL) {
        if (temp1->data > temp2->data) {
            temp_data = temp1->data;
            temp1->data = temp2->data;
            temp2->data = temp_data;
            temp2 = temp2->next;
        } else {
            temp2 = temp2->next;
        }
    }
}

int main() {
    push(5);
    push(3);
    push(7);
    push(1);
    push(6);
    push(8);
    push(2);
    push(4);

    printf("Original list: ");
    print_list();

    reverse_list();

    printf("Reversed list: ");
    print_list();

    sort_list();

    printf("Sorted list: ");
    print_list();

    pop();
    pop();

    printf("List after popping two elements: ");
    print_list();

    return 0;
}