//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct {
    int x;
    int y;
} Point;


typedef struct {
    Point *points;
    int num_points;
} Cluster;


Cluster* create_cluster(int num_points) {
    Cluster *cluster = malloc(sizeof(Cluster));
    cluster->points = malloc(sizeof(Point) * num_points);
    cluster->num_points = num_points;
    return cluster;
}


void free_cluster(Cluster *cluster) {
    free(cluster->points);
    free(cluster);
}


void add_point_to_cluster(Cluster *cluster, Point point) {
    cluster->points[cluster->num_points++] = point;
}


double distance_between_points(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}


Cluster* find_closest_cluster(Cluster *clusters, int num_clusters, Point point) {
    double min_distance = INFINITY;
    Cluster *closest_cluster = NULL;

    for (int i = 0; i < num_clusters; i++) {
        double distance = distance_between_points(point, clusters[i].points[0]);
        if (distance < min_distance) {
            min_distance = distance;
            closest_cluster = &clusters[i];
        }
    }

    return closest_cluster;
}


void cluster_points(Cluster *clusters, int num_clusters, Point *points, int num_points) {
    for (int i = 0; i < num_points; i++) {
        Cluster *closest_cluster = find_closest_cluster(clusters, num_clusters, points[i]);
        add_point_to_cluster(closest_cluster, points[i]);
    }
}


void print_clusters(Cluster *clusters, int num_clusters) {
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d:\n", i + 1);
        for (int j = 0; j < clusters[i].num_points; j++) {
            printf("(%d, %d)\n", clusters[i].points[j].x, clusters[i].points[j].y);
        }
        printf("\n");
    }
}


int main() {
    int num_points, num_clusters;
    printf("Enter the number of points: ");
    scanf("%d", &num_points);

    Point *points = malloc(sizeof(Point) * num_points);
    for (int i = 0; i < num_points; i++) {
        printf("Enter the coordinates of point %d: ", i + 1);
        scanf("%d %d", &points[i].x, &points[i].y);
    }

    printf("Enter the number of clusters: ");
    scanf("%d", &num_clusters);

    Cluster *clusters = create_cluster(num_clusters);
    cluster_points(clusters, num_clusters, points, num_points);

    print_clusters(clusters, num_clusters);

    free(points);
    free_cluster(clusters);

    return 0;
}