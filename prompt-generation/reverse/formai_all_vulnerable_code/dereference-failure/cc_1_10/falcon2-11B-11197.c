//Falcon2-11B DATASET v1.0 Category: File system simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* create_node(int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void print_list(Node* head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void insert_at_beginning(Node** head_ref, int data) {
    Node* new_node = create_node(data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void insert_at_end(Node** head_ref, int data) {
    Node* new_node = create_node(data);
    Node* current = *head_ref;
    while (current->next!= NULL) {
        current = current->next;
    }
    current->next = new_node;
}

void delete_node(Node** head_ref, int key) {
    Node* current = *head_ref;
    Node* prev = NULL;

    while (current!= NULL && current->data!= key) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Key not found in the linked list\n");
    } else {
        if (prev == NULL) {
            *head_ref = current->next;
            free(current);
        } else {
            prev->next = current->next;
            free(current);
        }
    }
}

int main() {
    Node* head = NULL;

    insert_at_beginning(&head, 1);
    insert_at_end(&head, 2);
    insert_at_beginning(&head, 3);
    insert_at_end(&head, 4);
    insert_at_end(&head, 5);

    print_list(head);

    delete_node(&head, 3);

    print_list(head);

    return 0;
}