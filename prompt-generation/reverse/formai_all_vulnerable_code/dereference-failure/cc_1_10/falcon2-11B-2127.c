//Falcon2-11B DATASET v1.0 Category: Memory Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
    int value;
    struct node* next;
} Node;

Node* create_node(int value) {
    Node* new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

void print_list(Node* head) {
    Node* current = head;
    while (current!= NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("null\n");
}

void shuffle_list(Node* head) {
    srand(time(NULL));
    Node* current = head;
    while (current!= NULL) {
        int random_index = rand() % current->value;
        Node* temp = current->next;
        current->next = current->next->next;
        current->next->next = temp;
        current = current->next;
    }
}

void free_list(Node* head) {
    Node* current = head;
    while (current!= NULL) {
        Node* temp = current->next;
        free(current);
        current = temp;
    }
}

int main() {
    Node* head = create_node(3);
    Node* current = head;
    int value;
    while (1) {
        printf("Enter a number between 1 and 3: ");
        scanf("%d", &value);
        if (value < 1 || value > 3) {
            printf("Invalid input. Please try again.\n");
            continue;
        }
        current->next = create_node(value);
        current = current->next;
    }
}