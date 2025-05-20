//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 50

struct command {
    char *name;
    void (*func)(void);
};

void turn_on_light(void) {
    printf("Turning on the light\n");
}

void turn_off_light(void) {
    printf("Turning off the light\n");
}

void lock_door(void) {
    printf("Locking the door\n");
}

void unlock_door(void) {
    printf("Unlocking the door\n");
}

int main(void) {
    struct command commands[MAX_COMMANDS] = {
        {"turn_on_light", turn_on_light},
        {"turn_off_light", turn_off_light},
        {"lock_door", lock_door},
        {"unlock_door", unlock_door}
    };

    char input[MAX_COMMAND_LENGTH];
    while (1) {
        printf("Enter a command: ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0'; // Remove newline character

        int i;
        for (i = 0; i < MAX_COMMANDS; i++) {
            if (strcmp(input, commands[i].name) == 0) {
                commands[i].func();
                break;
            }
        }

        if (i == MAX_COMMANDS) {
            printf("Invalid command\n");
        }
    }

    return 0;
}