//LLAMA2-13B DATASET v1.0 Category: Data mining ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_RECORDS 10000
#define MAX_FEATURES 10

// Structure to represent a record
typedef struct {
    int age;
    int income;
    char gender[10];
} record_t;

// Function to read data from a file
record_t *read_records(const char *file_name) {
    record_t *records = malloc(MAX_RECORDS * sizeof(record_t));
    int i = 0;
    char line[1024];

    // Open the file and read each line
    FILE *file = fopen(file_name, "r");
    while (fgets(line, 1024, file) != NULL) {
        // Parse the line and extract the features
        int feature_count = sscanf(line, "%d%d%9s", &records[i].age, &records[i].income, records[i].gender);

        // Check for errors
        if (feature_count < 3) {
            printf("Error: Unable to parse record %d\n", i + 1);
            continue;
        }

        // Increment the index and continue
        i++;
    }

    // Return the array of records
    return records;
}

// Function to perform clustering using k-means
void perform_clustering(record_t *records, int k) {
    int i, j;
    double sum_squared_distances[k];
    double *centroids[k];

    // Initialize the centroids and the sum of squared distances
    for (i = 0; i < k; i++) {
        centroids[i] = malloc(sizeof(double));
        sum_squared_distances[i] = 0;
    }

    // Calculate the squared distances between each record and the centroids
    for (i = 0; i < MAX_RECORDS; i++) {
        for (j = 0; j < k; j++) {
            double distance = 0;
            for (int feature_index = 0; feature_index < MAX_FEATURES; feature_index++) {
                distance += pow(records[i].age - centroids[j][feature_index], 2);
            }
            sum_squared_distances[j] += distance;
        }
    }

    // Calculate the centroids
    for (i = 0; i < k; i++) {
        centroids[i][0] = sum_squared_distances[i] / records[0].age;
    }

    // Print the centroids
    for (i = 0; i < k; i++) {
        printf("Centroid %d: %f, %f, %f\n", i + 1, centroids[i][0], centroids[i][1], centroids[i][2]);
    }
}

int main() {
    record_t *records = read_records("data.txt");
    int k = 3; // Number of clusters

    perform_clustering(records, k);

    return 0;
}