//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MIN_VALUE 0.01
#define MAX_VALUE 1000000
#define SAMPLE_SIZE 10000

// Function to generate random numbers
float random_number(void) {
    return (float)rand() / RAND_MAX;
}

// Function to calculate the mean and standard deviation
void calculate_mean_stddev(float *numbers, int size) {
    float sum = 0;
    float square_sum = 0;
    int i;

    for (i = 0; i < size; i++) {
        sum += numbers[i];
        square_sum += (numbers[i] * numbers[i]);
    }

    float mean = sum / size;
    float stddev = sqrt(square_sum / (size - 1));

    printf("Mean: %f\n", mean);
    printf("Standard Deviation: %f\n", stddev);
}

int main() {
    // Generate a random sample of size SAMPLE_SIZE
    float *numbers = calloc(SAMPLE_SIZE, sizeof(float));
    for (int i = 0; i < SAMPLE_SIZE; i++) {
        numbers[i] = random_number();
    }

    // Calculate the mean and standard deviation
    calculate_mean_stddev(numbers, SAMPLE_SIZE);

    // Print the histogram of the sample
    int bin_size = 100;
    int histogram[100];
    for (int i = 0; i < SAMPLE_SIZE; i++) {
        int bin = (int)((numbers[i] - MIN_VALUE) / bin_size);
        histogram[bin]++;
    }

    for (int i = 0; i < 100; i++) {
        printf("%3d: %5d\n", i * bin_size, histogram[i]);
    }

    free(numbers);
    return 0;
}