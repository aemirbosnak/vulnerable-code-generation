//FormAI DATASET v1.0 Category: Data mining ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    // Read in data from file
    FILE *fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("Error: Cannot open file\n");
        exit(1);
    }
    int num_rows;
    fscanf(fp, "%d", &num_rows);
    
    float data[num_rows][3];
    for (int i = 0; i < num_rows; i++) {
        fscanf(fp, "%f,%f,%f", &data[i][0], &data[i][1], &data[i][2]);
    }
    fclose(fp);

    // Normalize data
    float means[3] = {0.0};
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < 3; j++) {
            means[j] += data[i][j];
        }
    }
    for (int i = 0; i < 3; i++) {
        means[i] /= num_rows;
    }
    float std_devs[3] = {0.0};
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < 3; j++) {
            std_devs[j] += pow(data[i][j] - means[j], 2);
        }
    }
    for (int i = 0; i < 3; i++) {
        std_devs[i] = sqrt(std_devs[i] / num_rows);
    }
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < 3; j++) {
            data[i][j] = (data[i][j] - means[j]) / std_devs[j];
        }
    }

    // Cluster data
    int num_clusters = round(sqrt(num_rows));
    float centroids[num_clusters][3];
    int assignments[num_rows];
    for (int i = 0; i < num_clusters; i++) {
        for (int j = 0; j < 3; j++) {
            centroids[i][j] = data[rand() % num_rows][j];
        }
    }
    float dists[num_clusters];
    for (int iter = 0; iter < 50; iter++) {
        for (int i = 0; i < num_rows; i++) {
            float min_dist = INFINITY;
            int closest_cluster;
            for (int j = 0; j < num_clusters; j++) {
                float dist = 0.0;
                for (int k = 0; k < 3; k++) {
                    dist += pow(data[i][k] - centroids[j][k], 2);
                }
                dist = sqrt(dist);
                if (dist < min_dist) {
                    min_dist = dist;
                    closest_cluster = j;
                }
            }
            assignments[i] = closest_cluster;
        }
        for (int i = 0; i < num_clusters; i++) {
            for (int j = 0; j < 3; j++) {
                float sum = 0.0;
                int count = 0;
                for (int k = 0; k < num_rows; k++) {
                    if (assignments[k] == i) {
                        sum += data[k][j];
                        count++;
                    }
                }
                if (count > 0) {
                    centroids[i][j] = sum / count;
                }
            }
        }
    }

    // Output results
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d:\n", i+1);
        for (int j = 0; j < num_rows; j++) {
            if (assignments[j] == i) {
                printf("(%f, %f, %f)\n", data[j][0], data[j][1], data[j][2]);
            }
        }
    }

    return 0;
}