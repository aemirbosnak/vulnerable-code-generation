//GPT-4o-mini DATASET v1.0 Category: Traffic Flow Simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Vehicle {
    char type[10];  // type of the vehicle (e.g., carriage, cart)
    int id;        // unique id for the vehicle
    struct Vehicle* next;
} Vehicle;

typedef struct Traffic {
    Vehicle* head;
    int count;
} Traffic;

Traffic* createTraffic() {
    Traffic* traffic = (Traffic*)malloc(sizeof(Traffic));
    traffic->head = NULL;
    traffic->count = 0;
    return traffic;
}

void addVehicle(Traffic* traffic, const char* type) {
    Vehicle* newVehicle = (Vehicle*)malloc(sizeof(Vehicle));
    strcpy(newVehicle->type, type);
    newVehicle->id = ++traffic->count;
    newVehicle->next = traffic->head;
    traffic->head = newVehicle;
}

void displayTraffic(Traffic* traffic) {
    Vehicle* current = traffic->head;
    printf("Traffic at the moment:\n");
    while (current != NULL) {
        printf("Vehicle ID: %d, Type: %s\n", current->id, current->type);
        current = current->next;
    }
}

void simulateTraffic(Traffic* traffic) {
    const char* vehicles[] = {"carriage", "cart", "bicycle", "pedestrian"};
    srand(time(NULL));
    for (int i = 0; i < 20; i++) {
        addVehicle(traffic, vehicles[rand() % 4]);
    }
}

void clearTraffic(Traffic* traffic) {
    Vehicle* current = traffic->head;
    Vehicle* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(traffic);
}

int main() {
    printf("Sherlock Holmes' Traffic Flow Simulation\n");
    printf("It's a bright day in Victorian London. The streets are alive!\n");

    Traffic* traffic = createTraffic();
    simulateTraffic(traffic);

    displayTraffic(traffic);

    printf("The traffic is now under control. Onwards to the next mystery!\n");

    clearTraffic(traffic);
    return 0;
}