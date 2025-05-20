//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double calc_euc_distance(int N, double *x, double *y, int i, int j) {
    double distance = 0.0;
    for (int k = 0; k < N; k++) {
        distance += pow((x[i*N+k] - x[j*N+k]), 2) + pow((y[i*N+k] - y[j*N+k]), 2);
    }
    return sqrt(distance);
}

void calc_cluster_distances(int N, double *x, double *y, int *cluster, double **distances) {
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            distances[i][j] = distances[j][i] = calc_euc_distance(N, x, y, i, j);
        }
    }
    for (int i = 0; i < N; i++) {
        distances[i][i] = 0.0;
    }
}

int update_cluster(int N, double **distances, int *cluster) {
    int modified = 0;
    for (int i = 0; i < N; i++) {
        double min_distance = distances[i][0];
        int min_cluster = 0;
        for (int j = 1; j < N; j++) {
            if (distances[i][j] < min_distance) {
                min_distance = distances[i][j];
                min_cluster = j;
            }
        }
        if (min_cluster != cluster[i]) {
            cluster[i] = min_cluster;
            modified = 1;
        }
    }
    return modified;
}

void print_classification(int N, int *cluster) {
    printf("Classification:\n");
    for (int i = 0; i < N; i++) {
        printf("Item %d: Cluster %d\n", i+1, cluster[i]+1);
    }
    printf("\n");
}

int main() {
    int N = 5; // Number of items
    double x[5][2] = {{-2.0, 2.0}, {2.0, -2.0}, {-1.0, 1.0}, {1.0, -1.0}, {0.0, 1.0}}; // X-coordinates
    double y[5][2] = {{3.0, 1.0}, {1.0, 3.0}, {2.0, 0.0}, {0.0, 2.0}, {1.0, 0.5}}; // Y-coordinates
    int cluster[5] = {0, 1, 2, 3, 4}; // Starting classification
    double **distances = (double **)malloc(N * sizeof(double *));
    for (int i = 0; i < N; i++) {
        distances[i] = (double *)malloc(N * sizeof(double));
    }
    calc_cluster_distances(N, *x, *y, cluster, distances);
    int modified = update_cluster(N, distances, cluster);
    int iter = 1;
    while (modified) {
        printf("Iteration %d:\n", iter);
        print_classification(N, cluster);
        calc_cluster_distances(N, x, y, cluster, distances);
        modified = update_cluster(N, distances, cluster);
        iter++;
    }
    printf("Final Classification:\n");
    print_classification(N, cluster);
    return 0;
}