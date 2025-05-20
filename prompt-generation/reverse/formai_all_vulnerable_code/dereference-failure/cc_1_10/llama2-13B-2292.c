//LLAMA2-13B DATASET v1.0 Category: Data mining ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_RECORDS 10000
#define MAX_FEATURES 5

// Structure to hold a single record
typedef struct {
    int age;
    int income;
    char gender[10];
    int education_level;
    int occupation[20];
} record_t;

// Function to read data from a file
record_t *read_data(const char *filename) {
    record_t *records = calloc(MAX_RECORDS, sizeof(record_t));
    int i = 0;
    FILE *file = fopen(filename, "r");

    while (fscanf(file, "%d%*c%d%*c%d", &records[i].age, &records[i].income, records[i].gender, records[i].education_level, records[i].occupation) == 5) {
        i++;
    }

    fclose(file);
    return records;
}

// Function to perform k-means clustering
void kmeans_clustering(record_t *records, int k) {
    int i, j;
    double sum[k];
    double count[k];
    int cluster[k];

    // Initialize centroids
    for (i = 0; i < k; i++) {
        sum[i] = 0;
        count[i] = 0;
    }

    // Loop through records and assign to nearest cluster
    for (i = 0; i < MAX_RECORDS; i++) {
        double distance = 0;
        int closest_cluster = -1;

        for (j = 0; j < k; j++) {
            distance += pow(records[i].age - sum[j], 2);
            distance += pow(records[i].income - sum[j], 2);
            distance += pow(strcmp(records[i].gender, records[j].gender), 2);
            distance += pow(records[i].education_level - sum[j], 2);
            distance += pow(strcmp(records[i].occupation, records[j].occupation), 2);
        }

        closest_cluster = (int) floor(distance / (2 * M_PI));

        if (closest_cluster == -1) {
            printf("No cluster found for record %d\n", i);
            continue;
        }

        count[closest_cluster]++;
        sum[closest_cluster] += records[i].age;
        sum[closest_cluster] += records[i].income;
        sum[closest_cluster] += strcmp(records[i].gender, records[closest_cluster].gender);
        sum[closest_cluster] += records[i].education_level;
        sum[closest_cluster] += strcmp(records[i].occupation, records[closest_cluster].occupation);
    }

    // Print cluster assignments and centroids
    for (i = 0; i < k; i++) {
        printf("%d: %d (%.2f, %.2f, %.2f, %.2f, %.2f)\n", i, count[i], sum[i], sum[i] / count[i], sum[i] / count[i], sum[i] / count[i]);
    }
}

int main() {
    record_t *records = read_data("data.csv");
    int k = 3; // number of clusters

    kmeans_clustering(records, k);

    return 0;
}