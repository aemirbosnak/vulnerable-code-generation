//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_KEY_LEN 100
#define MAX_VALUE_LEN 1000
#define MAX_INDEX_SIZE 10000

typedef struct {
    char key[MAX_KEY_LEN];
    char value[MAX_VALUE_LEN];
} Record;

typedef struct {
    Record *records;
    int num_records;
    int max_records;
} Index;

void init_index(Index *index) {
    index->records = malloc(MAX_INDEX_SIZE * sizeof(Record));
    index->num_records = 0;
    index->max_records = MAX_INDEX_SIZE;
}

void destroy_index(Index *index) {
    free(index->records);
}

int add_record(Index *index, char *key, char *value) {
    if (index->num_records >= index->max_records) {
        return -1;
    }

    Record *record = &index->records[index->num_records];
    strncpy(record->key, key, MAX_KEY_LEN);
    strncpy(record->value, value, MAX_VALUE_LEN);
    index->num_records++;

    return 0;
}

int search_index(Index *index, char *key, char *value) {
    int i;
    for (i = 0; i < index->num_records; i++) {
        if (strcmp(index->records[i].key, key) == 0) {
            strcpy(value, index->records[i].value);
            return 0;
        }
    }

    return -1;
}

int main() {
    Index index;
    init_index(&index);

    add_record(&index, "John", "Doe");
    add_record(&index, "Jane", "Doe");
    add_record(&index, "Bob", "Smith");

    char value[MAX_VALUE_LEN];
    search_index(&index, "John", value);
    printf("John's last name is %s\n", value);

    destroy_index(&index);

    return 0;
}