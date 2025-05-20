//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 10
#define COMMAND_SIZE 20

typedef struct {
    int row; 
    int col;
} Position;

typedef struct {
    int id;
    Position position;
    int fuel;
} Vehicle;

// function to generate random position on grid
Position getRandomPosition() {
    Position pos = {rand() % GRID_SIZE, rand() % GRID_SIZE};
    return pos;
}

// function to initialize vehicle
Vehicle* initVehicle(int id) {
    Vehicle* vehicle = (Vehicle*) malloc(sizeof(Vehicle));
    vehicle->id = id;
    vehicle->position = getRandomPosition();
    vehicle->fuel = 100;
    return vehicle;
}

// function to print grid and vehicles
void printGrid(Vehicle** vehicles) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            int hasVehicle = 0;
            for (int k = 0; k < 3; k++) {
                Vehicle* vehicle = vehicles[k];
                if (vehicle->position.row == i && vehicle->position.col == j) {
                    printf("%d ", vehicle->id);
                    hasVehicle = 1;
                    break;
                }
            }
            if (!hasVehicle) {
                printf("- ");
            }
        }
        printf("\n");
    }
}

// function to execute command on vehicle
void executeCommand(Vehicle* vehicle, char command[COMMAND_SIZE]) {
    if (strcmp(command, "left") == 0) {
        if (vehicle->position.col - 1 >= 0) {
            vehicle->position.col--;
            vehicle->fuel -= 5;
        }
    } else if (strcmp(command, "right") == 0) {
        if (vehicle->position.col + 1 < GRID_SIZE) {
            vehicle->position.col++;
            vehicle->fuel -= 5;
        }
    } else if (strcmp(command, "up") == 0) {
        if (vehicle->position.row - 1 >= 0) {
            vehicle->position.row--;
            vehicle->fuel -= 5;
        }
    } else if (strcmp(command, "down") == 0) {
        if (vehicle->position.row + 1 < GRID_SIZE) {
            vehicle->position.row++;
            vehicle->fuel -= 5;
        }
    }
}

int main() {
    // seed random
    srand(time(NULL));

    // initialize vehicles
    Vehicle* vehicle1 = initVehicle(1);
    Vehicle* vehicle2 = initVehicle(2);
    Vehicle* vehicle3 = initVehicle(3);
    Vehicle* vehicles[3] = {
        vehicle1,
        vehicle2,
        vehicle3
    };

    // print initial grid and vehicles
    printGrid(vehicles);

    // execute commands on vehicles
    char commands[3][COMMAND_SIZE] = {
        "left",
        "right",
        "up"
    };
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 3; j++) {
            int vehicleIndex = rand() % 3;
            Vehicle* vehicle = vehicles[vehicleIndex];
            executeCommand(vehicle, commands[j]);
        }
        printGrid(vehicles);
    }
    
    // free memory
    free(vehicle1);
    free(vehicle2);
    free(vehicle3);

    return 0;
}