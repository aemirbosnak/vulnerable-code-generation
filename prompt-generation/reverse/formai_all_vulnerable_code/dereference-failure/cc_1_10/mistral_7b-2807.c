//MISTRAL-7B DATASET v1.0 Category: Recursive ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* create_node(int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    if (!new_node) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void print_list_recursive(Node* head) {
    if (!head) {
        printf("List is empty!\n");
        return;
    }

    printf("%d -> ", head->data);
    print_list_recursive(head->next);
}

int main(void) {
    Node* head = NULL;
    Node* first = NULL;
    Node* second = NULL;
    Node* third = NULL;

    head = create_node(0);
    first = create_node(1);
    second = create_node(2);
    third = create_node(3);

    head->next = first;
    first->next = second;
    second->next = third;

    printf("List: ");
    print_list_recursive(head);

    free(head);
    free(first);
    free(second);
    free(third);

    printf("\nShocked! Your recursive function actually worked!\n");

    return 0;
}