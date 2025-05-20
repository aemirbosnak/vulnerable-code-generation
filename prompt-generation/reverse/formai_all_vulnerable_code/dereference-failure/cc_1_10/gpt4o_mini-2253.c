//GPT-4o-mini DATASET v1.0 Category: Traffic Flow Simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_VEHICLES 10
#define ROAD_LENGTH 20

typedef struct Vehicle {
    int id;
    int position;
    int speed;
    struct Vehicle* next;
} Vehicle;

Vehicle* head = NULL;

void addVehicle(int id) {
    Vehicle* newVehicle = (Vehicle*)malloc(sizeof(Vehicle));
    newVehicle->id = id;
    newVehicle->position = 0;
    newVehicle->speed = rand() % 3 + 1; // Speed between 1 and 3
    newVehicle->next = head;
    head = newVehicle;
}

void moveVehicles() {
    Vehicle* current = head;
    while (current != NULL) {
        current->position += current->speed;
        if (current->position >= ROAD_LENGTH) {
            current->position = ROAD_LENGTH; // Stop at the end of the road
        }
        current = current->next;
    }
}

void printRoad() {
    char road[ROAD_LENGTH + 1];
    for (int i = 0; i <= ROAD_LENGTH; i++) {
        road[i] = '_'; // Create an empty road
    }
    road[ROAD_LENGTH] = '\0'; // Null-terminate the string

    Vehicle* current = head;
    while (current != NULL) {
        if (current->position < ROAD_LENGTH) {
            road[current->position] = 'A' + current->id; // Place vehicle on the road
        }
        current = current->next;
    }

    printf("%s\n", road);
}

void freeVehicles() {
    Vehicle* current = head;
    while (current != NULL) {
        Vehicle* temp = current;
        current = current->next;
        free(temp);
    }
    head = NULL;
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    for (int i = 0; i < MAX_VEHICLES; i++) {
        addVehicle(i);
    }

    char command;
    printf("Welcome to the Traffic Flow Simulation! Press 'r' to run, 's' to stop, 'q' to quit.\n");
    
    while (1) {
        if (head == NULL) {
            printf("No vehicles on the road!\n");
            break;
        }

        printf("Command: ");
        scanf(" %c", &command);
        
        if (command == 'r') {
            printf("Simulation running...\n");
            while (1) {
                printRoad();
                moveVehicles();
                usleep(500000); // Wait for 0.5 seconds
                if (head != NULL) {
                    Vehicle* current = head;
                    while (current != NULL) {
                        if (current->position >= ROAD_LENGTH) {
                            printf("Vehicle %d has reached the end of the road!\n", current->id);
                        }
                        current = current->next;
                    }
                }
            }
        } else if (command == 's') {
            printf("Simulation paused.\n");
        } else if (command == 'q') {
            printf("Exiting the simulation...\n");
            freeVehicles();
            break;
        } else {
            printf("Invalid command! Try again.\n");
        }
    }

    return 0;
}