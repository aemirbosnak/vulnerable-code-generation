//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 100
#define MAX_VALUE_LENGTH 1000
#define MAX_INDEX_LENGTH 100

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} Record;

typedef struct {
    char index[MAX_INDEX_LENGTH];
    int record_count;
    Record *records;
} Index;

Index *create_index(char *index_name) {
    Index *index = (Index *) malloc(sizeof(Index));
    strcpy(index->index, index_name);
    index->record_count = 0;
    index->records = NULL;
    return index;
}

void destroy_index(Index *index) {
    free(index->records);
    free(index);
}

int add_record(Index *index, char *key, char *value) {
    Record *record = (Record *) malloc(sizeof(Record));
    strcpy(record->key, key);
    strcpy(record->value, value);
    index->records = (Record *) realloc(index->records, sizeof(Record) * (index->record_count + 1));
    index->records[index->record_count] = *record;
    index->record_count++;
    return 0;
}

int search_index(Index *index, char *key, char *value) {
    int i;
    for (i = 0; i < index->record_count; i++) {
        if (strcmp(index->records[i].key, key) == 0) {
            strcpy(value, index->records[i].value);
            return 0;
        }
    }
    return -1;
}

int main() {
    Index *index = create_index("my_index");
    add_record(index, "John", "Doe");
    add_record(index, "Jane", "Doe");
    add_record(index, "Bob", "Smith");
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
    while (1) {
        printf("Enter key to search: ");
        scanf("%s", key);
        if (search_index(index, key, value) == 0) {
            printf("Value: %s\n", value);
        } else {
            printf("Key not found.\n");
        }
    }
    destroy_index(index);
    return 0;
}