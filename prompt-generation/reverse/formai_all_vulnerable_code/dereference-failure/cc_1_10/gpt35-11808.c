//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
 
#define MAX_ARGS 10
#define MAX_ARG_LEN 100
#define MAX_PATH_LEN 300
#define MAX_INPUT_LEN 200
 
char* path_env; // stores the PATH environment variable
 
/* This function prints the shell prompt. */
void print_prompt() {
    char dir[MAX_PATH_LEN];
    getcwd(dir, MAX_PATH_LEN);
    printf("%s $", dir);
}
 
/* This function reads input from the user. */
void read_input(char* input) {
    fgets(input, MAX_INPUT_LEN, stdin);
    input[strlen(input)-1] = '\0';
}
 
/* This function parses the input string into command and arguments. */
void parse_input(char* input, char** command, char*** args, int* last_arg_index) {
    int i = 0;
    char* token = strtok(input, " ");
    *command = token;
    *last_arg_index = 0;
    while (token != NULL) {
        (*args)[i++] = token;
        token = strtok(NULL, " ");
        *last_arg_index = i;
    }
    (*args)[i] = NULL;
}
 
/* This function looks for the command in the directories specified in the PATH environment variable. */
char* look_for_command(char* command) {
    char* p = strtok(path_env, ":");
    while (p != NULL) {
        char path[MAX_PATH_LEN];
        strcpy(path, p); 
        strcat(path, "/");
        strcat(path, command);
        if (access(path, X_OK) == 0) {
            char* result = (char*) malloc(strlen(path)+1);
            strcpy(result, path);
            return result;
        }
        p = strtok(NULL, ":");
    }
    return NULL;
}
 
/* This function executes the command using fork() and execvp(). */
void execute_command(char* command, char** args) {
    pid_t pid = fork();
    if (pid == 0) {
        execvp(command, args);
        printf("Error: could not execute command.\n");
        exit(1);
    } else {
        wait(NULL);
    }
}
 
/* This function frees the memory allocated for the arguments. */
void free_args(char** args) {
    int i = 0;
    while (args[i] != NULL) {
        free(args[i++]);
    }
    free(args);
}
 
int main(int argc, char** argv, char** envp) {
    path_env = getenv("PATH"); // get the PATH environment variable
    char* input = (char*) malloc(MAX_INPUT_LEN);
    char* command;
    char** args = (char**) malloc(MAX_ARGS * sizeof(char*));
    int last_arg_index;
    while (1) {
        print_prompt();
        read_input(input);
        if (strcmp(input, "exit") == 0) {
            free(input);
            free_args(args);
            printf("Goodbye!\n");
            exit(0);
        }
        parse_input(input, &command, &args, &last_arg_index);
        char* command_path = look_for_command(command);
        if (command_path == NULL) {
            printf("Error: command not found.\n");
            continue;
        }
        args[0] = command_path; // replace the command with the full path
        execute_command(command_path, args);
    }
}