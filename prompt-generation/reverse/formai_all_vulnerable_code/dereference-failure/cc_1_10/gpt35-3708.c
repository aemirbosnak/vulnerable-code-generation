//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structure definition for a remote control vehicle
struct RemoteControlVehicle {
    int id;
    char name[20];
    char model[10];
    int year;
};

//Function to create a new remote control vehicle with unique id
struct RemoteControlVehicle createVehicle(int id, char name[], char model[], int year) {
    struct RemoteControlVehicle newVehicle;
    newVehicle.id = id;
    strcpy(newVehicle.name, name);
    strcpy(newVehicle.model, model);
    newVehicle.year = year;
    return newVehicle;
}

int main() {
    int i;
    int numberOfVehicles;

    printf("How many remote control vehicles do you want to simulate?\n");
    scanf("%d", &numberOfVehicles);

    struct RemoteControlVehicle *vehicles = malloc(numberOfVehicles * sizeof(struct RemoteControlVehicle)); //Dynamically allocate memory for array of vehicles

    for (i = 0; i < numberOfVehicles; i++) {
        printf("\nEnter details for Vehicle %d:\n", i + 1);
        int id;
        char name[20], model[10];
        int year;

        printf("Enter vehicle id: ");
        scanf("%d", &id);
        printf("Enter vehicle name: ");
        scanf("%s", name);
        printf("Enter vehicle model: ");
        scanf("%s", model);
        printf("Enter vehicle year of manufacture: ");
        scanf("%d", &year);

        vehicles[i] = createVehicle(id, name, model, year); //Create and store new vehicle in array
    }

    printf("\nRemote Control Vehicles simulated:\n");

    for (i = 0; i < numberOfVehicles; i++) {
        printf("\nVehicle %d:\nID: %d\nName: %s\nModel: %s\nYear: %d", i + 1, vehicles[i].id, vehicles[i].name, vehicles[i].model, vehicles[i].year);
    }

    free(vehicles); //Free allocated memory

    return 0;
}