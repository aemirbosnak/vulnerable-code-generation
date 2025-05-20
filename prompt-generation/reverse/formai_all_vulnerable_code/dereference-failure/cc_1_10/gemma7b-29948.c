//Gemma-7B DATASET v1.0 Category: System administration ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 256

typedef struct Command {
    char name[MAX_CMD_LEN];
    char description[MAX_CMD_LEN];
    struct Command* next;
} Command;

Command* createCommand(char* name, char* description) {
    Command* newCommand = malloc(sizeof(Command));
    strcpy(newCommand->name, name);
    strcpy(newCommand->description, description);
    newCommand->next = NULL;
    return newCommand;
}

void addCommand(Command* head, char* name, char* description) {
    Command* newCommand = createCommand(name, description);
    if (head == NULL) {
        head = newCommand;
    } else {
        Command* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newCommand;
    }
}

int main() {
    Command* commands = NULL;
    addCommand(commands, "reboot", "Resets the system.");
    addCommand(commands, "shutdown", "Shuts down the system.");
    addCommand(commands, "ping", "Tests network connectivity.");

    char cmd[MAX_CMD_LEN];

    printf("Enter a command: ");
    scanf("%s", cmd);

    Command* current = commands;
    while (current) {
        if (strcmp(cmd, current->name) == 0) {
            printf("Command: %s\n", current->name);
            printf("Description: %s\n", current->description);
            break;
        }
        current = current->next;
    }

    if (current == NULL) {
        printf("Command not found.\n");
    }

    return 0;
}