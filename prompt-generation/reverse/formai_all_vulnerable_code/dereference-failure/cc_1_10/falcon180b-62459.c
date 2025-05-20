//Falcon-180B DATASET v1.0 Category: System administration ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define MAX_ENV_VARIABLES 10

typedef struct {
    char *name;
    char *value;
} EnvVar;

int launch_shell(char **envp) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0) {
        // Child process
        if (execve("/bin/bash", NULL, envp) == -1) {
            perror("execve");
            exit(EXIT_FAILURE);
        }
    } else if (pid < 0) {
        // Error forking
        perror("fork");
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) &&!WIFSIGNALED(status));

        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        } else {
            return -1;
        }
    }
}

int execute_command(char *command, char **envp) {
    pid_t pid;
    int status;
    char *args[MAX_ARGUMENTS];
    int argc = 0;
    char *token;

    token = strtok(command, " ");
    while (token!= NULL && argc < MAX_ARGUMENTS) {
        args[argc++] = token;
        token = strtok(NULL, " ");
    }
    args[argc] = NULL;

    pid = launch_shell(envp);

    if (pid == -1) {
        return -1;
    }

    return pid;
}

int main(int argc, char *argv[]) {
    char input_buffer[MAX_COMMAND_LENGTH];
    char **envp;
    int env_count = 0;
    int status;

    envp = malloc(sizeof(char *) * MAX_ENV_VARIABLES);
    if (envp == NULL) {
        fprintf(stderr, "Error allocating memory for environment variables.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < argc; i++) {
        if (strcmp(argv[i], "--") == 0) {
            break;
        }

        EnvVar *var = malloc(sizeof(EnvVar));
        if (var == NULL) {
            fprintf(stderr, "Error allocating memory for environment variable.\n");
            exit(EXIT_FAILURE);
        }

        var->name = argv[i];
        var->value = NULL;

        envp[env_count++] = var->name;
    }

    while (fgets(input_buffer, sizeof(input_buffer), stdin)!= NULL) {
        input_buffer[strcspn(input_buffer, "\n")] = '\0';

        status = execute_command(input_buffer, envp);
        if (status == -1) {
            fprintf(stderr, "Error executing command.\n");
        }
    }

    for (int i = 0; i < env_count; i++) {
        free(envp[i]);
    }
    free(envp);

    return 0;
}