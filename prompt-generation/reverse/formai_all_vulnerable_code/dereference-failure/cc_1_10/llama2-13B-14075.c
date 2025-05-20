//LLAMA2-13B DATASET v1.0 Category: Data mining ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_RECORDS 1000
#define MAX_FEATURES 10

// Structure to represent a record
typedef struct {
    int age;
    char gender[10];
    int income;
} record_t;

// Function to generate random records
void generate_records(record_t **records, int *num_records) {
    int i, j;
    for (*num_records = 0; *num_records < MAX_RECORDS; (*num_records)++) {
        record_t *record = (record_t *)malloc(sizeof(record_t));
        for (i = 0; i < MAX_FEATURES; i++) {
            record->age = (i % 2 == 0) ? (rand() % 50 + 20) : (rand() % 50 + 30);
            record->gender[i] = (char)('M' + (rand() % 2));
            record->income = (rand() % 10000) + 1000;
        }
        records[*num_records] = record;
    }
}

// Function to mine data
void mine_data(record_t **records, int num_records) {
    int i, j;
    for (i = 0; i < num_records; i++) {
        for (j = 0; j < MAX_FEATURES; j++) {
            printf("%d ", records[i]->age);
            if (j < 5) {
                printf("%c ", records[i]->gender[j]);
            } else {
                printf("%d ", records[i]->income);
            }
        }
        printf("\n");
    }
}

int main() {
    record_t *records;
    int num_records;

    // Generate random records
    generate_records(&records, &num_records);

    // Mine data
    mine_data(records, num_records);

    return 0;
}