//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define K 3             // Number of clusters
#define MAX_ITER 100    // Max number of iterations
#define DATA "data.txt" // Data file

// Struct for a single data point
typedef struct Point {
    double x;
    double y;
} Point;

// Struct for a cluster
typedef struct Cluster {
    Point center;
    int size;
    Point *points;
} Cluster;

// Reads data from file
Point* readData(int *n) {
    FILE *fp = fopen(DATA, "r");
    if (fp == NULL) {
        printf("Error: cannot open file\n");
        exit(1);
    }

    fscanf(fp, "%d", n);
    Point *data = malloc(*n * sizeof(Point));
    for (int i = 0; i < *n; i++) {
        fscanf(fp, "%lf", &data[i].x);
        fscanf(fp, "%lf", &data[i].y);
    }

    fclose(fp);
    return data;
}

// Initializes clusters randomly
Cluster* initClusters(Point *data, int n) {
    Cluster *clusters = malloc(K * sizeof(Cluster));

    for (int i = 0; i < K; i++) {
        clusters[i].center.x = ((double)rand() / RAND_MAX) * 10;
        clusters[i].center.y = ((double)rand() / RAND_MAX) * 10;
        clusters[i].size = 0;
        clusters[i].points = malloc(n * sizeof(Point));
    }

    return clusters;
}

// Computes Euclidean distance between two points
double distance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// Assigns data points to nearest cluster
void assignPoints(Cluster *clusters, Point *data, int n) {
    for (int i = 0; i < n; i++) {
        double min_dist = INFINITY;
        int min_idx = -1;

        for (int j = 0; j < K; j++) {
            double dist = distance(data[i], clusters[j].center);
            if (dist < min_dist) {
                min_dist = dist;
                min_idx = j;
            }
        }

        clusters[min_idx].points[clusters[min_idx].size] = data[i];
        clusters[min_idx].size++;
    }
}

// Computes new cluster centers
void updateCenters(Cluster *clusters) {
    for (int i = 0; i < K; i++) {
        double sum_x = 0, sum_y = 0;

        for (int j = 0; j < clusters[i].size; j++) {
            sum_x += clusters[i].points[j].x;
            sum_y += clusters[i].points[j].y;
        }

        clusters[i].center.x = sum_x / clusters[i].size;
        clusters[i].center.y = sum_y / clusters[i].size;
    }
}

// Prints data and cluster points
void printData(Cluster *clusters) {
    for (int i = 0; i < K; i++) {
        printf("Cluster %d:\n", i);

        for (int j = 0; j < clusters[i].size; j++) {
            printf("(%lf, %lf) ", clusters[i].points[j].x, clusters[i].points[j].y);
        }

        printf("\n\n");
    }
}

// Frees memory used by clusters
void freeClusters(Cluster *clusters) {
    for (int i = 0; i < K; i++) {
        free(clusters[i].points);
    }

    free(clusters);
}

int main() {
    // Read data
    int n;
    Point *data = readData(&n);

    // Initialize clusters randomly
    Cluster *clusters = initClusters(data, n);

    // Loop until convergence, or max number of iterations
    int iter = 0, converged = 0;
    while (!converged && iter < MAX_ITER) {
        // Assign data points to nearest cluster
        assignPoints(clusters, data, n);

        // Compute new cluster centers
        updateCenters(clusters);

        // Check for convergence: if cluster centers did not change
        int prev_converged = converged;
        converged = 1;
        for (int i = 0; i < K; i++) {
            if (distance(clusters[i].center, clusters[i].points[0]) != 0) {
                converged = 0;
            }
        }

        // Print data and clusters
        if (!converged || prev_converged) {
            printf("Iteration %d:\n", iter);
            printData(clusters);
        }

        // Reset clusters
        for (int i = 0; i < K; i++) {
            clusters[i].size = 0;
        }

        // Increment iteration counter
        iter++;
    }

    // Free memory
    freeClusters(clusters);
    free(data);

    return 0;
}