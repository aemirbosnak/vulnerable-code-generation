//GPT-4o-mini DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_POINTS 1000
#define MAX_DIMENSIONS 10
#define MAX_CLUSTERS 10
#define EPSILON 1e-6

typedef struct {
    double coordinates[MAX_DIMENSIONS];
    int cluster;
} DataPoint;

typedef struct {
    double centroid[MAX_DIMENSIONS];
    int numPoints;
} Cluster;

int numPoints = 0;
int numDimensions = 0;
int numClusters = 0;
DataPoint points[MAX_POINTS];
Cluster clusters[MAX_CLUSTERS];

void readData(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // First line gives us the number of dimensions and points
    fscanf(file, "%d %d", &numDimensions, &numPoints);

    for (int i = 0; i < numPoints; i++) {
        for (int j = 0; j < numDimensions; j++) {
            fscanf(file, "%lf", &points[i].coordinates[j]);
        }
        points[i].cluster = -1; // Initialize cluster
    }

    fclose(file);
}

void initializeClusters() {
    for (int i = 0; i < numClusters; i++) {
        for (int j = 0; j < numDimensions; j++) {
            clusters[i].centroid[j] = points[rand() % numPoints].coordinates[j]; // Random initial centroids
        }
        clusters[i].numPoints = 0;
    }
}

double calculateDistance(DataPoint *point, Cluster *cluster) {
    double distance = 0.0;
    for (int j = 0; j < numDimensions; j++) {
        distance += pow(point->coordinates[j] - cluster->centroid[j], 2);
    }
    return sqrt(distance);
}

void assignClusters() {
    for (int i = 0; i < numPoints; i++) {
        double minDistance = INFINITY;
        int closestCluster = -1;
        
        for (int j = 0; j < numClusters; j++) {
            double distance = calculateDistance(&points[i], &clusters[j]);
            if (distance < minDistance) {
                minDistance = distance;
                closestCluster = j;
            }
        }
        
        points[i].cluster = closestCluster;
    }
}

void updateCentroids() {
    for (int i = 0; i < numClusters; i++) {
        memset(clusters[i].centroid, 0, sizeof(clusters[i].centroid));
        clusters[i].numPoints = 0;
    }

    for (int i = 0; i < numPoints; i++) {
        int clusterIndex = points[i].cluster;
        clusters[clusterIndex].numPoints++;
        for (int j = 0; j < numDimensions; j++) {
            clusters[clusterIndex].centroid[j] += points[i].coordinates[j];
        }
    }

    for (int i = 0; i < numClusters; i++) {
        if (clusters[i].numPoints != 0) {
            for (int j = 0; j < numDimensions; j++) {
                clusters[i].centroid[j] /= clusters[i].numPoints; // Calculate the new centroid
            }
        }
    }
}

int checkConvergence() {
    for (int i = 0; i < numClusters; i++) {
        if (fabs(clusters[i].centroid[0]) < EPSILON) continue;

        for (int j = 0; j < numDimensions; j++) {
            double distance = calculateDistance((DataPoint *)&clusters[i], &clusters[i]);
            if (distance > EPSILON) {
                return 0; // Not converged
            }
        }
    }
    return 1; // Converged
}

void kMeansClustering(int k) {
    numClusters = k;
    initializeClusters();
    
    while (1) {
        assignClusters();
        updateCentroids();
        
        if (checkConvergence()) break;
    }
}

void writeResults(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < numPoints; i++) {
        fprintf(file, "Point %d: Cluster %d\n", i, points[i].cluster);
    }
    
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <data_file> <num_clusters> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int k = atoi(argv[2]);
    if (k > MAX_CLUSTERS || k <= 0) {
        fprintf(stderr, "Number of clusters must be between 1 and %d\n", MAX_CLUSTERS);
        return EXIT_FAILURE;
    }

    readData(argv[1]);
    kMeansClustering(k);
    writeResults(argv[3]);
    
    return EXIT_SUCCESS;
}