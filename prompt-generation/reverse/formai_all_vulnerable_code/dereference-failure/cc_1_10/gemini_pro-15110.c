//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the structure of a GPS point
typedef struct {
    double latitude;
    double longitude;
    double altitude;
} GPSPoint;

// Define the structure of a GPS navigation system
typedef struct {
    GPSPoint currentLocation;
    GPSPoint destinationLocation;
    double speed;
    double bearing;
} GPSNavigationSystem;

// Create a new GPS navigation system
GPSNavigationSystem* createGPSNavigationSystem(GPSPoint currentLocation, GPSPoint destinationLocation, double speed, double bearing) {
    GPSNavigationSystem* gps = malloc(sizeof(GPSNavigationSystem));
    gps->currentLocation = currentLocation;
    gps->destinationLocation = destinationLocation;
    gps->speed = speed;
    gps->bearing = bearing;
    return gps;
}

// Destroy a GPS navigation system
void destroyGPSNavigationSystem(GPSNavigationSystem* gps) {
    free(gps);
}

// Update the current location of the GPS navigation system
void updateCurrentLocation(GPSNavigationSystem* gps, double latitude, double longitude, double altitude) {
    gps->currentLocation.latitude = latitude;
    gps->currentLocation.longitude = longitude;
    gps->currentLocation.altitude = altitude;
}

// Calculate the bearing between the current location and the destination location
double calculateBearing(GPSPoint currentLocation, GPSPoint destinationLocation) {
    double latitude1 = currentLocation.latitude * M_PI / 180;
    double longitude1 = currentLocation.longitude * M_PI / 180;
    double latitude2 = destinationLocation.latitude * M_PI / 180;
    double longitude2 = destinationLocation.longitude * M_PI / 180;

    double y = sin(longitude2 - longitude1) * cos(latitude2);
    double x = cos(latitude1) * sin(latitude2) - sin(latitude1) * cos(latitude2) * cos(longitude2 - longitude1);

    double bearing = atan2(y, x);
    bearing = bearing * 180 / M_PI;
    return bearing;
}

// Distance between two points on Earth
double distanceBetweenPoints(GPSPoint currentLocation, GPSPoint destinationLocation) {
    //Convert latitudes and longitudes from degrees to radians
    double latitude1 = currentLocation.latitude * M_PI / 180;
    double longitude1 = currentLocation.longitude * M_PI / 180;
    double latitude2 = destinationLocation.latitude * M_PI / 180;
    double longitude2 = destinationLocation.longitude * M_PI / 180;

    //Calculate the great circle distance using the Haversine formula
    double dLat = latitude2 - latitude1;
    double dLon = longitude2 - longitude1;

    double a = pow(sin(dLat / 2), 2) + cos(latitude1) * cos(latitude2) * pow(sin(dLon / 2), 2);
    double c = 2 * asin(sqrt(a));
    double r = 6371;  // Earth's radius in kilometers
    double distance = c * r;

    return distance;
}

void updateBearing(GPSNavigationSystem* gps) {
    double bearing = calculateBearing(gps->currentLocation, gps->destinationLocation);
    gps->bearing = bearing;
}

void updateSpeed(GPSNavigationSystem* gps, double speed) {
    gps->speed = speed;
}

void simulateNavigation(GPSNavigationSystem* gps) {
    double distance = distanceBetweenPoints(gps->currentLocation, gps->destinationLocation);
    double time = distance / gps->speed;

    // Update the current location based on the speed, bearing, and time
    gps->currentLocation.latitude += gps->speed * sin(gps->bearing * M_PI / 180) * time;
    gps->currentLocation.longitude += gps->speed * cos(gps->bearing * M_PI / 180) * time;
}

int main() {
    // Create a GPS navigation system
    GPSPoint currentLocation = { 37.7749, -122.4194, 0 };
    GPSPoint destinationLocation = { 37.7868, -122.3996, 0 };
    double speed = 10;  // km/h
    double bearing = 0;  // degrees

    GPSNavigationSystem* gps = createGPSNavigationSystem(currentLocation, destinationLocation, speed, bearing);

    // Simulate navigation
    while (distanceBetweenPoints(gps->currentLocation, gps->destinationLocation) > 0.1) {
        simulateNavigation(gps);
        updateBearing(gps);
    }

    // Print the final destination
    printf("Destination reached!\n");
    printf("Latitude: %.6f\n", gps->currentLocation.latitude);
    printf("Longitude: %.6f\n", gps->currentLocation.longitude);

    // Destroy the GPS navigation system
    destroyGPSNavigationSystem(gps);

    return 0;
}