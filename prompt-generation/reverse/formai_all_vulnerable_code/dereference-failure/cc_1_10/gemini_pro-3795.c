//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// A creative twist: Using a musical analogy to represent the sorting process
// Consider each element as a note, and the bucket sort as an orchestra arranging the notes into a beautiful symphony

// Define the "orchestra" (an array of buckets)
int** orchestra;

// The "conductor" function that sorts the notes into the orchestra's buckets
void conductor(int* notes, int num_notes) {
    // Create the orchestra with empty buckets for each possible note value
    orchestra = malloc(sizeof(int*) * 10); // assuming notes are between 0 and 9

    // Initialize each bucket to an empty list
    for (int i = 0; i < 10; i++) {
        orchestra[i] = malloc(sizeof(int) * num_notes);
        orchestra[i][0] = -1; // -1 to indicate an empty bucket
    }

    // Place each note into its designated bucket
    for (int i = 0; i < num_notes; i++) {
        int bucket = notes[i];
        int* bucket_list = orchestra[bucket];

        // Append the note to the end of the bucket's list
        int j = 0;
        while (bucket_list[j] != -1) {
            j++;
        }
        bucket_list[j] = notes[i];
    }
}

// The "musicians" function that sorts the notes within each bucket
void musicians() {
    for (int i = 0; i < 10; i++) {
        int* bucket_list = orchestra[i];

        // Skip empty buckets
        if (bucket_list[0] == -1) {
            continue;
        }

        // Sort the notes within the bucket using any preferred sorting algorithm (e.g., bubble sort)
        int n = 0;
        while (bucket_list[n] != -1) {
            n++;
        }

        // Swap the first and smallest note in the bucket
        for (int j = 0; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (bucket_list[j] > bucket_list[k]) {
                    int temp = bucket_list[j];
                    bucket_list[j] = bucket_list[k];
                    bucket_list[k] = temp;
                }
            }
        }
    }
}

// The "finale" function that combines the sorted notes back into a single array
int* finale(int num_notes) {
    // Create the final symphony
    int* symphony = malloc(sizeof(int) * num_notes);

    // Collect the notes from each bucket in order
    int index = 0;
    for (int i = 0; i < 10; i++) {
        int* bucket_list = orchestra[i];

        // Skip empty buckets
        if (bucket_list[0] == -1) {
            continue;
        }

        int j = 0;
        while (bucket_list[j] != -1) {
            symphony[index] = bucket_list[j];
            index++;
            j++;
        }
    }

    return symphony;
}

int main() {
    // The notes to be sorted
    int notes[] = {5, 3, 1, 4, 2, 9, 7, 6, 8, 0};
    int num_notes = 10;

    // Let the conductor arrange the notes into the orchestra
    conductor(notes, num_notes);

    // The musicians sort the notes within each bucket
    musicians();

    // The notes are combined into a beautiful symphony
    int* symphony = finale(num_notes);

    // Print the sorted symphony
    printf("The sorted symphony: ");
    for (int i = 0; i < num_notes; i++) {
        printf("%d ", symphony[i]);
    }
    printf("\n");

    return 0;
}