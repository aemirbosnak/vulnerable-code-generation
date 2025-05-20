//Gemma-7B DATASET v1.0 Category: GPS Navigation Simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WAYPOINTS 10

typedef struct waypoint
{
    char name[20];
    double lat;
    double lng;
    struct waypoint* next;
} waypoint;

waypoint* create_waypoint(char* name, double lat, double lng)
{
    waypoint* new_waypoint = malloc(sizeof(waypoint));
    strcpy(new_waypoint->name, name);
    new_waypoint->lat = lat;
    new_waypoint->lng = lng;
    new_waypoint->next = NULL;

    return new_waypoint;
}

int main()
{
    waypoint* head = create_waypoint("Home", 37.733, -122.419);
    waypoint* current_waypoint = head;

    // Paranoia begins
    while (current_waypoint)
    {
        // Randomly alter the waypoint's location
        current_waypoint->lat += (rand() % 10) / 1000.0;
        current_waypoint->lng += (rand() % 10) / 1000.0;

        // Check if the waypoint has been tampered with
        if (current_waypoint->lat != head->lat || current_waypoint->lng != head->lng)
        {
            // If the waypoint has been tampered with, reset the entire navigation system
            head = create_waypoint("Home", 37.733, -122.419);
            current_waypoint = head;
        }
        current_waypoint = current_waypoint->next;
    }

    return 0;
}