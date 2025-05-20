//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 80

struct command {
    char *name;
    void (*function)(char *);
};

void takeoff(char *args) {
    printf("Drone is taking off\n");
}

void land(char *args) {
    printf("Drone is landing\n");
}

void fly_to(char *args) {
    printf("Drone is flying to target location\n");
}

void record_video(char *args) {
    printf("Drone is recording video\n");
}

void take_picture(char *args) {
    printf("Drone is taking picture\n");
}

struct command commands[] = {
    {"takeoff", takeoff},
    {"land", land},
    {"fly_to", fly_to},
    {"record_video", record_video},
    {"take_picture", take_picture},
    {NULL, NULL}
};

int main() {
    char input[MAX_COMMAND_LENGTH];
    char *command;
    int i;

    printf("Welcome to the Drone Remote Control!\n");

    while (1) {
        printf("Enter command: ");
        if (fgets(input, MAX_COMMAND_LENGTH, stdin) == NULL) {
            printf("Error: %s\n", strerror(errno));
            exit(1);
        }

        command = strtok(input, " ");
        for (i = 0; commands[i].name!= NULL; i++) {
            if (strcmp(command, commands[i].name) == 0) {
                commands[i].function(strtok(NULL, " "));
                break;
            }
        }

        if (commands[i].name == NULL) {
            printf("Invalid command\n");
        }
    }

    return 0;
}