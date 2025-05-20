//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of waypoints
#define MAX_WAYPOINTS 100

// Define the structure of a waypoint
typedef struct waypoint {
    double latitude;
    double longitude;
    char* name;
} waypoint_t;

// Define the structure of the GPS navigation system
typedef struct gps_navigation_system {
    waypoint_t waypoints[MAX_WAYPOINTS];
    int num_waypoints;
} gps_navigation_system_t;

// Create a new GPS navigation system
gps_navigation_system_t* gps_navigation_system_new() {
    gps_navigation_system_t* gps_navigation_system = malloc(sizeof(gps_navigation_system_t));
    gps_navigation_system->num_waypoints = 0;
    return gps_navigation_system;
}

// Add a waypoint to the GPS navigation system
void gps_navigation_system_add_waypoint(gps_navigation_system_t* gps_navigation_system, double latitude, double longitude, char* name) {
    gps_navigation_system->waypoints[gps_navigation_system->num_waypoints].latitude = latitude;
    gps_navigation_system->waypoints[gps_navigation_system->num_waypoints].longitude = longitude;
    gps_navigation_system->waypoints[gps_navigation_system->num_waypoints].name = name;
    gps_navigation_system->num_waypoints++;
}

// Get the waypoint at a given index
waypoint_t* gps_navigation_system_get_waypoint(gps_navigation_system_t* gps_navigation_system, int index) {
    return &gps_navigation_system->waypoints[index];
}

// Get the number of waypoints in the GPS navigation system
int gps_navigation_system_get_num_waypoints(gps_navigation_system_t* gps_navigation_system) {
    return gps_navigation_system->num_waypoints;
}

// Print the GPS navigation system to the console
void gps_navigation_system_print(gps_navigation_system_t* gps_navigation_system) {
    printf("GPS Navigation System:\n");
    for (int i = 0; i < gps_navigation_system->num_waypoints; i++) {
        waypoint_t* waypoint = gps_navigation_system_get_waypoint(gps_navigation_system, i);
        printf("  - %s (%.6f, %.6f)\n", waypoint->name, waypoint->latitude, waypoint->longitude);
    }
}

// Free the memory allocated for the GPS navigation system
void gps_navigation_system_free(gps_navigation_system_t* gps_navigation_system) {
    for (int i = 0; i < gps_navigation_system->num_waypoints; i++) {
        free(gps_navigation_system->waypoints[i].name);
    }
    free(gps_navigation_system);
}

// Main function
int main() {
    // Create a new GPS navigation system
    gps_navigation_system_t* gps_navigation_system = gps_navigation_system_new();

    // Add some waypoints to the GPS navigation system
    gps_navigation_system_add_waypoint(gps_navigation_system, 40.7127, -74.0059, "New York City");
    gps_navigation_system_add_waypoint(gps_navigation_system, 37.7749, -122.4194, "San Francisco");
    gps_navigation_system_add_waypoint(gps_navigation_system, 48.8582, 2.2945, "Paris");
    gps_navigation_system_add_waypoint(gps_navigation_system, 51.5074, -0.1278, "London");
    gps_navigation_system_add_waypoint(gps_navigation_system, 41.8902, 12.4923, "Rome");

    // Print the GPS navigation system to the console
    gps_navigation_system_print(gps_navigation_system);

    // Free the memory allocated for the GPS navigation system
    gps_navigation_system_free(gps_navigation_system);

    return 0;
}