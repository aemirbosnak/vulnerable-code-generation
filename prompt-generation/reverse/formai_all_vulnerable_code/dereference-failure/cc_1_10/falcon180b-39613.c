//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 50
#define MAX_VALUE_SIZE 200
#define MAX_INDEX_SIZE 1000

typedef struct {
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];
} Record;

typedef struct {
    Record records[MAX_INDEX_SIZE];
    int count;
} Index;

Index *create_index() {
    Index *index = (Index *)malloc(sizeof(Index));
    index->count = 0;
    return index;
}

void add_record(Index *index, char *key, char *value) {
    if (index->count >= MAX_INDEX_SIZE) {
        printf("Error: Index is full!\n");
        return;
    }
    strcpy(index->records[index->count].key, key);
    strcpy(index->records[index->count].value, value);
    index->count++;
}

void search_index(Index *index, char *key) {
    int i;
    for (i = 0; i < index->count; i++) {
        if (strcmp(index->records[i].key, key) == 0) {
            printf("Record found:\n");
            printf("Key: %s\n", index->records[i].key);
            printf("Value: %s\n", index->records[i].value);
        }
    }
}

int main() {
    Index *index = create_index();
    add_record(index, "John", "25");
    add_record(index, "Jane", "30");
    add_record(index, "Bob", "40");
    search_index(index, "Jane");
    return 0;
}