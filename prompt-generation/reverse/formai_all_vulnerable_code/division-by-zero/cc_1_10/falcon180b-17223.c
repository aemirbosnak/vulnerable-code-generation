//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function to generate a random number between min and max
int randomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

//Function to calculate the sum of all even numbers in an array
int sumEvenNumbers(int arr[], int size) {
    int sum = 0;
    for(int i=0; i<size; i++) {
        if(arr[i] % 2 == 0) {
            sum += arr[i];
        }
    }
    return sum;
}

//Function to calculate the average of an array
double calculateAverage(int arr[], int size) {
    int sum = 0;
    for(int i=0; i<size; i++) {
        sum += arr[i];
    }
    return (double)sum / size;
}

//Function to calculate the variance of an array
double calculateVariance(int arr[], int size) {
    int sum = 0;
    int mean = calculateAverage(arr, size);
    for(int i=0; i<size; i++) {
        sum += pow((arr[i] - mean), 2);
    }
    return sum / size;
}

//Function to calculate the standard deviation of an array
double calculateStandardDeviation(int arr[], int size) {
    return sqrt(calculateVariance(arr, size));
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter %d numbers:\n", size);
    for(int i=0; i<size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("The sum of all even numbers in the array is: %d\n", sumEvenNumbers(arr, size));
    printf("The average of the array is: %.2f\n", calculateAverage(arr, size));
    printf("The variance of the array is: %.2f\n", calculateVariance(arr, size));
    printf("The standard deviation of the array is: %.2f\n", calculateStandardDeviation(arr, size));

    return 0;
}