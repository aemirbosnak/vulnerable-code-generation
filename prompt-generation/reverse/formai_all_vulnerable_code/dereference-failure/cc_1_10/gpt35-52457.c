//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Define the structure of a single point */
typedef struct point {
    double x;
    double y;
} Point;

/* Function to calculate distance between two points */
double distance(Point A, Point B) {
    double dx = A.x - B.x;
    double dy = A.y - B.y;
    return sqrt(dx*dx + dy*dy);
}

/* Function to calculate the centroid of a cluster */
Point centroid(Point* points, int size) {
    Point sum = {.x = 0, .y = 0};
    for(int i = 0; i < size; i++) {
        sum.x += points[i].x;
        sum.y += points[i].y;
    }
    Point c = {.x = sum.x/size, .y = sum.y/size};
    return c;
}

/* Function to print out a list of clusters */
void print_clusters(Point** clusters, int* sizes, int num_clusters) {
    printf("\n\n");
    for(int i = 0; i < num_clusters; i++) {
        printf("Cluster %d:\n", i+1);
        for(int j = 0; j < sizes[i]; j++) {
            Point p = clusters[i][j];
            printf("\t(%lf, %lf)\n", p.x, p.y);
        }
    }
    printf("\n\n");
}

int main() {

    /* Generate some random points */
    Point points[] = {{.x = 2.0, .y = 3.0},
                      {.x = 4.0, .y = 5.0},
                      {.x = 7.0, .y = 9.0},
                      {.x = 3.0, .y = 6.0},
                      {.x = 5.0, .y = 3.0},
                      {.x = 6.0, .y = 8.0},
                      {.x = 2.0, .y = 1.0},
                      {.x = 9.0, .y = 10.0},
                      {.x = 10.0, .y = 3.0},
                      {.x = 1.0, .y = 2.0}};

    /* Define some initial variables for K-Means Clustering */
    int k = 3;
    int num_points = sizeof(points)/sizeof(Point);
    Point** clusters = (Point**)calloc(k, sizeof(Point*));
    for(int i = 0; i < k; i++) {
        clusters[i] = (Point*)calloc(num_points/k, sizeof(Point));
    }
    int* sizes = (int*)calloc(k, sizeof(int));
    Point* centers = (Point*)calloc(k, sizeof(Point));
    int iterations = 10;

    /* Pick initial centers by randomly selecting points */
    for(int i = 0; i < k; i++) {
        int j = rand() % num_points;
        centers[i] = points[j];
    }

    /* Run the K-Means algorithm */
    for(int iter = 0; iter < iterations; iter++) {
        /* Assign each point to its closest cluster center */
        for(int i = 0; i < num_points; i++) {
            double min_dist = INFINITY;
            int best_cluster = 0;
            for(int j = 0; j < k; j++) {
                double d = distance(points[i], centers[j]);
                if(d < min_dist) {
                    min_dist = d;
                    best_cluster = j;
                }
            }
            sizes[best_cluster]++;
            clusters[best_cluster][sizes[best_cluster]-1] = points[i];
        }

        /* Calculate the centroids of each cluster */
        for(int i = 0; i < k; i++) {
            centers[i] = centroid(clusters[i], sizes[i]);
        }

        /* Reset the clusters */
        for(int i = 0; i < k; i++) {
            sizes[i] = 0;
        }
    }

    /* Print out the final clusters */
    print_clusters(clusters, sizes, k);

    /* Free the memory */
    for(int i = 0; i < k; i++) {
        free(clusters[i]);
    }
    free(clusters);
    free(sizes);
    free(centers);

    return 0;
}