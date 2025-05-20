//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of waypoints
#define MAX_WAYPOINTS 100

// Define the structure of a waypoint
typedef struct waypoint {
    double latitude;
    double longitude;
    char *name;
} waypoint;

// Define the function to generate a random waypoint
waypoint generate_waypoint() {
    // Generate a random latitude between -90 and 90 degrees
    double latitude = (double)rand() / (double)RAND_MAX * 180 - 90;

    // Generate a random longitude between -180 and 180 degrees
    double longitude = (double)rand() / (double)RAND_MAX * 360 - 180;

    // Generate a random name for the waypoint
    char *name = malloc(10);
    for (int i = 0; i < 10; i++) {
        name[i] = (char)((int)'A' + (rand() % 26));
    }

    // Return the waypoint
    return (waypoint){latitude, longitude, name};
}

// Define the function to print a waypoint
void print_waypoint(waypoint waypoint) {
    printf("Latitude: %.6f\n", waypoint.latitude);
    printf("Longitude: %.6f\n", waypoint.longitude);
    printf("Name: %s\n", waypoint.name);
}

// Define the function to simulate GPS navigation
void navigate(waypoint *waypoints, int num_waypoints, int current_waypoint) {
    // If we have reached the final waypoint, stop navigating
    if (current_waypoint == num_waypoints) {
        printf("Destination reached!\n");
        return;
    }

    // Get the current waypoint
    waypoint current = waypoints[current_waypoint];

    // Print the current waypoint
    printf("Current waypoint:\n");
    print_waypoint(current);

    // Get the next waypoint
    waypoint next = waypoints[current_waypoint + 1];

    // Calculate the distance to the next waypoint
    double distance = sqrt(pow(next.latitude - current.latitude, 2) + pow(next.longitude - current.longitude, 2));

    // Print the distance to the next waypoint
    printf("Distance to next waypoint: %.2f km\n", distance);

    // Simulate driving to the next waypoint
    printf("Driving to next waypoint...\n");
    sleep(distance / 100);

    // Recursively call the navigate function to continue navigating
    navigate(waypoints, num_waypoints, current_waypoint + 1);
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a random set of waypoints
    waypoint waypoints[MAX_WAYPOINTS];
    for (int i = 0; i < MAX_WAYPOINTS; i++) {
        waypoints[i] = generate_waypoint();
    }

    // Print the waypoints
    printf("Waypoints:\n");
    for (int i = 0; i < MAX_WAYPOINTS; i++) {
        print_waypoint(waypoints[i]);
    }

    // Simulate GPS navigation
    navigate(waypoints, MAX_WAYPOINTS, 0);

    return 0;
}