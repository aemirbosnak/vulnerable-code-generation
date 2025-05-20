//Falcon2-11B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX_NAME_LENGTH 50
#define MAX_COMMAND_LENGTH 100
#define MAX_ROOM_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char command[MAX_COMMAND_LENGTH];
    char room[MAX_ROOM_LENGTH];
} Command;

void printRoom(char* room);
void executeCommand(Command* command);

int main() {
    Command commands[3] = {
        {"Romeo", "move", "balcony"},
        {"Juliet", "move", "balcony"},
        {"Romeo", "say", "Juliet, I come!"}
    };

    for (int i = 0; i < 3; i++) {
        printRoom(commands[i].room);
        printf("--> %s: %s\n", commands[i].name, commands[i].command);
        executeCommand(&commands[i]);
    }

    return 0;
}

void printRoom(char* room) {
    printf("Room: %s\n", room);
}

void executeCommand(Command* command) {
    char* commandWords[3];
    strcpy(commandWords[0], command->command);
    strcpy(commandWords[1], command->room);

    switch (strncmp(commandWords[0], "move", 4)) {
        case 0:
            printf("Romeo has moved to the %s\n", commandWords[1]);
            break;
        case 1:
            printf("Juliet has moved to the %s\n", commandWords[1]);
            break;
        default:
            printf("Invalid command: %s\n", command->command);
            break;
    }
}