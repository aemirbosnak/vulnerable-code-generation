//Falcon-180B DATASET v1.0 Category: Data mining ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DATA_POINTS 1000
#define MAX_VARIABLES 10

typedef struct {
    double **data;
    int num_rows;
    int num_cols;
} DataSet;

DataSet* create_dataset(int num_rows, int num_cols) {
    DataSet *dataset = (DataSet*)malloc(sizeof(DataSet));
    dataset->num_rows = num_rows;
    dataset->num_cols = num_cols;
    dataset->data = (double**)malloc(sizeof(double*) * num_rows);
    for (int i = 0; i < num_rows; i++) {
        dataset->data[i] = (double*)malloc(sizeof(double) * num_cols);
    }
    return dataset;
}

void destroy_dataset(DataSet *dataset) {
    for (int i = 0; i < dataset->num_rows; i++) {
        free(dataset->data[i]);
    }
    free(dataset->data);
    free(dataset);
}

void fill_dataset(DataSet *dataset, double min_val, double max_val) {
    srand(time(NULL));
    for (int i = 0; i < dataset->num_rows; i++) {
        for (int j = 0; j < dataset->num_cols; j++) {
            dataset->data[i][j] = rand() % (int)(max_val - min_val + 1) + min_val;
        }
    }
}

void print_dataset(DataSet *dataset) {
    for (int i = 0; i < dataset->num_rows; i++) {
        for (int j = 0; j < dataset->num_cols; j++) {
            printf("%lf ", dataset->data[i][j]);
        }
        printf("\n");
    }
}

double calculate_mean(double *data, int num_data_points) {
    double sum = 0;
    for (int i = 0; i < num_data_points; i++) {
        sum += data[i];
    }
    return sum / num_data_points;
}

double calculate_variance(double *data, int num_data_points, double mean) {
    double sum_squares = 0;
    for (int i = 0; i < num_data_points; i++) {
        sum_squares += pow(data[i] - mean, 2);
    }
    return sum_squares / num_data_points;
}

double calculate_standard_deviation(double variance) {
    return sqrt(variance);
}

int main() {
    int num_rows, num_cols;
    printf("Enter number of rows: ");
    scanf("%d", &num_rows);
    printf("Enter number of columns: ");
    scanf("%d", &num_cols);

    DataSet *dataset = create_dataset(num_rows, num_cols);
    fill_dataset(dataset, 0, 100);
    print_dataset(dataset);

    double *data = dataset->data[0];
    int num_data_points = dataset->num_rows * dataset->num_cols;
    double mean = calculate_mean(data, num_data_points);
    double variance = calculate_variance(data, num_data_points, mean);
    double standard_deviation = calculate_standard_deviation(variance);

    printf("Mean: %lf\n", mean);
    printf("Variance: %lf\n", variance);
    printf("Standard Deviation: %lf\n", standard_deviation);

    destroy_dataset(dataset);
    return 0;
}