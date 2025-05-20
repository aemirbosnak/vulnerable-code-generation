//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_INDEX_SIZE 26

typedef struct {
    char *key;
    int value;
} Entry;

typedef struct {
    Entry *entries;
    int num_entries;
} Index;

void create_index(Index *index) {
    index->entries = (Entry *) malloc(MAX_ENTRIES * sizeof(Entry));
    index->num_entries = 0;
    for (int i = 0; i < MAX_ENTRIES; i++) {
        index->entries[i].key = NULL;
        index->entries[i].value = -1;
    }
}

void destroy_index(Index *index) {
    for (int i = 0; i < index->num_entries; i++) {
        free(index->entries[i].key);
    }
    free(index->entries);
}

int hash(char *key) {
    int sum = 0;
    while (*key) {
        sum += *key++;
    }
    return sum % MAX_INDEX_SIZE;
}

void add_entry(Index *index, char *key, int value) {
    int index_num = hash(key);
    while (index->entries[index_num].key!= NULL && strcmp(index->entries[index_num].key, key)!= 0) {
        index_num = (index_num + 1) % MAX_INDEX_SIZE;
    }
    index->entries[index_num].key = strdup(key);
    index->entries[index_num].value = value;
    index->num_entries++;
}

int get_value(Index *index, char *key) {
    int index_num = hash(key);
    while (index->entries[index_num].key!= NULL && strcmp(index->entries[index_num].key, key)!= 0) {
        index_num = (index_num + 1) % MAX_INDEX_SIZE;
    }
    if (index->entries[index_num].key == NULL) {
        return -1;
    } else {
        return index->entries[index_num].value;
    }
}

int main() {
    Index index;
    create_index(&index);
    add_entry(&index, "apple", 1);
    add_entry(&index, "banana", 2);
    add_entry(&index, "cherry", 3);
    int value = get_value(&index, "banana");
    printf("Value of banana: %d\n", value);
    destroy_index(&index);
    return 0;
}