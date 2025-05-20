//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME_LENGTH 100
#define MAX_INDEX_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char index[MAX_INDEX_LENGTH];
} Index;

typedef struct {
    Index* index;
    int size;
    int capacity;
} IndexList;

IndexList* create_index_list() {
    IndexList* list = malloc(sizeof(IndexList));
    list->size = 0;
    list->capacity = 10;
    list->index = malloc(list->capacity * sizeof(Index));
    return list;
}

void add_index(IndexList* list, const char* name, const char* index) {
    if (list->size >= list->capacity) {
        list->capacity *= 2;
        list->index = realloc(list->index, list->capacity * sizeof(Index));
    }
    strncpy(list->index[list->size].name, name, MAX_NAME_LENGTH);
    strncpy(list->index[list->size].index, index, MAX_INDEX_LENGTH);
    list->size++;
}

void print_index_list(IndexList* list) {
    for (int i = 0; i < list->size; i++) {
        printf("%s -> %s\n", list->index[i].name, list->index[i].index);
    }
}

int main() {
    IndexList* list = create_index_list();
    add_index(list, "John", "A123");
    add_index(list, "Jane", "B456");
    add_index(list, "Jack", "C789");
    print_index_list(list);
    free(list->index);
    free(list);
    return 0;
}