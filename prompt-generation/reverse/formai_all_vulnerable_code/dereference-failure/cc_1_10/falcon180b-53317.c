//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_LINE 80 // Maximum line length
#define MAX_ARGS 10 // Maximum number of arguments
#define MAX_ENV 20 // Maximum number of environment variables

char **environ; // Pointer to environment variables

typedef struct {
    char **args; // Pointer to command line arguments
    char **envs; // Pointer to environment variables
} process_t;

void start_shell() {
    char input[MAX_LINE];
    printf("Enter commands:\n");
    while(fgets(input, MAX_LINE, stdin)!= NULL) {
        char *line = strdup(input);
        char *token = strtok(line, " ");
        if(token == NULL) {
            continue;
        }
        process_t process;
        process.args = malloc(sizeof(char *) * MAX_ARGS);
        int num_args = 0;
        while(num_args < MAX_ARGS && token!= NULL) {
            process.args[num_args] = strdup(token);
            num_args++;
            token = strtok(NULL, " ");
        }
        process.args[num_args] = NULL;
        process.envs = environ;
        pid_t pid = fork();
        if(pid == -1) {
            fprintf(stderr, "Fork failed: %s\n", strerror(errno));
            exit(1);
        } else if(pid == 0) {
            execvp(process.args[0], process.args);
            fprintf(stderr, "Execvp failed: %s\n", strerror(errno));
            exit(1);
        } else {
            int status;
            waitpid(pid, &status, 0);
        }
    }
}

int main() {
    environ = malloc(sizeof(char *) * MAX_ENV);
    environ[0] = strdup("PATH=/bin:/usr/bin");
    start_shell();
    return 0;
}