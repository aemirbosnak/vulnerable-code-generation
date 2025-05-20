//MISTRAL-7B DATASET v1.0 Category: Haunted House Simulator ; Style: Cryptic
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct { float x, y, z; } point;

typedef struct { point p; int isDoorOpen; } door;

void createHouse(door* house, int numDoors) {
    house = malloc(numDoors * sizeof(door));
    for (int i = 0; i < numDoors; i++) {
        house[i].p.x = rand() % 20 + 10;
        house[i].p.y = rand() % 20 + 10;
        house[i].p.z = rand() % 20 + 10;
        house[i].isDoorOpen = 0;
    }
}

void openDoor(door* doorToOpen) {
    doorToOpen->isDoorOpen = 1;
}

void closeDoor(door* doorToClose) {
    doorToClose->isDoorOpen = 0;
}

void checkDoor(door* doorToCheck) {
    if (doorToCheck->isDoorOpen) {
        printf("Door %p is open.\n", doorToCheck);
    } else {
        printf("Door %p is closed.\n", doorToCheck);
    }
}

int main(int argc, char* argv[]) {
    srand(time(NULL));
    door* hauntedHouse;
    int numDoors = 5;

    createHouse(hauntedHouse, numDoors);

    printf("Haunted house doors initially:\n");
    for (int i = 0; i < numDoors; i++) {
        checkDoor(&hauntedHouse[i]);
    }

    printf("\nTrying to open door %p...\n", &hauntedHouse[rand() % numDoors]);
    openDoor(&hauntedHouse[rand() % numDoors]);

    printf("\nHaunted house doors after opening one door randomly:\n");
    for (int i = 0; i < numDoors; i++) {
        checkDoor(&hauntedHouse[i]);
    }

    free(hauntedHouse);
    return 0;
}