//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_N 1000

typedef struct {
    int n;
    double *x;
    double *y;
} ScatterPlot;

ScatterPlot *create_scatter_plot(int n) {
    ScatterPlot *scatter_plot = malloc(sizeof(ScatterPlot));
    scatter_plot->n = n;
    scatter_plot->x = malloc(n * sizeof(double));
    scatter_plot->y = malloc(n * sizeof(double));
    return scatter_plot;
}

void destroy_scatter_plot(ScatterPlot *scatter_plot) {
    free(scatter_plot->x);
    free(scatter_plot->y);
    free(scatter_plot);
}

void generate_random_scatter_plot(ScatterPlot *scatter_plot) {
    for (int i = 0; i < scatter_plot->n; i++) {
        scatter_plot->x[i] = (double)rand() / RAND_MAX;
        scatter_plot->y[i] = (double)rand() / RAND_MAX;
    }
}

void print_scatter_plot(ScatterPlot *scatter_plot) {
    for (int i = 0; i < scatter_plot->n; i++) {
        printf("(%f, %f)\n", scatter_plot->x[i], scatter_plot->y[i]);
    }
}

double calculate_mean(double *data, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += data[i];
    }
    return sum / n;
}

double calculate_variance(double *data, int n, double mean) {
    double sum_of_squared_differences = 0;
    for (int i = 0; i < n; i++) {
        sum_of_squared_differences += pow(data[i] - mean, 2);
    }
    return sum_of_squared_differences / (n - 1);
}

double calculate_covariance(double *x, double *y, int n, double mean_x, double mean_y) {
    double sum_of_products = 0;
    for (int i = 0; i < n; i++) {
        sum_of_products += (x[i] - mean_x) * (y[i] - mean_y);
    }
    return sum_of_products / (n - 1);
}

double calculate_correlation_coefficient(double *x, double *y, int n, double mean_x, double mean_y) {
    double covariance = calculate_covariance(x, y, n, mean_x, mean_y);
    double variance_x = calculate_variance(x, n, mean_x);
    double variance_y = calculate_variance(y, n, mean_y);
    return covariance / sqrt(variance_x * variance_y);
}

int main() {
    int n = 100;
    ScatterPlot *scatter_plot = create_scatter_plot(n);
    generate_random_scatter_plot(scatter_plot);
    print_scatter_plot(scatter_plot);

    double mean_x = calculate_mean(scatter_plot->x, n);
    double mean_y = calculate_mean(scatter_plot->y, n);

    double covariance = calculate_covariance(scatter_plot->x, scatter_plot->y, n, mean_x, mean_y);
    double variance_x = calculate_variance(scatter_plot->x, n, mean_x);
    double variance_y = calculate_variance(scatter_plot->y, n, mean_y);
    double correlation_coefficient = calculate_correlation_coefficient(scatter_plot->x, scatter_plot->y, n, mean_x, mean_y);

    printf("Mean of X: %f\n", mean_x);
    printf("Mean of Y: %f\n", mean_y);
    printf("Covariance: %f\n", covariance);
    printf("Variance of X: %f\n", variance_x);
    printf("Variance of Y: %f\n", variance_y);
    printf("Correlation coefficient: %f\n", correlation_coefficient);

    destroy_scatter_plot(scatter_plot);
    return 0;
}