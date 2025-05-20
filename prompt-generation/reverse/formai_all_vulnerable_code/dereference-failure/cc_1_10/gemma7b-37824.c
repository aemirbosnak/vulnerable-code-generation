//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_INDEX_SIZE 100

typedef struct IndexNode {
    char *key;
    struct IndexNode *next;
} IndexNode;

pthread_mutex_t mutex;

IndexNode **index_head = NULL;

void insert_index(char *key) {
    pthread_mutex_lock(&mutex);

    IndexNode *new_node = (IndexNode *)malloc(sizeof(IndexNode));
    new_node->key = strdup(key);
    new_node->next = NULL;

    if (index_head == NULL) {
        index_head = new_node;
    } else {
        IndexNode *current = index_head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_node;
    }

    pthread_mutex_unlock(&mutex);
}

void search_index(char *key) {
    pthread_mutex_lock(&mutex);

    IndexNode *current = index_head;
    while (current) {
        if (strcmp(current->key, key) == 0) {
            printf("Key found: %s\n", current->key);
            break;
        }
        current = current->next;
    }

    pthread_mutex_unlock(&mutex);
}

int main() {
    insert_index("abc");
    insert_index("def");
    insert_index("ghi");
    insert_index("jkl");

    search_index("abc");
    search_index("def");
    search_index("xyz");

    return 0;
}