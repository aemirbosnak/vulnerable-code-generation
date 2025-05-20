//FormAI DATASET v1.0 Category: Linked list operations ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct {
    struct Node* head;
    int size;
} LinkedList;

void init(LinkedList *list) {
    list->head = NULL;
    list->size = 0;
}

void push_front(LinkedList *list, int value) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next = list->head;
    list->head = new_node;
    list->size++;
}

void push_back(LinkedList *list, int value) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
    } else {
        struct Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
    list->size++;
}

void print_list(LinkedList *list) {
    printf("[");
    struct Node* current = list->head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(", ");
        }
        current = current->next;
    }
    printf("]\n");
}

void clear(LinkedList *list) {
    struct Node* current = list->head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    list->head = NULL;
    list->size = 0;
}

int main() {
    LinkedList list;
    init(&list);

    push_front(&list, 5);
    push_front(&list, 10);
    push_back(&list, 20);

    printf("List: ");
    print_list(&list);

    clear(&list);

    printf("List after clear: ");
    print_list(&list);

    return 0;
}