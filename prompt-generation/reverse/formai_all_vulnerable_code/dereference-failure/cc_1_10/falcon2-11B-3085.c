//Falcon2-11B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a vehicle
typedef struct vehicle {
    struct vehicle* next;
} vehicle;

// Function prototypes
void moveForward(vehicle*);
void moveBackward(vehicle*);
void moveLeft(vehicle*);
void moveRight(vehicle*);
int readInput(void);

int main() {
    // Create a vehicle and add it to the list
    vehicle* head = (vehicle*) malloc(sizeof(vehicle));
    head->next = NULL;

    // Add some more vehicles to the list
    head->next = (vehicle*) malloc(sizeof(vehicle));
    head->next->next = NULL;
    head->next->next = (vehicle*) malloc(sizeof(vehicle));
    head->next->next->next = NULL;
    head->next->next->next->next = NULL;

    while (1) {
        // Get user input
        int direction = readInput();

        // Move the vehicle based on the user input
        switch (direction) {
            case 1:
                moveForward(head);
                break;
            case 2:
                moveBackward(head);
                break;
            case 3:
                moveLeft(head);
                break;
            case 4:
                moveRight(head);
                break;
            default:
                printf("Invalid input!\n");
                break;
        }
    }

    return 0;
}

// Function to move the vehicle forward
void moveForward(vehicle* v) {
    v->next = (vehicle*) malloc(sizeof(vehicle));
    v->next->next = NULL;
}

// Function to move the vehicle backward
void moveBackward(vehicle* v) {
    v->next = v->next->next;
    v->next->next = NULL;
}

// Function to move the vehicle left
void moveLeft(vehicle* v) {
    v->next = v->next->next->next;
    v->next->next = v->next->next->next;
    v->next->next->next = NULL;
}

// Function to move the vehicle right
void moveRight(vehicle* v) {
    v->next = v->next->next->next;
    v->next->next = v;
    v->next->next->next = NULL;
}

// Function to read user input
int readInput() {
    char c;
    printf("Enter direction (1-4): ");
    scanf("%c", &c);
    return c - '0';
}