//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int X;
    int Y;
} Position;

typedef struct {
    char *Name;
    Position Pos;
} RCVehicle;

RCVehicle *NewVehicle(char *name, int x, int y) {
    RCVehicle *vehicle = malloc(sizeof(RCVehicle));
    vehicle->Name = malloc(sizeof(char) * (strlen(name) + 1));
    strcpy(vehicle->Name, name);
    vehicle->Pos.X = x;
    vehicle->Pos.Y = y;
    return vehicle;
}

void Move(RCVehicle *vehicle, int x, int y) {
    vehicle->Pos.X = x;
    vehicle->Pos.Y = y;
}

void PrintVehicle(RCVehicle *vehicle) {
    printf("Vehicle %s is at position (%d,%d)\n", vehicle->Name, vehicle->Pos.X, vehicle->Pos.Y);
}

int main() {
    RCVehicle *vehicle1 = NewVehicle("Red Car", 0, 0);
    RCVehicle *vehicle2 = NewVehicle("Blue Car", 5, 5);

    PrintVehicle(vehicle1);
    PrintVehicle(vehicle2);

    Move(vehicle1, 2, 2);
    Move(vehicle2, 8, 10);

    PrintVehicle(vehicle1);
    PrintVehicle(vehicle2);

    free(vehicle1->Name);
    free(vehicle1);
    free(vehicle2->Name);
    free(vehicle2);

    return 0;
}