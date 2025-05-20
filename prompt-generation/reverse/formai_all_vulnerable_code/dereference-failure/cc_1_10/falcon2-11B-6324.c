//Falcon2-11B DATASET v1.0 Category: Bingo Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max (inclusive)
int randomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to check if a number is in the array
int isInArray(int num, int array[], int size) {
    for (int i = 0; i < size; i++) {
        if (num == array[i]) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int size = 25;
    int *array = (int*)malloc(size * sizeof(int));
    
    // Generate random numbers and add them to the array
    for (int i = 0; i < size; i++) {
        array[i] = randomNumber(1, 100);
    }
    
    // Print the array
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    // Generate a random bingo number
    int bingoNumber = randomNumber(1, 100);
    
    // Check if the bingo number is in the array
    int isBingo = isInArray(bingoNumber, array, size);
    
    // Print the result
    if (isBingo) {
        printf("Bingo!\n");
    } else {
        printf("No Bingo.\n");
    }
    
    // Free the memory
    free(array);
    
    return 0;
}