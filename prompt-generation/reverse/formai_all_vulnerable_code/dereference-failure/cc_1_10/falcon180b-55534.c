//Falcon-180B DATASET v1.0 Category: Memory management ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct node {
    char* data;
    struct node* next;
} Node;

Node* create_node(char* data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void delete_node(Node* node) {
    if (node == NULL) {
        return;
    }
    free(node->data);
    free(node);
}

void push_back(Node** head, char* data) {
    Node* new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    Node* last_node = *head;
    while (last_node->next!= NULL) {
        last_node = last_node->next;
    }
    last_node->next = new_node;
}

void pop_back(Node** head) {
    if (*head == NULL) {
        return;
    }
    Node* last_node = *head;
    while (last_node->next!= NULL) {
        last_node = last_node->next;
    }
    delete_node(last_node);
    last_node = *head;
    *head = last_node->next;
    if (*head == NULL) {
        free(last_node);
    }
}

void print_list(Node* head) {
    if (head == NULL) {
        printf("Empty list\n");
        return;
    }
    Node* current_node = head;
    while (current_node!= NULL) {
        printf("%s -> ", current_node->data);
        current_node = current_node->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    push_back(&head, "Hello");
    push_back(&head, "World");
    print_list(head);
    pop_back(&head);
    print_list(head);
    return 0;
}