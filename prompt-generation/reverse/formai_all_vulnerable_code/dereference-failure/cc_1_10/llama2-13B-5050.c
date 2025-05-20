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

void* malloc_wrapper(size_t size) {
    void* ptr = malloc(size);
    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    return ptr;
}

void free_wrapper(void* ptr) {
    free(ptr);
}

list_t* create_list(void) {
    list_t* list = malloc_wrapper(sizeof(list_t));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void add_to_list(list_t* list, int data) {
    node_t* new_node = malloc_wrapper(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
}

int main() {
    list_t* list = create_list();

    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        int data = rand() % 100;
        add_to_list(list, data);
    }

    // traverse the list
    node_t* current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    // free the list
    free_wrapper(list);

    return 0;
}