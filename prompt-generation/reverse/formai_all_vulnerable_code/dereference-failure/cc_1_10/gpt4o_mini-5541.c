//GPT-4o-mini DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_POINTS 100
#define MAX_CLUSTERS 10
#define DIMENSIONS 3
#define MAX_ITER 100

typedef struct {
    double coordinates[DIMENSIONS];
} Point;

typedef struct {
    Point centroid;
    Point points[MAX_POINTS];
    int point_count;
} Cluster;

double distance(Point a, Point b) {
    double dist = 0.0;
    for(int i = 0; i < DIMENSIONS; i++) {
        dist += pow(a.coordinates[i] - b.coordinates[i], 2);
    }
    return sqrt(dist);
}

void initialize_points(Point *points, int n) {
    srand(time(NULL));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < DIMENSIONS; j++) {
            points[i].coordinates[j] = (double)(rand() % 100) + (double)(rand()) / (double)(RAND_MAX);
        }
    }
}

void initialize_clusters(Cluster *clusters, Point *points, int k, int n) {
    for(int i = 0; i < k; i++) {
        clusters[i].centroid = points[rand() % n];
        clusters[i].point_count = 0;
    }
}

void assign_points_to_clusters(Point *points, Cluster *clusters, int n, int k) {
    for(int i = 0; i < k; i++) {
        clusters[i].point_count = 0;
    }

    for(int i = 0; i < n; i++) {
        double min_dist = -1;
        int assigned_cluster = -1;

        for(int j = 0; j < k; j++) {
            double dist = distance(points[i], clusters[j].centroid);
            if (min_dist < 0 || dist < min_dist) {
                min_dist = dist;
                assigned_cluster = j;
            }
        }
        clusters[assigned_cluster].points[clusters[assigned_cluster].point_count++] = points[i];
    }
}

void update_centroids(Cluster *clusters, int k) {
    for(int i = 0; i < k; i++) {
        if(clusters[i].point_count == 0) continue;
        for(int j = 0; j < DIMENSIONS; j++) {
            double sum = 0.0;
            for(int p = 0; p < clusters[i].point_count; p++) {
                sum += clusters[i].points[p].coordinates[j];
            }
            clusters[i].centroid.coordinates[j] = sum / clusters[i].point_count;
        }
    }
}

int main() {
    Point points[MAX_POINTS];
    Cluster clusters[MAX_CLUSTERS];
    int n, k, iter;

    printf("=== Quantum Cluster Master (QCM) ===\n");
    printf("Enter number of data points (max %d): ", MAX_POINTS);
    scanf("%d", &n);
    if(n > MAX_POINTS) {
        printf("Exceeded maximum points limit. Setting to %d.\n", MAX_POINTS);
        n = MAX_POINTS;
    }

    initialize_points(points, n);

    printf("Enter number of clusters (max %d): ", MAX_CLUSTERS);
    scanf("%d", &k);
    if(k > MAX_CLUSTERS) {
        printf("Exceeded maximum clusters limit. Setting to %d.\n", MAX_CLUSTERS);
        k = MAX_CLUSTERS;
    }

    initialize_clusters(clusters, points, k, n);
    
    for(iter = 0; iter < MAX_ITER; iter++) {
        assign_points_to_clusters(points, clusters, n, k);
        update_centroids(clusters, k);

        printf("\nIteration %d:\n", iter + 1);
        for(int i = 0; i < k; i++) {
            printf("Cluster %d - Centroid: (", i + 1);
            for(int j = 0; j < DIMENSIONS; j++) {
                printf("%f%s", clusters[i].centroid.coordinates[j], (j < DIMENSIONS - 1) ? ", " : "");
            }
            printf(") | Points: %d\n", clusters[i].point_count);
        }
    }

    printf("\n=== Final Clusters ===\n");
    for(int i = 0; i < k; i++) {
        printf("Cluster %d - Centroid: (", i + 1);
        for(int j = 0; j < DIMENSIONS; j++) {
            printf("%f%s", clusters[i].centroid.coordinates[j], (j < DIMENSIONS - 1) ? ", " : "");
        }
        printf(") | Points: %d\n", clusters[i].point_count);
    }

    printf("=== QCM execution completed successfully ===\n");
    return 0;
}