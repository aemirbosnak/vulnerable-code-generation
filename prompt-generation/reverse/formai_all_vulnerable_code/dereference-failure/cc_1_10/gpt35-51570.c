//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 128
#define MAX_JOBS 32
#define MAX_PATH_LENGTH 256

int num_jobs = 0;
pid_t job_processes[MAX_JOBS];
char* job_commands[MAX_JOBS];

char* get_current_directory() {
    char* current_directory = (char*)malloc(MAX_PATH_LENGTH);
    if (getcwd(current_directory, MAX_PATH_LENGTH) == NULL) {
        perror("Error getting current directory");
        return NULL;
    }
    return current_directory;
}

void print_prompt() {
    char* current_directory = get_current_directory();
    if (current_directory == NULL) {
        printf("$ ");
    } else {
        printf("%s $ ", current_directory);
        free(current_directory);
    }
}

char* read_command() {
    char* command = (char*)malloc(MAX_COMMAND_LENGTH);
    if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL) {
        free(command);
        return NULL;
    }
    int len = strlen(command);
    if (command[len - 1] == '\n') {
        command[len - 1] = '\0';
    }
    return command;
}

char** parse_command(char* command, int* num_arguments) {
    int argc = 0;
    char* argument = strtok(command, " ");
    char** args = (char**)malloc(MAX_ARGUMENTS * sizeof(char*));
    while (argument != NULL && argc < MAX_ARGUMENTS - 1) {
        args[argc++] = argument;
        argument = strtok(NULL, " ");
    }
    args[argc] = NULL;
    *num_arguments = argc;
    return args;
}

void run_command(char** args) {
    if (strcmp(args[0], "cd") == 0) {
        if (args[1] == NULL) {
            chdir(getenv("HOME"));
        } else {
            chdir(args[1]);
        }
    } else if (strcmp(args[0], "exit") == 0) {
        exit(0);
    } else {
        pid_t pid = fork();
        if (pid == 0) {
            int result = execvp(args[0], args);
            if (result == -1) {
                perror("Error executing command");
            }
            exit(0);
        } else if (pid > 0) {
            job_processes[num_jobs] = pid;
            job_commands[num_jobs] = strdup(args[0]);
            num_jobs++;
        } else {
            perror("Error forking process");
        }
    }
}

void check_jobs() {
    int status;
    for (int i = 0; i < num_jobs; i++) {
        if (waitpid(job_processes[i], &status, WNOHANG) != 0) {
            printf("[%d] %s\n", i, job_commands[i]);
            num_jobs--;
            for (int j = i; j < num_jobs; j++) {
                job_processes[j] = job_processes[j+1];
                job_commands[j] = job_commands[j+1];
            }
        }
    }
}

int main() {
    while (1) {
        print_prompt();
        char* command = read_command();
        if (command == NULL) {
            printf("\n");
            exit(0);
        }
        int num_arguments = 0;
        char** args = parse_command(command, &num_arguments);
        if (num_arguments > 0) {
            run_command(args);
        }
        check_jobs();
        free(command);
        free(args);
    }
    return 0;
}