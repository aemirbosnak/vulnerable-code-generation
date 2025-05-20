//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_INDEX 1000
#define MAX_DATA 1000

typedef struct Node {
    char data[MAX_DATA];
    struct Node* next;
} Node;

typedef struct Index {
    int key;
    struct Node* head;
} Index;

Index** index_array;

pthread_mutex_t mutex;

void insert_data(char* data) {
    pthread_mutex_lock(&mutex);

    Index* new_index = malloc(sizeof(Index));
    new_index->key = strlen(data) + 1;
    new_index->head = NULL;

    if (index_array == NULL) {
        index_array = malloc(MAX_INDEX * sizeof(Index));
    }

    index_array[new_index->key] = new_index;

    pthread_mutex_unlock(&mutex);
}

void search_data(char* query) {
    pthread_mutex_lock(&mutex);

    for (int i = 0; i < MAX_INDEX; i++) {
        Index* index = index_array[i];
        if (index != NULL) {
            Node* node = index->head;
            while (node) {
                if (strstr(node->data, query) != NULL) {
                    printf("%s\n", node->data);
                }
                node = node->next;
            }
        }
    }

    pthread_mutex_unlock(&mutex);
}

int main() {
    insert_data("abc");
    insert_data("bcd");
    insert_data("cde");
    insert_data("def");

    search_data("bcd");

    return 0;
}