//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    size_t capacity;
    size_t size;
    struct Node* next;
} Node;

Node* create_node(size_t capacity) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = 0;
    new_node->capacity = capacity;
    new_node->size = 0;
    new_node->next = NULL;
    return new_node;
}

void resize(Node** head, size_t new_capacity) {
    Node* new_head = create_node(new_capacity);
    Node* current = *head;
    Node* previous = new_head;

    while (current != NULL) {
        previous->next = current;
        previous = current;
        current = current->next;
    }

    *head = new_head;
}

void push_back(Node** head, int data) {
    Node* new_node = create_node(1);
    new_node->data = data;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    Node* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

int pop_front(Node** head) {
    if (*head == NULL) {
        return -1;
    }

    int data = (*head)->data;
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);

    return data;
}

int main() {
    Node* head = NULL;
    int size = 0;
    int input;

    while (1) {
        printf("Enter the number to push back (-1 to exit): ");
        scanf("%d", &input);

        if (input == -1) {
            break;
        }

        push_back(&head, input);
        size++;

        if (size % 5 == 0) {
            printf("Array size has reached %d. Resizing...\n", size);
            resize(&head, size + 10);
        }
    }

    printf("Popping front elements:\n");
    while (head != NULL) {
        int data = pop_front(&head);
        printf("%d ", data);
    }

    printf("\n");

    return 0;
}