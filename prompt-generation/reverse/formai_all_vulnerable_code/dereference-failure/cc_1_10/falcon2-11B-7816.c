//Falcon2-11B DATASET v1.0 Category: GPS Navigation Simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LINES 100

typedef struct {
    int latitude;
    int longitude;
} GPSCoordinates;

typedef struct {
    char* destination;
    GPSCoordinates* destinationCoordinates;
} GPSDestination;

typedef struct {
    GPSCoordinates* currentCoordinates;
} GPSCurrent;

void printGPSCoordinates(GPSCoordinates* coordinates) {
    printf("Latitude: %d\nLongitude: %d\n", coordinates->latitude, coordinates->longitude);
}

void printGPSDestination(GPSDestination* destination) {
    printf("Destination: %s\n", destination->destination);
    printGPSCoordinates(destination->destinationCoordinates);
}

void printGPSCurrent(GPSCurrent* current) {
    printf("Current Coordinates: Latitude: %d\nLongitude: %d\n", current->currentCoordinates->latitude, current->currentCoordinates->longitude);
}

void printGPSNavigation(GPSCurrent* current, GPSDestination* destination) {
    printf("Current Coordinates:\n");
    printGPSCurrent(current);
    printf("\nDestination Coordinates:\n");
    printGPSDestination(destination);
    printf("\n");
}

int main() {
    GPSDestination* destination = (GPSDestination*) malloc(sizeof(GPSDestination));
    destination->destination = "San Francisco";
    GPSCoordinates* destinationCoordinates = (GPSCoordinates*) malloc(sizeof(GPSCoordinates));
    destinationCoordinates->latitude = 37.7749;
    destinationCoordinates->longitude = -122.4194;
    destination->destinationCoordinates = destinationCoordinates;

    GPSCurrent* current = (GPSCurrent*) malloc(sizeof(GPSCurrent));
    GPSCoordinates* currentCoordinates = (GPSCoordinates*) malloc(sizeof(GPSCoordinates));
    currentCoordinates->latitude = 37.7749;
    currentCoordinates->longitude = -122.4194;
    current->currentCoordinates = currentCoordinates;

    printGPSNavigation(current, destination);

    return 0;
}