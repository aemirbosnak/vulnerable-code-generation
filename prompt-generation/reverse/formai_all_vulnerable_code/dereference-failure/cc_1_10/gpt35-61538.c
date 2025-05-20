//FormAI DATASET v1.0 Category: System administration ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>

#define MAX_ARGS 10
#define MAX_CMD_LEN 1024

typedef struct {
    char* args[MAX_ARGS];
    int args_count;
} command;

typedef struct node {
    command* cmd;
    struct node* next;
} node;

node* commands_list = NULL;

/**
* Adds a new command to the list of commands
*/
void add_command(char* cmd) {
    command* c = (command*)malloc(sizeof(command));
    c->args_count = 0;

    char delim[] = " ";
    char* token = strtok(cmd, delim);

    while(token != NULL) {
        c->args[c->args_count++] = token;
        token = strtok(NULL, delim);
    }

    node* new_node = (node*)malloc(sizeof(node));
    new_node->cmd = c;
    new_node->next = NULL;

    if(commands_list == NULL) {
        commands_list = new_node;
    }
    else {
        node* temp = commands_list;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

/**
* Executes all commands in the list asynchronously
*/
void execute_commands() {
    node* temp = commands_list;

    while(temp != NULL) {
        pid_t pid = fork();

        if(pid == 0) {
            execvp(temp->cmd->args[0], temp->cmd->args);
        }
        else if(pid > 0) {
            // Parent process
        }
        else {
            printf("Error occurred while forking: %s\n", strerror(errno));
            exit(1);
        }

        temp = temp->next;
    }

    // Wait for all child processes to finish
    while(wait(NULL) > 0);
}

int main() {
    char cmd[MAX_CMD_LEN];

    printf("Enter commands to execute (enter 'quit' to exit): ");

    while(1) {
        fgets(cmd, MAX_CMD_LEN, stdin);

        // Remove newline character at the end
        cmd[strcspn(cmd, "\n")] = 0;

        if(strcmp(cmd, "quit") == 0) {
            break;
        }
        else {
            add_command(cmd);
        }
    }

    execute_commands();

    return 0;
}