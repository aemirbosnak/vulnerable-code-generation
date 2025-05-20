//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* create_node(int data) {
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

Node* append_node(Node *head, int data) {
    Node *new_node = create_node(data);
    Node *current = head;

    if (head == NULL) {
        head = new_node;
    } else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }

    return head;
}

void print_list(Node *head) {
    Node *current = head;

    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }

    printf("NULL\n");
}

void free_list(Node *head) {
    Node *current = head;
    Node *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    Node *head = NULL;

    head = append_node(head, 5);
    head = append_node(head, 10);
    head = append_node(head, 15);
    head = append_node(head, 20);

    printf("Linked List: ");
    print_list(head);

    free_list(head);

    return 0;
}