//GPT-4o-mini DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#include <time.h>

#define MAX_POINTS 100
#define MAX_CLUSTERS 5
#define DIMENSIONS 2
#define MAX_ITERATIONS 100
#define THRESHOLD 0.01

typedef struct {
    double points[MAX_POINTS][DIMENSIONS];
    int point_count;
} Dataset;

typedef struct {
    double centroid[DIMENSIONS];
    int points_count;
} Cluster;

typedef struct {
    Dataset dataset;
    Cluster clusters[MAX_CLUSTERS];
    int cluster_count;
    int iterations;
    pthread_mutex_t mutex;
} KMeansData;

void initialize_clusters(KMeansData *data) {
    for (int i = 0; i < data->cluster_count; i++) {
        data->clusters[i].centroid[0] = rand() % 100;
        data->clusters[i].centroid[1] = rand() % 100;
        data->clusters[i].points_count = 0;
    }
}

double euclidean_distance(double *point1, double *point2) {
    return sqrt(pow(point1[0] - point2[0], 2) + pow(point1[1] - point2[1], 2));
}

int assign_to_cluster(KMeansData *data, double *point) {
    int cluster_index = -1;
    double min_distance = INFINITY;
    
    for (int i = 0; i < data->cluster_count; i++) {
        double distance = euclidean_distance(point, data->clusters[i].centroid);
        if (distance < min_distance) {
            min_distance = distance;
            cluster_index = i;
        }
    }
    
    return cluster_index;
}

void *threaded_clustering(void *arg) {
    KMeansData *data = (KMeansData *)arg;

    for (int iteration = 0; iteration < data->iterations; iteration++) {
        // Reset clusters
        for (int i = 0; i < data->cluster_count; i++) {
            data->clusters[i].points_count = 0;
        }

        // Assign points to the closest cluster
        for (int i = 0; i < data->dataset.point_count; i++) {
            int cluster_index = assign_to_cluster(data, data->dataset.points[i]);
            pthread_mutex_lock(&data->mutex);
            data->clusters[cluster_index].points_count++;
            pthread_mutex_unlock(&data->mutex);
        }

        // Calculate new centroids
        for (int i = 0; i < data->cluster_count; i++) {
            double sum[DIMENSIONS] = {0.0, 0.0};
            int count = 0;

            for (int j = 0; j < data->dataset.point_count; j++) {
                if (assign_to_cluster(data, data->dataset.points[j]) == i) {
                    sum[0] += data->dataset.points[j][0];
                    sum[1] += data->dataset.points[j][1];
                    count++;
                }
            }

            if (count > 0) {
                double new_centroid[DIMENSIONS] = {sum[0] / count, sum[1] / count};
                if (euclidean_distance(data->clusters[i].centroid, new_centroid) < THRESHOLD) {
                    continue;
                }
                pthread_mutex_lock(&data->mutex);
                data->clusters[i].centroid[0] = new_centroid[0];
                data->clusters[i].centroid[1] = new_centroid[1];
                pthread_mutex_unlock(&data->mutex);
            }
        }
    }

    return NULL;
}

void generate_random_data(Dataset *dataset, int count) {
    dataset->point_count = count;
    for (int i = 0; i < count; i++) {
        dataset->points[i][0] = rand() % 100;
        dataset->points[i][1] = rand() % 100;
    }
}

int main() {
    srand(time(NULL));

    KMeansData kmeans_data;
    kmeans_data.cluster_count = MAX_CLUSTERS;
    kmeans_data.iterations = MAX_ITERATIONS;
    pthread_mutex_init(&kmeans_data.mutex, NULL);

    generate_random_data(&kmeans_data.dataset, MAX_POINTS);
    initialize_clusters(&kmeans_data);

    pthread_t cluster_thread;
    pthread_create(&cluster_thread, NULL, threaded_clustering, (void *)&kmeans_data);
    pthread_join(cluster_thread, NULL);

    printf("Final cluster centroids:\n");
    for (int i = 0; i < kmeans_data.cluster_count; i++) {
        printf("Cluster %d: Centroid (%.2f, %.2f) with %d points\n", 
                i, 
                kmeans_data.clusters[i].centroid[0], 
                kmeans_data.clusters[i].centroid[1], 
                kmeans_data.clusters[i].points_count);
    }

    pthread_mutex_destroy(&kmeans_data.mutex);
    return 0;
}