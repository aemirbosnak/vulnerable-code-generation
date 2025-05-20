//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100 // maximum length of a command
#define MAX_ARGUMENTS 10 // maximum number of arguments in a command
#define MAX_PATH_LENGTH 50 // maximum length of a file path

char *get_command(); // to get user input
char **parse_command(char *command); // to tokenize user input
void execute_command(char **command); // to execute user command
void execute_external_command(char **command); // to execute external commands
char *check_command_in_paths(char *command, char **path_list); // check if command exists in paths

int main() {
    char *command;
    char **parsed_command;

    printf("Welcome to MyShell! Type 'exit' to quit.\n");

    while (1) {
        printf("$ "); //print command prompt
        command = get_command(); //get user input
        parsed_command = parse_command(command); //tokenize user input

        if (strcmp(parsed_command[0], "exit") == 0) { //exit condition
            free(command);
            free(parsed_command);
            printf("Goodbye!\n");
            break;
        }

        execute_command(parsed_command); //execute user command

        free(command);
        free(parsed_command);
    }

    return 0;
}

char *get_command() {
    char *command = malloc(MAX_COMMAND_LENGTH * sizeof(char));
    fgets(command, MAX_COMMAND_LENGTH, stdin);

    // remove trailing newline character
    for (int i = 0; i < MAX_COMMAND_LENGTH; i++) {
        if (command[i] == '\n') {
            command[i] = '\0';
            break;
        }
    }

    return command;
}

char **parse_command(char *command) {
    char **parsed_command = malloc(MAX_ARGUMENTS * sizeof(char *));
    int i = 0;

    // tokenize command by space
    parsed_command[i] = strtok(command, " ");
    while (parsed_command[i] != NULL && i < MAX_ARGUMENTS - 1) {
        i++;
        parsed_command[i] = strtok(NULL, " ");
    }

    return parsed_command;
}

void execute_command(char **command) {
    if (command[0] == NULL) {
        return; //empty command
    }

    if (strcmp(command[0], "cd") == 0) { //change directory command
        if (command[1] == NULL) { //no directory specified
            printf("cd: please specify a directory\n");
        } else {
            if (chdir(command[1]) != 0) { //error changing directory
                printf("cd: cannot change directory to %s\n", command[1]);
            }
        }
    } else {
        execute_external_command(command); //execute external command
    }
}

void execute_external_command(char **command) {
    char *path_list[] = {"/usr/bin", "/usr/local/bin", NULL}; //list of paths to search for command
    char *command_path = check_command_in_paths(command[0], path_list); //get full path of command

    pid_t pid = fork();
    if (pid == 0) {
        if (command_path != NULL) { //command found in path
            //execute command with arguments
            execv(command_path, command);
            //if execv returns, error occurred
            printf("Error executing command: %s\n", command[0]);
            exit(1);
        } else { //command not found in path
            printf("Command not found: %s\n", command[0]);
            exit(1);
        }
    } else if (pid < 0) { //error occurred
        printf("Error executing command: %s\n", command[0]);
    } else { //parent process
        int status;
        waitpid(pid, &status, 0); //wait for child process to finish
    }

    //free memory used for command_path
    if (command_path != NULL) {
        free(command_path);
    }
}

char *check_command_in_paths(char *command, char **path_list) {
    int i = 0;
    while (path_list[i] != NULL) {
        //construct full path to command
        char *command_path = malloc(MAX_PATH_LENGTH * sizeof(char));
        strcpy(command_path, path_list[i]);
        strcat(command_path, "/");
        strcat(command_path, command);

        //check if command exists in path
        if (access(command_path, X_OK) == 0) {
            return command_path; //return full path if command found
        }

        free(command_path);
        i++;
    }

    return NULL; //return NULL if command not found in any path
}