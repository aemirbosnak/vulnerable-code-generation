//FormAI DATASET v1.0 Category: Educational ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

// Function to compute the square of a scalar variable
float square(float num){
    return num*num;
}

// Function to perform an element-wise multiplication of two arrays
void elementwise_product(float *A, float *B, float *C, int size){
    for (int i =0 ; i < size; i ++){
        C[i] = A[i] * B[i];
    }
}

// Function to compute the sum of all elements in an array
float sum(float *arr, int size){
    float total = 0;
    for(int i = 0; i < size; i++){
        total += arr[i];
    }

    return total;
}

// Main function
int main(){

    // Declare variables
    float scalar = 3.2;
    int size = 10;

    // Allocate memory for arrays
    float *array1 = (float*)malloc(size*sizeof(float));
    float *array2 = (float*)malloc(size*sizeof(float));
    float *array3 = (float*)malloc(size*sizeof(float));

    // Initialize array1 and array2 with random numbers between 0.0 and 1.0
    for(int i = 0; i < size; i++){
        array1[i] = ((float) rand() / (RAND_MAX));
        array2[i] = ((float) rand() / (RAND_MAX));
    }

    // Compute the element-wise product of array1 and array2 and store the result in array3
    elementwise_product(array1, array2, array3, size);

    // Compute the square of scalar and print the result
    float scalar_squared = square(scalar);
    printf("The square of %f is %f\n", scalar, scalar_squared);

    // Compute the sum of all elements in array3 and print the result
    float array3_sum = sum(array3, size);
    printf("The sum of the elements in array3 is %f\n", array3_sum);

    // Free memory
    free(array1);
    free(array2);
    free(array3);

    return 0;
}