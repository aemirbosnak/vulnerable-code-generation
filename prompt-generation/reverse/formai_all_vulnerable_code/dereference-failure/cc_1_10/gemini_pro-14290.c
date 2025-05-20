//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double latitude;
    double longitude;
} Coordinate;

typedef struct {
    Coordinate current;
    Coordinate destination;
} GPS;

//Initialize the GPS with a current and destination coordinate
GPS* initGPS(Coordinate current, Coordinate destination) {
    GPS *gps = malloc(sizeof(GPS));
    gps->current = current;
    gps->destination = destination;
    return gps;
}


//Calculate the distance between two coordinates using the Haversine formula
double haversine(Coordinate c1, Coordinate c2) {
    double R = 6371.0; // Earth's radius in kilometers
    double dLat = (c2.latitude - c1.latitude) * M_PI / 180.0;
    double dLon = (c2.longitude - c1.longitude) * M_PI / 180.0;
    double a = sin(dLat/2) * sin(dLat/2) + cos(c1.latitude * M_PI / 180.0) * cos(c2.latitude * M_PI / 180.0) * sin(dLon/2) * sin(dLon/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    return R * c;
}

//Update the current coordinate of the GPS
void updateCurrent(GPS *gps, Coordinate newCurrent) {
    gps->current = newCurrent;
}

//Get the current coordinate of the GPS
Coordinate getCurrent(GPS *gps) {
    return gps->current;
}

//Get the distance between the current and destination coordinate
double getDistance(GPS *gps) {
    return haversine(gps->current, gps->destination);
}

//Check if the GPS has reached the destination
int atDestination(GPS *gps) {
    return getDistance(gps) < 0.001;
}

//Get the direction to the destination from the current coordinate
double getDirection(GPS *gps) {
    double dLat = (gps->destination.latitude - gps->current.latitude) * M_PI / 180.0;
    double dLon = (gps->destination.longitude - gps->current.longitude) * M_PI / 180.0;
    return atan2(sin(dLon) * cos(gps->destination.latitude * M_PI / 180.0), cos(gps->current.latitude * M_PI / 180.0) * sin(gps->destination.latitude * M_PI / 180.0) - sin(gps->current.latitude * M_PI / 180.0) * cos(gps->destination.latitude * M_PI / 180.0) * cos(dLon)) * 180.0 / M_PI;
}

//Print the current coordinate, distance to destination, and direction to destination
void printStatus(GPS *gps) {
    printf("Current Coordinate: (%f, %f)\n", gps->current.latitude, gps->current.longitude);
    printf("Distance to Destination: %f kilometers\n", getDistance(gps));
    printf("Direction to Destination: %f degrees\n", getDirection(gps));
}

int main() {
    //Initialize the GPS with a current and destination coordinate
    Coordinate current = {37.7833, -122.4167};
    Coordinate destination = {37.8190, -122.4789};
    GPS *gps = initGPS(current, destination);

    //Simulate the GPS by updating the current coordinate and printing the status
    for (int i = 0; i < 10; i++) {
        //Update the current coordinate
        double lat = current.latitude + (rand() % 100) / 1000.0;
        double lon = current.longitude + (rand() % 100) / 1000.0;
        Coordinate newCurrent = {lat, lon};
        updateCurrent(gps, newCurrent);

        //Print the status
        printStatus(gps);

        //Check if the GPS has reached the destination
        if (atDestination(gps)) {
            printf("Destination reached!\n");
            break;
        }
    }

    //Free the GPS memory
    free(gps);

    return 0;
}