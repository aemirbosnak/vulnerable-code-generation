//GPT-4o-mini DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100
#define MAX_CLUSTERS 10
#define DIMENSIONS 2
#define MAX_ITERATIONS 100

typedef struct {
    double coordinates[DIMENSIONS];
    int cluster_id;
} Point;

typedef struct {
    double centroid[DIMENSIONS];
    int num_points;
} Cluster;

void initialize_clusters(Cluster clusters[], Point points[], int k, int num_points) {
    for (int i = 0; i < k; i++) {
        clusters[i].centroid[0] = points[rand() % num_points].coordinates[0];
        clusters[i].centroid[1] = points[rand() % num_points].coordinates[1];
        clusters[i].num_points = 0;
    }
}

double euclidean_distance(double a[], double b[]) {
    double sum = 0.0;
    for (int i = 0; i < DIMENSIONS; i++) {
        sum += (a[i] - b[i]) * (a[i] - b[i]);
    }
    return sqrt(sum);
}

void assign_clusters(Point points[], Cluster clusters[], int num_points, int k) {
    for (int i = 0; i < num_points; i++) {
        double min_distance = INFINITY;
        int cluster_id = -1;

        for (int j = 0; j < k; j++) {
            double distance = euclidean_distance(points[i].coordinates, clusters[j].centroid);
            if (distance < min_distance) {
                min_distance = distance;
                cluster_id = j;
            }
        }

        points[i].cluster_id = cluster_id;
        clusters[cluster_id].num_points += 1;
    }
}

void update_centroids(Cluster clusters[], Point points[], int k, int num_points) {
    for (int i = 0; i < k; i++) {
        clusters[i].num_points = 0;
        for (int dim = 0; dim < DIMENSIONS; dim++) {
            clusters[i].centroid[dim] = 0.0;
        }
    }

    for (int i = 0; i < num_points; i++) {
        int cluster_id = points[i].cluster_id;
        clusters[cluster_id].num_points += 1;
        for (int dim = 0; dim < DIMENSIONS; dim++) {
            clusters[cluster_id].centroid[dim] += points[i].coordinates[dim];
        }
    }

    for (int i = 0; i < k; i++) {
        if (clusters[i].num_points > 0) {
            for (int dim = 0; dim < DIMENSIONS; dim++) {
                clusters[i].centroid[dim] /= clusters[i].num_points;
            }
        }
    }
}

int main() {
    Point points[MAX_POINTS];
    Cluster clusters[MAX_CLUSTERS];
    int num_points, k;

    // Read number of points
    printf("Enter number of points (max %d): ", MAX_POINTS);
    scanf("%d", &num_points);
    if(num_points > MAX_POINTS) {
        fprintf(stderr, "Error: Maximum points exceeded.\n");
        return 1;
    }

    // Input points
    for (int i = 0; i < num_points; i++) {
        printf("Enter coordinates for point %d (x y): ", i + 1);
        scanf("%lf %lf", &points[i].coordinates[0], &points[i].coordinates[1]);
    }

    // Read number of clusters
    printf("Enter number of clusters (max %d): ", MAX_CLUSTERS);
    scanf("%d", &k);
    if(k > MAX_CLUSTERS) {
        fprintf(stderr, "Error: Maximum clusters exceeded.\n");
        return 1;
    }

    initialize_clusters(clusters, points, k, num_points);
    
    for (int iteration = 0; iteration < MAX_ITERATIONS; iteration++) {
        for (int i = 0; i < num_points; i++) {
            points[i].cluster_id = -1; // Resetting cluster assignments
        }
        
        assign_clusters(points, clusters, num_points, k);
        update_centroids(clusters, points, k, num_points);
        
        // Output the centroids
        printf("Iteration %d:\n", iteration + 1);
        for (int i = 0; i < k; i++) {
            printf("Cluster %d: Centroid = (%f, %f), Points = %d\n", i, clusters[i].centroid[0], clusters[i].centroid[1], clusters[i].num_points);
        }
    }

    return 0;
}