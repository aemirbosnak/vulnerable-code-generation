//GEMINI-pro DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
} point;

typedef struct {
    point *points;
    int num_points;
} cluster;

typedef struct {
    cluster *clusters;
    int num_clusters;
} data;

data *generate_data(int num_points, int num_clusters) {
    data *data = malloc(sizeof(data));
    data->clusters = malloc(sizeof(cluster) * num_clusters);
    data->num_clusters = num_clusters;

    for (int i = 0; i < num_clusters; i++) {
        data->clusters[i].points = malloc(sizeof(point) * num_points);
        data->clusters[i].num_points = num_points;

        for (int j = 0; j < num_points; j++) {
            data->clusters[i].points[j].x = rand() % 100;
            data->clusters[i].points[j].y = rand() % 100;
        }
    }

    return data;
}

void free_data(data *data) {
    for (int i = 0; i < data->num_clusters; i++) {
        free(data->clusters[i].points);
    }
    free(data->clusters);
    free(data);
}

int main() {
    srand(time(NULL));

    int num_points = 1000;
    int num_clusters = 10;

    data *data = generate_data(num_points, num_clusters);

    // Calculate the probability of an alien invasion

    double probability = 0.0;

    for (int i = 0; i < data->num_clusters; i++) {
        cluster *cluster = &data->clusters[i];

        // Calculate the distance between the points in the cluster

        double distance = 0.0;

        for (int j = 0; j < cluster->num_points; j++) {
            point *point1 = &cluster->points[j];

            for (int k = j + 1; k < cluster->num_points; k++) {
                point *point2 = &cluster->points[k];

                distance += sqrt(pow(point1->x - point2->x, 2) + pow(point1->y - point2->y, 2));
            }
        }

        // Calculate the probability of an alien invasion based on the distance between the points

        probability += exp(-distance / 1000.0);
    }

    probability /= data->num_clusters;

    // Print the probability of an alien invasion

    printf("The probability of an alien invasion is %.2f%%\n", probability * 100.0);

    free_data(data);

    return 0;
}