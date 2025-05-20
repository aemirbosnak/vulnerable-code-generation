//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the structure of a waypoint
typedef struct waypoint {
    double latitude;
    double longitude;
    char name[50];
} waypoint;

// Define the structure of a route
typedef struct route {
    int num_waypoints;
    waypoint *waypoints;
} route;

// Define the structure of a GPS device
typedef struct gps {
    double latitude;
    double longitude;
    route *route;
    int current_waypoint;
} gps;

// Create a new waypoint
waypoint *create_waypoint(double latitude, double longitude, char *name) {
    waypoint *w = (waypoint *)malloc(sizeof(waypoint));
    w->latitude = latitude;
    w->longitude = longitude;
    strcpy(w->name, name);
    return w;
}

// Create a new route
route *create_route(int num_waypoints, waypoint *waypoints) {
    route *r = (route *)malloc(sizeof(route));
    r->num_waypoints = num_waypoints;
    r->waypoints = waypoints;
    return r;
}

// Create a new GPS device
gps *create_gps(double latitude, double longitude, route *route) {
    gps *g = (gps *)malloc(sizeof(gps));
    g->latitude = latitude;
    g->longitude = longitude;
    g->route = route;
    g->current_waypoint = 0;
    return g;
}

// Calculate the distance between two waypoints
double distance_between_waypoints(waypoint *w1, waypoint *w2) {
    double dx = w2->longitude - w1->longitude;
    double dy = w2->latitude - w1->latitude;
    return sqrt(dx * dx + dy * dy);
}

// Calculate the bearing between two waypoints
double bearing_between_waypoints(waypoint *w1, waypoint *w2) {
    double dx = w2->longitude - w1->longitude;
    double dy = w2->latitude - w1->latitude;
    return atan2(dy, dx);
}

// Navigate to the next waypoint
void navigate_to_next_waypoint(gps *g) {
    // Calculate the distance to the next waypoint
    double distance = distance_between_waypoints(&g->route->waypoints[g->current_waypoint], &g->route->waypoints[g->current_waypoint + 1]);

    // Calculate the bearing to the next waypoint
    double bearing = bearing_between_waypoints(&g->route->waypoints[g->current_waypoint], &g->route->waypoints[g->current_waypoint + 1]);

    // Update the GPS device's position
    g->latitude += distance * sin(bearing);
    g->longitude += distance * cos(bearing);

    // Increment the current waypoint index
    g->current_waypoint++;

    // If we have reached the end of the route, stop navigating
    if (g->current_waypoint == g->route->num_waypoints) {
        printf("You have reached your destination!\n");
        return;
    }

    // Otherwise, navigate to the next waypoint
    navigate_to_next_waypoint(g);
}

// Print the GPS device's current position
void print_gps_position(gps *g) {
    printf("Current position: %.6f, %.6f\n", g->latitude, g->longitude);
}

// Main function
int main() {
    // Create a new route
    route *route = create_route(3, (waypoint *[]){
        create_waypoint(40.7127, -74.0059, "Times Square"),
        create_waypoint(40.7068, -74.0128, "Empire State Building"),
        create_waypoint(40.6995, -73.9968, "Statue of Liberty"),
    });

    // Create a new GPS device
    gps *gps = create_gps(40.7127, -74.0059, route);

    // Navigate to the next waypoint
    navigate_to_next_waypoint(gps);

    // Print the GPS device's current position
    print_gps_position(gps);

    return 0;
}