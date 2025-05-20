//FormAI DATASET v1.0 Category: Error handling ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

// function to check if divisor is zero
void checkDivisor(int divisor) {
    if(divisor == 0) {
        printf("\nError: Division by zero is not allowed.\n");
        exit(EXIT_FAILURE);
    }
}

// function to divide two given numbers
float divide(float num1, float num2) {
    float result;
    checkDivisor(num2);
    result = num1 / num2;
    return result;
}

// function to calculate the average of given numbers
float calculateAverage(int size, int numbers[]) {
    int i;
    float sum = 0, average;
    for(i=0; i<size; i++) {
        sum += numbers[i];
    }
    checkDivisor(size);
    average = divide(sum, size);
    return average;
}

// main function to execute the program
int main() {
    int size, i;
    float average;
    int *numbers;

    // get the size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    // allocate memory dynamically for the array
    numbers = (int *) malloc(size * sizeof(int));

    // check if memory is allocated
    if(numbers == NULL) {
        printf("\nError: Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    // get the elements of the array
    printf("Enter %d elements of the array: ", size);
    for(i=0; i<size; i++) {
        scanf("%d", &numbers[i]);
    }

    // calculate the average of the elements of the array
    average = calculateAverage(size, numbers);

    // print the result
    printf("The average of the elements of the array is: %.2f\n", average);

    // free the allocated memory
    free(numbers);

    return 0;
}