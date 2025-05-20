//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_ITERATIONS 100   // maximum number of iterations
#define EPSILON 0.00001      // end clustering if change in centroids is less than this value

// struct to represent a data point
typedef struct {
    double x;
    double y;
    int cluster;
} DataPoint;

// struct to represent a centroid
typedef struct {
    double x;
    double y;
} Centroid;

// function to compute Euclidean distance between two points
double distance(double x1, double y1, double x2, double y2) {
    double dx = x1 - x2;
    double dy = y1 - y2;
    return sqrt(dx*dx + dy*dy);
}

// function to choose initial centroids randomly
void choose_initial_centroids(DataPoint *data, int n, Centroid centroids[], int k) {
    int i, j;
    int *chosen = malloc(n*sizeof(int));   // array to keep track of chosen data points
    memset(chosen, 0, n*sizeof(int));      // initialize to zero
    for (i = 0; i < k; i++) {
        while (1) {
            j = rand()%n;   // choose random data point
            if (!chosen[j]) {
                centroids[i].x = data[j].x;
                centroids[i].y = data[j].y;
                chosen[j] = 1;
                break;
            }
        }
    }
    free(chosen);
}

// function to assign data points to clusters based on closest centroid
void assign_clusters(DataPoint *data, int n, Centroid centroids[], int k) {
    int i, j;
    double d, min_d;
    for (i = 0; i < n; i++) {
        min_d = INFINITY;   // initialize minimum distance to infinity
        for (j = 0; j < k; j++) {
            d = distance(data[i].x, data[i].y, centroids[j].x, centroids[j].y);
            if (d < min_d) {
                min_d = d;
                data[i].cluster = j;
            }
        }
    }
}

// function to compute new centroids for each cluster
void compute_centroids(DataPoint *data, int n, Centroid centroids[], int k) {
    int i, j;
    int count;
    double sum_x, sum_y;
    for (j = 0; j < k; j++) {
        count = 0;
        sum_x = 0;
        sum_y = 0;
        for (i = 0; i < n; i++) {
            if (data[i].cluster == j) {
                count++;
                sum_x += data[i].x;
                sum_y += data[i].y;
            }
        }
        if (count > 0) {
            centroids[j].x = sum_x/count;
            centroids[j].y = sum_y/count;
        }
    }
}

// function to print clusters
void print_clusters(DataPoint *data, int n, int k) {
    int i, j;
    for (j = 0; j < k; j++) {
        printf("Cluster %d: ", j);
        for (i = 0; i < n; i++) {
            if (data[i].cluster == j) {
                printf("(%f, %f) ", data[i].x, data[i].y);
            }
        }
        printf("\n");
    }
}

// main function
int main() {
    int n = 10;    // number of data points
    int k = 3;     // number of clusters
    int i, j, iter;
    double d, max_d, delta;
    DataPoint *data = malloc(n*sizeof(DataPoint));
    Centroid *centroids = malloc(k*sizeof(Centroid));
    // initialize data points randomly
    for (i = 0; i < n; i++) {
        data[i].x = (double)rand()/RAND_MAX*10;
        data[i].y = (double)rand()/RAND_MAX*10;
    }
    choose_initial_centroids(data, n, centroids, k);   // choose initial centroids randomly
    for (iter = 0; iter < MAX_ITERATIONS; iter++) {
        assign_clusters(data, n, centroids, k);        // assign data points to clusters based on closest centroid
        compute_centroids(data, n, centroids, k);      // compute new centroids for each cluster
        // check if change in centroids is less than EPSILON
        max_d = 0;
        for (j = 0; j < k; j++) {
            d = distance(data[j].x, data[j].y, centroids[j].x, centroids[j].y);
            if (d > max_d) {
                max_d = d;
            }
        }
        if (max_d < EPSILON) {
            break;
        }
    }
    print_clusters(data, n, k);    // print clusters
    free(data);
    free(centroids);
    return 0;
}