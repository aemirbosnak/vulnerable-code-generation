//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Cluster {
    double x;
    double y;
    int size;
};

void k_means_clustering(double *data, int data_size, struct Cluster *clusters, int k) {
    int i, j, closest_cluster;
    double distance, min_distance;
    
    // randomly initialize cluster centers
    for (i = 0; i < k; i++) {
        clusters[i].x = (double)rand() / RAND_MAX;
        clusters[i].y = (double)rand() / RAND_MAX;
        clusters[i].size = 0;
    }
    
    int iterations = 0;
    while (iterations < 100) { // limit number of iterations to prevent infinite loop
        
        // assign data points to closest cluster
        for (i = 0; i < data_size; i++) {
            closest_cluster = 0;
            min_distance = INFINITY;
            for (j = 0; j < k; j++) {
                distance = sqrt(pow(data[i*2]-clusters[j].x, 2) + pow(data[i*2+1]-clusters[j].y, 2));
                if (distance < min_distance) {
                    min_distance = distance;
                    closest_cluster = j;
                }
            }
            clusters[closest_cluster].size++;
        }
        
        // recompute cluster centers
        for (i = 0; i < k; i++) {
            double sum_x = 0, sum_y = 0;
            for (j = 0; j < data_size; j++) {
                if (closest_cluster == i) {
                    sum_x += data[j*2];
                    sum_y += data[j*2+1];
                }
            }
            clusters[i].x = sum_x / clusters[i].size;
            clusters[i].y = sum_y / clusters[i].size;
        }
        
        iterations++;
    }
}

int main() {
    int data_size = 100;
    int k = 4;
    double *data = malloc(sizeof(double) * data_size * 2);
    int i;
    for (i = 0; i < data_size*2; i++) {
        data[i] = (double)rand() / RAND_MAX;
    }
    
    struct Cluster *clusters = malloc(sizeof(struct Cluster) * k);
    
    k_means_clustering(data, data_size, clusters, k);
    
    for (i = 0; i < k; i++) {
        printf("Cluster %d center: (%f, %f), size: %d\n", i, clusters[i].x, clusters[i].y, clusters[i].size);
    }
    
    free(data);
    free(clusters);
    return 0;
}