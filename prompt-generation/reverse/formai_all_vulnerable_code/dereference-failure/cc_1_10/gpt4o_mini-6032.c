//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_STEPS 100
#define EARTH_RADIUS 6371.0 // Radius of Earth in kilometers

typedef struct {
    double latitude;
    double longitude;
} Coordinate;

typedef struct {
    Coordinate *path;
    int stepCount;
} Route;

// Function to calculate distance between two coordinates
double calculateDistance(Coordinate src, Coordinate dest) {
    double lat1 = src.latitude * M_PI / 180.0;
    double lat2 = dest.latitude * M_PI / 180.0;
    double dLat = (dest.latitude - src.latitude) * M_PI / 180.0;
    double dLon = (dest.longitude - src.longitude) * M_PI / 180.0;

    double a = sin(dLat / 2) * sin(dLat / 2) +
               cos(lat1) * cos(lat2) * 
               sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return EARTH_RADIUS * c; // Distance in kilometers
}

// Function to create a route from the source to destination
Route createRoute(Coordinate src, Coordinate dest) {
    Route route;
    route.path = malloc(MAX_STEPS * sizeof(Coordinate));
    route.stepCount = 0;

    // For simplicity, we will create a linear path approximation
    for (int i = 0; i < MAX_STEPS; i++) {
        double ratio = (double) i / (MAX_STEPS - 1);
        route.path[i].latitude = src.latitude + ratio * (dest.latitude - src.latitude);
        route.path[i].longitude = src.longitude + ratio * (dest.longitude - src.longitude);
        route.stepCount++;
    }

    return route;
}

// Function to display current position
void displayCurrentPosition(Coordinate current, Coordinate destination) {
    printf("Current Position: (%.6f, %.6f)\n", current.latitude, current.longitude);
    printf("Destination: (%.6f, %.6f)\n", destination.latitude, destination.longitude);
}

int main() {
    Coordinate start, destination;
    
    printf("=== GPS Navigation Simulation ===\n");
    printf("Enter starting latitude: ");
    scanf("%lf", &start.latitude);
    printf("Enter starting longitude: ");
    scanf("%lf", &start.longitude);
    
    printf("Enter destination latitude: ");
    scanf("%lf", &destination.latitude);
    printf("Enter destination longitude: ");
    scanf("%lf", &destination.longitude);
    
    Route route = createRoute(start, destination);
    
    printf("Route created with %d steps.\n", route.stepCount);
    
    Coordinate current = start;
    int currentStep = 0;
    
    while (1) {
        displayCurrentPosition(current, destination);
        double distanceToDestination = calculateDistance(current, destination);
        
        if (distanceToDestination < 0.01) {
            printf("You have reached your destination!\n");
            break;
        }

        printf("Moving to the next step...\n");
        current = route.path[currentStep];
        currentStep++;
        
        if (currentStep >= route.stepCount) {
            printf("End of route.\n");
            break;
        }
        
        // Simulate a delay to mimic real-time movement
        sleep(1);
    }
    
    free(route.path);
    return 0;
}