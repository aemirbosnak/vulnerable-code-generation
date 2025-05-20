//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: Alan Touring
#include<stdio.h>
#include<math.h>

/**
* Clustering algorithm implementation in C language using Euclidean Distance as a measure
* Author : [Your Name Here]
*/

// Defining the maximum number of data points
#define MAX_SAMPLES 1000

// Function to calculate the Euclidean Distance between two points in n-dimensional space
float euclideanDistance(float *point1, float *point2, int n)
{
    float distance = 0.0;
    for(int i=0; i<n; i++)
    {
        distance += pow((point1[i] - point2[i]), 2);
    }
    return sqrt(distance);
}

// Function to find the nearest neighbors of a point
int* findNearestNeighbors(float **data, float *point, int nSamples, int nFeatures, int nNeighbors)
{
    int* neighbors = (int*) malloc (nNeighbors * sizeof(int));
    float* distances = (float*) malloc (nSamples * sizeof(float));
    float currentDistance;

    // Calculate distance between input point and all other data points
    for(int i=0; i<nSamples; i++)
    {
        currentDistance = euclideanDistance(data[i], point, nFeatures);
        distances[i] = currentDistance;
    }

    // Find the nearest neighbors
    for(int i=0; i<nNeighbors; i++)
    {
        int minIndex = 0;
        for(int j=0; j<nSamples; j++)
        {
            if(distances[j] < distances[minIndex])
            {
                minIndex = j;
            }
        }
        neighbors[i] = minIndex;
        distances[minIndex] = INFINITY;
    }

    free(distances);
    return neighbors;
}

// Function to cluster the data points
int* clusterData(float** data, int nSamples, int nFeatures, int nClusters, int nNeighbors, float threshold)
{
    int* clusterAssignments = (int*) malloc (nSamples * sizeof(int));
    int* clusterCounts = (int*) malloc (nClusters * sizeof(int));
    for(int i=0; i<nSamples; i++)
    {
        clusterAssignments[i] = -1;
    }
    for(int i=0; i<nClusters; i++)
    {
        clusterCounts[i] = 0;
    }

    // Starting with an arbitrary data point as a cluster center
    int currentCluster = 0;
    clusterAssignments[0] = currentCluster;
    clusterCounts[currentCluster]++;
    // Find the nearest neighbors of the current cluster center
    int* nearestIndices = findNearestNeighbors(data, data[0], nSamples, nFeatures, nNeighbors);

    // Until all data points are assigned to a cluster
    while(1)
    {
        float minDistance = threshold;
        int minDistanceIndex = -1;

        // Find the nearest unassigned data point to a cluster center
        for(int i=0; i<nNeighbors; i++)
        {
            int sampleIndex = nearestIndices[i];
            if(clusterAssignments[sampleIndex] == -1){
                float currentDistance = euclideanDistance(data[sampleIndex], data[nearestIndices[0]], nFeatures);
                if(currentDistance < minDistance)
                {
                    minDistance = currentDistance;
                    minDistanceIndex = sampleIndex;
                }
            }
        }

        // If all data points are assigned, exit the loop
        if(minDistanceIndex == -1)
        {
            break;
        }

        // Assign the unassigned data point to a new cluster or existing cluster with minimum distance
        int assignedCluster = -1;
        minDistance = threshold;

        for(int i=0; i<nClusters; i++)
        {
            if(clusterCounts[i] == 0)
            {
                assignedCluster = i;
                break;
            }
            float currentDistance = euclideanDistance(data[minDistanceIndex], data[nearestIndices[0]], nFeatures);
            if((clusterAssignments[nearestIndices[i]] == i) && (currentDistance < minDistance))
            {
                assignedCluster = i;
                minDistance = currentDistance;
            }
        }

        if(assignedCluster == -1)
        {
            assignedCluster = ++currentCluster;
        }

        clusterAssignments[minDistanceIndex] = assignedCluster;
        clusterCounts[assignedCluster]++;
        nearestIndices = findNearestNeighbors(data, data[minDistanceIndex], nSamples, nFeatures, nNeighbors);
    }

    return clusterAssignments;
}

int main()
{
    // Data initialization
    float data[MAX_SAMPLES][2] = {{0,0},{1,0},{0,1},{1,1},{5,5},{5.2,5.3},{4.9,4.7},{6.1,6.3},{100,100},{101,99},{99,101},{102,98},{98,102},{101.9,99.9}};
    int nSamples = 14;
    int nFeatures = 2;
    int nClusters = 3;
    int nNeighbors = 3;
    float threshold = 1.5;

    // Clustering
    int* clusterAssignments = clusterData((float**) data, nSamples, nFeatures, nClusters, nNeighbors, threshold);

    // Results printing
    printf("Data points clustered as follows:\n");
    for(int i=0; i<nSamples; i++){
        printf("data point [%d] : Cluster %d\n", i, clusterAssignments[i]);
    }

    return 0;
}