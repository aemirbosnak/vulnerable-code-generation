//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct point{
    double x;
    double y;
    int cluster;
};

void kmeans_clustering(struct point* data, int n, int k){
    
    int i, j, min_i;
    double min_dist, sum;
    struct point* centroids = (struct point*) malloc(k * sizeof(struct point));

    centroids[0] = data[0]; // Select first point as initial centroid
    for(i = 1; i < k; i++){
        sum = 0;
        for(j = 0; j < n; j++){
            double dist = sqrt(pow(data[j].x - centroids[i-1].x, 2) + pow(data[j].y - centroids[i-1].y, 2));
            if(dist > sum){
                sum = dist;
                centroids[i] = data[j];
            }
        }
    }

    int max_iter = 100;
    while(max_iter--){
        for(i = 0; i < n; i++){
            min_dist = INFINITY;
            for(j = 0; j < k; j++){
                double dist = sqrt(pow(data[i].x - centroids[j].x, 2) + pow(data[i].y - centroids[j].y, 2));
                if(dist < min_dist){
                    min_dist = dist;
                    min_i = j;
                }
            }
            data[i].cluster = min_i;
        }

        // Update centroids
        for(i = 0; i < k; i++){
            double sum_x = 0;
            double sum_y = 0;
            int cnt = 0;
            for(j = 0; j < n; j++){
                if(data[j].cluster == i){
                    sum_x += data[j].x;
                    sum_y += data[j].y;
                    cnt++;
                }
            }
            centroids[i].x = cnt > 0 ? sum_x / cnt : 0;
            centroids[i].y = cnt > 0 ? sum_y / cnt : 0;
        }
    }
    
    // Print results
    printf("%d clusters:\n", k);
    for(i = 0; i < k; i++){
        printf("Cluster %d with centroid (%.2f, %.2f):\n", i, centroids[i].x, centroids[i].y);
        for(j = 0; j < n; j++){
            if(data[j].cluster == i){
                printf("(%f, %f)\n", data[j].x, data[j].y);
            }
        }
    }

    // Free memory
    free(centroids);
}

int main(){
    struct point data[] = {{2, 3},
                           {4, 5},
                           {7, 8},
                           {8, 7},
                           {9, 10},
                           {10, 8},
                           {12, 13},
                           {14, 15},
                           {15, 12},
                           {17, 14}};

    kmeans_clustering(data, 10, 3);

    return 0;
}