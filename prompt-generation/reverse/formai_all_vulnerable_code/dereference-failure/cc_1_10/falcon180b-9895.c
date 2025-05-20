//Falcon-180B DATASET v1.0 Category: System administration ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_COMMANDS 10
#define MAX_ARGUMENTS 10
#define MAX_PID 1000

int command_count = 0;
char **commands = NULL;
int *pids = NULL;
char **arguments = NULL;

void execute_command(char **command) {
    pid_t pid = fork();
    if (pid == 0) {
        execvp(command[0], command);
        perror("Error: ");
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("Error: ");
        exit(EXIT_FAILURE);
    } else {
        pids[command_count] = pid;
        command_count++;
    }
}

void print_status() {
    printf("Command\tPID\tStatus\n");
    for (int i = 0; i < command_count; i++) {
        printf("%s\t%d\t", commands[i], pids[i]);
        if (waitpid(pids[i], NULL, WNOHANG) == 0) {
            printf("Running\n");
        } else {
            printf("Terminated\n");
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Error: No command specified.\n");
        return 1;
    }

    commands = (char **)malloc(MAX_COMMANDS * sizeof(char *));
    pids = (int *)malloc(MAX_COMMANDS * sizeof(int));
    arguments = (char **)malloc(MAX_ARGUMENTS * sizeof(char *));

    strcpy(commands[0], "ls");
    strcpy(commands[1], "pwd");
    strcpy(commands[2], "date");

    execute_command(commands[0]);
    execute_command(commands[1]);
    execute_command(commands[2]);

    while (1) {
        print_status();
        sleep(1);
    }

    return 0;
}