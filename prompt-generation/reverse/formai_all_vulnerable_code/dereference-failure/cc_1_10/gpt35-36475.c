//FormAI DATASET v1.0 Category: System administration ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define CMD_SIZE 1024

char *get_user_input() {
    char *input = (char *) malloc(sizeof(char) * CMD_SIZE);
    if (!input) {
        printf("Error: Could not allocate memory for input buffer.\n");
        exit(EXIT_FAILURE);
    }
    printf("> ");
    fgets(input, CMD_SIZE, stdin);
    return input;
}

void run_command(char *cmd) {
    int status = system(cmd);
    if (status == -1) {
        printf("Error: Could not execute command\n");
        exit(EXIT_FAILURE);
    }
}

int main() {
    char *cmd;
    while (1) {
        printf("Enter a command to run or 'exit' to quit.\n");
        cmd = get_user_input();

        if (strcmp(cmd, "exit\n") == 0) {
            break;
        }
        else if (strcmp(cmd, "list processes\n") == 0) {
            run_command("ps -ax");
        }
        else if (strcmp(cmd, "list files\n") == 0) {
            run_command("ls -l");
        }
        else if (strcmp(cmd, "disk usage\n") == 0) {
            run_command("df -h");
        }
        else {
            printf("Unrecognized command: %s\n", cmd);
        }

        free(cmd);
    }
    return 0;
}