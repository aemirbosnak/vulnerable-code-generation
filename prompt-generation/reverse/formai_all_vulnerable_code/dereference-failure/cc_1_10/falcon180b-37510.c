//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 1024
#define MAX_ARG 32
#define MAX_COMMAND 64
#define MAX_RESPONSE 1024

#define QOS_ENABLE "QoS Enable"
#define QOS_DISABLE "QoS Disable"
#define QOS_STATUS "QoS Status"

typedef struct {
    char *command;
    void (*handler)(char *response);
} command_t;

void qos_enable(char *response) {
    printf("QoS Enabled\n");
}

void qos_disable(char *response) {
    printf("QoS Disabled\n");
}

void qos_status(char *response) {
    printf("QoS Status: %s\n", response);
}

command_t commands[] = {
    {"enable", qos_enable},
    {"disable", qos_disable},
    {"status", qos_status},
    {NULL, NULL}
};

int main() {
    char input[MAX_LINE];
    char *command, *response;
    int i;

    printf("QoS Monitor\n");
    printf("Commands: enable, disable, status\n");

    while (fgets(input, MAX_LINE, stdin)) {
        response = strtok(input, "\n");
        command = strtok(NULL, " ");

        for (i = 0; commands[i].command!= NULL; i++) {
            if (strcmp(command, commands[i].command) == 0) {
                commands[i].handler(response);
                break;
            }
        }

        if (commands[i].command == NULL) {
            printf("Invalid command\n");
        }
    }

    return 0;
}