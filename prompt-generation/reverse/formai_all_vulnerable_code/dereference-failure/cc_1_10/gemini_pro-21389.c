//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: innovative
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct {
    double *data;
    int size;
} DataFrame;

DataFrame *create_dataframe(int size) {
    DataFrame *df = malloc(sizeof(DataFrame));
    df->data = malloc(size * sizeof(double));
    df->size = size;
    return df;
}

void free_dataframe(DataFrame *df) {
    free(df->data);
    free(df);
}

void print_dataframe(DataFrame *df) {
    for (int i = 0; i < df->size; i++) {
        printf("%f ", df->data[i]);
    }
    printf("\n");
}

int main() {
    // Create a dataframe with 10 random numbers
    DataFrame *df = create_dataframe(10);
    for (int i = 0; i < df->size; i++) {
        df->data[i] = rand() / (double)RAND_MAX;
    }

    // Print the dataframe
    print_dataframe(df);

    // Calculate the mean of the dataframe
    double mean = 0;
    for (int i = 0; i < df->size; i++) {
        mean += df->data[i];
    }
    mean /= df->size;

    // Calculate the standard deviation of the dataframe
    double stddev = 0;
    for (int i = 0; i < df->size; i++) {
        stddev += pow(df->data[i] - mean, 2);
    }
    stddev /= df->size;
    stddev = sqrt(stddev);

    // Print the mean and standard deviation
    printf("Mean: %f\n", mean);
    printf("Standard deviation: %f\n", stddev);

    // Free the dataframe
    free_dataframe(df);

    return 0;
}