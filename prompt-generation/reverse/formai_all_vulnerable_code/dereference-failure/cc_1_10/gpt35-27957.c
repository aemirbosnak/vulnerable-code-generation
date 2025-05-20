//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: future-proof
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point centroid;
    Point *points;
    int size;
} Cluster;

int get_closest_cluster(Point point, Cluster *clusters, int num_clusters) {
    int closest_cluster = -1;
    double min_distance = INFINITY;
    for(int i=0; i<num_clusters; i++) {
        double distance = sqrt(pow(point.x - clusters[i].centroid.x, 2) + pow(point.y - clusters[i].centroid.y, 2));
        if(distance < min_distance) {
            min_distance = distance;
            closest_cluster = i;
        }
    }
    return closest_cluster;
}

void update_centroids(Cluster *clusters, int num_clusters) {
    for(int i=0; i<num_clusters; i++) {
        double avg_x = 0;
        double avg_y = 0;
        for(int j=0; j<clusters[i].size; j++) {
            avg_x += clusters[i].points[j].x;
            avg_y += clusters[i].points[j].y;
        }
        clusters[i].centroid.x = avg_x / clusters[i].size;
        clusters[i].centroid.y = avg_y / clusters[i].size;
    }
}

int main() {
    int num_points = 100;
    Point *points = malloc(num_points * sizeof(Point));
    for(int i=0; i<num_points; i++) {
        points[i].x = rand() % 100;
        points[i].y = rand() % 100;
    }
    int num_clusters = 5;
    Cluster *clusters = malloc(num_clusters * sizeof(Cluster));
    for(int i=0; i<num_clusters; i++) {
        clusters[i].centroid.x = rand() % 100;
        clusters[i].centroid.y = rand() % 100;
        clusters[i].points = malloc(num_points * sizeof(Point));
        clusters[i].size = 0;
    }

    int max_iterations = 100;
    for(int i=0; i<max_iterations; i++) {
        // assign points to clusters
        for(int j=0; j<num_points; j++) {
            int closest_cluster = get_closest_cluster(points[j], clusters, num_clusters);
            clusters[closest_cluster].points[clusters[closest_cluster].size++] = points[j];
        }
        // update centroids
        update_centroids(clusters, num_clusters);
        // print cluster information
        printf("Iteration %d:\n", i+1);
        for(int j=0; j<num_clusters; j++) {
            printf("Cluster %d:\n", j+1);
            printf("Centroid: (%.2lf, %.2lf)\n", clusters[j].centroid.x, clusters[j].centroid.y);
            printf("Points: ");
            for(int k=0; k<clusters[j].size; k++) {
                printf("(%.2lf, %.2lf) ", clusters[j].points[k].x, clusters[j].points[k].y);
            }
            printf("\n\n");
            // reset cluster points for next iteration
            clusters[j].size = 0;
        }
    }

    // free memory
    for(int i=0; i<num_clusters; i++) {
        free(clusters[i].points);
    }
    free(clusters);
    free(points);

    return 0;
}