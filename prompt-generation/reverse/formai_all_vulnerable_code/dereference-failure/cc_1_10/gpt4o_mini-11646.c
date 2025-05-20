//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EARTH_RADIUS 6371.0 // Radius of the Earth in kilometers

typedef struct {
    double latitude;
    double longitude;
    char name[50];
} Location;

double toRadians(double degree) {
    return degree * (M_PI / 180.0);
}

double haversineDistance(Location loc1, Location loc2) {
    double dLat = toRadians(loc2.latitude - loc1.latitude);
    double dLon = toRadians(loc2.longitude - loc1.longitude);
    
    double a = sin(dLat / 2) * sin(dLat / 2) +
               cos(toRadians(loc1.latitude)) * cos(toRadians(loc2.latitude)) *
               sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    
    return EARTH_RADIUS * c; // distance in kilometers
}

void displayLocations(Location* locations, int count) {
    printf("Available Locations:\n");
    for (int i = 0; i < count; i++) {
        printf("%d: %s - Latitude: %.6f, Longitude: %.6f\n", i + 1, locations[i].name, locations[i].latitude, locations[i].longitude);
    }
}

Location* createLocationArray(int size) {
    return (Location *)malloc(size * sizeof(Location));
}

void freeLocationArray(Location* locations) {
    free(locations);
}

int main() {
    int numLocations = 5;
    Location *locations = createLocationArray(numLocations);

    // Sample Locations
    locations[0] = (Location){37.7749, -122.4194, "San Francisco"};
    locations[1] = (Location){34.0522, -118.2437, "Los Angeles"};
    locations[2] = (Location){40.7128, -74.0060, "New York"};
    locations[3] = (Location){41.8781, -87.6298, "Chicago"};
    locations[4] = (Location){29.7604, -95.3698, "Houston"};

    double currentLat, currentLon;
    printf("Enter your current latitude: ");
    scanf("%lf", &currentLat);
    printf("Enter your current longitude: ");
    scanf("%lf", &currentLon);
    
    Location currentLocation = {currentLat, currentLon, "Current Location"};
    
    displayLocations(locations, numLocations);
    
    printf("\nDistances from your current location:\n");
    for (int i = 0; i < numLocations; i++) {
        double distance = haversineDistance(currentLocation, locations[i]);
        printf("Distance to %s: %.2f km\n", locations[i].name, distance);
    }

    freeLocationArray(locations);
    return 0;
}