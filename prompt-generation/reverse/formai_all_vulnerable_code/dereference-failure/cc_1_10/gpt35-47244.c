//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000 // Maximum Size of the RAM Available

// Function to Calculate the Current RAM Usage
float calculate_ram_usage(int* arr) {
    int i;
    float used_ram = 0.0;
    for (i = 0; i < MAX_SIZE; i++) {
        if (*(arr + i) != NULL) {
            used_ram += sizeof(*(arr + i));
        }
    }
    return used_ram;
}

int main() {
    int* arr;
    int size, i;

    printf("Enter the Size of the Array: ");
    scanf("%d", &size);

    // Checking whether the Size of the Array is less than the Maximum Size of the RAM Available
    if (size <= MAX_SIZE) {
        arr = (int*) malloc(size * sizeof(int));

        // Initializing the Array with 0
        for (i = 0; i < size; i++) {
            *(arr + i) = 0;
        }

        // Displaying the Initial RAM Usage
        printf("Initial RAM Usage: %.2f KB\n", calculate_ram_usage(arr) / 1024);

        // Updating the Array with Random Values
        for (i = 0; i < size; i++) {
            *(arr + i) = rand();
        }

        // Displaying the Updated RAM Usage
        printf("Updated RAM Usage: %.2f KB\n", calculate_ram_usage(arr) / 1024);

        // Freeing the Memory Allocated for the Array
        free(arr);
    } else {
        printf("Error! Array Size exceeds the Maximum Size of the RAM Available.\n");
    }

    return 0;
}