//FormAI DATASET v1.0 Category: Data mining ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

// Define a struct for a data point
typedef struct datapoint {
    float x;
    float y;
    char label[10];
} DataPoint;

// Function to generate random data points
DataPoint* generateData(int numPoints) {
    DataPoint* data = (DataPoint*)malloc(sizeof(DataPoint)*numPoints);
    srand(time(NULL));
    for(int i=0; i<numPoints; i++) {
        float x = (float)(rand()%100);
        float y = (float)(rand()%100);
        strcpy(data[i].label, (x+y>100) ? "positive" : "negative");
        data[i].x = x;
        data[i].y = y;
    }
    return data;
}

// Function to print the data
void printData(DataPoint* data, int numPoints) {
    for(int i=0; i<numPoints; i++) {
        printf("[%f,%f,%s]\n", data[i].x, data[i].y, data[i].label);
    }
}

// Function to perform k-means clustering on the data
void kmeans(DataPoint* data, int numPoints, int k) {
    int* centroids = (int*)malloc(sizeof(int)*k);
    for(int i=0; i<k; i++) {
        centroids[i] = rand()%numPoints; // randomly initialize the centroids
    }

    // iterate until convergence
    int numIterations = 0;
    while(numIterations < 10) {
        float* clusterSumsX = (float*)calloc(k, sizeof(float));
        float* clusterSumsY = (float*)calloc(k, sizeof(float));
        int* clusterSizes = (int*)calloc(k, sizeof(int));

        // assign each point to the closest centroid
        for(int i=0; i<numPoints; i++) {
            int closestCentroid = 0;
            float closestDist = INFINITY;
            for(int j=0; j<k; j++) {
                float dist = sqrt((data[i].x-data[centroids[j]].x)*(data[i].x-data[centroids[j]].x) + (data[i].y-data[centroids[j]].y)*(data[i].y-data[centroids[j]].y));
                if(dist < closestDist) {
                    closestCentroid = j;
                    closestDist = dist;
                }
            }
            strcpy(data[i].label, (closestCentroid%2==0) ? "even" : "odd");
            clusterSumsX[closestCentroid] += data[i].x;
            clusterSumsY[closestCentroid] += data[i].y;
            clusterSizes[closestCentroid]++;
        }

        // update the centroids
        for(int j=0; j<k; j++) {
            if(clusterSizes[j] > 0) {
                centroids[j] = -1;
                float minDist = INFINITY;
                for(int i=0; i<numPoints; i++) {
                    float dist = sqrt((data[i].x-clusterSumsX[j]/clusterSizes[j])*(data[i].x-clusterSumsX[j]/clusterSizes[j]) + (data[i].y-clusterSumsY[j]/clusterSizes[j])*(data[i].y-clusterSumsY[j]/clusterSizes[j]));
                    if(dist < minDist) {
                        centroids[j] = i;
                        minDist = dist;
                    }
                }
            }
        }

        numIterations++;
    }

    free(centroids);
}

int main() {
    int numPoints = 100;
    int k = 4;
    DataPoint* data = generateData(numPoints);

    printf("Initial data:\n");
    printData(data, numPoints);

    kmeans(data, numPoints, k);

    printf("After clustering:\n");
    printData(data, numPoints);

    free(data);

    return 0;
}