//GPT-4o-mini DATASET v1.0 Category: Robot movement control ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GRID_SIZE 5
#define MAX_COMMANDS 100

typedef struct {
    int x;
    int y;
} Robot;

void initialize_robot(Robot *robot) {
    robot->x = 0;
    robot->y = 0;
}

void move_robot(Robot *robot, const char *command) {
    if (strcmp(command, "UP") == 0 && robot->y < GRID_SIZE - 1) {
        robot->y++;
    } else if (strcmp(command, "DOWN") == 0 && robot->y > 0) {
        robot->y--;
    } else if (strcmp(command, "LEFT") == 0 && robot->x > 0) {
        robot->x--;
    } else if (strcmp(command, "RIGHT") == 0 && robot->x < GRID_SIZE - 1) {
        robot->x++;
    }
}

void display_position(const Robot *robot) {
    printf("Robot is at position: (%d, %d)\n", robot->x, robot->y);
}

int main(int argc, char *argv[]) {
    Robot robot;
    initialize_robot(&robot);

    char *commands[MAX_COMMANDS];
    int command_count = 0;

    printf("Enter movement commands (UP, DOWN, LEFT, RIGHT). Type 'EXIT' to stop:\n");

    while (1) {
        char input[20];
        printf("Command %d: ", command_count + 1);
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;  // Remove newline character

        if (strcmp(input, "EXIT") == 0) {
            break;
        }

        commands[command_count] = malloc(strlen(input) + 1);
        strcpy(commands[command_count], input);
        command_count++;

        move_robot(&robot, input);
        display_position(&robot);
    }

    // Free allocated memory for commands
    for (int i = 0; i < command_count; i++) {
        free(commands[i]);
    }

    printf("Final position of robot: (%d, %d)\n", robot.x, robot.y);
    return 0;
}