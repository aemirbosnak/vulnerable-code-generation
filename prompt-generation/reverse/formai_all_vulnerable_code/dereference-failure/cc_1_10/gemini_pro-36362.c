//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the Earth's radius in kilometers
#define EARTH_RADIUS 6371.0

// Define the GPS receiver's latitude and longitude in degrees
#define LATITUDE 37.422
#define LONGITUDE -122.084

// Define the destination latitude and longitude in degrees
#define DEST_LATITUDE 37.386
#define DEST_LONGITUDE -122.084

// Define the speed of the GPS receiver in kilometers per hour
#define SPEED 50.0

// Define the time interval between GPS updates in seconds
#define TIME_INTERVAL 1.0

// Define the maximum number of GPS updates
#define MAX_UPDATES 100

// Define the GPS update structure
typedef struct {
    double latitude;
    double longitude;
    double speed;
    double time;
} gps_update;

// Function to calculate the distance between two points on the Earth's surface
double distance(double lat1, double lon1, double lat2, double lon2) {
    // Convert the latitudes and longitudes to radians
    lat1 = lat1 * M_PI / 180.0;
    lon1 = lon1 * M_PI / 180.0;
    lat2 = lat2 * M_PI / 180.0;
    lon2 = lon2 * M_PI / 180.0;

    // Calculate the difference between the latitudes and longitudes
    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;

    // Calculate the distance between the points
    double a = pow(sin(dlat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(dlon / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distance = EARTH_RADIUS * c;

    return distance;
}

// Function to simulate the GPS receiver
void simulate_gps(gps_update *updates) {
    // Initialize the GPS receiver's position and speed
    updates[0].latitude = LATITUDE;
    updates[0].longitude = LONGITUDE;
    updates[0].speed = SPEED;
    updates[0].time = 0.0;

    // Simulate the GPS receiver's movement
    for (int i = 1; i < MAX_UPDATES; i++) {
        // Calculate the distance traveled since the last update
        double distance_traveled = updates[i - 1].speed * TIME_INTERVAL;

        // Calculate the bearing to the destination
        double bearing = atan2(DEST_LATITUDE - updates[i - 1].latitude, DEST_LONGITUDE - updates[i - 1].longitude);

        // Update the GPS receiver's position
        updates[i].latitude = updates[i - 1].latitude + distance_traveled * sin(bearing);
        updates[i].longitude = updates[i - 1].longitude + distance_traveled * cos(bearing);

        // Update the GPS receiver's speed
        updates[i].speed = SPEED;

        // Update the GPS receiver's time
        updates[i].time = updates[i - 1].time + TIME_INTERVAL;
    }
}

// Function to print the GPS updates
void print_updates(gps_update *updates) {
    for (int i = 0; i < MAX_UPDATES; i++) {
        printf("Update %d:\n", i);
        printf("Latitude: %.6f degrees\n", updates[i].latitude);
        printf("Longitude: %.6f degrees\n", updates[i].longitude);
        printf("Speed: %.2f km/h\n", updates[i].speed);
        printf("Time: %.2f seconds\n", updates[i].time);
        printf("\n");
    }
}

// Main function
int main() {
    // Allocate memory for the GPS updates
    gps_update *updates = malloc(MAX_UPDATES * sizeof(gps_update));

    // Simulate the GPS receiver
    simulate_gps(updates);

    // Print the GPS updates
    print_updates(updates);

    // Free the memory allocated for the GPS updates
    free(updates);

    return 0;
}