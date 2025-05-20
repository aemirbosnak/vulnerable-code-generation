//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Global variables to store the current GPS location
double current_latitude = 0.0;
double current_longitude = 0.0;

void *get_gps_data(void *arg)
{
    // This thread simulates the GPS module and generates random data
    printf("Simulating GPS...\n");
    while (1)
    {
        // Generate random GPS data
        current_latitude = (double)(rand() % 180) - 90;
        current_longitude = (double)(rand() % 360) - 180;
        printf("Current latitude: %lf\n", current_latitude);
        printf("Current longitude: %lf\n", current_longitude);
        sleep(1);
    }
}

void *calculate_distance(void *arg)
{
    // This thread calculates the distance between the current location and a given destination
    double dest_latitude = *((double *) arg);
    double dest_longitude = *((double *)(arg + sizeof(double)));

    printf("Calculating distance...\n");
    while(1)
    {
        // Calculate the distance
        double delta_latitude = dest_latitude - current_latitude;
        double delta_longitude = dest_longitude - current_longitude;
        double distance = sqrt(delta_latitude * delta_latitude + delta_longitude * delta_longitude);
        printf("Distance to destination: %lf\n", distance);
        sleep(1);
    }
}

int main()
{
    // Initialize the GPS module and start collecting data
    pthread_t gps_thread;
    pthread_create(&gps_thread, NULL, get_gps_data, NULL);

    // Define a destination
    double dest_latitude = 45.5231;
    double dest_longitude = -122.6765;

    // Calculate the distance to the destination
    pthread_t distance_thread;
    double *args = (double *) malloc(2 * sizeof(double));
    args[0] = dest_latitude;
    args[1] = dest_longitude;
    pthread_create(&distance_thread, NULL, calculate_distance, (void *) args);

    // Wait for the threads to finish
    pthread_join(gps_thread, NULL);
    pthread_join(distance_thread, NULL);

    return 0;
}