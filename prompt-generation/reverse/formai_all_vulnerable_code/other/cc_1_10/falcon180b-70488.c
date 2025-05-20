//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DRONES 10
#define MAX_COMMANDS 5
#define MAX_COMMAND_LENGTH 50

typedef struct {
    char name[MAX_COMMAND_LENGTH];
    int (*function)(int drone_id);
} command_t;

void fly_to(int drone_id, int x, int y, int z) {
    printf("Drone %d is flying to (%d, %d, %d)\n", drone_id, x, y, z);
}

void take_off(int drone_id) {
    printf("Drone %d is taking off\n", drone_id);
}

void land(int drone_id) {
    printf("Drone %d is landing\n", drone_id);
}

void status(int drone_id) {
    printf("Drone %d status: ", drone_id);
}

int main() {
    srand(time(NULL));

    command_t commands[MAX_COMMANDS] = {
        {"fly_to", fly_to},
        {"take_off", take_off},
        {"land", land},
        {"status", status},
        {"none", NULL}
    };

    int num_drones = rand() % MAX_DRONES + 1;
    int drones[MAX_DRONES];

    for (int i = 0; i < num_drones; i++) {
        drones[i] = i + 1;
    }

    int num_commands = rand() % MAX_COMMANDS + 1;

    for (int i = 0; i < num_commands; i++) {
        int command_index = rand() % MAX_COMMANDS;
        printf("Entering command: %s\n", commands[command_index].name);
        int drone_id = drones[rand() % num_drones];
        (*commands[command_index].function)(drone_id);
    }

    return 0;
}