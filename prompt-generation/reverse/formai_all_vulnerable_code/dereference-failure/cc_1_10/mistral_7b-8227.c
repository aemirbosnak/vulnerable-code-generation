//MISTRAL-7B DATASET v1.0 Category: Data structures visualization ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next;
    char symbol;
} Node;

void print_list(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%c->", current->symbol);
        printf("%d ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void create_node(Node** head, int data, char symbol) {
    Node* new_node = (Node*) malloc(sizeof(Node));

    if (new_node == NULL) {
        printf("Memory error!\n");
        exit(EXIT_FAILURE);
    }

    new_node->data = data;
    new_node->symbol = symbol;
    new_node->next = *head;

    *head = new_node;
}

int main() {
    Node* head = NULL;
    char symbols[] = {'@', '&', '*', '#', '%', '+', '-', '=', '!'};

    create_node(&head, 5, '@');
    create_node(&head, 10, '&');
    create_node(&head, 15, '*');
    create_node(&head, 20, '#');
    create_node(&head, 25, '%');
    create_node(&head, 30, '+');

    print_list(head);

    return 0;
}