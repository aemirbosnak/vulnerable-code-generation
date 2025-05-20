//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Define the GPS data structure
typedef struct gps {
    double latitude;
    double longitude;
    double altitude;
} gps_t;

// Create a new GPS object
gps_t *gps_new() {
    gps_t *gps = malloc(sizeof(gps_t));
    if (gps == NULL) {
        return NULL;
    }

    gps->latitude = 0.0;
    gps->longitude = 0.0;
    gps->altitude = 0.0;

    return gps;
}

// Free the GPS object
void gps_free(gps_t *gps) {
    free(gps);
}

// Set the GPS data
void gps_set_data(gps_t *gps, double latitude, double longitude, double altitude) {
    gps->latitude = latitude;
    gps->longitude = longitude;
    gps->altitude = altitude;
}

// Get the GPS data
void gps_get_data(gps_t *gps, double *latitude, double *longitude, double *altitude) {
    *latitude = gps->latitude;
    *longitude = gps->longitude;
    *altitude = gps->altitude;
}

// Print the GPS data
void gps_print_data(gps_t *gps) {
    printf("Latitude: %f\n", gps->latitude);
    printf("Longitude: %f\n", gps->longitude);
    printf("Altitude: %f\n", gps->altitude);
}

// Simulate the GPS by generating random data
void gps_simulate(gps_t *gps) {
    gps->latitude += (rand() % 100) / 100000.0;
    gps->longitude += (rand() % 100) / 100000.0;
    gps->altitude += (rand() % 10) / 100.0;
}

// The main function
int main() {
    // Create a new GPS object
    gps_t *gps = gps_new();

    // Simulate the GPS for 10 seconds
    for (int i = 0; i < 10; i++) {
        gps_simulate(gps);

        // Print the GPS data
        gps_print_data(gps);

        // Sleep for 1 second
        sleep(1);
    }

    // Free the GPS object
    gps_free(gps);

    return 0;
}