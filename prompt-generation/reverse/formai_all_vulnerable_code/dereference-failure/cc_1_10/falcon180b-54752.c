//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 256
#define MAX_ARGUMENTS 64
#define MAX_ENV_VARIABLES 64

typedef struct {
    char *name;
    char *value;
} env_var_t;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <command>\n", argv[0]);
        return 1;
    }

    char command[MAX_COMMAND_LENGTH] = {0};
    strcpy(command, argv[1]);

    char *args[MAX_ARGUMENTS] = {0};
    int num_args = 0;
    char *token = strtok(command, " ");
    while (token!= NULL) {
        args[num_args] = token;
        num_args++;
        token = strtok(NULL, " ");
    }

    env_var_t env_vars[MAX_ENV_VARIABLES] = {0};
    int num_env_vars = 0;
    char *env_var_token = strtok(command, " ");
    while (env_var_token!= NULL && env_var_token[0] == '$') {
        env_var_t *var = &env_vars[num_env_vars];
        var->name = env_var_token + 1;
        var->value = strtok(NULL, " ");
        num_env_vars++;
        env_var_token = strtok(NULL, " ");
    }

    pid_t pid = fork();
    if (pid == -1) {
        printf("Error forking process: %s\n", strerror(errno));
        return 1;
    } else if (pid == 0) {
        // Child process
        for (int i = 0; i < num_env_vars; i++) {
            setenv(env_vars[i].name, env_vars[i].value, 1);
        }

        execvp(args[0], args);
        printf("Error executing command: %s\n", strerror(errno));
        return 1;
    } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
    }

    return 0;
}