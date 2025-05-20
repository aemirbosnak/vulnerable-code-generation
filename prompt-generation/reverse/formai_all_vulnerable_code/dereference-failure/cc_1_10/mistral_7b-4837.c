//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) {
        fprintf(stderr, "Memory error\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

Node* add_node(Node* head, int data) {
    Node* new_node = create_node(data);
    if (!head) {
        head = new_node;
        return head;
    }
    Node* current = head;
    while (current->next) {
        current = current->next;
    }
    current->next = new_node;
    return head;
}

void print_list(Node* head) {
    Node* current = head;
    printf("List: ");
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void generate_random_numbers(int* numbers, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        numbers[i] = rand() % 100;
    }
}

int main() {
    int list_size = 10;
    int* random_numbers = (int*)calloc(list_size, sizeof(int));
    generate_random_numbers(random_numbers, list_size);

    Node* head = NULL;
    for (int i = 0; i < list_size; i++) {
        head = add_node(head, random_numbers[i]);
    }

    print_list(head);

    free(random_numbers);
    Node* current = head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }

    return 0;
}