//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DRONES 10
#define MAX_COMMANDS 5

typedef struct drone {
    int id;
    char name[20];
    int altitude;
    int speed;
} Drone;

typedef struct command {
    char name[20];
    int (*function)(Drone*, int, int*);
} Command;

void takeoff(Drone* drone, int arg1, int* arg2) {
    drone->altitude += arg1;
    *arg2 = drone->altitude;
}

void land(Drone* drone, int arg1, int* arg2) {
    drone->altitude -= arg1;
    *arg2 = drone->altitude;
}

void move(Drone* drone, int arg1, int* arg2) {
    drone->speed += arg1;
    *arg2 = drone->speed;
}

void rotate(Drone* drone, int arg1, int* arg2) {
    drone->speed -= arg1;
    *arg2 = drone->speed;
}

Drone* getDrone(int id) {
    Drone* drones = (Drone*)malloc(MAX_DRONES * sizeof(Drone));
    int i = 0;
    while (i < MAX_DRONES) {
        if (drones[i].id == id) {
            return &drones[i];
        }
        i++;
    }
    return NULL;
}

int main() {
    int choice;
    int arg1, arg2;
    Command commands[MAX_COMMANDS] = {{"takeoff", takeoff}, {"land", land}, {"move", move}, {"rotate", rotate}};
    int numCommands = 0;

    do {
        printf("\nDrone Remote Control\n");
        printf("1. Takeoff\n2. Land\n3. Move\n4. Rotate\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
            case 2:
            case 3:
            case 4:
                printf("Enter drone ID: ");
                scanf("%d", &arg1);
                Drone* drone = getDrone(arg1);
                if (drone == NULL) {
                    printf("Drone not found.\n");
                } else {
                    printf("Enter altitude/speed: ");
                    scanf("%d", &arg2);
                    commands[numCommands].function(drone, arg2, &arg2);
                    printf("Altitude/Speed: %d\n", arg2);
                }
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
        numCommands++;
    } while (1);

    return 0;
}