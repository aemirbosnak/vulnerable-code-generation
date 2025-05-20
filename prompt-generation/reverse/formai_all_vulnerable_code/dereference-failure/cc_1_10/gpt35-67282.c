//FormAI DATASET v1.0 Category: Data mining ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Function to calculate Euclidean distance between two data points
float euclidean_distance(float *datapoint1, float *datapoint2, int n_features){
    float distance = 0;
    for(int i=0; i<n_features; i++){
        distance += pow(datapoint1[i] - datapoint2[i], 2);
    }
    return sqrt(distance);
}

// Function to find K nearest neighbours of a given datapoint
void knn(float **datapoints, float *datapoint, int n_datapoints, int n_features, int k){
    float distances[n_datapoints];
    int indices[n_datapoints];
    for(int i=0; i<n_datapoints; i++){
        distances[i] = euclidean_distance(datapoints[i], datapoint, n_features);
        indices[i] = i;
    }
    for(int i=0; i<k; i++){
        for(int j=i+1; j<n_datapoints; j++){
            if(distances[j] < distances[i]){
                float distance = distances[i];
                distances[i] = distances[j];
                distances[j] = distance;
                int index = indices[i];
                indices[i] = indices[j];
                indices[j] = index;
            }
        }
    }
    printf("K Nearest Neighbours: ");
    for(int i=0; i<k; i++){
        printf("%d ", indices[i]);
    }
    printf("\n");
}

int main(){
    // Sample datapoints
    float datapoints[7][3] = {{2, 3, 0},
                              {2, 7, 0},
                              {5, 5, 0},
                              {8, 4, 0},
                              {9, 1, 0},
                              {4, 4, 0},
                              {6, 2, 0}};
    int n_datapoints = 7;
    int n_features = 2;
    int k = 3;
    float datapoint[2] = {3, 5};
    // Converting 2D array to 1D array of pointers for easy passing of datapoints to functions
    float **datapointers = malloc(n_datapoints * sizeof(float*));
    for(int i=0; i<n_datapoints; i++){
        datapointers[i] = datapoints[i];
    }
    // Finding K nearest neighbours of the given datapoint
    knn(datapointers, datapoint, n_datapoints, n_features, k);
    free(datapointers);
    return 0;
}