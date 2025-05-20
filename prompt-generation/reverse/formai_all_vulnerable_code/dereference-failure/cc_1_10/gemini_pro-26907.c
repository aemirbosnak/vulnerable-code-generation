//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

#define EARTH_RADIUS 6371.0 // kilometers

// Structure to represent a GPS coordinate
typedef struct {
    double latitude;
    double longitude;
} GPS_Coordinate;

// Structure to represent a GPS device
typedef struct {
    GPS_Coordinate current_location;
    pthread_mutex_t lock;
} GPS_Device;

// Mutex to protect shared data
pthread_mutex_t shared_data_lock;

// Array of GPS devices
GPS_Device *gps_devices[10];

// Function to calculate the distance between two GPS coordinates
double calculate_distance(GPS_Coordinate coord1, GPS_Coordinate coord2) {
    double lat1 = coord1.latitude;
    double lon1 = coord1.longitude;
    double lat2 = coord2.latitude;
    double lon2 = coord2.longitude;

    // Convert degrees to radians
    lat1 = lat1 * M_PI / 180.0;
    lon1 = lon1 * M_PI / 180.0;
    lat2 = lat2 * M_PI / 180.0;
    lon2 = lon2 * M_PI / 180.0;

    // Calculate the distance using the Haversine formula
    double dlon = lon2 - lon1;
    double dlat = lat2 - lat1;
    double a = pow(sin(dlat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(dlon / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return EARTH_RADIUS * c; // Distance in kilometers
}

// Function to simulate the movement of a GPS device
void *move_gps_device(void *arg) {
    GPS_Device *gps_device = (GPS_Device *)arg;

    while (1) {
        // Acquire the lock to protect shared data
        pthread_mutex_lock(&shared_data_lock);

        // Generate a random movement
        double delta_lat = (double)rand() / RAND_MAX * 0.1;
        double delta_lon = (double)rand() / RAND_MAX * 0.1;

        // Update the current location
        gps_device->current_location.latitude += delta_lat;
        gps_device->current_location.longitude += delta_lon;

        // Release the lock
        pthread_mutex_unlock(&shared_data_lock);

        // Sleep for a random amount of time
        usleep((double)rand() / RAND_MAX * 1000000);
    }

    return NULL;
}

// Function to simulate the GPS navigation system
void gps_navigation_system() {
    // Initialize the GPS devices
    for (int i = 0; i < 10; i++) {
        gps_devices[i] = malloc(sizeof(GPS_Device));
        pthread_mutex_init(&gps_devices[i]->lock, NULL);
        gps_devices[i]->current_location.latitude = 0.0;
        gps_devices[i]->current_location.longitude = 0.0;
    }

    // Initialize the shared data lock
    pthread_mutex_init(&shared_data_lock, NULL);

    // Create threads to simulate the movement of the GPS devices
    pthread_t threads[10];
    for (int i = 0; i < 10; i++) {
        pthread_create(&threads[i], NULL, move_gps_device, gps_devices[i]);
    }

    // Main loop of the GPS navigation system
    while (1) {
        // Acquire the lock to protect shared data
        pthread_mutex_lock(&shared_data_lock);

        // Calculate the distance between each pair of GPS devices
        for (int i = 0; i < 10; i++) {
            for (int j = i + 1; j < 10; j++) {
                double distance = calculate_distance(gps_devices[i]->current_location, gps_devices[j]->current_location);
                printf("Distance between GPS devices %d and %d: %.2f kilometers\n", i, j, distance);
            }
        }

        // Release the lock
        pthread_mutex_unlock(&shared_data_lock);

        // Sleep for a second
        sleep(1);
    }

    // Join the threads
    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy the shared data lock
    pthread_mutex_destroy(&shared_data_lock);

    // Free the GPS devices
    for (int i = 0; i < 10; i++) {
        pthread_mutex_destroy(&gps_devices[i]->lock);
        free(gps_devices[i]);
    }
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Start the GPS navigation system
    gps_navigation_system();

    return 0;
}