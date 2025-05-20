//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* create_node(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void print_list(Node* head) {
    Node* current = head;
    while (current!= NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void insert_at_beginning(Node** head, int data) {
    Node* new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

void insert_at_end(Node** head, int data) {
    Node* new_node = create_node(data);
    Node* current = *head;
    while (current->next!= NULL) {
        current = current->next;
    }
    current->next = new_node;
}

void insert_at_position(Node** head, int data, int position) {
    if (position <= 0) {
        insert_at_beginning(head, data);
    } else if (position > 0) {
        Node* new_node = create_node(data);
        Node* current = *head;
        for (int i = 1; i < position; i++) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

int main() {
    srand(time(NULL));

    Node* head = NULL;
    insert_at_beginning(&head, rand() % 1000);
    print_list(head);
    printf("\n");

    insert_at_end(&head, rand() % 1000);
    print_list(head);
    printf("\n");

    insert_at_position(&head, rand() % 1000, rand() % 1000);
    print_list(head);
    printf("\n");

    free(head);
    return 0;
}