//LLAMA2-13B DATASET v1.0 Category: Data mining ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

// Define the data structure for the surprise data
typedef struct {
    int surprise;
    int cause;
} SurpriseData;

// Define the function to calculate the surprise score
int calculate_surprise(SurpriseData *data, int num_data) {
    int i, j, k;
    int sum = 0;

    // Calculate the surprise score for each data point
    for (i = 0; i < num_data; i++) {
        sum += data[i].surprise;
    }

    // Calculate the average surprise score
    int avg_surprise = sum / num_data;

    // Calculate the standard deviation of the surprise score
    int std_dev = sqrt(sum * (num_data - 1) / (num_data * (num_data - 1)));

    // Calculate the z-score for each data point
    for (i = 0; i < num_data; i++) {
        int z_score = (data[i].surprise - avg_surprise) / std_dev;

        // Print the z-score and the corresponding cause
        printf("Z-score: %d, Cause: %d\n", z_score, data[i].cause);
    }

    return 0;
}

int main() {
    // Generate some random surprise data
    SurpriseData data[10];
    for (int i = 0; i < 10; i++) {
        data[i].surprise = (int)(10 * (rand() / RAND_MAX));
        data[i].cause = (int)(10 * (rand() / RAND_MAX));
    }

    // Call the calculate_surprise function
    calculate_surprise(data, 10);

    return 0;
}