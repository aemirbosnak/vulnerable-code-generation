//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TRUE   1
#define FALSE  0
#define MAX_COMMANDS 10
#define MAX_LENGTH 20

typedef struct {
    char *command;
    void (*function)(void);
} command_t;

void turn_on_light(void) {
    printf("Light turned on.\n");
}

void turn_off_light(void) {
    printf("Light turned off.\n");
}

void open_door(void) {
    printf("Door opened.\n");
}

void close_door(void) {
    printf("Door closed.\n");
}

void set_temperature(void) {
    printf("Temperature set.\n");
}

int main(void) {
    command_t commands[MAX_COMMANDS] = {
        {"turn_on_light", turn_on_light},
        {"turn_off_light", turn_off_light},
        {"open_door", open_door},
        {"close_door", close_door},
        {"set_temperature", set_temperature}
    };

    char input[MAX_LENGTH];
    int i;

    printf("Welcome to the Smart Home Automation System!\n");
    printf("Please enter a command:\n");

    while (fgets(input, MAX_LENGTH, stdin)!= NULL) {
        for (i = 0; i < MAX_COMMANDS; i++) {
            if (strcmp(commands[i].command, input) == 0) {
                commands[i].function();
                break;
            }
        }

        if (i == MAX_COMMANDS) {
            printf("Invalid command.\n");
        }

        printf("Please enter a command:\n");
    }

    return 0;
}