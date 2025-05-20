//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define RECORD_SIZE 1000000
#define NAME_SIZE 20

typedef struct record_s {
    int data;
    char name[NAME_SIZE];
} record_t;

int main() {
    srand((unsigned int) time(NULL));
    record_t *records = (record_t*) malloc(RECORD_SIZE * sizeof(record_t));
    int i, num_changes = 0;

    // Fill up records with random data and names
    for (i = 0; i < RECORD_SIZE; i++) {
        records[i].data = rand() % 10000;
        snprintf(records[i].name, NAME_SIZE, "Record %d", i);
    }

    // Print records before sorting
    for (i = 0; i < RECORD_SIZE; i++) {
        printf("%s - %d\n", records[i].name, records[i].data);
    }

    // Sort records using bubble sort
    for (i = 0; i < RECORD_SIZE - 1; i++) {
        int j;
        for (j = 0; j < RECORD_SIZE - i - 1; j++) {
            if (records[j].data > records[j+1].data) {
                // Swap records
                record_t temp = records[j];
                records[j] = records[j+1];
                records[j+1] = temp;
                num_changes++;
            }
        }

        if (num_changes == 0) {
            // No swaps were made, the list is sorted
            break;
        }
    }

    // Print records after sorting
    for (i = 0; i < RECORD_SIZE; i++) {
        printf("%s - %d\n", records[i].name, records[i].data);
    }

    free(records);
    return 0;
}