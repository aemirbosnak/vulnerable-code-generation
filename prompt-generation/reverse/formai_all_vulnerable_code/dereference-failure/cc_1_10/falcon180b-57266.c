//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 100
#define MAX_VALUE_LEN 1000
#define MAX_FIELDS 100

typedef struct {
    char *key;
    char *value;
} record_t;

typedef struct {
    int count;
    record_t *records;
} index_t;

index_t *create_index(int fields) {
    index_t *index = (index_t *)malloc(sizeof(index_t));
    index->count = 0;
    index->records = (record_t *)malloc(fields * sizeof(record_t));
    return index;
}

void destroy_index(index_t *index) {
    free(index->records);
    free(index);
}

void add_record(index_t *index, char *key, char *value) {
    index->records[index->count].key = strdup(key);
    index->records[index->count].value = strdup(value);
    index->count++;
}

void print_index(index_t *index) {
    for (int i = 0; i < index->count; i++) {
        printf("Key: %s, Value: %s\n", index->records[i].key, index->records[i].value);
    }
}

int main() {
    index_t *index = create_index(2);
    add_record(index, "Name", "John");
    add_record(index, "Age", "30");
    print_index(index);
    destroy_index(index);
    return 0;
}