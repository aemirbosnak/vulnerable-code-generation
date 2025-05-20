//FormAI DATASET v1.0 Category: Educational ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

int main() {
    int array[MAX];
    int min, max, sum, average;
    int i, n;

    srand(time(0));

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Generate random numbers between 1 and 100 and store them in the array
    for(i = 0; i < n; i++) {
        array[i] = rand() % 100 + 1;
    }

    // Print the array
    printf("\nThe elements of the array are: ");
    for(i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }

    // Calculate the minimum value
    min = array[0];
    for(i = 1; i < n; i++) {
        if(array[i] < min) {
            min = array[i];
        }
    }

    // Calculate the maximum value
    max = array[0];
    for(i = 1; i < n; i++) {
        if(array[i] > max) {
            max = array[i];
        }
    }

    // Calculate the sum and average
    sum = 0;
    for(i = 0; i < n; i++) {
        sum += array[i];
    }
    average = sum / n;

    // Print the minimum, maximum, sum, and average
    printf("\n\nThe minimum value is: %d", min);
    printf("\nThe maximum value is: %d", max);
    printf("\nThe sum of the elements is: %d", sum);
    printf("\nThe average of the elements is: %d", average);

    return 0;
}