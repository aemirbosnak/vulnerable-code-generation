//FormAI DATASET v1.0 Category: Data structures visualization ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct list {
    Node* head;
    int size;
} List;

void init(List* list) {
    list->head = NULL;
    list->size = 0;
}

void destroy(List* list) {
    Node* current = list->head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    list->size = 0;
}

void append(List* list, int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
    } else {
        Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
    list->size++;
}

void print(List* list) {
    printf("[");
    Node* current = list->head;
    while (current != NULL) {
        printf(" %d", current->data);
        current = current->next;
    }
    printf(" ]\n");
}

int main() {
    List list;
    init(&list);
    append(&list, 1);
    append(&list, 2);
    append(&list, 3);
    print(&list);
    destroy(&list);
    return 0;
}