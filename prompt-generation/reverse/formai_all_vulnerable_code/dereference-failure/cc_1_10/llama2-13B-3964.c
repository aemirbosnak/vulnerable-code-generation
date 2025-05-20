//LLAMA2-13B DATASET v1.0 Category: Memory Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define MEMORY_CAPACITY 10
#define MEMORY_DELAY 1000

typedef struct memory_node {
    char word[20];
    int index;
    struct memory_node *next;
} memory_node_t;

memory_node_t *memory_list = NULL;

void init_memory() {
    int i, j;
    for (i = 0; i < MEMORY_CAPACITY; i++) {
        memory_node_t *node = malloc(sizeof(memory_node_t));
        node->word[0] = 'A' + (i % 26);
        node->index = i;
        node->next = NULL;
        if (i == 0) {
            memory_list = node;
        } else {
            memory_list->next = node;
        }
        memory_list = node;
    }
}

void print_memory() {
    memory_node_t *current = memory_list;
    while (current != NULL) {
        printf("%c%d ", current->word[0], current->index);
        current = current->next;
    }
    printf("\n");
}

void add_to_memory(char word[]) {
    int i, j;
    for (i = 0; i < strlen(word); i++) {
        for (j = 0; j < MEMORY_CAPACITY; j++) {
            if (word[i] == memory_list->word[j]) {
                memory_list->word[j] = word[i];
                memory_list->index = j;
                return;
            }
        }
    }
    printf("Word already in memory\n");
}

void recall_memory() {
    int i, j;
    for (i = 0; i < MEMORY_CAPACITY; i++) {
        for (j = 0; j < MEMORY_CAPACITY; j++) {
            if (memory_list->word[j] == 'A' + (i % 26)) {
                printf("%c%d ", memory_list->word[j], memory_list->index);
                break;
            }
        }
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    init_memory();
    add_to_memory("example");
    recall_memory();
    sleep(MEMORY_DELAY);
    print_memory();
    return 0;
}