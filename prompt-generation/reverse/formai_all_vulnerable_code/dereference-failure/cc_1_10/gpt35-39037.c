//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPSILON 0.0001

typedef struct {
    double x, y;
} Point;

typedef struct {
    int n;
    Point *points;
} Cluster;

// Calculate Euclidean distance between two points
double distance(Point *p1, Point *p2) {
    return sqrt(pow(p2->x - p1->x, 2) + pow(p2->y - p1->y, 2));
}

// Check if cluster has converged
int converged(Cluster *c1, Cluster *c2) {
    int i;
    Point *p1, *p2;
    if (c1->n != c2->n) return 0;

    for (i = 0; i < c1->n; i++) {
        p1 = &(c1->points[i]);
        p2 = &(c2->points[i]);
        if (distance(p1, p2) > EPSILON) {
            return 0;
        }
    }

    return 1;
}

// Perform clustering on a set of points
Cluster* cluster(Point *points, int n, int k) {
    Cluster *clusters = malloc(sizeof(Cluster) * k);
    int i, j, m;
    double d, max_d;
    int max_d_idx, *assigned;
    int iter_count = 0;
    Cluster *old_clusters = malloc(sizeof(Cluster) * k);
    Point *center, *p;

    // Initialize clusters with random points as center
    for (i = 0; i < k; i++) {
        clusters[i].n = 1;
        clusters[i].points = malloc(sizeof(Point));
        clusters[i].points[0] = points[rand() % n];
    }

    // Keep iterating until convergence
    do {
        // Copy clusters to old_clusters
        for (i = 0; i < k; i++) {
            old_clusters[i].n = clusters[i].n;
            old_clusters[i].points = malloc(sizeof(Point) * clusters[i].n);
            for (j = 0; j < clusters[i].n; j++) {
                old_clusters[i].points[j] = clusters[i].points[j];
            }
        }

        // Assign points to clusters
        assigned = calloc(n, sizeof(int));
        for (i = 0; i < n; i++) {
            p = &points[i];
            max_d = -1;
            for (j = 0; j < k; j++) {
                center = &clusters[j].points[0];
                d = distance(p, center);
                if (d > max_d && !assigned[i]) {
                    max_d = d;
                    max_d_idx = j;
                }
            }
            clusters[max_d_idx].n++;
            clusters[max_d_idx].points = realloc(clusters[max_d_idx].points, sizeof(Point) * clusters[max_d_idx].n);
            clusters[max_d_idx].points[clusters[max_d_idx].n-1] = *p;
            assigned[i] = 1;
        }
        free(assigned);

        iter_count++;
    } while (iter_count < 10 || !converged(clusters, old_clusters));

    // Free old_clusters
    for (i = 0; i < k; i++) {
        free(old_clusters[i].points);
    }
    free(old_clusters);

    return clusters;
}

// Main function
int main() {
    int n = 1000, k = 4;
    Point *points = malloc(sizeof(Point) * n);
    int i;
    Cluster *clusters;

    // Generate n random points
    for (i = 0; i < n; i++) {
        points[i].x = (double) rand() / RAND_MAX * 10;
        points[i].y = (double) rand() / RAND_MAX * 10;
    }

    // Perform clustering
    clusters = cluster(points, n, k);

    // Print clusters
    for (i = 0; i < k; i++) {
        printf("Cluster %d:\n", i+1);
        int j;
        for (j = 0; j < clusters[i].n; j++) {
            printf("%lf %lf\n", clusters[i].points[j].x, clusters[i].points[j].y);
        }
    }

    // Free memory
    for (i = 0; i < k; i++) {
        free(clusters[i].points);
    }
    free(clusters);
    free(points);

    return 0;
}