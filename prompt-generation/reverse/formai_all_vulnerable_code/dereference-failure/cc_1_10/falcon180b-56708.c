//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 100
#define MAX_VALUE_SIZE 1000

typedef struct {
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];
} Record;

int compare_records(const void *a, const void *b) {
    Record *record_a = (Record *) a;
    Record *record_b = (Record *) b;

    return strcmp(record_a->key, record_b->key);
}

int main() {
    int num_records;
    Record *records;
    char input_buffer[1000];

    // Read the number of records from the user
    printf("Enter the number of records: ");
    scanf("%d", &num_records);

    // Allocate memory for the records
    records = malloc(num_records * sizeof(Record));

    // Read the records from the user
    for (int i = 0; i < num_records; i++) {
        printf("Enter record %d:\n");
        fgets(input_buffer, 1000, stdin);

        // Parse the input buffer and store the key and value in the record
        char *key = strtok(input_buffer, ":");
        char *value = strtok(NULL, ":");

        strncpy(records[i].key, key, MAX_KEY_SIZE);
        strncpy(records[i].value, value, MAX_VALUE_SIZE);
    }

    // Sort the records by key
    qsort(records, num_records, sizeof(Record), compare_records);

    // Print the sorted records
    printf("Sorted records:\n");
    for (int i = 0; i < num_records; i++) {
        printf("Key: %s\nValue: %s\n", records[i].key, records[i].value);
    }

    // Free the memory allocated for the records
    free(records);

    return 0;
}