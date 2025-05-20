//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 20

typedef struct {
    char name[MAX_COMMAND_LENGTH];
    void (*function)(void);
} command_t;

void turn_on_light(void) {
    printf("The light is now on.\n");
}

void turn_off_light(void) {
    printf("The light is now off.\n");
}

void open_door(void) {
    printf("The door is now open.\n");
}

void close_door(void) {
    printf("The door is now closed.\n");
}

void set_temperature(int temperature) {
    printf("The temperature is now set to %d degrees.\n", temperature);
}

int main(int argc, char *argv[]) {
    int i;
    char input[MAX_COMMAND_LENGTH];
    command_t commands[MAX_COMMANDS] = {
        {"light_on", turn_on_light},
        {"light_off", turn_off_light},
        {"door_open", open_door},
        {"door_close", close_door},
        {"set_temperature", set_temperature}
    };

    printf("Welcome to the surrealist smart home automation system.\n");

    while (1) {
        printf("Enter a command: ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        for (i = 0; i < MAX_COMMANDS; i++) {
            if (strcmp(commands[i].name, input) == 0) {
                (*commands[i].function)();
            }
        }
    }

    return 0;
}