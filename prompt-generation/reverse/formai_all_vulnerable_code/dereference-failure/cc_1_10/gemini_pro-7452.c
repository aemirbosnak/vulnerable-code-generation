//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the data structure for a statistical sample
typedef struct {
    double *data;
    int size;
} sample;

// Create a new sample
sample *sample_new(int size) {
    sample *s = malloc(sizeof(sample));
    s->data = malloc(sizeof(double) * size);
    s->size = size;
    return s;
}

// Free a sample
void sample_free(sample *s) {
    free(s->data);
    free(s);
}

// Add a value to a sample
void sample_add(sample *s, double value) {
    s->data[s->size++] = value;
}

// Get the mean of a sample
double sample_mean(sample *s) {
    double sum = 0;
    for (int i = 0; i < s->size; i++) {
        sum += s->data[i];
    }
    return sum / s->size;
}

// Get the standard deviation of a sample
double sample_stddev(sample *s) {
    double mean = sample_mean(s);
    double sum = 0;
    for (int i = 0; i < s->size; i++) {
        sum += pow(s->data[i] - mean, 2);
    }
    return sqrt(sum / (s->size - 1));
}

// Find the minimum value in a sample
double sample_min(sample *s) {
    double min = s->data[0];
    for (int i = 1; i < s->size; i++) {
        if (s->data[i] < min) {
            min = s->data[i];
        }
    }
    return min;
}

// Find the maximum value in a sample
double sample_max(sample *s) {
    double max = s->data[0];
    for (int i = 1; i < s->size; i++) {
        if (s->data[i] > max) {
            max = s->data[i];
        }
    }
    return max;
}

// Print the contents of a sample
void sample_print(sample *s) {
    printf("Sample size: %d\n", s->size);
    printf("Sample mean: %.2f\n", sample_mean(s));
    printf("Sample standard deviation: %.2f\n", sample_stddev(s));
    printf("Sample minimum: %.2f\n", sample_min(s));
    printf("Sample maximum: %.2f\n", sample_max(s));
    printf("Sample data:\n");
    for (int i = 0; i < s->size; i++) {
        printf("%.2f ", s->data[i]);
    }
    printf("\n");
}

// Example usage
int main() {
    // Create a new sample
    sample *s = sample_new(10);

    // Add some values to the sample
    sample_add(s, 10.0);
    sample_add(s, 20.0);
    sample_add(s, 30.0);
    sample_add(s, 40.0);
    sample_add(s, 50.0);
    sample_add(s, 60.0);
    sample_add(s, 70.0);
    sample_add(s, 80.0);
    sample_add(s, 90.0);
    sample_add(s, 100.0);

    // Print the contents of the sample
    sample_print(s);

    // Free the sample
    sample_free(s);

    return 0;
}