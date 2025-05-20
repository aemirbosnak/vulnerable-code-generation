//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Curious Clustering Algorithm!\n\n");

    srand(time(NULL)); //seed random number generator

    int n = 10; // number of points
    int k = 3; // number of clusters

    // initialize arrays for x and y coordinates of points
    int *x = malloc(n * sizeof(int));
    int *y = malloc(n * sizeof(int));

    // randomly generate coordinates for points
    for (int i = 0; i < n; i++) {
        x[i] = rand() % 100;
        y[i] = rand() % 100;
    }

    // print out generated points
    printf("Generated Points:\n");
    for (int i = 0; i < n; i++) {
        printf("(%d,%d) ", x[i], y[i]);
    }
    printf("\n\n");

    // initialize arrays for cluster centers and counts
    int *cx = malloc(k * sizeof(int));
    int *cy = malloc(k * sizeof(int));
    int *count = malloc(k * sizeof(int));

    // randomly initialize cluster centers
    for (int i = 0; i < k; i++) {
        cx[i] = rand() % 100;
        cy[i] = rand() % 100;
        count[i] = 0;
    }

    // loop through points and assign them to the closest cluster
    for (int i = 0; i < n; i++) {
        int closest = 0;
        int closest_dist = 10000;

        // calculate distance to each cluster center
        for (int j = 0; j < k; j++) {
            int dist = (x[i]-cx[j])*(x[i]-cx[j]) + (y[i]-cy[j])*(y[i]-cy[j]);
            if (dist < closest_dist) {
                closest = j;
                closest_dist = dist;
            }
        }

        // add point to closest cluster
        cx[closest] = (cx[closest]*count[closest] + x[i]) / (count[closest]+1);
        cy[closest] = (cy[closest]*count[closest] + y[i]) / (count[closest]+1);
        count[closest]++;
    }

    // print out final cluster centers
    printf("Final Cluster Centers:\n");
    for (int i = 0; i < k; i++) {
        printf("(%d,%d) ", cx[i], cy[i]);
    }
    printf("\n");

    free(x);
    free(y);
    free(cx);
    free(cy);
    free(count);

    return 0;
}