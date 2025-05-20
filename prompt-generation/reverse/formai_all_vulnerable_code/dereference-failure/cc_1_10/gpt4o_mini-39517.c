//GPT-4o-mini DATASET v1.0 Category: Traffic Flow Simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_VEHICLES 100
#define SIMULATION_DURATION 30       // Duration in seconds
#define VEHICLE_GEN_INTERVAL 2       // Interval in seconds for generating vehicles

typedef struct Vehicle {
    int id;
    char *type; // car, truck, bike
    struct Vehicle *next;
} Vehicle;

typedef struct {
    Vehicle *head;
    int count;
} VehicleList;

void initializeVehicleList(VehicleList *list) {
    list->head = NULL;
    list->count = 0;
}

void addVehicle(VehicleList *list, int id, char *type) {
    Vehicle *newVehicle = (Vehicle *)malloc(sizeof(Vehicle));
    newVehicle->id = id;
    newVehicle->type = type;
    newVehicle->next = list->head;
    list->head = newVehicle;
    list->count++;
}

void removeVehicle(VehicleList *list) {
    if (list->head != NULL) {
        Vehicle *temp = list->head;
        list->head = list->head->next;
        free(temp);
        list->count--;
    }
}

void displayVehicles(VehicleList *list) {
    Vehicle *current = list->head;
    printf("Current vehicles in the simulation:\n");
    while (current != NULL) {
        printf("Vehicle ID: %d, Type: %s\n", current->id, current->type);
        current = current->next;
    }
}

void freeVehicles(VehicleList *list) {
    while (list->head != NULL) {
        removeVehicle(list);
    }
}

int main() {
    VehicleList vehicleList;
    initializeVehicleList(&vehicleList);
    
    srand(time(NULL));
    int vehicleId = 0;
    time_t startTime = time(NULL);
    
    while (difftime(time(NULL), startTime) < SIMULATION_DURATION) {
        sleep(VEHICLE_GEN_INTERVAL);
        vehicleId++;
        
        char *types[] = {"Car", "Truck", "Bike"};
        int typeIndex = rand() % 3; // Random vehicle type
        
        addVehicle(&vehicleList, vehicleId, types[typeIndex]);
        displayVehicles(&vehicleList);
    }

    printf("Simulation ended. Cleaning up...\n");
    freeVehicles(&vehicleList);
    
    return 0;
}