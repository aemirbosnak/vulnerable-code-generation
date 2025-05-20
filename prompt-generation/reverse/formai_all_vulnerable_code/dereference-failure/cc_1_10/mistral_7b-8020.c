//MISTRAL-7B DATASET v1.0 Category: Data structures visualization ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* create_node(int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

Node* push(Node* head, int data) {
    Node* new_node = create_node(data);
    if (!head) {
        head = new_node;
    } else {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
    return head;
}

void print_list(Node* head, int length) {
    int i;
    Node* current = head;
    printf("\033[1;1H"); // Clear the terminal

    for (i = 0; i < length; i++) {
        printf("[");
        if (current == NULL) {
            printf("null");
        } else {
            printf("%d", current->data);
            current = current->next;
        }
        printf(" <- ");
    }
    printf("HEAD\n");

    current = head;
    while (current != NULL) {
        printf("%d [%p] <- ", current->data, current);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    srand(time(NULL));
    Node* head = NULL;
    int length = 10;

    while (length > 0) {
        head = push(head, rand() % 100);
        length--;
    }

    print_list(head, 11);

    Node* current = head;
    while (current != NULL) {
        Node* temp = current->next;
        free(current);
        current = temp;
    }

    return 0;
}