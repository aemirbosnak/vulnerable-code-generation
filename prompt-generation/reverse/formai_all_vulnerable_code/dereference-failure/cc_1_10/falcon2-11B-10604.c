//Falcon2-11B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int data;
    float distance;
} Cluster;

void kmeans(int num_data, int k, float *data, int *clusters) {
    // initialize clusters
    for (int i = 0; i < k; i++) {
        clusters[i] = 0;
    }
    
    // randomly select k initial centers
    for (int i = 0; i < k; i++) {
        int rand_index = rand() % num_data;
        clusters[i] = rand_index;
        float sum_distance = 0;
        for (int j = 0; j < num_data; j++) {
            sum_distance += sqrt(pow(data[j] - data[rand_index], 2));
        }
        clusters[i] = (sum_distance / num_data);
    }
    
    // assign each data point to the nearest center
    for (int i = 0; i < num_data; i++) {
        float min_distance = 1000;
        int min_index = 0;
        for (int j = 0; j < k; j++) {
            float distance = sqrt(pow(data[i] - data[clusters[j]], 2));
            if (distance < min_distance) {
                min_distance = distance;
                min_index = j;
            }
        }
        clusters[min_index]++;
    }
}

int main() {
    // define data and clusters
    int num_data = 100;
    int k = 3;
    float *data = (float*)malloc(num_data * sizeof(float));
    int *clusters = (int*)malloc(k * sizeof(int));
    
    // generate random data
    for (int i = 0; i < num_data; i++) {
        data[i] = (float)rand() / (float)(RAND_MAX);
    }
    
    // run k-means algorithm
    kmeans(num_data, k, data, clusters);
    
    // print results
    printf("Clusters: ");
    for (int i = 0; i < k; i++) {
        printf("%d, ", clusters[i]);
    }
    printf("\n");
    
    for (int i = 0; i < num_data; i++) {
        printf("%f, ", data[i]);
    }
    printf("\n");
    
    return 0;
}