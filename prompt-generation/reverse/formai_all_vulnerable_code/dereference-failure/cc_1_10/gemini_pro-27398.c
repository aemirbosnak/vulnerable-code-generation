//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the Earth's radius in meters
#define EARTH_RADIUS 6371000.0

// Define the maximum number of waypoints
#define MAX_WAYPOINTS 100

// Define the structure of a waypoint
typedef struct {
    double latitude;
    double longitude;
} waypoint_t;

// Define the structure of a route
typedef struct {
    int num_waypoints;
    waypoint_t waypoints[MAX_WAYPOINTS];
} route_t;

// Create a new route
route_t* create_route() {
    route_t* route = malloc(sizeof(route_t));
    route->num_waypoints = 0;
    return route;
}

// Add a waypoint to a route
void add_waypoint(route_t* route, waypoint_t waypoint) {
    route->waypoints[route->num_waypoints] = waypoint;
    route->num_waypoints++;
}

// Calculate the distance between two waypoints
double calculate_distance(waypoint_t waypoint1, waypoint_t waypoint2) {
    // Convert the latitudes and longitudes to radians
    double lat1 = waypoint1.latitude * M_PI / 180.0;
    double lon1 = waypoint1.longitude * M_PI / 180.0;
    double lat2 = waypoint2.latitude * M_PI / 180.0;
    double lon2 = waypoint2.longitude * M_PI / 180.0;

    // Calculate the difference in latitudes and longitudes
    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;

    // Calculate the distance using the Haversine formula
    double a = pow(sin(dlat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(dlon / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distance = EARTH_RADIUS * c;

    return distance;
}

// Calculate the total distance of a route
double calculate_total_distance(route_t* route) {
    double total_distance = 0.0;
    for (int i = 1; i < route->num_waypoints; i++) {
        total_distance += calculate_distance(route->waypoints[i - 1], route->waypoints[i]);
    }
    return total_distance;
}

// Print the waypoints of a route
void print_route(route_t* route) {
    printf("Route:\n");
    for (int i = 0; i < route->num_waypoints; i++) {
        printf("Waypoint %d: (%f, %f)\n", i + 1, route->waypoints[i].latitude, route->waypoints[i].longitude);
    }
}

// Main function
int main() {
    // Create a new route
    route_t* route = create_route();

    // Add some waypoints to the route
    waypoint_t waypoint1 = {37.7749, -122.4194};
    waypoint_t waypoint2 = {37.7633, -122.4222};
    waypoint_t waypoint3 = {37.7519, -122.4324};
    add_waypoint(route, waypoint1);
    add_waypoint(route, waypoint2);
    add_waypoint(route, waypoint3);

    // Print the waypoints of the route
    print_route(route);

    // Calculate the total distance of the route
    double total_distance = calculate_total_distance(route);

    // Print the total distance of the route
    printf("Total distance: %f meters\n", total_distance);

    return 0;
}