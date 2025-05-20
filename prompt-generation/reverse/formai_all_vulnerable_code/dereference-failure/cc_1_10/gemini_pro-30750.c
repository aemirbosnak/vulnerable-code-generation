//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the GPS navigation system
typedef struct {
    double latitude;
    double longitude;
    double altitude;
    double speed;
    double heading;
} GPS;

// Define the map of the world
typedef struct {
    double *latitude;
    double *longitude;
    char **name;
    int num_locations;
} Map;

// Create a new GPS navigation system
GPS *new_gps() {
    GPS *gps = (GPS *)malloc(sizeof(GPS));
    gps->latitude = 0.0;
    gps->longitude = 0.0;
    gps->altitude = 0.0;
    gps->speed = 0.0;
    gps->heading = 0.0;
    return gps;
}

// Destroy a GPS navigation system
void destroy_gps(GPS *gps) {
    free(gps);
}

// Create a new map of the world
Map *new_map() {
    Map *map = (Map *)malloc(sizeof(Map));
    map->latitude = (double *)malloc(sizeof(double) * 1000);
    map->longitude = (double *)malloc(sizeof(double) * 1000);
    map->name = (char **)malloc(sizeof(char *) * 1000);
    map->num_locations = 0;
    return map;
}

// Destroy a map of the world
void destroy_map(Map *map) {
    free(map->latitude);
    free(map->longitude);
    free(map->name);
    free(map);
}

// Add a location to the map
void add_location(Map *map, double latitude, double longitude, char *name) {
    map->latitude[map->num_locations] = latitude;
    map->longitude[map->num_locations] = longitude;
    map->name[map->num_locations] = name;
    map->num_locations++;
}

// Find the nearest location to the GPS coordinates
char *find_nearest_location(Map *map, GPS *gps) {
    double min_distance = 1000000.0;
    int min_index = -1;
    for (int i = 0; i < map->num_locations; i++) {
        double distance = sqrt(pow(map->latitude[i] - gps->latitude, 2) + pow(map->longitude[i] - gps->longitude, 2));
        if (distance < min_distance) {
            min_distance = distance;
            min_index = i;
        }
    }
    return map->name[min_index];
}

// Simulate the GPS navigation system
void simulate_gps(GPS *gps, Map *map) {
    // Move the GPS forward by 1 meter
    gps->latitude += 0.00001 * cos(gps->heading);
    gps->longitude += 0.00001 * sin(gps->heading);

    // Update the GPS speed and heading
    gps->speed = 10.0;
    gps->heading += 0.01;

    // Find the nearest location to the GPS coordinates
    char *nearest_location = find_nearest_location(map, gps);

    // Print the GPS information
    printf("Latitude: %f\n", gps->latitude);
    printf("Longitude: %f\n", gps->longitude);
    printf("Altitude: %f\n", gps->altitude);
    printf("Speed: %f\n", gps->speed);
    printf("Heading: %f\n", gps->heading);
    printf("Nearest location: %s\n", nearest_location);
}

// Main function
int main() {
    // Create a new GPS navigation system
    GPS *gps = new_gps();

    // Create a new map of the world
    Map *map = new_map();

    // Add some locations to the map
    add_location(map, 40.7128, -74.0059, "New York City");
    add_location(map, 37.7749, -122.4194, "San Francisco");
    add_location(map, 34.0522, -118.2437, "Los Angeles");
    add_location(map, 30.2672, -97.7431, "Austin");
    add_location(map, 29.7604, -95.3698, "Houston");

    // Simulate the GPS navigation system
    for (int i = 0; i < 1000; i++) {
        simulate_gps(gps, map);
    }

    // Destroy the GPS navigation system and the map
    destroy_gps(gps);
    destroy_map(map);

    return 0;
}