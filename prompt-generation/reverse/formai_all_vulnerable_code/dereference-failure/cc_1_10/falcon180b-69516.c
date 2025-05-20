//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_NODES 100

typedef struct node_t {
    int data;
    int freq;
    struct node_t* next;
} node_t;

typedef struct {
    node_t* head;
    int count;
} linked_list_t;

void init_list(linked_list_t* list) {
    list->head = NULL;
    list->count = 0;
}

void add_node(linked_list_t* list, int data) {
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->freq = 1;
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
    } else {
        node_t* prev_node = list->head;
        while (prev_node->next!= NULL) {
            prev_node = prev_node->next;
        }
        prev_node->next = new_node;
    }

    list->count++;
}

void print_list(linked_list_t* list) {
    node_t* curr_node = list->head;
    while (curr_node!= NULL) {
        printf("%d (%d)\n", curr_node->data, curr_node->freq);
        curr_node = curr_node->next;
    }
}

int main() {
    srand(time(NULL));

    linked_list_t list;
    init_list(&list);

    for (int i = 0; i < MAX_NODES; i++) {
        int data = rand() % 100;
        add_node(&list, data);
    }

    print_list(&list);

    return 0;
}