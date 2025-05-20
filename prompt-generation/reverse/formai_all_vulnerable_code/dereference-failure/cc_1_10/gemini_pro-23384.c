//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    double lat;
    double lon;
} Coordinate;

typedef struct {
    Coordinate start;
    Coordinate end;
} Route;

typedef struct {
    Route* routes;
    int num_routes;
} NavigationData;

// Generate a random route
Route generate_route() {
    Route route;
    route.start.lat = (double)rand() / (double)RAND_MAX;
    route.start.lon = (double)rand() / (double)RAND_MAX;
    route.end.lat = (double)rand() / (double)RAND_MAX;
    route.end.lon = (double)rand() / (double)RAND_MAX;
    return route;
}

// Plot a course on a map
void plot_course(Route route) {
    printf("Starting at: (%f, %f)\n", route.start.lat, route.start.lon);
    printf("Ending at: (%f, %f)\n", route.end.lat, route.end.lon);
}

// Get directions from start to end
void get_directions(Coordinate start, Coordinate end) {
    printf("Turn left at the next intersection.\n");
    printf("Turn right at the second intersection.\n");
    printf("You have arrived at your destination.\n");
}

// Main function
int main() {
    srand(time(NULL));

    // Create a navigation data structure
    NavigationData data;
    data.num_routes = 10;
    data.routes = malloc(sizeof(Route) * data.num_routes);

    // Generate random routes
    for (int i = 0; i < data.num_routes; i++) {
        data.routes[i] = generate_route();
    }

    // Plot the first route
    plot_course(data.routes[0]);

    // Get directions from the start to end of the first route
    get_directions(data.routes[0].start, data.routes[0].end);

    return 0;
}