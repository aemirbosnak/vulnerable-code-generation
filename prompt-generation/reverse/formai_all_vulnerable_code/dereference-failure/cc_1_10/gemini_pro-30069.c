//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: sophisticated
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

// Define the structure of a route
typedef struct route {
    int num_waypoints;
    waypoint *waypoints;
} route;

// Create a new waypoint
waypoint *create_waypoint(double latitude, double longitude, char *name) {
    waypoint *wp = malloc(sizeof(waypoint));
    wp->latitude = latitude;
    wp->longitude = longitude;
    wp->name = name;
    return wp;
}

// Create a new route
route *create_route() {
    route *r = malloc(sizeof(route));
    r->num_waypoints = 0;
    r->waypoints = NULL;
    return r;
}

// Add a waypoint to a route
void add_waypoint(route *r, waypoint *wp) {
    r->waypoints = realloc(r->waypoints, (r->num_waypoints + 1) * sizeof(waypoint));
    r->waypoints[r->num_waypoints] = *wp;
    r->num_waypoints++;
}

// Print a waypoint
void print_waypoint(waypoint *wp) {
    printf("Latitude: %f\n", wp->latitude);
    printf("Longitude: %f\n", wp->longitude);
    printf("Name: %s\n", wp->name);
}

// Print a route
void print_route(route *r) {
    for (int i = 0; i < r->num_waypoints; i++) {
        print_waypoint(&r->waypoints[i]);
    }
}

// Simulate GPS navigation
void simulate_gps(route *r) {
    // Initialize the GPS simulation
    srand(time(NULL));
    double latitude = r->waypoints[0].latitude;
    double longitude = r->waypoints[0].longitude;
    int current_waypoint = 0;

    // Simulate the GPS navigation loop
    while (current_waypoint < r->num_waypoints) {
        // Get the next waypoint
        waypoint *next_wp = &r->waypoints[current_waypoint + 1];

        // Calculate the distance to the next waypoint
        double distance = sqrt(pow(next_wp->latitude - latitude, 2) + pow(next_wp->longitude - longitude, 2));

        // Simulate the GPS error
        double error = (double)rand() / RAND_MAX;
        distance += error * 0.1;

        // Simulate the GPS update
        latitude += (next_wp->latitude - latitude) / distance;
        longitude += (next_wp->longitude - longitude) / distance;

        // Print the GPS update
        printf("Latitude: %f\n", latitude);
        printf("Longitude: %f\n", longitude);

        // Increment the current waypoint
        current_waypoint++;
    }
}

// Main function
int main() {
    // Create a new route
    route *r = create_route();

    // Add waypoints to the route
    add_waypoint(r, create_waypoint(40.7128, -74.0059, "Times Square"));
    add_waypoint(r, create_waypoint(40.7068, -73.9986, "Empire State Building"));
    add_waypoint(r, create_waypoint(40.7124, -73.9780, "Statue of Liberty"));

    // Print the route
    print_route(r);

    // Simulate GPS navigation
    simulate_gps(r);

    // Free the route
    free(r->waypoints);
    free(r);

    return 0;
}