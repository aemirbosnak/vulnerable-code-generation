//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: rigorous
#include <stdio.h>
#include <math.h>

// Define the GPS data structure
typedef struct {
    double latitude;
    double longitude;
    double altitude;
    double speed;
    double heading;
} GPSData;

// Define the simulation parameters
#define SIMULATION_TIME 10.0  // Simulation time in seconds
#define UPDATE_INTERVAL 0.1  // GPS update interval in seconds
#define SPEED 10.0  // Speed in meters per second
#define HEADING 0.0  // Heading in radians

// Define the simulation state
GPSData gpsData;

// Define the simulation functions
void updateGPS();
void displayGPS();

// Main function
int main() {
    // Initialize the simulation state
    gpsData.latitude = 0.0;
    gpsData.longitude = 0.0;
    gpsData.altitude = 0.0;
    gpsData.speed = SPEED;
    gpsData.heading = HEADING;

    // Start the simulation
    double startTime = time();
    while (time() - startTime < SIMULATION_TIME) {
        // Update the GPS data
        updateGPS();

        // Display the GPS data
        displayGPS();
    }

    return 0;
}

// Update the GPS data
void updateGPS() {
    // Calculate the distance traveled since the last update
    double distance = SPEED * UPDATE_INTERVAL;

    // Calculate the change in latitude and longitude
    double dLat = distance * cos(HEADING);
    double dLon = distance * sin(HEADING);

    // Update the latitude and longitude
    gpsData.latitude += dLat;
    gpsData.longitude += dLon;

    // Update the altitude
    gpsData.altitude += 0.0;  // Assuming no altitude change

    // Update the speed
    gpsData.speed = SPEED;  // Assuming constant speed

    // Update the heading
    gpsData.heading = HEADING;  // Assuming constant heading
}

// Display the GPS data
void displayGPS() {
    printf("Latitude: %f\n", gpsData.latitude);
    printf("Longitude: %f\n", gpsData.longitude);
    printf("Altitude: %f\n", gpsData.altitude);
    printf("Speed: %f\n", gpsData.speed);
    printf("Heading: %f\n", gpsData.heading);
    printf("\n");
}