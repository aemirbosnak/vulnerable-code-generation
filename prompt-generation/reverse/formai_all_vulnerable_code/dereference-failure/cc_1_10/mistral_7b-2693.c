//MISTRAL-7B DATASET v1.0 Category: Data structures visualization ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>

#define SIZE 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct List {
    Node* head;
    Node* tail;
} List;

void print_list(List* list) {
    Node* current = list->head;
    printf("List: [");
    while (current != NULL) {
        printf("%d, ", current->data);
        current = current->next;
    }
    printf("\b\b]\n");
}

Node* create_node(int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

List* create_list() {
    List* new_list = (List*) malloc(sizeof(List));
    if (new_list == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    new_list->head = NULL;
    new_list->tail = NULL;
    return new_list;
}

void add_to_list(List* list, int data) {
    Node* new_node = create_node(data);
    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
}

int main() {
    srand(time(NULL));
    List* my_list = create_list();
    int i;

    for (i = 0; i < SIZE; i++) {
        add_to_list(my_list, rand() % 10);
    }

    printf("Initial list: ");
    print_list(my_list);

    Node* temp = my_list->head;
    while (temp != NULL) {
        if (temp->data % 2 == 0) {
            Node* current = temp;
            Node* next = temp->next;

            temp->data = next->data;
            next->data = current->data;

            temp = next;
        }
        temp = temp->next;
    }

    printf("List after swapping even and odd numbers: ");
    print_list(my_list);

    free(my_list);

    return 0;
}