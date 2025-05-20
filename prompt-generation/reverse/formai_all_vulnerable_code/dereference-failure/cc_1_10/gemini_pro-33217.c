//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SATELLITES 5
#define NUM_LOCATIONS 10

// Satellite data structure
typedef struct {
    char id;
    double x, y, z;
} Satellite;

// Location data structure
typedef struct {
    char id;
    double latitude, longitude, altitude;
} Location;

// Function to generate random satellite data
Satellite* generate_satellites(int num_satellites) {
    Satellite* satellites = malloc(sizeof(Satellite) * num_satellites);
    for (int i = 0; i < num_satellites; i++) {
        satellites[i].id = 'S' + i;
        satellites[i].x = rand() % 100000;
        satellites[i].y = rand() % 100000;
        satellites[i].z = rand() % 100000;
    }
    return satellites;
}

// Function to generate random location data
Location* generate_locations(int num_locations) {
    Location* locations = malloc(sizeof(Location) * num_locations);
    for (int i = 0; i < num_locations; i++) {
        locations[i].id = 'L' + i;
        locations[i].latitude = rand() % 90 - 90;
        locations[i].longitude = rand() % 180 - 180;
        locations[i].altitude = rand() % 1000;
    }
    return locations;
}

// Function to calculate the distance between two points in 3D space
double distance(double x1, double y1, double z1, double x2, double y2, double z2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2));
}

// Function to simulate GPS navigation
Location* gps_navigation(Satellite* satellites, Location* locations, int num_satellites, int num_locations) {
    // Calculate the distance between each satellite and each location
    double distances[num_satellites][num_locations];
    for (int i = 0; i < num_satellites; i++) {
        for (int j = 0; j < num_locations; j++) {
            distances[i][j] = distance(satellites[i].x, satellites[i].y, satellites[i].z, locations[j].latitude, locations[j].longitude, locations[j].altitude);
        }
    }

    // Find the closest satellite to each location
    int closest_satellites[num_locations];
    for (int i = 0; i < num_locations; i++) {
        double min_distance = distances[0][i];
        int closest_satellite = 0;
        for (int j = 1; j < num_satellites; j++) {
            if (distances[j][i] < min_distance) {
                min_distance = distances[j][i];
                closest_satellite = j;
            }
        }
        closest_satellites[i] = closest_satellite;
    }

    // Calculate the location using the closest satellites
    Location* estimated_locations = malloc(sizeof(Location) * num_locations);
    for (int i = 0; i < num_locations; i++) {
        estimated_locations[i] = locations[closest_satellites[i]];
    }

    return estimated_locations;
}

int main() {
    // Initialize random seed
    srand(time(NULL));

    // Generate satellite and location data
    Satellite* satellites = generate_satellites(NUM_SATELLITES);
    Location* locations = generate_locations(NUM_LOCATIONS);

    // Simulate GPS navigation
    Location* estimated_locations = gps_navigation(satellites, locations, NUM_SATELLITES, NUM_LOCATIONS);

    // Print the estimated locations
    for (int i = 0; i < NUM_LOCATIONS; i++) {
        printf("Location %c:\n", estimated_locations[i].id);
        printf("Latitude: %f\n", estimated_locations[i].latitude);
        printf("Longitude: %f\n", estimated_locations[i].longitude);
        printf("Altitude: %f\n\n", estimated_locations[i].altitude);
    }

    // Free the allocated memory
    free(satellites);
    free(locations);
    free(estimated_locations);

    return 0;
}