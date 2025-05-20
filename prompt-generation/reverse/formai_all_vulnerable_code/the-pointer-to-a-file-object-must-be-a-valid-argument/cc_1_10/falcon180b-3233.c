//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 256

// Function to split a command string into arguments
char **split_command(char *command)
{
    char **arguments = malloc(MAX_ARGUMENTS * sizeof(char*));
    int argument_count = 0;
    char *token = strtok(command, " ");

    while (token!= NULL) {
        arguments[argument_count] = strdup(token);
        argument_count++;
        token = strtok(NULL, " ");
    }

    arguments[argument_count] = NULL;
    return arguments;
}

// Function to execute a command and return its output as a string
char *execute_command(char **arguments)
{
    pid_t pid;
    int status;
    FILE *fp;
    char *output = NULL;
    size_t output_size = 0;

    pid = fork();

    if (pid == 0) {
        // Child process
        if (execvp(arguments[0], arguments) == -1) {
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    } else {
        // Parent process
        waitpid(pid, &status, 0);

        if (WIFEXITED(status)) {
            fp = popen("echo $?", "r");
            fscanf(fp, "%d", &status);
            pclose(fp);
        } else {
            status = WTERMSIG(status);
        }

        if (status == 0) {
            fp = popen("echo $(cat)", "r");
            while (fgets(output, MAX_COMMAND_LENGTH, fp)!= NULL) {
                output_size += strlen(output);
            }
            pclose(fp);
        } else {
            fprintf(stderr, "Command failed with status %d\n", status);
        }
    }

    return output;
}

int main(int argc, char **argv)
{
    char input[MAX_COMMAND_LENGTH];
    char **arguments;
    char *output;

    printf("Welcome to the Unix-like shell!\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        arguments = split_command(input);

        // Exit the shell if the user enters "exit"
        if (strcmp(arguments[0], "exit") == 0) {
            break;
        }

        output = execute_command(arguments);
        printf("%s", output);
        free(output);
        free(arguments);
    }

    return 0;
}