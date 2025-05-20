//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_WAYPOINTS 100
#define RADIUS_EARTH 6371 // Radius of Earth in km

typedef struct {
    double latitude;
    double longitude;
} Waypoint;

typedef struct {
    Waypoint waypoints[MAX_WAYPOINTS];
    int count;
    int current_index;
    sem_t semaphore;
} NavigationData;

NavigationData nav_data;

void* gps_listener(void* arg) {
    // Simulating GPS updates every 2 seconds
    while (1) {
        sem_wait(&nav_data.semaphore);
        nav_data.current_index = (nav_data.current_index + 1) % nav_data.count;
        printf("GPS Listener: Current Waypoint: (%.5f, %.5f)\n",
               nav_data.waypoints[nav_data.current_index].latitude,
               nav_data.waypoints[nav_data.current_index].longitude);
        sem_post(&nav_data.semaphore);
        sleep(2);
    }
    return NULL;
}

double degrees_to_radians(double degrees) {
    return degrees * (M_PI / 180.0);
}

double calculate_distance(Waypoint p1, Waypoint p2) {
    double lat1 = degrees_to_radians(p1.latitude);
    double lat2 = degrees_to_radians(p2.latitude);
    double dlat = degrees_to_radians(p2.latitude - p1.latitude);
    double dlon = degrees_to_radians(p2.longitude - p1.longitude);

    double a = sin(dlat/2) * sin(dlat/2) +
               cos(lat1) * cos(lat2) *
               sin(dlon/2) * sin(dlon/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));

    return RADIUS_EARTH * c; // Distance in km
}

void* route_manager(void* arg) {
    Waypoint destination;
    printf("Set a destination (latitude longitude): ");
    scanf("%lf %lf", &destination.latitude, &destination.longitude);

    while (1) {
        sem_wait(&nav_data.semaphore);
        double distance = calculate_distance(nav_data.waypoints[nav_data.current_index], destination);
        printf("Route Manager: Distance to destination (%.5f, %.5f): %.2f km\n",
               destination.latitude, destination.longitude, distance);
        sem_post(&nav_data.semaphore);
        sleep(5);
    }
    return NULL;
}

void* waypoint_adder(void* arg) {
    while (1) {
        if (nav_data.count >= MAX_WAYPOINTS) {
            printf("Waypoint list is full!\n");
            break;
        }
        double latitude, longitude;
        printf("Add a waypoint (latitude longitude): ");
        scanf("%lf %lf", &latitude, &longitude);
        
        sem_wait(&nav_data.semaphore);
        nav_data.waypoints[nav_data.count].latitude = latitude;
        nav_data.waypoints[nav_data.count].longitude = longitude;
        nav_data.count++;
        printf("Waypoint added: (%.5f, %.5f), Total waypoints: %d\n",
               latitude, longitude, nav_data.count);
        sem_post(&nav_data.semaphore);
    }
    return NULL;
}

int main() {
    pthread_t gps_thread, manager_thread, adder_thread;
    nav_data.count = 0;
    nav_data.current_index = 0;
    sem_init(&nav_data.semaphore, 0, 1);

    // Create threads for GPS listener, route manager, and waypoint adder.
    pthread_create(&gps_thread, NULL, gps_listener, NULL);
    pthread_create(&manager_thread, NULL, route_manager, NULL);
    pthread_create(&adder_thread, NULL, waypoint_adder, NULL);
    
    // Join threads to the main thread.
    pthread_join(adder_thread, NULL); // Wait for the waypoint adder to finish.
    
    // Cancel other threads
    pthread_cancel(gps_thread);
    pthread_cancel(manager_thread);

    sem_destroy(&nav_data.semaphore);
    return 0;
}