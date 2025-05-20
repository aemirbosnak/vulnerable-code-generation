//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STRLEN 50
#define MAX_MEM 1000

typedef struct node {
    char *str;
    struct node *next;
} node_t;

node_t *mem_list = NULL;

void init_mem() {
    srand(time(NULL));
    for (int i = 0; i < MAX_MEM; i++) {
        char *str = malloc(rand() % MAX_STRLEN + 1);
        str[rand() % 10] = '\0';
        node_t *new_node = (node_t *) malloc(sizeof(node_t));
        new_node->str = str;
        new_node->next = mem_list;
        mem_list = new_node;
    }
}

void print_mem() {
    node_t *current = mem_list;
    while (current != NULL) {
        printf("%s\n", current->str);
        current = current->next;
    }
}

void free_mem() {
    node_t *current = mem_list;
    while (current != NULL) {
        node_t *temp = current;
        current = current->next;
        free(temp->str);
        free(temp);
    }
    mem_list = NULL;
}

int main() {
    init_mem();
    print_mem();
    free_mem();
    print_mem();
    return 0;
}