//FormAI DATASET v1.0 Category: Data structures visualization ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* next;
} Node;

typedef struct linked_list {
    Node* head;
    int length;
} LinkedList;

void init(LinkedList* list) {
    list->head = NULL;
    list->length = 0;
}

void insert(LinkedList* list, int value) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = list->head;
    list->head = new_node;
    list->length++;
}

int delete(LinkedList* list, int value) {
    if (list->length == 0) {
        return 0;
    }

    Node* current_node = list->head;
    Node* prev_node = NULL;

    while (current_node != NULL) {
        if (current_node->value == value) {
            if (prev_node == NULL) {
                list->head = current_node->next;
            } else {
                prev_node->next = current_node->next;
            }
            free(current_node);
            list->length--;
            return 1;
        }

        prev_node = current_node;
        current_node = current_node->next;
    }

    return 0;
}

void print_list(LinkedList* list) {
    Node* current_node = list->head;
    printf("[ ");

    while (current_node != NULL) {
        printf("%d ", current_node->value);
        current_node = current_node->next;
    }

    printf("]\n");
}

int main() {
    LinkedList list;
    init(&list);

    insert(&list, 3);
    insert(&list, 12);
    insert(&list, 7);
    insert(&list, 1);

    printf("Initial list: ");
    print_list(&list);

    delete(&list, 7);

    printf("After deleting 7: ");
    print_list(&list);

    delete(&list, 15);

    printf("After deleting 15 (which doesn't exist): ");
    print_list(&list);

    return 0;
}