//FormAI DATASET v1.0 Category: Memory management ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Hello there! I am a C program that demonstrates memory management using malloc and free.\n");
    printf("I bet you are wondering what I can do... Well, let me show you!\n");

    // Let's allocate some memory for an integer
    int* myInt = (int*) malloc(sizeof(int));

    if (myInt == NULL) {
        printf("Oh no! Something went wrong with memory allocation.\n");
        return 1;
    }

    // Let's assign a value to our integer
    *myInt = 42;

    printf("Congratulations! We have allocated memory for an integer and set its value to %d.\n", *myInt);

    // Now, let's allocate an array of floats
    int size = 5;
    float* myFloatArray = (float*) malloc(size * sizeof(float));

    if (myFloatArray == NULL) {
        printf("Uh-oh! Something went wrong with memory allocation.\n");
        return 1;
    }

    // Let's assign some values to our float array
    for (int i = 0; i < size; i++) {
        myFloatArray[i] = (float) (i + 1) / 10;
    }

    printf("Great news! We have allocated memory for an array of floats and assigned the values:\n");

    for (int i = 0; i < size; i++) {
        printf("%f ", myFloatArray[i]);
    }

    printf("\n");

    // Let's free up our allocated memory
    free(myInt);
    free(myFloatArray);

    printf("We are all done! We have successfully allocated and freed up memory in our C program.\n");

    return 0;
}