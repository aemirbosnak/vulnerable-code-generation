//FormAI DATASET v1.0 Category: Database Indexing System ; Style: future-proof
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_KEYS 100
#define MAX_DATA 1000

typedef struct {
    char* key;
    char* data;
} Record;

typedef struct {
    int num_records;
    Record records[MAX_KEYS];
} Index;

int main() {
    Index index;
    index.num_records = 0;

    char input[MAX_DATA];
    char* key = NULL;
    char* data = NULL;

    printf("Please enter a key-value pair (key:value), or type 'quit' to exit:\n");

    while (fgets(input, MAX_DATA, stdin)) {
        if (strncmp(input, "quit", 4) == 0) {
            break;
        }

        // Parse input into key-value pair
        key = strtok(input, ":");
        data = strtok(NULL, "\n");

        // Add record to index
        Record record;
        record.key = malloc(strlen(key) + 1);
        record.data = malloc(strlen(data) + 1);
        strcpy(record.key, key);
        strcpy(record.data, data);

        index.records[index.num_records++] = record;

        printf("Record added successfully.\n");
        printf("Please enter a key-value pair (key:value), or type 'quit' to exit:\n");
    }

    // Search for record by key
    printf("Please enter a key to search for: ");
    char search_key[MAX_DATA];
    fgets(search_key, MAX_DATA, stdin);
    search_key[strcspn(search_key, "\n")] = 0; // remove newline character

    int found = 0;
    for (int i = 0; i < index.num_records; i++) {
        if (strcmp(index.records[i].key, search_key) == 0) {
            printf("Record found: %s:%s\n", index.records[i].key, index.records[i].data);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Record not found.\n");
    }

    // Free memory
    for (int i = 0; i < index.num_records; i++) {
        free(index.records[i].key);
        free(index.records[i].data);
    }

    return 0;
}