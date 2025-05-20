//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(void) {

    char cwd[1024];
    char userInput[100];
    char *args[10];
    int argc = 0;
    pid_t pid;

    while(1) {
        
        getcwd(cwd, sizeof(cwd));
        printf("%s$ ", cwd);
        fgets(userInput, sizeof(userInput), stdin);
        userInput[strcspn(userInput, "\n")] = 0;

        char *token = strtok(userInput, " ");
        while(token != NULL) {
            args[argc++] = token;
            token = strtok(NULL, " ");
        }
        args[argc] = NULL;

        if(strcmp(args[0], "exit") == 0) {
            exit(0);
        }

        if((pid = fork()) < 0) {
            printf("Fork Error");
            exit(0);
        }

        if(pid == 0) {
            execvp(args[0], args);
            printf("Error: %s command not found\n", args[0]);
            exit(0);
        }
        else {
            wait(NULL);
            argc = 0;
            memset(args, 0, sizeof(args));
        }
    }
    return 0;
}