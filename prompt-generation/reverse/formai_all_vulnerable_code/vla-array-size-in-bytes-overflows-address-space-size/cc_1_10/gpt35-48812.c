//FormAI DATASET v1.0 Category: Image compression ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_INPUT_SIZE 1000
#define MAX_OUTPUT_SIZE 1000

// Function to calculate the sum of a list of numbers
double sum(double arr[], int size) {
    double total = 0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    return total;
}

// Function to calculate the mean of a list of numbers
double mean(double arr[], int size) {
    return sum(arr, size) / size;
}

// Function to calculate the standard deviation of a list of numbers
double std_dev(double arr[], int size, double mean_val) {
    double sum_dev = 0;
    for (int i = 0; i < size; i++) {
        sum_dev += pow(arr[i] - mean_val, 2);
    }
    return sqrt(sum_dev / size);
}

// Function to perform image compression using mathematical calculation
void compress_image(double input[][MAX_INPUT_SIZE], int height, int width, int levels, double output[][MAX_OUTPUT_SIZE]) {
    // Calculate the mean and standard deviation of each row
    double row_means[MAX_INPUT_SIZE];
    double row_std_devs[MAX_INPUT_SIZE];

    for (int i = 0; i < height; i++) {
        row_means[i] = mean(input[i], width);
        row_std_devs[i] = std_dev(input[i], width, row_means[i]);
    }

    // Determine the range for each quantization level
    double range = 255.0 / levels;
    double level_values[levels];

    for (int i = 0; i < levels; i++) {
        level_values[i] = (i + 0.5) * range; 
    }

    // Set the output values based on the quantization levels
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int level = (int)floor((input[i][j] - row_means[i]) / row_std_devs[i] * range + level_values[0] + 0.5);
            level = (level > (levels - 1)) ? (levels - 1) : level;
            output[i][j] = level_values[level];
        }
    }
}

int main() {
    // Read in the input image
    int height, width, levels;
    double input[MAX_INPUT_SIZE][MAX_INPUT_SIZE];

    scanf("%d %d %d", &height, &width, &levels);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            scanf("%lf", &input[i][j]);
        }
    }

    // Compress the image and output the result
    double output[MAX_INPUT_SIZE][MAX_OUTPUT_SIZE];
    compress_image(input, height, width, levels, output);

    printf("%d %d\n", height, width);
    printf("%d\n", levels);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", (int)output[i][j]);
        }
        printf("\n");
    }

    return 0;
}