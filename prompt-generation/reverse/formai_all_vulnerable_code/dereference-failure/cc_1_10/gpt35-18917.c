//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("What? A clustering algorithm implementation? In C??\n");
    printf("I'm totally shocked.\n\n");

    float *points = malloc(sizeof(float) * 100);
    // Just randomly allocating some memory for the points. Because why not?

    printf("Let's generate some random points...\n");
    for(int i=0; i<100; i++) {
        points[i] = ((float) rand() / RAND_MAX) * 10;
        printf("%.2f ", points[i]);
    }
    printf("\n\n");

    printf("Wow, these points are really unique and definitely not clustered.\n");
    printf("But let's cluster them anyway because, you know, programming!\n\n");

    // Algorithm Time!
    int k = 3; // Let's say we want to create 3 clusters
    float *centroids = malloc(sizeof(float) * k);
    for(int i=0; i<k; i++) {
        centroids[i] = ((float) rand() / RAND_MAX) * 10;
    }

    // Now we need to assign each point to a cluster
    int *assigned_cluster = malloc(sizeof(int) * 100);
    for(int i=0; i<100; i++) {
        float point = points[i];
        float closest_centroid = centroids[0];
        int closest_cluster = 0;
        for(int j=0; j<k; j++) {
            float distance = abs(point - centroids[j]);
            if(distance < abs(point - closest_centroid)) {
                closest_centroid = centroids[j];
                closest_cluster = j;
            }
        }
        assigned_cluster[i] = closest_cluster;
    }

    // Now that we have each point assigned to a cluster, let's calculate the new centroids
    for(int i=0; i<k; i++) {
        float sum = 0;
        int count = 0;
        for(int j=0; j<100; j++) {
            if(assigned_cluster[j] == i) {
                sum += points[j];
                count++;
            }
        }
        centroids[i] = sum / count;
    }

    printf("Ta-da! Clustering complete.\n\n");
    printf("Here are the new centroids:\n");
    for(int i=0; i<k; i++) {
        printf("%.2f ", centroids[i]);
    }
    printf("\n\n");

    free(points);
    free(centroids);
    free(assigned_cluster);

    return 0;
}