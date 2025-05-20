//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

int main() {
    char *input, *token;
    char *args[50];
    char cwd[1024];

    while (1) {
        getcwd(cwd, sizeof(cwd));
        printf("%s$ ", cwd);

        input = fgets(input, BUFFER_SIZE, stdin);

        int arg_cnt = 0;
        token = strtok(input, " \n");

        while (token != NULL) {
            args[arg_cnt] = token;
            arg_cnt++;
            token = strtok(NULL, " \n");
        }

        args[arg_cnt] = NULL;

        if (strcmp(args[0], "cd") == 0) {
            if (arg_cnt == 2) {
                chdir(args[1]);
            }
            else {
                printf("Incorrect number of arguments\n");
            }
        }
        else if (strcmp(args[0], "exit") == 0) {
            exit(0);
        }
        else {
            int pid = fork();

            if (pid == 0) {
                execvp(args[0], args);
                printf("Command not found\n");
                exit(0);
            }
            else {
                wait(NULL);
            }
        }
    }

    return 0;
}