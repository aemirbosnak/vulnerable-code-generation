//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LEN 100
#define MAX_RECORD_LEN 1000
#define MAX_INDEX_LEN 100
#define MAX_INDEX_LEVELS 5

typedef struct {
    char *key;
    int record_index;
} IndexEntry;

typedef struct {
    IndexEntry *entries;
    int num_entries;
} Index;

typedef struct {
    char *data;
    int length;
} Record;

Index *create_index(int num_levels) {
    Index *index = malloc(sizeof(Index));
    index->entries = malloc(MAX_INDEX_LEVELS * sizeof(IndexEntry));
    index->num_entries = 0;
    return index;
}

void add_record(Index *index, char *key, Record *record) {
    IndexEntry *entry = malloc(sizeof(IndexEntry));
    entry->key = strdup(key);
    entry->record_index = index->num_entries;
    index->entries[index->num_entries++] = *entry;
}

Record *search_index(Index *index, char *key) {
    int level = 0;
    while (level < MAX_INDEX_LEVELS && index->entries[level].key!= NULL) {
        int cmp = strcmp(key, index->entries[level].key);
        if (cmp == 0) {
            return index->entries[level].record_index;
        } else if (cmp < 0) {
            level++;
        } else {
            level--;
        }
    }
    return NULL;
}

void print_index(Index *index) {
    for (int i = 0; i < index->num_entries; i++) {
        printf("%s -> %d\n", index->entries[i].key, index->entries[i].record_index);
    }
}

int main() {
    Index *index = create_index(2);
    Record record1 = {"Hello", 5};
    Record record2 = {"World", 6};
    Record record3 = {"Foo", 7};
    Record record4 = {"Bar", 8};
    add_record(index, "Hello", &record1);
    add_record(index, "World", &record2);
    add_record(index, "Foo", &record3);
    add_record(index, "Bar", &record4);
    print_index(index);
    Record *record = search_index(index, "World");
    if (record!= NULL) {
        printf("Record found: %s\n", record->data);
    } else {
        printf("Record not found.\n");
    }
    return 0;
}