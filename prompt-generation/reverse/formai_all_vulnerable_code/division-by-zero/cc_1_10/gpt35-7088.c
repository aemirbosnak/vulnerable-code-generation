//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate random points in x-y plane
void generateRandomPoints(int n, float *x, float *y) {
    srand(time(NULL));
    for (int i=0; i<n; i++) {
        x[i] = (float) rand()/RAND_MAX;
        y[i] = (float) rand()/RAND_MAX;
    }
}

// function to calculate distance between two points
float distance(float x1, float y1, float x2, float y2) {
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

int main(int argc, char const *argv[]) {
    int n = atoi(argv[1]);
    float *x = malloc(n*sizeof(float));
    float *y = malloc(n*sizeof(float));

    generateRandomPoints(n, x, y);

    int k = 5;  // number of clusters
    int *assignedCluster = malloc(n*sizeof(int)); // array to keep track of which cluster a point is assigned to

    // initialize cluster centers to random points
    float *clusterX = malloc(k*sizeof(float));
    float *clusterY = malloc(k*sizeof(float));
    int *clusterSize = calloc(k,sizeof(int));
    for (int i=0; i<k; i++) {
        int randomIndex = rand() % n;
        clusterX[i] = x[randomIndex];
        clusterY[i] = y[randomIndex];
    }

    float threshold = 0.1;
    while (1) { // repeat until convergence
        int flag = 1;
        for (int i=0; i<n; i++) {
            float minDist = 1000000; // initialize minimum distance to large value
            int assignedClusterThisPoint = -1; // initialize to invalid value
            for (int j=0; j<k; j++) {
                float distJ = distance(x[i], y[i], clusterX[j], clusterY[j]);
                if (distJ < minDist) {
                    minDist = distJ;
                    assignedClusterThisPoint = j;
                }
            }
            if (assignedClusterThisPoint != assignedCluster[i]) { // if the point's assigned cluster changed
                assignedCluster[i] = assignedClusterThisPoint;
                flag = 0;
            }
            clusterSize[assignedClusterThisPoint]++;
            clusterX[assignedClusterThisPoint] += x[i];
            clusterY[assignedClusterThisPoint] += y[i];
        }
        if (flag) {
            printf("Converged!\n");
            break;
        }
        // update cluster centers to the mean of the points assigned to it
        for (int j=0; j<k; j++) {
            clusterX[j] /= clusterSize[j];
            clusterY[j] /= clusterSize[j];
        }
        // reset clusterSize and clusterX/Y
        memset(clusterSize,0,k*sizeof(int));
        memset(clusterX,0,k*sizeof(float));
        memset(clusterY,0,k*sizeof(float));
    }

    return 0;
}