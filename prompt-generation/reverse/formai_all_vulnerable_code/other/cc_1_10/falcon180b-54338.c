//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 20
#define DELAY_TIME 500

typedef struct {
    char command[MAX_COMMAND_LENGTH];
    void (*function)(void);
} command_t;

void turn_on_light(void) {
    printf("Light turned on.\n");
}

void turn_off_light(void) {
    printf("Light turned off.\n");
}

void set_brightness(int level) {
    printf("Light brightness set to %d.\n", level);
}

void set_color(char *color) {
    printf("Light color set to %s.\n", color);
}

int main(void) {
    char input[MAX_COMMAND_LENGTH];
    command_t commands[MAX_COMMANDS];
    int num_commands = 0;

    memset(commands, 0, sizeof(commands));

    commands[num_commands++] = (command_t) {"turn on", turn_on_light};
    commands[num_commands++] = (command_t) {"turn off", turn_off_light};
    commands[num_commands++] = (command_t) {"set brightness", set_brightness};
    commands[num_commands++] = (command_t) {"set color", set_color};

    while (1) {
        printf("Enter a command: ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        for (int i = 0; i < num_commands; i++) {
            if (strcasecmp(input, commands[i].command) == 0) {
                commands[i].function();
            }
        }
    }

    return 0;
}