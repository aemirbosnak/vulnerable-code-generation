//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 100
#define K 3
#define E 0.000001

void initiate_points(float points[][2], int n); 
float dist(float x1, float y1, float x2, float y2); 
int find_closest_cluster(float x, float y, float clusters[][3], int k); 
void update_clusters(float points[][2], int n, float clusters[][3], int k); 

int main() {
    float points[N][2];
    float clusters[K][3];
    int n, i, j, k, iterations;
    
    printf("Enter the number of points (max %d): ", N);
    scanf("%d", &n);
    
    initiate_points(points, n);
    
    printf("Initial Points Coordinates:\n");
    for(i = 0; i < n; i++)
        printf("(%f, %f)\n", points[i][0], points[i][1]);
    
    //randomly initialize cluster centroids
    for(i = 0; i < K; i++) {
        clusters[i][0] = points[rand() % n][0];
        clusters[i][1] = points[rand() % n][1];
        clusters[i][2] = i;
    }
    
    printf("\nInitial Cluster Centroids:\n");
    for(i = 0; i < K; i++)
        printf("Centroid %d: (%f, %f)\n", (int) clusters[i][2], clusters[i][0], clusters[i][1]);
    
    iterations = 0;
    do {
        update_clusters(points, n, clusters, K);
        
        iterations++;
        if(iterations > 100) {
            printf("Max iterations reached! Exiting...\n");
            return 0;
        }
    } while(clusters[K-1][2] - clusters[0][2] > E);
    
    printf("\nFinal Cluster Centroids:\n");
    for(i = 0; i < K; i++)
        printf("Centroid %d: (%f, %f)\n", (int) clusters[i][2], clusters[i][0], clusters[i][1]);
    
    return 0;
}

void initiate_points(float points[][2], int n) {
    int i;
    for(i = 0; i < n; i++) {
        points[i][0] = (float) rand() / (float) RAND_MAX;
        points[i][1] = (float) rand() / (float) RAND_MAX;
    }
}

float dist(float x1, float y1, float x2, float y2) {
    return sqrt(pow((x2-x1),2) + pow((y2-y1),2));
}

int find_closest_cluster(float x, float y, float clusters[][3], int k) {
    int i;
    int min_index = 0;
    float min_distance, distance;
    
    min_distance = dist(x, y, clusters[0][0], clusters[0][1]);
    for(i = 1; i < k; i++) {
        distance = dist(x, y, clusters[i][0], clusters[i][1]);
        if(distance < min_distance) {
            min_distance = distance;
            min_index = i;
        }
    }
    
    return min_index;
}

void update_clusters(float points[][2], int n, float clusters[][3], int k) {
    int i, j, closest_cluster;
    float sum_x, sum_y, num_points;
    
    //initialize clusters' counters
    for(i = 0; i < k; i++) {
        clusters[i][0] = 0;
        clusters[i][1] = 0;
        clusters[i][2] = 0;
    }
    
    //assign points to clusters
    for(i = 0; i < n; i++) {
        closest_cluster = find_closest_cluster(points[i][0], points[i][1], clusters, k);
        clusters[closest_cluster][0] += points[i][0];
        clusters[closest_cluster][1] += points[i][1];
        clusters[closest_cluster][2] += 1;
    }
    
    //update clusters' centroids
    for(i = 0; i < k; i++) {
        if(clusters[i][2] > 0) {
            clusters[i][0] = clusters[i][0] / clusters[i][2];
            clusters[i][1] = clusters[i][1] / clusters[i][2];
        }
    }
    
    //sort clusters by index and recalculate clusters' counters
    for(i = 0; i < k; i++) {
        for(j = i+1; j < k; j++) {
            if(clusters[j][2] < clusters[i][2]) {
                float temp_x = clusters[j][0];
                float temp_y = clusters[j][1];
                int temp_cnt = clusters[j][2];
                clusters[j][0] = clusters[i][0];
                clusters[j][1] = clusters[i][1];
                clusters[j][2] = clusters[i][2];
                clusters[i][0] = temp_x;
                clusters[i][1] = temp_y;
                clusters[i][2] = temp_cnt;
            }
        }
    }
}