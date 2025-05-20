//FormAI DATASET v1.0 Category: Data mining ; Style: realistic
/* 
This C program demonstrates data mining by analyzing a dataset of student grades.
The program takes input from a CSV file, preprocesses the data and performs clustering using the k-means algorithm. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_RECORDS 1000
#define MAX_ATTRIBUTES 10
#define CLUSTERS 3
#define MAX_ITERATIONS 100

int num_records = 0;
int num_attributes = 0;
float data[MAX_RECORDS][MAX_ATTRIBUTES]; // dataset to be analyzed
float centroids[CLUSTERS][MAX_ATTRIBUTES]; // initial centroids for clustering

// Function to calculate Euclidean distance between two points (record and centroid)
float euclidean_distance(float *record, float *centroid) {
    float distance = 0.0;
    for(int i=0; i<num_attributes; i++) {
        distance += pow((record[i] - centroid[i]), 2);
    }
    return sqrt(distance);
}

// Function to assign clusters to records based on centroid distances
void assign_clusters(int *clusters) {
    float min_distance = 999999;
    for(int i=0; i<num_records; i++) {
        for(int j=0; j<CLUSTERS; j++) {
            float distance = euclidean_distance(data[i], centroids[j]);
            if(distance < min_distance) {
                min_distance = distance;
                clusters[i] = j;
            }
        }
        min_distance = 999999; // reset minimum distance for next record
    }
}

// Function to recalculate centroid locations based on assigned clusters
void recalculate_centroids(int *clusters) {
    int counts[CLUSTERS] = {0}; // number of records assigned to each cluster
    for(int i=0; i<num_records; i++) {
        for(int j=0; j<num_attributes; j++) {
            centroids[clusters[i]][j] += data[i][j];
        }
        counts[clusters[i]]++;
    }
    for(int i=0; i<CLUSTERS; i++) {
        for(int j=0; j<num_attributes; j++) {
            centroids[i][j] /= counts[i];
        }
    }
}

// Function to write the final cluster assignments to a CSV file
void write_cluster_assignments(int *clusters) {
    FILE *fp = fopen("output.csv", "w");
    fprintf(fp, "Record ID, Cluster\n");
    for(int i=0; i<num_records; i++) {
        fprintf(fp, "%d, %d\n", i+1, clusters[i]);
    }
    fclose(fp);
}

int main() {
    // Read dataset from CSV file
    FILE *fp = fopen("input.csv", "r");
    char buffer[1024];
    fgets(buffer, 1024, fp); // ignore header row
    while(fgets(buffer, 1024, fp)) {
        char *token = strtok(buffer, ",");
        int attribute_index = 0;
        while(token != NULL) {
            data[num_records][attribute_index] = atof(token);
            attribute_index++;
            token = strtok(NULL, ",");
        }
        num_records++;
        num_attributes = attribute_index;
    }
    fclose(fp);

    // Initialize centroids randomly
    for(int i=0; i<CLUSTERS; i++) {
        int index = rand() % num_records;
        for(int j=0; j<num_attributes; j++) {
            centroids[i][j] = data[index][j];
        }
    }

    // Perform clustering using k-means algorithm
    int clusters[num_records];
    int iterations = 0;
    do {
        assign_clusters(clusters);
        recalculate_centroids(clusters);
        iterations++;
    } while(iterations < MAX_ITERATIONS);

    // Write the final cluster assignments to a CSV file
    write_cluster_assignments(clusters);

    return 0;
}