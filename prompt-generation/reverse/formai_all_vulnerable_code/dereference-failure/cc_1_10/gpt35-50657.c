//FormAI DATASET v1.0 Category: Data structures visualization ; Style: careful
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

void init_list(LinkedList* list) {
    list->head = NULL;
    list->length = 0;
}

void insert_at_beginning(LinkedList* list, int value) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = list->head;
    list->head = new_node;
    list->length++;
}

void insert_at_end(LinkedList* list, int value) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->value = value;
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
    list->length++;
}

void remove_from_beginning(LinkedList* list) {
    if (list->head == NULL) {
        return; // list is empty, do nothing
    }
    Node* temp = list->head;
    list->head = list->head->next;
    free(temp);
    list->length--;
}

void remove_from_end(LinkedList* list) {
    if (list->head == NULL) {
        return; // list is empty, do nothing
    }
    if (list->head->next == NULL) {
        // list has only one element, just remove it
        free(list->head);
        list->head = NULL;
    } else {
        Node* current = list->head;
        while (current->next->next != NULL) {
            current = current->next;
        }
        free(current->next);
        current->next = NULL;
    }
    list->length--;
}

void print_list(LinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

int main() {
    LinkedList list;
    init_list(&list);

    insert_at_end(&list, 10);
    insert_at_beginning(&list, 5);
    insert_at_beginning(&list, 3);
    insert_at_end(&list, 15);
    print_list(&list);

    remove_from_beginning(&list);
    print_list(&list);

    remove_from_end(&list);
    print_list(&list);

    return 0;
}