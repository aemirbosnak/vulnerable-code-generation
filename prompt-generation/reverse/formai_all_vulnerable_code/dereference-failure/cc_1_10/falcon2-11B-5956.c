//Falcon2-11B DATASET v1.0 Category: Elevator Simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of floors
#define MAX_FLOORS 10

typedef struct floor {
    int floor;
    int status;
    struct floor* next;
} Floor;

Floor* floors[MAX_FLOORS];

void addFloor(int floor, int status) {
    Floor* newFloor = (Floor*)malloc(sizeof(Floor));
    newFloor->floor = floor;
    newFloor->status = status;
    newFloor->next = NULL;
    if (floors[floor-1] == NULL) {
        floors[floor-1] = newFloor;
    } else {
        Floor* currentFloor = floors[floor-1];
        while (currentFloor->next!= NULL) {
            currentFloor = currentFloor->next;
        }
        currentFloor->next = newFloor;
    }
}

void printFloor(int floor) {
    if (floor >= 0 && floor < MAX_FLOORS) {
        printf("Floor %d:\n", floor);
        Floor* currentFloor = floors[floor];
        while (currentFloor!= NULL) {
            printf(" - %s\n", currentFloor->status == 1? "Occupied" : "Free");
            currentFloor = currentFloor->next;
        }
    }
}

int main() {
    srand(time(NULL));

    // Add floors to the elevator
    addFloor(1, 0);
    addFloor(2, 0);
    addFloor(3, 0);
    addFloor(4, 0);
    addFloor(5, 0);
    addFloor(6, 0);
    addFloor(7, 0);
    addFloor(8, 0);
    addFloor(9, 0);
    addFloor(10, 0);

    // Print initial state of the elevator
    printf("Initial state of the elevator:\n");
    for (int i = 1; i <= MAX_FLOORS; i++) {
        printFloor(i);
    }

    while (1) {
        // Get user input
        char command[100];
        printf("Enter command (up/down/status): ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = '\0';

        // Process command
        if (strncmp(command, "up", 2) == 0) {
            int floor = atoi(command + 2);
            if (floor >= 1 && floor <= MAX_FLOORS) {
                if (floors[floor-1]->status == 0) {
                    printf("Elevator going up to floor %d...\n", floor);
                    floors[floor-1]->status = 1;
                } else {
                    printf("Elevator already at floor %d.\n", floor);
                }
            } else {
                printf("Invalid floor number.\n");
            }
        } else if (strncmp(command, "down", 3) == 0) {
            int floor = atoi(command + 3);
            if (floor >= 1 && floor <= MAX_FLOORS) {
                if (floors[floor-1]->status == 1) {
                    printf("Elevator going down to floor %d...\n", floor);
                    floors[floor-1]->status = 0;
                } else {
                    printf("Elevator already at floor %d.\n", floor);
                }
            } else {
                printf("Invalid floor number.\n");
            }
        } else if (strncmp(command, "status", 5) == 0) {
            int floor = atoi(command + 5);
            if (floor >= 1 && floor <= MAX_FLOORS) {
                printFloor(floor);
            } else {
                printf("Invalid floor number.\n");
            }
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}