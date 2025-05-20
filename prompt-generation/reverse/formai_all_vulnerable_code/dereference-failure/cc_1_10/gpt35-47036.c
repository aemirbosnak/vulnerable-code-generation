//FormAI DATASET v1.0 Category: Database Indexing System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

// Define a structure for the index
typedef struct {
    int key;
    int position;
} Index;

int main() {
    // Read in the number of records to be indexed
    int num_records;
    printf("How many records do you want to index?");
    scanf("%d", &num_records);

    // Dynamically allocate memory for the records and indexes arrays
    int* records = (int*) malloc(num_records * sizeof(int));
    Index* indexes = (Index*) malloc(num_records * sizeof(Index));

    // Read in the records and populate the indexes
    printf("Enter the records:\n");
    for (int i = 0; i < num_records; i++) {
        scanf("%d", &records[i]);

        // Set the key and position for the index
        indexes[i].key = records[i];
        indexes[i].position = i;
    }

    // Sort the indexes by key value
    for (int i = 0; i < num_records - 1; i++) {
        for (int j = i + 1; j < num_records; j++) {
            if (indexes[i].key > indexes[j].key) {
                // Swap the indexes
                Index temp = indexes[i];
                indexes[i] = indexes[j];
                indexes[j] = temp;
            }
        }
    }

    // Print out the sorted records and their positions
    printf("Sorted records:\n");
    for (int i = 0; i < num_records; i++) {
        printf("%d ", records[indexes[i].position]);
    }
    printf("\nPositions:\n");
    for (int i = 0; i < num_records; i++) {
        printf("%d ", indexes[i].position);
    }

    // Free the dynamically allocated memory
    free(records);
    free(indexes);

    return 0;
}