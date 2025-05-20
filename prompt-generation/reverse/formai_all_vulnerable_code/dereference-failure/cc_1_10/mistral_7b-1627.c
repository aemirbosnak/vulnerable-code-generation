//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 50
#define DATA_TYPE char

typedef struct Node {
    DATA_TYPE data[MAX_LEN];
    int length;
    struct Node* next;
} Node;

Node* create_node(DATA_TYPE* data, int length) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    strncpy(new_node->data, data, MAX_LEN);
    new_node->length = length;
    new_node->next = NULL;
    return new_node;
}

void insert_at_beginning(Node** head, Node* new_node) {
    new_node->next = *head;
    *head = new_node;
}

void print_list(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%.*s\n", current->length, current->data);
        current = current->next;
    }
}

int main() {
    Node* head = NULL;
    char data1[20] = "Hello";
    char data2[15] = "World";
    int length1 = strlen(data1);
    int length2 = strlen(data2);

    Node* new_node1 = create_node(data1, length1);
    Node* new_node2 = create_node(data2, length2);

    insert_at_beginning(&head, new_node1);
    insert_at_beginning(&head, new_node2);

    print_list(head);

    return 0;
}