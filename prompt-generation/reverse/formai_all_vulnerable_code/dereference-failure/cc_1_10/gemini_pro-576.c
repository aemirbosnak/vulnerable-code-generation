//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    TAKE_OFF = 1,
    LAND = 2,
    MOVE_FORWARD = 3,
    MOVE_BACKWARD = 4,
    MOVE_LEFT = 5,
    MOVE_RIGHT = 6,
    ROTATE_LEFT = 7,
    ROTATE_RIGHT = 8,
    FLIP = 9,
    HOVER = 10,
    QUIT = 11
} Command;

char *command_strings[] = {
    "TAKE OFF",
    "LAND",
    "MOVE FORWARD",
    "MOVE BACKWARD",
    "MOVE LEFT",
    "MOVE RIGHT",
    "ROTATE LEFT",
    "ROTATE RIGHT",
    "FLIP",
    "HOVER",
    "QUIT"
};

void print_help() {
    printf("Usage: drone_remote_control <command>\n");
    printf("Commands:\n");
    for (int i = 0; i < QUIT; i++) {
        printf("%d. %s\n", i + 1, command_strings[i]);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        print_help();
        return EXIT_FAILURE;
    }

    Command command = atoi(argv[1]);

    switch (command) {
        case TAKE_OFF:
            printf("Taking off!\n");
            break;
        case LAND:
            printf("Landing!\n");
            break;
        case MOVE_FORWARD:
            printf("Moving forward!\n");
            break;
        case MOVE_BACKWARD:
            printf("Moving backward!\n");
            break;
        case MOVE_LEFT:
            printf("Moving left!\n");
            break;
        case MOVE_RIGHT:
            printf("Moving right!\n");
            break;
        case ROTATE_LEFT:
            printf("Rotating left!\n");
            break;
        case ROTATE_RIGHT:
            printf("Rotating right!\n");
            break;
        case FLIP:
            printf("Flipping!\n");
            break;
        case HOVER:
            printf("Hovering!\n");
            break;
        case QUIT:
            printf("Quitting!\n");
            return EXIT_SUCCESS;
        default:
            printf("Invalid command!\n");
            print_help();
            return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}