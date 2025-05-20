//FormAI DATASET v1.0 Category: Searching algorithm ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// This function will generate an array of random integers between 1 and 100.
int* generateRandomArray(int size) {
    int* array = malloc(size * sizeof(int));

    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100 + 1;
    }

    return array;
}

// This function will search for a random integer in the array.
int searchForRandomInteger(int* array, int size, int* randomInteger) {
    *randomInteger = rand() % 100 + 1;

    for (int i = 0; i < size; i++) {
        if (array[i] == *randomInteger) {
            return i;
        }
    }

    return -1;
}

int main() {
    int size = 10;
    int* array = generateRandomArray(size);
    int randomInteger, index;

    printf("Hello there! I am a unique searching algorithm program.\n");
    printf("I have generated an array of %d random integers between 1 and 100.\n", size);
    printf("Now, I will search for a random integer in the array.\n");

    index = searchForRandomInteger(array, size, &randomInteger);

    if (index == -1) {
        printf("Oh no! I couldn't find the random integer %d in the array.\n", randomInteger);
    } else {
        printf("Yay! I found the random integer %d at index %d in the array.\n", randomInteger, index);
    }

    free(array);

    printf("Thanks for using me! Goodbye!\n");

    return 0;
}