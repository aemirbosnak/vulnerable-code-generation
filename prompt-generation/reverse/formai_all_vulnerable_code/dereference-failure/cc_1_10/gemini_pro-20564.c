//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WAYPOINTS 1000
#define MAX_LENGTH 100

typedef struct {
    char name[MAX_LENGTH];
    double latitude;
    double longitude;
} Waypoint;

typedef struct {
    int num_waypoints;
    Waypoint waypoints[MAX_WAYPOINTS];
} Route;

char* input_get_line(void) {
    char* line = NULL;
    size_t len = 0;
    ssize_t nread;
    nread = getline(&line, &len, stdin);
    if (nread == -1) {
        free(line);
        return NULL;
    }
    if (nread > 0 && line[nread - 1] == '\n') {
        line[nread - 1] = '\0';
    }
    return line;
}

Route* input_get_route(void) {
    Route* route = malloc(sizeof(Route));
    if (route == NULL) {
        return NULL;
    }
    route->num_waypoints = 0;
    char* line = input_get_line();
    while (line != NULL && strlen(line) > 0) {
        Waypoint waypoint;
        sscanf(line, "%s %lf %lf", waypoint.name, &waypoint.latitude, &waypoint.longitude);
        route->waypoints[route->num_waypoints++] = waypoint;
        free(line);
        line = input_get_line();
    }
    free(line);
    return route;
}

void output_route(Route* route) {
    for (int i = 0; i < route->num_waypoints; i++) {
        printf("%s %.6lf %.6lf\n", route->waypoints[i].name, route->waypoints[i].latitude, route->waypoints[i].longitude);
    }
}

int main(void) {
    Route* route = input_get_route();
    if (route == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for route.\n");
        return EXIT_FAILURE;
    }
    output_route(route);
    free(route);
    return EXIT_SUCCESS;
}