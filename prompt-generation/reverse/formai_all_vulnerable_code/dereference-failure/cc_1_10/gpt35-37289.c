//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Structure for storing data points
struct Point 
{
    int x, y;
};

// Function to calculate Euclidean distance between two points
float distance(struct Point a, struct Point b)
{
    return sqrt( (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y) );
} 

// Clustering function that groups the data points into clusters
void cluster(struct Point* points, int num_points, float threshold)
{
    // Create an array to hold cluster labels
    int* labels = (int*) malloc(num_points * sizeof(int));
    
    // Initialize labels to -1, meaning unassigned
    for(int i=0; i<num_points; i++) 
        labels[i] = -1;
    
    // Initialize cluster count, starting with 0
    int cluster_count = 0;
    
    // Iterate through all points
    for(int i=0; i<num_points; i++) 
    {
        // Check if point i has already been assigned a cluster
        if(labels[i] != -1) 
            continue;
        
        // Initialize a new cluster with point i
        labels[i] = cluster_count;
        cluster_count++;
        
        // Iterate through all remaining points
        for(int j=i+1; j<num_points; j++)
        {
            // Check if point j has already been assigned a cluster
            if(labels[j] != -1) 
                continue;
            
            // Calculate Euclidean distance between points i and j
            float d = distance(points[i], points[j]);
            
            // If distance between the two points is less than threshold, assign j to the same cluster as i
            if(d < threshold)
                labels[j] = labels[i];
        }
    }
    
    // Print the final clusters along with their respective data points
    for(int i=0; i<cluster_count; i++)
    {
        printf("Cluster %d:\n", i);
        for(int j=0; j<num_points; j++)
        {
            if(labels[j] == i)
                printf("(%d, %d)\n", points[j].x, points[j].y);
        }
        printf("\n");
    }
    
    // Free memory allocated for labels array
    free(labels);
}

int main()
{
    // Example usage
    struct Point points[] = {{1,2}, {2,3}, {5,6}, {6,7}, {9,10}};
    int num_points = sizeof(points)/sizeof(struct Point);
    float threshold = 2.5;
    cluster(points, num_points, threshold);
    
    return 0;
}