//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_COMMANDS 10
#define PI 3.14159265359

typedef struct {
    char *command;
    void (*function)(void);
} command_t;

void fly_forward(void);
void turn_left(void);
void turn_right(void);
void ascend(void);
void descend(void);

int main() {
    command_t commands[MAX_COMMANDS] = {{"fly_forward", fly_forward},
                                        {"turn_left", turn_left},
                                        {"turn_right", turn_right},
                                        {"ascend", ascend},
                                        {"descend", descend}};

    int num_commands = sizeof(commands) / sizeof(commands[0]);

    printf("Enter command: ");
    char input[50];
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0'; // Remove newline character

    for (int i = 0; i < num_commands; i++) {
        if (strcmp(commands[i].command, input) == 0) {
            commands[i].function();
            break;
        }
    }

    return 0;
}

void fly_forward(void) {
    printf("Flying forward...\n");
}

void turn_left(void) {
    printf("Turning left...\n");
}

void turn_right(void) {
    printf("Turning right...\n");
}

void ascend(void) {
    printf("Ascending...\n");
}

void descend(void) {
    printf("Descending...\n");
}