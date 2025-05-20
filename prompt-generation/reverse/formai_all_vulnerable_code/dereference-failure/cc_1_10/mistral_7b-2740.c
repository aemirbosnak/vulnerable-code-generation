//MISTRAL-7B DATASET v1.0 Category: Data structures visualization ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
    int data;
    struct node_t* next;
} node_t;

typedef struct list_t {
    node_t* head;
    node_t* tail;
    int size;
} list_t;

node_t* create_node(int data) {
    node_t* new_node = (node_t*) malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void add_node(list_t* list, int data) {
    node_t* new_node = create_node(data);
    if (list->size == 0) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
    list->size++;
}

void print_list(list_t* list) {
    node_t* current = list->head;
    printf("List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    list_t* my_list = (list_t*) malloc(sizeof(list_t));
    my_list->head = NULL;
    my_list->tail = NULL;
    my_list->size = 0;

    add_node(my_list, 10);
    add_node(my_list, 20);
    add_node(my_list, 30);

    print_list(my_list);

    free(my_list);
    return 0;
}