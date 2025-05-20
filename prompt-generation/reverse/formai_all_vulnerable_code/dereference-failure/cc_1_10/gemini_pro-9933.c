//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: medieval
#include <stdlib.h>
#include <stdio.h>

typedef struct _record {
    int key;
    char *data;
} record;

typedef struct _index {
    int key;
    int pos;
} index;

int main() {
    // Array of records
    record *records = malloc(sizeof(record) * 10);

    // Array of indexes
    index *indexes = malloc(sizeof(index) * 10);

    // Populate the records and indexes
    for (int i = 0; i < 10; i++) {
        records[i].key = i;
        records[i].data = malloc(sizeof(char) * 100);
        sprintf(records[i].data, "This is record %d", i);

        indexes[i].key = i;
        indexes[i].pos = i;
    }

    // Sort the indexes by key
    for (int i = 0; i < 10; i++) {
        for (int j = i + 1; j < 10; j++) {
            if (indexes[i].key > indexes[j].key) {
                // Swap the indexes
                index temp = indexes[i];
                indexes[i] = indexes[j];
                indexes[j] = temp;
            }
        }
    }

    // Print the records
    for (int i = 0; i < 10; i++) {
        printf("Record %d: %s\n", records[indexes[i].pos].key, records[indexes[i].pos].data);
    }

    // Free the memory
    for (int i = 0; i < 10; i++) {
        free(records[i].data);
    }
    free(records);
    free(indexes);

    return 0;
}