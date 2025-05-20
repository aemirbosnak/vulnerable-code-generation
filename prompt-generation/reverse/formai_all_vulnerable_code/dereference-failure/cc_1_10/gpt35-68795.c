//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double euclidean_distance(double *a, double *b, int dim) {
    double dist = 0;
    for(int i = 0; i < dim; i++) {
        dist += pow((a[i] - b[i]), 2);
    }
    return sqrt(dist);
}

int find_closest_cluster(double *point, double **clusters, int num_clusters, int dim) {
    int closest_cluster = 0;
    double dist = euclidean_distance(point, clusters[0], dim);
    for(int i = 1; i < num_clusters; i++) {
        double temp_dist = euclidean_distance(point, clusters[i], dim);
        if(temp_dist < dist) {
            dist = temp_dist;
            closest_cluster = i;
        }
    }
    return closest_cluster;
}

void update_cluster(double **points, int *cluster_assignments, int num_points, int dim, int cluster_num, double *new_cluster) {
    int count = 0;
    for(int i = 0; i < num_points; i++) {
        if(cluster_assignments[i] == cluster_num) {
            for(int j = 0; j < dim; j++) {
                new_cluster[j] += points[i][j];
            }
            count++;
        }
    }
    if(count != 0) {
        for(int j = 0; j < dim; j++) {
            new_cluster[j] = new_cluster[j] / count;
        }
    }
}

double get_total_distance(double **points, int *cluster_assignments, double **clusters, int num_points, int num_clusters, int dim) {
    double total_distance = 0;
    for(int i = 0; i < num_points; i++) {
        total_distance += euclidean_distance(points[i], clusters[cluster_assignments[i]], dim);
    }
    return total_distance;
}

void k_means(double **points, int num_points, int num_clusters, int dim) {
    double **clusters = calloc(num_clusters, sizeof(double *));
    for(int i = 0; i < num_clusters; i++) {
        clusters[i] = calloc(dim, sizeof(double));
        for(int j = 0; j < dim; j++) {
            clusters[i][j] = points[i][j];
        }
    }
    
    int *cluster_assignments = calloc(num_points, sizeof(int));
    int changed = 1;
    while(changed) {
        changed = 0;
        for(int i = 0; i < num_points; i++) {
            int closest_cluster = find_closest_cluster(points[i], clusters, num_clusters, dim);
            if(cluster_assignments[i] != closest_cluster) {
                changed = 1;
                cluster_assignments[i] = closest_cluster;
            }
        }
        for(int i = 0; i < num_clusters; i++) {
            double *new_cluster = calloc(dim, sizeof(double));
            update_cluster(points, cluster_assignments, num_points, dim, i, new_cluster);
            for(int j = 0; j < dim; j++) {
                clusters[i][j] = new_cluster[j];
            }
            free(new_cluster);
        }
    }
    
    double total_distance = get_total_distance(points, cluster_assignments, clusters, num_points, num_clusters, dim);
    printf("Total distance: %f\n", total_distance);
    
    for(int i = 0; i < num_clusters; i++) {
        printf("Cluster %d:", i);
        for(int j = 0; j < dim; j++) {
            printf(" %f", clusters[i][j]);
        }
        printf("\n");
    }
    
    for(int i = 0; i < num_clusters; i++) {
        free(clusters[i]);
    }
    free(clusters);
    free(cluster_assignments);
}

int main() {
    double **points = calloc(10, sizeof(double *));
    for(int i = 0; i < 10; i++) {
        points[i] = calloc(2, sizeof(double));
        points[i][0] = i * 2.0;
        points[i][1] = i * 3.0;
    }
    k_means(points, 10, 3, 2);
    for(int i = 0; i < 10; i++) {
        free(points[i]);
    }
    free(points);
    return 0;
}