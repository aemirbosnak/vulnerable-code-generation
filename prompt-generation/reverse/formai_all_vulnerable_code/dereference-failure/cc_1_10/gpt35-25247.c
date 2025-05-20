//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float euclidean_distance(float *x, float *y, int feature_size) {
    float distance = 0.0;
    for(int i = 0; i < feature_size; i++) {
        distance += pow((x[i] - y[i]), 2);
    }
    return sqrt(distance);
}

void k_means_clustering(float **data_points, int *cluster_ids, int num_data_points, int feature_size, int num_clusters, int max_iterations) {

    float **centroids = (float **)malloc(num_clusters * sizeof(float *));
    for(int i = 0; i < num_clusters; i++) {
        centroids[i] = (float *)malloc(feature_size * sizeof(float));
        for(int j = 0; j < feature_size; j++) {
            centroids[i][j] = data_points[rand() % num_data_points][j];
        }
    }

    int *num_points_cluster = (int *)calloc(num_clusters, sizeof(int));
    int *updated_cluster_ids = (int *)calloc(num_data_points, sizeof(int));

    int iteration = 0;
    int is_changed = 1;

    while(iteration < max_iterations && is_changed) {

        is_changed = 0;

        for(int i = 0; i < num_data_points; i++) {

            float min_distance = euclidean_distance(data_points[i], centroids[0], feature_size);
            int min_index = 0;

            for(int j = 1; j < num_clusters; j++) {
                float distance = euclidean_distance(data_points[i], centroids[j], feature_size);
                if(distance < min_distance) {
                    min_distance = distance;
                    min_index = j;
                }
            }

            if(cluster_ids[i] != min_index) {
                cluster_ids[i] = min_index;
                is_changed = 1;
            }

            num_points_cluster[min_index]++;
            for(int j = 0; j < feature_size; j++) {
                centroids[min_index][j] += (data_points[i][j] - centroids[min_index][j]) / num_points_cluster[min_index];
            }
        }

        iteration++;

    }

    for(int i = 0; i < num_data_points; i++) {
        updated_cluster_ids[i] = cluster_ids[i];
    }

    for(int i = 0; i < num_clusters; i++) {
        for(int j = 0; j < feature_size; j++) {
            centroids[i][j] = 0;
        }
    }

    for(int i = 0; i < num_data_points; i++) {
        int cluster_id = updated_cluster_ids[i];
        num_points_cluster[cluster_id]++;
        for(int j = 0; j < feature_size; j++) {
            centroids[cluster_id][j] += data_points[i][j] / num_points_cluster[cluster_id];
        }
    }

    for(int i = 0; i < num_data_points; i++) {
        cluster_ids[i] = updated_cluster_ids[i];
    }

    for(int i = 0; i < num_clusters; i++) {
        free(centroids[i]);
    }
    free(centroids);
    free(num_points_cluster);
    free(updated_cluster_ids);

}

int main() {

    int num_data_points = 100;
    int feature_size = 2;
    int num_clusters = 3;
    int max_iterations = 100;

    float **data_points = (float **)malloc(num_data_points * sizeof(float *));
    for(int i = 0; i < num_data_points; i++) {
        data_points[i] = (float *)malloc(feature_size * sizeof(float));
        data_points[i][0] = ((float)(rand() % 1000)) / 1000;
        data_points[i][1] = ((float)(rand() % 1000)) / 1000;
    }

    int *cluster_ids = (int *)malloc(num_data_points * sizeof(int));

    k_means_clustering(data_points, cluster_ids, num_data_points, feature_size, num_clusters, max_iterations);

    for(int i = 0; i < num_data_points; i++) {
        printf("%.2f,%.2f,%d\n", data_points[i][0], data_points[i][1], cluster_ids[i]);
    }

    for(int i = 0; i < num_data_points; i++) {
        free(data_points[i]);
    }
    free(data_points);
    free(cluster_ids);

    return 0;

}