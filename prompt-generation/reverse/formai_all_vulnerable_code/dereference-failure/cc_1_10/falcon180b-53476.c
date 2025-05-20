//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 20

enum {
    LIGHT_OFF = 0,
    LIGHT_ON = 1,
    LIGHT_DIM = 2
};

struct command {
    char *name;
    int (*func)(int, int);
};

int light_control(int argc, int *argv) {
    if (argc < 2) {
        printf("Usage: light [on|off|dim] [percentage]\n");
        return 1;
    }

    if (strcmp(argv[1], "on") == 0) {
        set_light(LIGHT_ON);
    } else if (strcmp(argv[1], "off") == 0) {
        set_light(LIGHT_OFF);
    } else if (strcmp(argv[1], "dim") == 0) {
        if (argc < 3) {
            printf("Usage: light dim [percentage]\n");
            return 1;
        }
        int percentage = atoi(argv[2]);
        set_light(LIGHT_DIM, percentage);
    } else {
        printf("Invalid command\n");
        return 1;
    }

    return 0;
}

int set_light(int state, int percentage) {
    // TODO: Implement light control logic
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        printf("Usage: smart_home [command] [args]\n");
        return 1;
    }

    struct command commands[MAX_COMMANDS] = {
        {"light", light_control},
        {NULL, NULL}
    };

    int i = 0;
    while (commands[i].name!= NULL) {
        if (strcmp(argv[1], commands[i].name) == 0) {
            int result = commands[i].func(argc - 2, argv + 2);
            if (result!= 0) {
                printf("Error executing command\n");
            }
            return result;
        }
        i++;
    }

    printf("Invalid command\n");
    return 1;
}