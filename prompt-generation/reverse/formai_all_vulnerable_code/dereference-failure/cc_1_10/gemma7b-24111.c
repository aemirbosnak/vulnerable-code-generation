//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void cluster(int **arr, int n, int **clusters, int *c_num) {

    int i, j, k, d, min_dist, cluster_size = 0, centroid_index = -1;
    float centroid_distance;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i != j) {
                d = abs(arr[i] - arr[j]);
                if (min_dist == -1 || d < min_dist) {
                    min_dist = d;
                    centroid_index = j;
                }
            }
        }
    }

    clusters[*c_num] = centroid_index;
    (*c_num)++;

    for (k = 0; k < n; k++) {
        if (arr[k] == arr[centroid_index]) {
            cluster_size++;
        }
    }

    if (cluster_size > 1) {
        centroid_distance = (float)min_dist / sqrtf(cluster_size);
        printf("Centroid Distance: %.2f\n", centroid_distance);
    }

    if (cluster_size > 1) {
        cluster(arr, cluster_size, clusters, c_num);
    }
}

int main() {
    int n, i, **arr, **clusters, c_num = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));
    clusters = (int *)malloc((n / 2) * sizeof(int));

    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    cluster(arr, n, clusters, &c_num);

    return 0;
}