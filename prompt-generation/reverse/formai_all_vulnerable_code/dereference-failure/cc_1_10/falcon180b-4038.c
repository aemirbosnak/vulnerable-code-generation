//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DRONES 10
#define MAX_COMMANDS 5
#define MAX_COMMAND_LENGTH 20

typedef struct {
    char name[MAX_COMMAND_LENGTH];
    int (*function)(int drone_index, int parameter);
} command_t;

int move_forward(int drone_index, int parameter) {
    printf("Drone %d is moving forward with speed %d\n", drone_index, parameter);
    return 0;
}

int turn_left(int drone_index, int parameter) {
    printf("Drone %d is turning left with angle %d\n", drone_index, parameter);
    return 0;
}

int turn_right(int drone_index, int parameter) {
    printf("Drone %d is turning right with angle %d\n", drone_index, parameter);
    return 0;
}

int take_off(int drone_index, int parameter) {
    printf("Drone %d is taking off\n", drone_index);
    return 0;
}

int land(int drone_index, int parameter) {
    printf("Drone %d is landing\n", drone_index);
    return 0;
}

command_t commands[MAX_COMMANDS] = {
    { "move_forward", move_forward },
    { "turn_left", turn_left },
    { "turn_right", turn_right },
    { "take_off", take_off },
    { "land", land }
};

int main() {
    int num_drones;
    printf("Enter the number of drones: ");
    scanf("%d", &num_drones);

    if (num_drones > MAX_DRONES) {
        printf("Error: Too many drones\n");
        return 1;
    }

    printf("Enter the names of the drones:\n");
    for (int i = 0; i < num_drones; i++) {
        scanf("%s", &commands[i].name);
    }

    int choice;
    while (1) {
        printf("\nSelect an option:\n");
        printf("1. Move forward\n");
        printf("2. Turn left\n");
        printf("3. Turn right\n");
        printf("4. Take off\n");
        printf("5. Land\n");
        printf("6. Exit\n");
        scanf("%d", &choice);

        if (choice == 6) {
            break;
        }

        int drone_index;
        printf("Enter the drone index: ");
        scanf("%d", &drone_index);

        if (drone_index >= num_drones) {
            printf("Error: Invalid drone index\n");
            continue;
        }

        int parameter;
        printf("Enter the parameter: ");
        scanf("%d", &parameter);

        commands[choice - 1].function(drone_index, parameter);
    }

    return 0;
}