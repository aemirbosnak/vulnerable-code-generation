//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the structure of a GPS receiver
typedef struct {
    double latitude;
    double longitude;
    double altitude;
    double speed;
    double heading;
} GPSReceiver;

// Define the structure of a GPS waypoint
typedef struct {
    double latitude;
    double longitude;
    char *name;
} GPSWaypoint;

// Create a new GPS receiver
GPSReceiver *createGPSReceiver() {
    GPSReceiver *receiver = malloc(sizeof(GPSReceiver));
    receiver->latitude = 0.0;
    receiver->longitude = 0.0;
    receiver->altitude = 0.0;
    receiver->speed = 0.0;
    receiver->heading = 0.0;
    return receiver;
}

// Destroy a GPS receiver
void destroyGPSReceiver(GPSReceiver *receiver) {
    free(receiver);
}

// Update the position of a GPS receiver
void updateGPSReceiverPosition(GPSReceiver *receiver, double latitude, double longitude, double altitude, double speed, double heading) {
    receiver->latitude = latitude;
    receiver->longitude = longitude;
    receiver->altitude = altitude;
    receiver->speed = speed;
    receiver->heading = heading;
}

// Create a new GPS waypoint
GPSWaypoint *createGPSWaypoint(double latitude, double longitude, char *name) {
    GPSWaypoint *waypoint = malloc(sizeof(GPSWaypoint));
    waypoint->latitude = latitude;
    waypoint->longitude = longitude;
    waypoint->name = strdup(name);
    return waypoint;
}

// Destroy a GPS waypoint
void destroyGPSWaypoint(GPSWaypoint *waypoint) {
    free(waypoint->name);
    free(waypoint);
}

// Calculate the distance between two GPS waypoints
double calculateDistanceBetweenWaypoints(GPSWaypoint *waypoint1, GPSWaypoint *waypoint2) {
    double dLat = (waypoint2->latitude - waypoint1->latitude) * M_PI / 180.0;
    double dLon = (waypoint2->longitude - waypoint1->longitude) * M_PI / 180.0;
    double a = sin(dLat / 2) * sin(dLat / 2) + cos(waypoint1->latitude * M_PI / 180.0) * cos(waypoint2->latitude * M_PI / 180.0) * sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distance = 6371.0 * c;
    return distance;
}

// Find the closest GPS waypoint to a given GPS receiver
GPSWaypoint *findClosestWaypoint(GPSReceiver *receiver, GPSWaypoint *waypoints, int numWaypoints) {
    double closestDistance = INFINITY;
    GPSWaypoint *closestWaypoint = NULL;
    for (int i = 0; i < numWaypoints; i++) {
        double distance = calculateDistanceBetweenWaypoints(receiver, &waypoints[i]);
        if (distance < closestDistance) {
            closestDistance = distance;
            closestWaypoint = &waypoints[i];
        }
    }
    return closestWaypoint;
}

// Print the navigation instructions for a given GPS receiver and GPS waypoint
void printNavigationInstructions(GPSReceiver *receiver, GPSWaypoint *waypoint) {
    double distance = calculateDistanceBetweenWaypoints(receiver, waypoint);
    double bearing = atan2(waypoint->longitude - receiver->longitude, waypoint->latitude - receiver->latitude) * 180.0 / M_PI;
    printf("Navigate %.1f miles at a bearing of %.1f degrees to reach %s.\n", distance, bearing, waypoint->name);
}

// Main function
int main() {
    // Create a GPS receiver
    GPSReceiver *receiver = createGPSReceiver();

    // Create a list of GPS waypoints
    GPSWaypoint waypoints[] = {
        {37.7749, -122.4194, "Golden Gate Bridge"},
        {37.8043, -122.2711, "Alcatraz Island"},
        {37.7604, -122.3910, "Fisherman's Wharf"},
        {37.7940, -122.3989, "Pier 39"},
        {37.8267, -122.4233, "Presidio National Park"}
    };
    int numWaypoints = sizeof(waypoints) / sizeof(waypoints[0]);

    // Update the position of the GPS receiver
    updateGPSReceiverPosition(receiver, 37.7772, -122.4206, 0.0, 0.0, 0.0);

    // Find the closest GPS waypoint to the GPS receiver
    GPSWaypoint *closestWaypoint = findClosestWaypoint(receiver, waypoints, numWaypoints);

    // Print the navigation instructions
    printNavigationInstructions(receiver, closestWaypoint);

    // Destroy the GPS receiver and waypoints
    destroyGPSReceiver(receiver);
    for (int i = 0; i < numWaypoints; i++) {
        destroyGPSWaypoint(&waypoints[i]);
    }

    return 0;
}