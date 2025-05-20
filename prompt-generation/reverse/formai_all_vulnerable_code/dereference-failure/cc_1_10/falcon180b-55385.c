//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

#define MAX_SIZE 1000
#define MIN_VALUE -10
#define MAX_VALUE 10

int main() {
    int size;
    double *array;
    int i, j, sum, count;
    double mean, variance, standard_deviation;
    bool is_valid_input = true;

    printf("Enter the size of the array (between 1 and %d): ", MAX_SIZE);
    scanf("%d", &size);

    if (size < 1 || size > MAX_SIZE) {
        printf("Invalid size. Please enter a number between 1 and %d.\n", MAX_SIZE);
        is_valid_input = false;
    }

    if (is_valid_input) {
        array = (double *) malloc(size * sizeof(double));

        for (i = 0; i < size; i++) {
            printf("Enter element %d (between %.1f and %.1f): ", i + 1, MIN_VALUE, MAX_VALUE);
            scanf("%lf", &array[i]);

            if (array[i] < MIN_VALUE || array[i] > MAX_VALUE) {
                printf("Invalid input. Please enter a number between %.1f and %.1f.\n", MIN_VALUE, MAX_VALUE);
                is_valid_input = false;
                break;
            }
        }

        if (is_valid_input) {
            sum = 0;
            for (i = 0; i < size; i++) {
                sum += array[i];
            }

            mean = sum / size;

            for (i = 0; i < size; i++) {
                sum += pow(array[i] - mean, 2);
            }

            variance = sum / size;
            standard_deviation = sqrt(variance);

            printf("Mean: %.2f\n", mean);
            printf("Variance: %.2f\n", variance);
            printf("Standard Deviation: %.2f\n", standard_deviation);
        }
    }

    free(array);
    return 0;
}