//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600
#define NUM_POINTS 100

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point *points;
    int size;
} PointCloud;

void generateRandomPointCloud(PointCloud *cloud, int numPoints) {
    cloud->points = (Point *)malloc(sizeof(Point) * numPoints);
    cloud->size = numPoints;
    for (int i = 0; i < numPoints; i++) {
        cloud->points[i].x = rand() % WIDTH;
        cloud->points[i].y = rand() % HEIGHT;
    }
}

void freePointCloud(PointCloud *cloud) {
    free(cloud->points);
}

double calculateDistance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

void findClosestPair(PointCloud *cloud) {
    double minDistance = INFINITY;
    Point closestA, closestB;

    for (int i = 0; i < cloud->size; i++) {
        for (int j = i + 1; j < cloud->size; j++) {
            double distance = calculateDistance(cloud->points[i], cloud->points[j]);
            if (distance < minDistance) {
                minDistance = distance;
                closestA = cloud->points[i];
                closestB = cloud->points[j];
            }
        }
    }

    printf("Closest Points:\n");
    printf("Point A: (%.2f, %.2f)\n", closestA.x, closestA.y);
    printf("Point B: (%.2f, %.2f)\n", closestB.x, closestB.y);
    printf("Distance: %.2f\n", minDistance);
}

void plotPointCloud(PointCloud *cloud) {
    printf("Plotting Point Cloud:\n");
    for (int i = 0; i < cloud->size; i++) {
        printf("Point %d: (%.2f, %.2f)\n", i+1, cloud->points[i].x, cloud->points[i].y);
    }
}

void displayCyberpunkBackground() {
    printf("=== Cyberpunk City Grid ===\n");
    printf("Activating neon lights...\n");
    for (int i = 0; i < WIDTH / 100; i++) {
        for (int j = 0; j < HEIGHT / 100; j++) {
            printf("▓▓");
        }
        printf("\n");
    }
    printf("Neon lights activated. Ready for action...\n");
}

int main() {
    srand(time(0));
    PointCloud cloud;
    
    displayCyberpunkBackground();
    generateRandomPointCloud(&cloud, NUM_POINTS);
    plotPointCloud(&cloud);
    findClosestPair(&cloud);
    freePointCloud(&cloud);

    printf("Mission completed successfully.\n");
    return 0;
}