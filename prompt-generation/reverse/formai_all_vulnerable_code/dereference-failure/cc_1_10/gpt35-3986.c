//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: Linus Torvalds
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Define structure to hold point coordinates
typedef struct {
    double x;
    double y;
} Point;

// Define structure to hold cluster details
typedef struct {
    Point* center;
    int num_points;
    Point* points;
} Cluster;

// Function to calculate Euclidean distance between two points
double distance(Point* a, Point* b) {
    double x_diff = a->x - b->x;
    double y_diff = a->y - b->y;
    return sqrt(x_diff*x_diff + y_diff*y_diff);
}

// Function to randomly initialize cluster centers
void initialize_clusters(Point* points, Cluster* clusters, int k, int num_points) {
    int* indexes = (int*)malloc(k*sizeof(int));
    for(int i=0; i<k; i++) {
        // Generate unique random index
        int index;
        do {
            index = rand() % num_points;
        }
        while (indexes[index] == 1);
        indexes[index] = 1;
        clusters[i].center = &points[index];
        clusters[i].num_points = 0;
        clusters[i].points = (Point*)malloc(num_points*sizeof(Point));
    }
}

// Function to assign each point to its nearest cluster
void assign_points(Point* points, Cluster* clusters, int k, int num_points) {
    for(int i=0; i<num_points; i++) {
        double min_dist = distance(&clusters[0].center, &points[i]);
        int assigned_cluster = 0;
        for(int j=1; j<k; j++) {
            double dist = distance(&clusters[j].center, &points[i]);
            if(dist < min_dist) {
                min_dist = dist;
                assigned_cluster = j;
            }
        }
        clusters[assigned_cluster].points[clusters[assigned_cluster].num_points] = points[i];
        clusters[assigned_cluster].num_points++;
    }
}

// Function to calculate new cluster centers
void calculate_centers(Cluster* clusters, int k) {
    for(int i=0; i<k; i++) {
        double sum_x = 0;
        double sum_y = 0;
        for(int j=0; j<clusters[i].num_points; j++) {
            sum_x += clusters[i].points[j].x;
            sum_y += clusters[i].points[j].y;
        }
        clusters[i].center->x = sum_x/clusters[i].num_points;
        clusters[i].center->y = sum_y/clusters[i].num_points;
    }
}

// Function to print cluster details
void print_clusters(Cluster* clusters, int k) {
    for(int i=0; i<k; i++) {
        printf("Cluster %d:\n", i+1);
        printf("Center: (%f, %f)\n", clusters[i].center->x, clusters[i].center->y);
        printf("Points: ");
        for(int j=0; j<clusters[i].num_points; j++) {
            printf("(%f, %f) ", clusters[i].points[j].x, clusters[i].points[j].y);
        }
        printf("\n");
    }
}

// Main function
int main() {
    srand(time(NULL)); // Seed random number generator
    int num_points, k;
    printf("Enter number of points: ");
    scanf("%d", &num_points);
    Point* points = (Point*)malloc(num_points*sizeof(Point));
    for(int i=0; i<num_points; i++) {
        printf("Enter coordinates of point %d (in format x,y): ", i+1);
        scanf("%lf,%lf", &points[i].x, &points[i].y);
    }
    printf("Enter number of clusters: ");
    scanf("%d", &k);
    Cluster* clusters = (Cluster*)malloc(k*sizeof(Cluster));
    initialize_clusters(points, clusters, k, num_points);
    int iter = 0; // Iteration counter
    while(iter < 5) { // Perform 5 iterations for simplicity
        assign_points(points, clusters, k, num_points);
        calculate_centers(clusters, k);
        print_clusters(clusters, k);
        iter++;
    }
    return 0;
}