//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 100
#define MAX_VALUE_LENGTH 1000
#define MAX_INDEX_SIZE 1000

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} Record;

typedef struct {
    Record *records;
    int size;
} Index;

void create_index(Index *index) {
    index->records = (Record *)malloc(MAX_INDEX_SIZE * sizeof(Record));
    index->size = 0;
}

void destroy_index(Index *index) {
    free(index->records);
}

int add_record(Index *index, char *key, char *value) {
    Record *record = (Record *)malloc(sizeof(Record));

    strncpy(record->key, key, MAX_KEY_LENGTH);
    strncpy(record->value, value, MAX_VALUE_LENGTH);

    index->records[index->size] = *record;
    index->size++;

    return 0;
}

int search_record(Index *index, char *key, char *value) {
    int i;

    for (i = 0; i < index->size; i++) {
        if (strcmp(index->records[i].key, key) == 0) {
            strcpy(value, index->records[i].value);
            return 0;
        }
    }

    return -1;
}

int main() {
    Index index;

    create_index(&index);

    add_record(&index, "John", "Doe");
    add_record(&index, "Jane", "Doe");
    add_record(&index, "Bob", "Smith");

    char value[MAX_VALUE_LENGTH];

    search_record(&index, "John", value);
    printf("John: %s\n", value);

    search_record(&index, "Jane", value);
    printf("Jane: %s\n", value);

    search_record(&index, "Bob", value);
    printf("Bob: %s\n", value);

    destroy_index(&index);

    return 0;
}