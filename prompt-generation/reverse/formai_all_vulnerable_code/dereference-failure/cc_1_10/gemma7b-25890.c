//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the distance function
double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// Define the clustering function
void clustering(int **arr, int n, int k) {
    // Calculate the centroid of each cluster
    for (int i = 0; i < k; i++) {
        double sumx = 0.0;
        double sumy = 0.0;
        for (int j = 0; j < n; j++) {
            if (arr[j][i] == 1) {
                sumx += arr[j][0];
                sumy += arr[j][1];
            }
        }
        arr[i][2] = sumx / arr[i][0];
        arr[i][3] = sumy / arr[i][0];
    }

    // Assign each data point to the nearest centroid
    for (int i = 0; i < n; i++) {
        double mindist = distance(arr[i][0], arr[i][1], arr[0][2], arr[0][3]);
        for (int j = 1; j < k; j++) {
            double dist = distance(arr[i][0], arr[i][1], arr[j][2], arr[j][3]);
            if (dist < mindist) {
                mindist = dist;
                arr[i][4] = j;
            }
        }
    }
}

int main() {
    int n = 5;
    int k = 3;
    int **arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        arr[i] = (int *)malloc(k * sizeof(int));
    }

    // Populate the array
    arr[0][0] = 10;
    arr[0][1] = 20;
    arr[1][0] = 15;
    arr[1][1] = 30;
    arr[2][0] = 25;
    arr[2][1] = 40;
    arr[3][0] = 35;
    arr[3][1] = 50;
    arr[4][0] = 45;
    arr[4][1] = 60;

    clustering(arr, n, k);

    // Print the results
    for (int i = 0; i < n; i++) {
        printf("Data point %d belongs to cluster %d\n", arr[i][0], arr[i][4]);
    }

    return 0;
}