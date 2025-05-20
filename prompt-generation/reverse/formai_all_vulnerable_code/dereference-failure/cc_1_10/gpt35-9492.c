//FormAI DATASET v1.0 Category: Memory management ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MAX_ALLOCATIONS 10

int main() {
    int *myArray[MAX_ALLOCATIONS];
    int numAllocations = 0;

    while (numAllocations < MAX_ALLOCATIONS) {
        // Generate a random size for our next allocation between 1 and 10 MB
        int allocationSize = rand() % 10 + 1;
        size_t bytes = allocationSize * 1024 * 1024;

        // Check if we have enough memory available
        int canAllocate = 0;
        while (!canAllocate && allocationSize > 0) {
            int *temp = malloc(bytes);
            if (temp != NULL) {
                // Allocation successful! Add the pointer to our array
                myArray[numAllocations] = temp;
                numAllocations++;
                canAllocate = 1;
            } else {
                // Not enough memory available. Free up a previously allocated block.
                free(myArray[numAllocations - 1]);
                numAllocations--;
                allocationSize--;
                bytes = allocationSize * 1024 * 1024;
            }
        }

        // If we couldn't allocate anything, give up and exit the program
        if (!canAllocate) {
            printf("Couldn't allocate any more memory. Exiting program.\n");
            exit(1);
        }

        printf("Allocated %d MB of memory. Total memory allocated so far: %d MB\n",
                allocationSize, numAllocations);
    }

    // Free up all the memory we allocated
    for (int i = 0; i < numAllocations; i++) {
        free(myArray[i]);
    }

    printf("Program finished successfully!\n");
    return 0;
}