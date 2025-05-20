//FormAI DATASET v1.0 Category: Memory management ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    srand(time(NULL)); //Initialize random number generator

    //Allocate 100 integers dynamically and store random numbers from 0 to 99 in it
    int *arr = (int*) malloc(100 * sizeof(int));
    for (int i = 0; i < 100; i++) {
        *(arr + i) = rand() % 100;
    }

    //Print the numbers stored in the array
    for (int i = 0; i < 100; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");

    //Allocate space for a new array of size 50 and copy every other element of the previous array to it
    int *newArr = (int*) malloc(50 * sizeof(int));
    for (int i = 0, j = 0; i < 100; i += 2, j++) {
        *(newArr + j) = *(arr + i);
    }

    //Free the previous array
    free(arr);

    //Print the numbers stored in the new array
    for (int i = 0; i < 50; i++) {
        printf("%d ", *(newArr + i));
    }
    printf("\n");

    //Reallocate space for the new array of size 75 and assign random numbers from 0 to 99 to the new positions
    newArr = (int*) realloc(newArr, 75 * sizeof(int));
    for (int i = 50; i < 75; i++) {
        *(newArr + i) = rand() % 100;
    }

    //Print the numbers stored in the new array
    for (int i = 0; i < 75; i++) {
        printf("%d ", *(newArr + i));
    }
    printf("\n");

    //Free the new array
    free(newArr);

    return 0;
}