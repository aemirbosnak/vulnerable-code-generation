//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_LOCATIONS 10
#define MAX_ROUTES 5

typedef struct {
    char *name;
    double latitude;
    double longitude;
} Location;

typedef struct {
    Location *start;
    Location *end;
    double distance;
    double time;
} Route;

// Create a new location
Location *create_location(char *name, double latitude, double longitude) {
    Location *location = malloc(sizeof(Location));
    location->name = name;
    location->latitude = latitude;
    location->longitude = longitude;
    return location;
}

// Create a new route
Route *create_route(Location *start, Location *end, double distance, double time) {
    Route *route = malloc(sizeof(Route));
    route->start = start;
    route->end = end;
    route->distance = distance;
    route->time = time;
    return route;
}

// Calculate the distance between two locations
double calculate_distance(Location *start, Location *end) {
    double lat1 = start->latitude;
    double lon1 = start->longitude;
    double lat2 = end->latitude;
    double lon2 = end->longitude;
    
    double dLat = (lat2 - lat1) * M_PI / 180;
    double dLon = (lon2 - lon1) * M_PI / 180;
    
    double a = sin(dLat / 2) * sin(dLat / 2) +
               cos(lat1 * M_PI / 180) * cos(lat2 * M_PI / 180) *
               sin(dLon / 2) * sin(dLon / 2);
    
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    
    double distance = 6371 * c;
    
    return distance;
}

// Calculate the time it takes to travel a route
double calculate_time(Route *route) {
    double distance = route->distance;
    double time = distance / 60;
    return time;
}

// Print the details of a location
void print_location(Location *location) {
    printf("Name: %s\n", location->name);
    printf("Latitude: %f\n", location->latitude);
    printf("Longitude: %f\n", location->longitude);
}

// Print the details of a route
void print_route(Route *route) {
    printf("Start: %s\n", route->start->name);
    printf("End: %s\n", route->end->name);
    printf("Distance: %f km\n", route->distance);
    printf("Time: %f hours\n", route->time);
}

// Main function
int main() {
    // Create locations
    Location *loc1 = create_location("Home", 40.7127, -74.0059);
    Location *loc2 = create_location("Work", 40.7051, -74.0112);
    Location *loc3 = create_location("School", 40.7295, -73.9965);
    Location *loc4 = create_location("Park", 40.7175, -74.0397);
    Location *loc5 = create_location("Mall", 40.7580, -73.9857);

    // Create routes
    Route *rte1 = create_route(loc1, loc2, 5, 0.5);
    Route *rte2 = create_route(loc2, loc3, 10, 1.0);
    Route *rte3 = create_route(loc3, loc4, 5, 0.5);
    Route *rte4 = create_route(loc4, loc5, 15, 1.5);
    Route *rte5 = create_route(loc5, loc1, 10, 1.0);

    // Print the details of all locations
    printf("Locations:\n");
    print_location(loc1);
    print_location(loc2);
    print_location(loc3);
    print_location(loc4);
    print_location(loc5);
    
    // Print the details of all routes
    printf("\nRoutes:\n");
    print_route(rte1);
    print_route(rte2);
    print_route(rte3);
    print_route(rte4);
    print_route(rte5);
    
    return 0;
}