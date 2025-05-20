//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

#define MAX_STATIONS 10

typedef struct Station {
    char name[20];
    struct Station* next;
    struct Station* prev;
} Station;

Station* CreateStation(char* name) {
    Station* station = malloc(sizeof(Station));
    strcpy(station->name, name);
    station->next = NULL;
    station->prev = NULL;
    return station;
}

void AddStation(Station* station, Station* newStation) {
    if (station) {
        station->next = newStation;
        newStation->prev = station;
    }
}

void PrintTopology(Station* station) {
    printf("Topology:");
    while (station) {
        printf(" %s", station->name);
        station = station->next;
    }
    printf("\n");
}

int main() {
    // Create a paranoid network topology
    Station* stationA = CreateStation("A");
    Station* stationB = CreateStation("B");
    Station* stationC = CreateStation("C");
    Station* stationD = CreateStation("D");
    Station* stationE = CreateStation("E");
    AddStation(stationA, stationB);
    AddStation(stationA, stationC);
    AddStation(stationB, stationD);
    AddStation(stationC, stationE);

    // Print the topology
    PrintTopology(stationA);

    // Check for suspicious activity
    if (stationB->next->prev->name != "C") {
        printf("Suspicious activity detected!");
    }

    return 0;
}