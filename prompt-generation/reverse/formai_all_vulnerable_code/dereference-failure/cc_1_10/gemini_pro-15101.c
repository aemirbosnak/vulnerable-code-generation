//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the Earth's radius in kilometers
#define EARTH_RADIUS 6371

// Define the GPS coordinate system
typedef struct {
    double latitude;
    double longitude;
} GPS_COORDINATE;

// Define the GPS navigation system
typedef struct {
    GPS_COORDINATE current_position;
    GPS_COORDINATE destination;
    double distance_to_destination;
    double bearing_to_destination;
} GPS_NAVIGATION;

// Create a new GPS navigation system
GPS_NAVIGATION* gps_navigation_new(GPS_COORDINATE current_position, GPS_COORDINATE destination) {
    GPS_NAVIGATION* gps_navigation = malloc(sizeof(GPS_NAVIGATION));
    gps_navigation->current_position = current_position;
    gps_navigation->destination = destination;
    gps_navigation->distance_to_destination = 0.0;
    gps_navigation->bearing_to_destination = 0.0;
    return gps_navigation;
}

// Free the memory allocated for a GPS navigation system
void gps_navigation_free(GPS_NAVIGATION* gps_navigation) {
    free(gps_navigation);
}

// Calculate the distance between two GPS coordinates
double gps_navigation_distance_between(GPS_COORDINATE coordinate1, GPS_COORDINATE coordinate2) {
    // Convert the coordinates to radians
    double latitude1 = coordinate1.latitude * M_PI / 180.0;
    double longitude1 = coordinate1.longitude * M_PI / 180.0;
    double latitude2 = coordinate2.latitude * M_PI / 180.0;
    double longitude2 = coordinate2.longitude * M_PI / 180.0;

    // Calculate the difference in latitude and longitude
    double delta_latitude = latitude2 - latitude1;
    double delta_longitude = longitude2 - longitude1;

    // Calculate the distance using the Haversine formula
    double a = pow(sin(delta_latitude / 2), 2) + cos(latitude1) * cos(latitude2) * pow(sin(delta_longitude / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distance = EARTH_RADIUS * c;

    return distance;
}

// Calculate the bearing between two GPS coordinates
double gps_navigation_bearing_between(GPS_COORDINATE coordinate1, GPS_COORDINATE coordinate2) {
    // Convert the coordinates to radians
    double latitude1 = coordinate1.latitude * M_PI / 180.0;
    double longitude1 = coordinate1.longitude * M_PI / 180.0;
    double latitude2 = coordinate2.latitude * M_PI / 180.0;
    double longitude2 = coordinate2.longitude * M_PI / 180.0;

    // Calculate the difference in latitude and longitude
    double delta_latitude = latitude2 - latitude1;
    double delta_longitude = longitude2 - longitude1;

    // Calculate the bearing using the arctangent function
    double bearing = atan2(delta_longitude, delta_latitude);

    // Convert the bearing to degrees
    bearing = bearing * 180.0 / M_PI;

    return bearing;
}

// Update the GPS navigation system
void gps_navigation_update(GPS_NAVIGATION* gps_navigation) {
    // Calculate the distance to the destination
    gps_navigation->distance_to_destination = gps_navigation_distance_between(gps_navigation->current_position, gps_navigation->destination);

    // Calculate the bearing to the destination
    gps_navigation->bearing_to_destination = gps_navigation_bearing_between(gps_navigation->current_position, gps_navigation->destination);
}

// Print the GPS navigation system information
void gps_navigation_print(GPS_NAVIGATION* gps_navigation) {
    printf("Current position: (%f, %f)\n", gps_navigation->current_position.latitude, gps_navigation->current_position.longitude);
    printf("Destination: (%f, %f)\n", gps_navigation->destination.latitude, gps_navigation->destination.longitude);
    printf("Distance to destination: %.2f km\n", gps_navigation->distance_to_destination);
    printf("Bearing to destination: %.2f degrees\n", gps_navigation->bearing_to_destination);
}

// Main function
int main() {
    // Create a new GPS navigation system
    GPS_COORDINATE current_position = {37.7833, -122.4167};
    GPS_COORDINATE destination = {37.8021, -122.4075};
    GPS_NAVIGATION* gps_navigation = gps_navigation_new(current_position, destination);

    // Update the GPS navigation system
    gps_navigation_update(gps_navigation);

    // Print the GPS navigation system information
    gps_navigation_print(gps_navigation);

    // Free the memory allocated for the GPS navigation system
    gps_navigation_free(gps_navigation);

    return 0;
}