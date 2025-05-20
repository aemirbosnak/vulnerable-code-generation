//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMMANDS 10
#define MAX_LENGTH 50

struct command {
    char *name;
    void (*function)(void);
};

void turn_on_lights(void) {
    printf("Turning on lights...\n");
}

void turn_off_lights(void) {
    printf("Turning off lights...\n");
}

void lock_door(void) {
    printf("Locking door...\n");
}

void unlock_door(void) {
    printf("Unlocking door...\n");
}

int main(void) {
    struct command commands[MAX_COMMANDS] = {
        {"turn_on_lights", turn_on_lights},
        {"turn_off_lights", turn_off_lights},
        {"lock_door", lock_door},
        {"unlock_door", unlock_door}
    };

    char input[MAX_LENGTH];
    while (1) {
        printf("> ");
        fgets(input, MAX_LENGTH, stdin);

        char *command = strtok(input, " ");
        for (int i = 0; i < MAX_COMMANDS; i++) {
            if (strcmp(command, commands[i].name) == 0) {
                commands[i].function();
                break;
            }
        }
    }

    return 0;
}