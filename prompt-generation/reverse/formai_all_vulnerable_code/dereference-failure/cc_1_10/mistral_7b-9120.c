//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    char *name;
    struct Node *next;
} Node;

void print_list(Node *head) {
    Node *current = head;
    printf("\n=============== Happy Linked List ===============\n");
    printf("Index | Data  | Name\n");
    printf("--------------------------------------------------\n");
    int i = 0;
    while (current != NULL) {
        printf("|%2d|%7d|%10s|\n", i++, current->data, current->name);
        current = current->next;
    }
}

void add_node(Node **head, int data, char *name) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->name = strdup(name);
    new_node->next = *head;
    *head = new_node;
}

void free_list(Node *head) {
    Node *current = head;
    Node *next;
    while (current != NULL) {
        next = current->next;
        free(current->name);
        free(current);
        current = next;
    }
}

int main() {
    Node *happy_list = NULL;
    add_node(&happy_list, 3, "Apple");
    add_node(&happy_list, 5, "Banana");
    add_node(&happy_list, 7, "Cherry");
    add_node(&happy_list, 11, "Durian");
    add_node(&happy_list, 13, "Elderberry");

    print_list(happy_list);

    free_list(happy_list);

    printf("\n=============== Happy List is Empty ===============\n");
    print_list(NULL);

    return 0;
}