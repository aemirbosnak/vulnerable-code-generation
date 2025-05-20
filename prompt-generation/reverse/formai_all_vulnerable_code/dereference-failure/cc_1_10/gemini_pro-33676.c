//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct {
    int data;
} Node;

typedef struct {
    Node *nodes;
    int size;
} LinkedList;

LinkedList *create_linked_list() {
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    list->nodes = (Node *)malloc(sizeof(Node) * MAX_SIZE);
    list->size = 0;
    return list;
}

void destroy_linked_list(LinkedList *list) {
    free(list->nodes);
    free(list);
}

void add_node_to_linked_list(LinkedList *list, int data) {
    if (list->size == MAX_SIZE) {
        printf("Error: Linked list is full.\n");
        return;
    }

    list->nodes[list->size].data = data;
    list->size++;
}

void remove_node_from_linked_list(LinkedList *list, int data) {
    int i;

    for (i = 0; i < list->size; i++) {
        if (list->nodes[i].data == data) {
            break;
        }
    }

    if (i == list->size) {
        printf("Error: Node not found.\n");
        return;
    }

    for (i++; i < list->size; i++) {
        list->nodes[i - 1] = list->nodes[i];
    }

    list->size--;
}

void print_linked_list(LinkedList *list) {
    int i;

    printf("Linked list: ");
    for (i = 0; i < list->size; i++) {
        printf("%d ", list->nodes[i].data);
    }
    printf("\n");
}

int main() {
    LinkedList *list = create_linked_list();

    add_node_to_linked_list(list, 1);
    add_node_to_linked_list(list, 2);
    add_node_to_linked_list(list, 3);
    add_node_to_linked_list(list, 4);
    add_node_to_linked_list(list, 5);

    print_linked_list(list);

    remove_node_from_linked_list(list, 3);

    print_linked_list(list);

    destroy_linked_list(list);

    return 0;
}