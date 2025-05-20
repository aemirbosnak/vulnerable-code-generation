//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

// Define the structure of a GPS point
typedef struct {
    double latitude;
    double longitude;
} GPSPoint;

// Function to calculate the distance between two GPS points
double calculateDistance(GPSPoint point1, GPSPoint point2) {
    double distance = 0.0;
    double deltaLat = point2.latitude - point1.latitude;
    double deltaLon = point2.longitude - point1.longitude;
    double a = sin(deltaLat / 2) * sin(deltaLat / 2) + cos(point1.latitude) * cos(point2.latitude) * sin(deltaLon / 2) * sin(deltaLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    distance = 6371 * c; // Earth's radius in kilometers
    return distance;
}

// Function to get user input for a GPS point
GPSPoint getGPSPoint() {
    GPSPoint point;
    printf("Enter the latitude: ");
    scanf("%lf", &point.latitude);
    printf("Enter the longitude: ");
    scanf("%lf", &point.longitude);
    return point;
}

// Function to display the current position and nearby points of interest
void displayCurrentPosition(GPSPoint currentPosition, int numPoints, GPSPoint points[]) {
    printf("\nCurrent position:\n");
    printf("Latitude: %.6lf\n", currentPosition.latitude);
    printf("Longitude: %.6lf\n", currentPosition.longitude);
    printf("\nNearby points of interest:\n");
    for (int i = 0; i < numPoints; i++) {
        double distance = calculateDistance(currentPosition, points[i]);
        if (distance <= 1000) { // Only display points within 1 kilometer
            printf("%.6lf km - ", distance);
            printf("%s\n", points[i].latitude > currentPosition.latitude? "North" : "South");
            printf("%s\n", points[i].longitude > currentPosition.longitude? "East" : "West");
        }
    }
}

int main() {
    int numPoints;
    printf("Enter the number of points of interest: ");
    scanf("%d", &numPoints);
    GPSPoint points[numPoints];
    for (int i = 0; i < numPoints; i++) {
        points[i] = getGPSPoint();
    }
    GPSPoint currentPosition = getGPSPoint();
    displayCurrentPosition(currentPosition, numPoints, points);
    return 0;
}