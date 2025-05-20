//MISTRAL-7B DATASET v1.0 Category: Digital signal processing ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#define WINDOW_SIZE 5

typedef struct {
    float data[WINDOW_SIZE];
    float sum;
    int index;
} moving_average;

void moving_average_filter(float input[], float output[], int sample_rate, int num_samples, int window_size) {
    moving_average ma;
    int i;

    ma.sum = 0.0;
    ma.index = 0;

    for (i = 0; i < num_samples; i++) {
        ma.data[ma.index] = input[i];
        ma.sum += input[i];

        if (++ma.index >= window_size) {
            ma.index -= window_size;
            output[i] = ma.sum / window_size;
            ma.sum -= input[i - window_size];
        }
    }

    // Pad the last output with the average of the last window if not full
    if (ma.index < window_size) {
        int padding_samples = window_size - ma.index;
        float last_window_sum = ma.sum;
        for (i = 0; i < padding_samples; i++) {
            last_window_sum += input[num_samples - i - 1];
        }
        output[num_samples - 1 + ma.index] = last_window_sum / window_size;
    }
}

int main() {
    float input[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
    float output[15]; // enough for the given input and the padding
    int sample_rate = 1000;
    int num_samples = sizeof(input) / sizeof(input[0]);

    printf("Original Input:\n");
    for (int i = 0; i < num_samples; i++) {
        printf("%.1f ", input[i]);
    }
    printf("\n");

    moving_average_filter(input, output, sample_rate, num_samples, WINDOW_SIZE);

    printf("\nJolly Moving Average Filter Output:\n");
    for (int i = 0; i < num_samples; i++) {
        printf("%.1f ", output[i]);
    }
    printf("\n");

    return 0;
}