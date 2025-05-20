//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_CMD_LEN 256

typedef struct Node {
    char **commands;
    struct Node *next;
} Node;

Node *head = NULL;

void addCommand(char **command) {
    Node *newNode = malloc(sizeof(Node));
    newNode->commands = malloc(MAX_CMD_LEN * sizeof(char *));
    newNode->next = NULL;

    for (int i = 0; command[i] != NULL; i++) {
        newNode->commands[i] = strdup(command[i]);
    }

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }
}

int main() {

    char cmd[MAX_CMD_LEN];

    while (1) {
        printf("$ ");
        fgets(cmd, MAX_CMD_LEN, stdin);

        if (strcmp(cmd, "exit") == 0) {
            break;
        }

        char **command = malloc(MAX_CMD_LEN * sizeof(char *));

        int i = 0;
        char *token = strtok(cmd, " ");

        while (token) {
            command[i++] = strdup(token);
            token = strtok(NULL, " ");
        }

        command[i] = NULL;

        addCommand(command);

        free(command);
    }

    return 0;
}