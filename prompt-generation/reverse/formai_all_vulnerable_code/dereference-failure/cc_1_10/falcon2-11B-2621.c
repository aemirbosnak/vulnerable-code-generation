//Falcon2-11B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: medieval
// 1. Declare the necessary variables and data structures
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int num_points = atoi(argv[1]); // number of points
    int num_clusters = atoi(argv[2]); // number of clusters
    int points[num_points][2]; // array of points with x and y coordinates
    int clusters[num_clusters][2]; // array of clusters with center coordinates
    int cluster_count[num_clusters]; // array to keep track of cluster sizes
    int num_clusters_found = 0; // variable to keep track of the number of clusters found
    
    // 2. Read in the points from the command line arguments
    FILE* file = fopen(argv[3], "r");
    if (file == NULL) {
        printf("Failed to open file!\n");
        return 1;
    }
    
    fscanf(file, "%d", &num_points);
    for (int i = 0; i < num_points; i++) {
        fscanf(file, "%d %d", &points[i][0], &points[i][1]);
    }
    
    // 3. Perform the clustering algorithm
    for (int i = 0; i < num_clusters; i++) {
        clusters[i][0] = 0;
        clusters[i][1] = 0;
    }
    
    for (int i = 0; i < num_points; i++) {
        int min_distance = 1000; // initial distance to infinity
        int min_index = -1; // index of the minimum distance cluster
        
        for (int j = 0; j < num_clusters; j++) {
            int distance = (clusters[j][0] - points[i][0]) * (clusters[j][0] - points[i][0]) + (clusters[j][1] - points[i][1]) * (clusters[j][1] - points[i][1]);
            if (distance < min_distance) {
                min_distance = distance;
                min_index = j;
            }
        }
        
        // Assign the point to the minimum distance cluster
        clusters[min_index][0] += points[i][0];
        clusters[min_index][1] += points[i][1];
        
        // Increment the cluster count
        cluster_count[min_index]++;
    }
    
    // 4. Find the number of clusters and print the results
    for (int i = 0; i < num_clusters; i++) {
        if (cluster_count[i] > 0) {
            num_clusters_found++;
        }
    }
    
    printf("Clustering algorithm complete!\n");
    printf("Number of clusters found: %d\n", num_clusters_found);
    
    // 5. Print the cluster centers
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d center: (%d, %d)\n", i, clusters[i][0] / cluster_count[i], clusters[i][1] / cluster_count[i]);
    }
    
    // 6. Close the file
    fclose(file);
    
    return 0;
}