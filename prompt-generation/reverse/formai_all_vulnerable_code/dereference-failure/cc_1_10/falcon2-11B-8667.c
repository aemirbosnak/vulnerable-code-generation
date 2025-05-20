//Falcon2-11B DATASET v1.0 Category: Searching algorithm ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char data;
    struct node *next;
} Node;

Node* create_node(char data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void print_list(Node* head) {
    Node* current = head;
    while (current!= NULL) {
        printf("%c ", current->data);
        current = current->next;
    }
    printf("\n");
}

void insert_node(Node** head, char data) {
    Node* new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
    } else {
        Node* current = *head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

int main() {
    Node* head = NULL;
    insert_node(&head, 'A');
    insert_node(&head, 'B');
    insert_node(&head, 'C');
    insert_node(&head, 'D');
    insert_node(&head, 'E');

    print_list(head);

    return 0;
}