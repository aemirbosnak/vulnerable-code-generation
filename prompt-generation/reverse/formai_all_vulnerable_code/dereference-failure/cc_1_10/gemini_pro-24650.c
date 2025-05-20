//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the GPS data structure
typedef struct GPS {
    double latitude;
    double longitude;
    double altitude;
    double speed;
    double heading;
} GPS;

// Define the configuration structure
typedef struct Config {
    double startLatitude;
    double startLongitude;
    double startAltitude;
    double speed;
    double heading;
    double distance;
    double turnAngle;
} Config;

// Create a new GPS object
GPS* newGPS(double latitude, double longitude, double altitude, double speed, double heading)
{
    GPS* gps = (GPS*)malloc(sizeof(GPS));
    gps->latitude = latitude;
    gps->longitude = longitude;
    gps->altitude = altitude;
    gps->speed = speed;
    gps->heading = heading;
    return gps;
}

// Free the GPS object
void freeGPS(GPS* gps)
{
    free(gps);
}

// Create a new configuration object
Config* newConfig(double startLatitude, double startLongitude, double startAltitude, double speed, double heading, double distance, double turnAngle)
{
    Config* config = (Config*)malloc(sizeof(Config));
    config->startLatitude = startLatitude;
    config->startLongitude = startLongitude;
    config->startAltitude = startAltitude;
    config->speed = speed;
    config->heading = heading;
    config->distance = distance;
    config->turnAngle = turnAngle;
    return config;
}

// Free the configuration object
void freeConfig(Config* config)
{
    free(config);
}

// Simulate the GPS navigation
void simulateGPS(GPS* gps, Config* config)
{
    // Set the initial GPS data
    gps->latitude = config->startLatitude;
    gps->longitude = config->startLongitude;
    gps->altitude = config->startAltitude;
    gps->speed = config->speed;
    gps->heading = config->heading;

    // Simulate the movement
    for (int i = 0; i < config->distance; i++)
    {
        // Update the latitude and longitude
        gps->latitude += config->speed * cos(gps->heading * M_PI / 180) / 60 / 60;
        gps->longitude += config->speed * sin(gps->heading * M_PI / 180) / 60 / 60;

        // Update the altitude
        gps->altitude += 0; // Assuming no altitude change

        // Update the speed
        gps->speed = config->speed;

        // Update the heading
        gps->heading += config->turnAngle;

        // Print the GPS data
        printf("Latitude: %f, Longitude: %f, Altitude: %f, Speed: %f, Heading: %f\n", gps->latitude, gps->longitude, gps->altitude, gps->speed, gps->heading);
    }
}

// Main function
int main()
{
    // Create the configuration object
    Config* config = newConfig(37.7749, -122.4194, 0, 60, 0, 1000, 90);

    // Create the GPS object
    GPS* gps = newGPS(config->startLatitude, config->startLongitude, config->startAltitude, config->speed, config->heading);

    // Simulate the GPS navigation
    simulateGPS(gps, config);

    // Free the GPS object
    freeGPS(gps);

    // Free the configuration object
    freeConfig(config);

    return 0;
}