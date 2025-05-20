//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} point;

typedef struct {
    int n;
    point *points;
} dataset;

dataset *create_dataset(int n) {
    dataset *ds = malloc(sizeof(dataset));
    ds->n = n;
    ds->points = malloc(n * sizeof(point));
    return ds;
}

void destroy_dataset(dataset *ds) {
    free(ds->points);
    free(ds);
}

void add_point(dataset *ds, double x, double y) {
    ds->points[ds->n].x = x;
    ds->points[ds->n].y = y;
    ds->n++;
}

void print_dataset(dataset *ds) {
    for (int i = 0; i < ds->n; i++) {
        printf("(%f, %f)\n", ds->points[i].x, ds->points[i].y);
    }
}

double mean(dataset *ds) {
    double sum = 0;
    for (int i = 0; i < ds->n; i++) {
        sum += ds->points[i].x;
    }
    return sum / ds->n;
}

double variance(dataset *ds) {
    double mean_x = mean(ds);
    double sum = 0;
    for (int i = 0; i < ds->n; i++) {
        sum += pow(ds->points[i].x - mean_x, 2);
    }
    return sum / (ds->n - 1);
}

double standard_deviation(dataset *ds) {
    return sqrt(variance(ds));
}

int main() {
    dataset *ds = create_dataset(10);
    add_point(ds, 1, 2);
    add_point(ds, 3, 4);
    add_point(ds, 5, 6);
    add_point(ds, 7, 8);
    add_point(ds, 9, 10);
    print_dataset(ds);
    printf("Mean: %f\n", mean(ds));
    printf("Variance: %f\n", variance(ds));
    printf("Standard deviation: %f\n", standard_deviation(ds));
    destroy_dataset(ds);
    return 0;
}