//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 100
#define MAX_VALUE_SIZE 1000

typedef struct {
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];
    int index;
} record_t;

int compare_records(const void *a, const void *b) {
    const record_t *ra = (const record_t *)a;
    const record_t *rb = (const record_t *)b;
    return strcmp(ra->key, rb->key);
}

int main() {
    record_t *records = NULL;
    int num_records = 0;
    int max_records = 1000;

    records = (record_t *)malloc(max_records * sizeof(record_t));
    if (records == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }

    FILE *csv_file = fopen("data.csv", "r");
    if (csv_file == NULL) {
        printf("Error: Cannot open data file.\n");
        exit(1);
    }

    char line[MAX_VALUE_SIZE];
    while (fgets(line, MAX_VALUE_SIZE, csv_file)!= NULL) {
        char *token = strtok(line, ",");
        if (token == NULL) {
            continue;
        }

        strcpy(records[num_records].key, token);
        records[num_records].index = num_records;

        token = strtok(NULL, ",");
        if (token == NULL) {
            continue;
        }

        strcpy(records[num_records].value, token);
        num_records++;

        if (num_records >= max_records) {
            printf("Warning: Maximum number of records reached.\n");
            break;
        }
    }

    fclose(csv_file);

    qsort(records, num_records, sizeof(record_t), compare_records);

    for (int i = 0; i < num_records; i++) {
        printf("%s: %s\n", records[i].key, records[i].value);
    }

    free(records);
    return 0;
}