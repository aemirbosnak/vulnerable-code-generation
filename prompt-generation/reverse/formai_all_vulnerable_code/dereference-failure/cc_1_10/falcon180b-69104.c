//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    char data;
    struct node* next;
} Node;

Node* create_node(char data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error: Memory allocation failed!\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void add_node(Node* head, char data) {
    Node* new_node = create_node(data);
    new_node->next = head->next;
    head->next = new_node;
}

void delete_node(Node* head, char data) {
    Node* curr_node = head->next;
    Node* prev_node = head;
    while (curr_node!= NULL) {
        if (curr_node->data == data) {
            prev_node->next = curr_node->next;
            free(curr_node);
            return;
        }
        curr_node = curr_node->next;
        prev_node = prev_node->next;
    }
    printf("Error: Node not found!\n");
}

void display_list(Node* head) {
    Node* curr_node = head->next;
    while (curr_node!= NULL) {
        printf("%c ", curr_node->data);
        curr_node = curr_node->next;
    }
    printf("\n");
}

int main() {
    Node* head = create_node('A');
    add_node(head, 'B');
    add_node(head, 'C');
    add_node(head, 'D');
    display_list(head);

    delete_node(head, 'B');
    delete_node(head, 'C');
    display_list(head);

    return 0;
}