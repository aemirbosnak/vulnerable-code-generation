//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 64

// Function to parse command and arguments
int parse_command(char *line, char **arguments)
{
    int arg_count = 0;
    char *arg;

    while ((arg = strsep(&line, " \t\n")) != NULL && arg_count < MAX_ARGUMENTS) {
        if (*arg != '\0')
            arguments[arg_count++] = arg;
    }

    return arg_count;
}

// Function to execute the command
void execute_command(char **arguments)
{
    pid_t pid;
    int status;

    if ((pid = fork()) < 0) {
        printf("Error: Unable to fork process\n");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        if (execvp(arguments[0], arguments) < 0) {
            printf("Error: Unable to execute command\n");
            exit(EXIT_FAILURE);
        }
    } else {
        // Parent process
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}

// Signal handler function to ignore the Ctrl+C and Ctrl+Z signals
void signal_handler(int signum)
{
    printf("\nShell >> ");
    fflush(stdout);
}

// Main function
int main()
{
    char line[MAX_COMMAND_LENGTH];
    char *arguments[MAX_ARGUMENTS];
    int arg_count;

    signal(SIGINT, SIG_IGN);
    signal(SIGTSTP, SIG_IGN);

    printf("Welcome to my super awesome Unix-like Shell!\n");
    printf("Enter 'exit' to quit the shell\n\n");

    while (1) {
        printf("Shell >> ");
        if (fgets(line, MAX_COMMAND_LENGTH, stdin) == NULL)
            break;

        arg_count = parse_command(line, arguments);
        if (arg_count == 0)
            continue;

        if (strcmp(arguments[0], "exit") == 0)
            break;

        if (strcmp(arguments[0], "cd") == 0) {
            if (arg_count == 1)
                chdir(getenv("HOME"));
            else
                chdir(arguments[1]);

            continue;
        }

        execute_command(arguments);
    }

    printf("Bye bye! Have a great day :)\n");

    return 0;
}