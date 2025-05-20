//GPT-4o-mini DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITER 100
#define DIMENSIONS 2

typedef struct {
    double *coordinates;
} Point;

typedef struct {
    double *centroid;
    Point *points;
    int point_count;
} Cluster;

double euclidean_distance(double *a, double *b) {
    double sum = 0.0;
    for (int i = 0; i < DIMENSIONS; i++) {
        sum += pow(a[i] - b[i], 2);
    }
    return sqrt(sum);
}

void initialize_clusters(Cluster *clusters, int k) {
    for (int i = 0; i < k; i++) {
        clusters[i].centroid = (double *)malloc(DIMENSIONS * sizeof(double));
        clusters[i].points = NULL;
        clusters[i].point_count = 0;
    }
}

void free_clusters(Cluster *clusters, int k) {
    for (int i = 0; i < k; i++) {
        free(clusters[i].centroid);
        free(clusters[i].points);
    }
}

void assign_points_to_clusters(Point *points, int point_count, Cluster *clusters, int k) {
    for (int i = 0; i < point_count; i++) {
        int best_cluster = 0;
        double best_distance = euclidean_distance(points[i].coordinates, clusters[0].centroid);
        
        for (int j = 1; j < k; j++) {
            double distance = euclidean_distance(points[i].coordinates, clusters[j].centroid);
            if (distance < best_distance) {
                best_distance = distance;
                best_cluster = j;
            }
        }
        
        clusters[best_cluster].points = realloc(clusters[best_cluster].points, 
                                                (clusters[best_cluster].point_count + 1) * sizeof(Point));
        clusters[best_cluster].points[clusters[best_cluster].point_count].coordinates = points[i].coordinates;
        clusters[best_cluster].point_count++;
    }
}

void update_centroids(Cluster *clusters, int k) {
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < DIMENSIONS; j++) {
            clusters[i].centroid[j] = 0.0;
        }
        
        for (int j = 0; j < clusters[i].point_count; j++) {
            for (int d = 0; d < DIMENSIONS; d++) {
                clusters[i].centroid[d] += clusters[i].points[j].coordinates[d];
            }
        }
        
        for (int d = 0; d < DIMENSIONS; d++) {
            if (clusters[i].point_count > 0) {
                clusters[i].centroid[d] /= clusters[i].point_count;
            }
        }
    }
}

int main() {
    int k, point_count;

    printf("Enter the number of clusters (k): ");
    scanf("%d", &k);

    printf("Enter the number of points: ");
    scanf("%d", &point_count);

    Point *points = (Point *)malloc(point_count * sizeof(Point));
    printf("Enter the points (x y format):\n");
    for (int i = 0; i < point_count; i++) {
        points[i].coordinates = (double *)malloc(DIMENSIONS * sizeof(double));
        for (int j = 0; j < DIMENSIONS; j++) {
            scanf("%lf", &points[i].coordinates[j]);
        }
    }

    Cluster *clusters = (Cluster *)malloc(k * sizeof(Cluster));
    initialize_clusters(clusters, k);

    // Initialize random centroids
    for (int i = 0; i < k; i++) {
        clusters[i].centroid[0] = points[rand() % point_count].coordinates[0];
        clusters[i].centroid[1] = points[rand() % point_count].coordinates[1];
    }

    for (int iter = 0; iter < MAX_ITER; iter++) {
        // Clear previously assigned points
        for (int i = 0; i < k; i++) {
            clusters[i].point_count = 0;
            free(clusters[i].points);
            clusters[i].points = NULL;
        }

        // Assign points to clusters
        assign_points_to_clusters(points, point_count, clusters, k);
        
        // Update centroid of each cluster
        update_centroids(clusters, k);
    }

    printf("\nClustering result:\n");
    for (int i = 0; i < k; i++) {
        printf("Cluster %d:\n", i + 1);
        printf("Centroid: (");
        for (int d = 0; d < DIMENSIONS; d++) {
            printf("%lf", clusters[i].centroid[d]);
            if (d < DIMENSIONS - 1) printf(", ");
        }
        printf(")\nPoints:\n");
        for (int j = 0; j < clusters[i].point_count; j++) {
            printf("  (");
            for (int d = 0; d < DIMENSIONS; d++) {
                printf("%lf", clusters[i].points[j].coordinates[d]);
                if (d < DIMENSIONS - 1) printf(", ");
            }
            printf(")\n");
        }
    }

    // Free allocated memory
    free_clusters(clusters, k);
    free(clusters);
    for (int i = 0; i < point_count; i++) {
        free(points[i].coordinates);
    }
    free(points);

    return 0;
}