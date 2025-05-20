//LLAMA2-13B DATASET v1.0 Category: Memory Game ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MEMORY_SIZE 10
#define MEMORY_DEPTH 4

typedef struct memory_node {
    int value;
    struct memory_node *next;
} memory_node_t;

memory_node_t *memory[MEMORY_SIZE];
int current_position = 0;

void init_memory() {
    int i;
    for (i = 0; i < MEMORY_SIZE; i++) {
        memory[i] = NULL;
    }
}

void insert_value(int value) {
    memory_node_t *new_node = (memory_node_t *)malloc(sizeof(memory_node_t));
    new_node->value = value;
    new_node->next = memory[current_position];
    memory[current_position] = new_node;
    current_position = (current_position + 1) % MEMORY_SIZE;
}

int get_value() {
    int value = 0;
    memory_node_t *current = memory[current_position];
    while (current != NULL) {
        value = current->value;
        current = current->next;
    }
    return value;
}

void game_loop() {
    int value;
    do {
        printf("Enter a value: ");
        scanf("%d", &value);
        insert_value(value);
    } while (get_value() != -1);
}

int main() {
    srand(time(NULL));
    init_memory();
    game_loop();
    return 0;
}