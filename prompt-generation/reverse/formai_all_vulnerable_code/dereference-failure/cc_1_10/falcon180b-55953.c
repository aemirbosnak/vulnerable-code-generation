//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 20

struct command {
    char name[MAX_COMMAND_LENGTH];
    int (*func)(int, char**);
};

int turn_on_light(int argc, char** argv) {
    printf("Turning on the light.\n");
    return 0;
}

int turn_off_light(int argc, char** argv) {
    printf("Turning off the light.\n");
    return 0;
}

int set_light_brightness(int argc, char** argv) {
    if (argc!= 3) {
        printf("Usage: set_light_brightness <brightness>\n");
        return 1;
    }

    int brightness = atoi(argv[2]);
    printf("Setting light brightness to %d.\n", brightness);
    return 0;
}

int main() {
    struct command commands[MAX_COMMANDS] = {
        {"turn_on_light", turn_on_light},
        {"turn_off_light", turn_off_light},
        {"set_light_brightness", set_light_brightness}
    };

    int num_commands = sizeof(commands) / sizeof(commands[0]);

    while (1) {
        printf("Enter a command: ");
        fflush(stdout);

        char input[MAX_COMMAND_LENGTH];
        if (fgets(input, MAX_COMMAND_LENGTH, stdin) == NULL) {
            printf("Error reading input.\n");
            continue;
        }

        input[strcspn(input, "\n")] = '\0';

        int i;
        for (i = 0; i < num_commands; i++) {
            if (strcmp(commands[i].name, input) == 0) {
                int argc = 1;
                char** argv = &input;
                int ret = commands[i].func(argc, argv);

                if (ret!= 0) {
                    printf("Error executing command.\n");
                }

                break;
            }
        }

        if (i == num_commands) {
            printf("Unknown command.\n");
        }
    }

    return 0;
}