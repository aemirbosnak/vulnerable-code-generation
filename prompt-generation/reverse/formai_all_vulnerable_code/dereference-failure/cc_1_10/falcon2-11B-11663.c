//Falcon2-11B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: immersive
#include <stdio.h>
#include <math.h>

// Function to calculate Euclidean distance
double euclideanDistance(double* point1, double* point2, int dimension) {
    double distance = 0.0;
    for(int i=0; i<dimension; i++) {
        distance += pow((point1[i] - point2[i]), 2);
    }
    return sqrt(distance);
}

// Function to print a cluster
void printCluster(double* cluster, int size) {
    for(int i=0; i<size; i++) {
        printf("%f ", cluster[i]);
    }
    printf("\n");
}

int main() {
    int numberOfPoints = 5;
    int dimension = 3;
    int numberOfClusters = 2;
    double* clusters = (double*) malloc(sizeof(double) * numberOfPoints * dimension * numberOfClusters);
    double* cluster1 = (double*) malloc(sizeof(double) * numberOfPoints * dimension * numberOfClusters);
    double* cluster2 = (double*) malloc(sizeof(double) * numberOfPoints * dimension * numberOfClusters);
    
    // Create points
    double* point1 = (double*) malloc(sizeof(double) * dimension);
    point1[0] = 0.0;
    point1[1] = 0.0;
    point1[2] = 0.0;
    
    double* point2 = (double*) malloc(sizeof(double) * dimension);
    point2[0] = 1.0;
    point2[1] = 1.0;
    point2[2] = 1.0;
    
    double* point3 = (double*) malloc(sizeof(double) * dimension);
    point3[0] = -1.0;
    point3[1] = -1.0;
    point3[2] = -1.0;
    
    double* point4 = (double*) malloc(sizeof(double) * dimension);
    point4[0] = 2.0;
    point4[1] = 2.0;
    point4[2] = 2.0;
    
    double* point5 = (double*) malloc(sizeof(double) * dimension);
    point5[0] = -2.0;
    point5[1] = -2.0;
    point5[2] = -2.0;
    
    // Create clusters
    for(int i=0; i<numberOfPoints; i++) {
        for(int j=0; j<dimension; j++) {
            clusters[i * dimension + j * numberOfClusters] = point1[j];
            clusters[i * dimension + j * numberOfClusters + 1] = point2[j];
            clusters[i * dimension + j * numberOfClusters + 2] = point3[j];
            clusters[i * dimension + j * numberOfClusters + 3] = point4[j];
            clusters[i * dimension + j * numberOfClusters + 4] = point5[j];
        }
    }
    
    // Calculate clusters
    for(int i=0; i<numberOfClusters; i++) {
        cluster1[i * numberOfPoints * dimension] = 0;
        cluster1[i * numberOfPoints * dimension + 1] = 0;
        cluster1[i * numberOfPoints * dimension + 2] = 0;
        cluster1[i * numberOfPoints * dimension + 3] = 0;
        cluster1[i * numberOfPoints * dimension + 4] = 0;
        
        for(int j=0; j<numberOfPoints; j++) {
            for(int k=0; k<dimension; k++) {
                double minDistance = 1000000000.0;
                int minIndex = 0;
                
                for(int l=0; l<numberOfClusters; l++) {
                    double distance = euclideanDistance(cluster1 + l * numberOfPoints * dimension, point1 + j * dimension, dimension);
                    if(distance < minDistance) {
                        minDistance = distance;
                        minIndex = l;
                    }
                }
                
                cluster1[i * numberOfPoints * dimension + j * dimension + k] = minIndex;
            }
        }
    }
    
    // Print clusters
    printf("Cluster 1:\n");
    printCluster(cluster1, numberOfPoints);
    printf("Cluster 2:\n");
    printCluster(cluster2, numberOfPoints);
    
    // Free memory
    free(clusters);
    free(cluster1);
    free(cluster2);
    free(point1);
    free(point2);
    free(point3);
    free(point4);
    free(point5);
    
    return 0;
}