//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STR_LEN 100
#define MAX_ARRAY_SIZE 10

typedef struct node {
    int data;
    struct node* next;
} node_t;

typedef struct list {
    node_t* head;
    node_t* tail;
} list_t;

node_t* create_node(int data) {
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

list_t* create_list(int size) {
    list_t* new_list = (list_t*)malloc(sizeof(list_t));
    for (int i = 0; i < size; i++) {
        new_list->head = create_node(i);
        new_list->tail = new_list->head;
        new_list->head = new_list->head->next = create_node(i);
    }
    return new_list;
}

void print_list(list_t* list) {
    node_t* current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void free_list(list_t* list) {
    node_t* current = list->head;
    while (current != NULL) {
        node_t* next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

int main() {
    srand(time(NULL));
    list_t* list = create_list(10);
    for (int i = 0; i < 10; i++) {
        list->head = create_node(i);
        list->tail = list->head;
        list->head = list->head->next = create_node(i);
    }
    print_list(list);
    free_list(list);
    return 0;
}