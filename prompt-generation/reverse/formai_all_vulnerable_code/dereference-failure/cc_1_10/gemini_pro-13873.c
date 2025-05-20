//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STOPS 10
#define MAX_ROUTE_LENGTH 100

typedef struct {
    double latitude;
    double longitude;
    char name[32];
} Stop;

typedef struct {
    Stop stops[MAX_STOPS];
    int num_stops;
    int current_stop;
} Route;

// Function to create a new route
Route* create_route() {
    Route* route = malloc(sizeof(Route));
    route->num_stops = 0;
    route->current_stop = -1;
    return route;
}

// Function to add a stop to a route
void add_stop(Route* route, double latitude, double longitude, char* name) {
    if (route->num_stops < MAX_STOPS) {
        route->stops[route->num_stops].latitude = latitude;
        route->stops[route->num_stops].longitude = longitude;
        strcpy(route->stops[route->num_stops].name, name);
        route->num_stops++;
    } else {
        printf("Error: Maximum number of stops reached\n");
    }
}

// Function to get the current stop of a route
Stop* get_current_stop(Route* route) {
    if (route->current_stop >= 0 && route->current_stop < route->num_stops) {
        return &route->stops[route->current_stop];
    } else {
        printf("Error: Invalid current stop\n");
        return NULL;
    }
}

// Function to set the current stop of a route
void set_current_stop(Route* route, int stop_index) {
    if (stop_index >= 0 && stop_index < route->num_stops) {
        route->current_stop = stop_index;
    } else {
        printf("Error: Invalid stop index\n");
    }
}

// Function to simulate GPS navigation
void navigate(Route* route) {
    Stop* current_stop;

    while ((current_stop = get_current_stop(route)) != NULL) {
        printf("Current stop: %s (%.6f, %.6f)\n", current_stop->name, current_stop->latitude, current_stop->longitude);

        // Simulate driving to the next stop
        set_current_stop(route, route->current_stop + 1);
    }

    printf("Destination reached\n");
}

// Main function
int main() {
    // Create a new route
    Route* route = create_route();

    // Add some stops to the route
    add_stop(route, 40.748440, -73.985664, "Times Square");
    add_stop(route, 40.705116, -74.016088, "Soho");
    add_stop(route, 40.689655, -73.996575, "Washington Square Park");
    add_stop(route, 40.730610, -73.985192, "Empire State Building");
    add_stop(route, 40.706445, -74.014450, "Little Italy");

    // Simulate GPS navigation
    navigate(route);

    // Free the memory allocated for the route
    free(route);

    return 0;
}