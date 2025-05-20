//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITERATIONS 1000 /* maximum number of iterations */
#define EPSILON 0.001 /* minimum distance change for convergence */

/* Euclidean distance calculation */
double euclidean_distance(double *p1, double *p2, int n) {
    double sum = 0.0;
    for (int i=0; i<n; i++) {
        sum += pow(p1[i] - p2[i], 2);
    }
    return sqrt(sum);
}

/* implementation of K-Means Clustering Algorithm */
void k_means(double **points, int n, int k, int *clusters) {
    double **centers = (double **)malloc(k * sizeof(double *));
    for (int i=0; i<k; i++) {
        centers[i] = (double *)malloc(n * sizeof(double));
    }
    /* initialize centers randomly */
    for (int i=0; i<k; i++) {
        for (int j=0; j<n; j++) {
            centers[i][j] = (double)rand() / RAND_MAX;
        }
    }
    int iterations = 0;
    while (iterations < MAX_ITERATIONS) {
        /* assign each point to closest cluster */
        int converged = 1;
        for (int i=0; i<n; i++) {
            double min_distance = INFINITY;
            int min_index;
            for (int j=0; j<k; j++) {
                double distance = euclidean_distance(points[i], centers[j], n);
                if (distance < min_distance) {
                    min_distance = distance;
                    min_index = j;
                }
            }
            if (clusters[i] != min_index) {
                clusters[i] = min_index;
                converged = 0;
            }
        }
        /* recompute centers */
        for (int i=0; i<k; i++) {
            int count = 0;
            for (int j=0; j<n; j++) {
                if (clusters[j] == i) {
                    count++;
                    for (int l=0; l<n; l++) {
                        centers[i][l] += points[j][l];
                    }
                }
            }
            if (count > 0) {
                for (int l=0; l<n; l++) {
                    centers[i][l] /= count;
                }
            }
        }
        iterations++;
        if (converged) {
            break;
        }
    }
    /* free memory */
    for (int i=0; i<k; i++) {
        free(centers[i]);
    }
    free(centers);
}

/* main function to test the program */
int main() {
    printf("Implementing K-Means Clustering Algorithm\n");

    int n = 10; /* number of points */
    int k = 3; /* number of clusters */
    double **points = (double **)malloc(n * sizeof(double *));
    for (int i=0; i<n; i++) {
        points[i] = (double *)malloc(2 * sizeof(double));
        points[i][0] = (double)rand() / RAND_MAX;
        points[i][1] = (double)rand() / RAND_MAX;
    }
    int *clusters = (int *)calloc(n, sizeof(int));

    k_means(points, n, k, clusters);

    printf("Results after K-Means Clustering:\n");
    for (int i=0; i<k; i++) {
        printf("Cluster %d:\n", i);
        for (int j=0; j<n; j++) {
            if (clusters[j] == i) {
                printf("(%f, %f)\n", points[j][0], points[j][1]);
            }
        }
    }

    /* free memory */
    for (int i=0; i<n; i++) {
        free(points[i]);
    }
    free(points);
    free(clusters);

    return 0;
}