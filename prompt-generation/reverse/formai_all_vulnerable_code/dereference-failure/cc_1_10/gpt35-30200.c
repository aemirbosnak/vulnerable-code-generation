//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Constants definition
#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371.0

// Struct definition
typedef struct {
    char name[50];
    double latitude_degrees;
    double longitude_degrees;
} Waypoint;

// Function prototypes
void read_waypoints(Waypoint *waypoints, int count);
double degrees_to_radians(double degrees);
double calculate_distance_between_waypoints(Waypoint waypoint1, Waypoint waypoint2);
void show_navigation_directions(Waypoint *waypoints, int count);

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Please specify the number of waypoints\n");
        return 1;
    }

    int count = atoi(argv[1]);
    Waypoint waypoints[count];

    // Read waypoints information
    read_waypoints(waypoints, count);

    // Show navigation directions
    show_navigation_directions(waypoints, count);

    return 0;
}

// Function to read waypoints information
void read_waypoints(Waypoint *waypoints, int count) {
    for (int i = 0; i < count; i++) {
        printf("Enter name for waypoint %d: ", i+1);
        scanf("%s", waypoints[i].name);

        printf("Enter latitude for waypoint %d (in degrees): ", i+1);
        scanf("%lf", &waypoints[i].latitude_degrees);

        printf("Enter longitude for waypoint %d (in degrees): ", i+1);
        scanf("%lf", &waypoints[i].longitude_degrees);

        printf("\n");
    }
}

// Function to convert degrees to radians
double degrees_to_radians(double degrees) {
    return degrees * PI / 180.0;
}

// Function to calculate distance between two waypoints
double calculate_distance_between_waypoints(Waypoint waypoint1, Waypoint waypoint2) {
    double lat1_rad = degrees_to_radians(waypoint1.latitude_degrees);
    double long1_rad = degrees_to_radians(waypoint1.longitude_degrees);
    double lat2_rad = degrees_to_radians(waypoint2.latitude_degrees);
    double long2_rad = degrees_to_radians(waypoint2.longitude_degrees);

    double d_lat = lat2_rad - lat1_rad;
    double d_long = long2_rad - long1_rad;

    double a = sin(d_lat/2) * sin(d_lat/2) + cos(lat1_rad) * cos(lat2_rad) * sin(d_long/2) * sin(d_long/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double distance = EARTH_RADIUS * c;

    return distance;
}

// Function to show navigation directions
void show_navigation_directions(Waypoint *waypoints, int count) {

    printf("===================================================\n");
    printf("                  NAVIGATION DIRECTIONS             \n");
    printf("===================================================\n");

    double total_distance = 0;
    Waypoint previous_waypoint = waypoints[0];

    for (int i = 1; i < count; i++) {
        Waypoint current_waypoint = waypoints[i];
        double distance = calculate_distance_between_waypoints(previous_waypoint, current_waypoint);
        total_distance += distance;

        printf("From %s, go straight %.1f km to %s\n", previous_waypoint.name, distance, current_waypoint.name);

        previous_waypoint = current_waypoint;
    }

    printf("Total distance: %.1f km\n", total_distance);
}