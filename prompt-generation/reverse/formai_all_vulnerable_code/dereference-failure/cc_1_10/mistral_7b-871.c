//MISTRAL-7B DATASET v1.0 Category: GPS Navigation Simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

// Struct to represent a GPS point
typedef struct {
    double latitude;
    double longitude;
} GPSPoint;

// Struct to represent a waypoint
typedef struct {
    char name[50];
    GPSPoint location;
} Waypoint;

// Function to generate random waypoints
Waypoint generateWaypoint(void) {
    Waypoint wp;
    wp.location.latitude = (rand() % 90) + 10.0;
    wp.location.longitude = (rand() % 180) + 100.0;
    sprintf(wp.name, "Random Waypoint %d", rand() % 100);
    return wp;
}

// Function to calculate distance between two GPS points (Haversine formula)
double distance(GPSPoint p1, GPSPoint p2) {
    const double R = 6371e3; // Earth radius in meters
    double lat1 = p1.latitude * M_PI / 180.0;
    double lon1 = p1.longitude * M_PI / 180.0;
    double lat2 = p2.latitude * M_PI / 180.0;
    double lon2 = p2.longitude * M_PI / 180.0;
    double dLat = lat2 - lat1;
    double dLon = lon2 - lon1;
    double a = pow(sin(dLat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(dLon / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return R * c;
}

// Struct to represent a car
typedef struct {
    GPSPoint currentPosition;
    Waypoint* destination;
    double speed;
    double fuelLevel;
} Car;

// Function to simulate car movement towards a waypoint
void moveCar(Car* car, Waypoint* wp) {
    double distanceToGo = distance(car->currentPosition, wp->location);
    double timeToReach = distanceToGo / car->speed;

    printf("\nYou are now driving towards %s...\n", wp->name);
    printf("It will take you %0.2f minutes to reach there.\n", timeToReach / 60.0);

    car->currentPosition = wp->location;
    car->fuelLevel -= timeToReach * 1.2; // Consume 1.2 liters of fuel per minute

    if (car->fuelLevel <= 0) {
        printf("Out of fuel! Game Over!\n");
        exit(EXIT_FAILURE);
    }
}

// Function to generate a random route with waypoints
void generateRoute(Car* car, int numWaypoints) {
    Waypoint* route = malloc(numWaypoints * sizeof(Waypoint));

    for (int i = 0; i < numWaypoints; i++) {
        route[i] = generateWaypoint();
        moveCar(car, &route[i]);
    }

    free(route);
}

// Main function
int main(void) {
    srand(time(NULL)); // Seed random number generator

    Car myCar = { { 51.5074, -0.0896 }, NULL, 120.0, 100.0 };
    int numWaypoints = 5;

    printf("\n--- GPS Adventure ---\n");
    generateRoute(&myCar, numWaypoints);

    return EXIT_SUCCESS;
}