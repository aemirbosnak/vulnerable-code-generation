//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_LENGTH 1024 // Maximum length of a command
#define MAX_ARGS 64     // Maximum number of arguments

char *history[MAX_ARGS]; // Array to keep track of command history
int history_count = 0;   // Count to keep track of the number of commands entered so far

// Function to split a command string into arguments
void parse_command_args(char *command, char **args)
{
    for (int i = 0; i < MAX_ARGS; i++)
    {
        args[i] = strsep(&command, " ");
        if (args[i] == NULL)
            break;
        if (strlen(args[i]) == 0)
            i--;
    }
}

// Handler for SIGINT to prevent Ctrl-C from killing the shell
void handle_sigint(int sig)
{
    printf("\n");
    printf("mysh $ ");
    fflush(stdout);
}

int main()
{
    char *command;                 // Input command
    char *args[MAX_ARGS];          // Parsed command arguments
    pid_t pid;                     // Process ID
    int status;                    // Process status
    struct sigaction sa;           // Signal action
    sa.sa_handler = &handle_sigint; // Set signal handler
    sa.sa_flags = SA_RESTART;       // Restart functions if interrupted by handler signal
    sigfillset(&sa.sa_mask);       // Mask other signals while handling handler signal
    sigaction(SIGINT, &sa, NULL);  // Set handler for SIGINT signal
    printf("Welcome to mysh - a simple Unix-like shell!\n");
    while (1)
    {
        printf("mysh $ ");
        fflush(stdout);
        command = (char *)malloc(MAX_LENGTH * sizeof(char));
        fgets(command, MAX_LENGTH, stdin);
        command[strlen(command) - 1] = '\0'; // Remove newline character from input
        if (strcmp(command, "exit") == 0)    // Exit command
        {
            exit(0);
        }
        if (strlen(command) > 0) // Add command to history
        {
            history[history_count++] = strdup(command);
        }
        if (strcmp(command, "history") == 0) // History command
        {
            for (int i = 0; i < history_count; i++)
            {
                printf("%d: %s\n", i + 1, history[i]);
            }
            continue;
        }
        if (strcmp(command, "!!") == 0) // Execute last command in history
        {
            if (history_count == 0)
            {
                printf("No commands in history!\n");
                continue;
            }
            strcpy(command, history[history_count - 1]);
        }
        if (command[0] == '!') // Execute command by index from history
        {
            int index = atoi(&command[1]);
            if (index <= 0 || index > history_count)
            {
                printf("Invalid command index!\n");
                continue;
            }
            strcpy(command, history[index - 1]);
        }
        parse_command_args(command, args); // Parse command arguments
        pid = fork();                      // Create child process
        if (pid == 0)                      // Child process
        {
            if (execvp(args[0], args) == -1) // Execute command
            {
                perror("mysh");
            }
            exit(0);
        }
        else if (pid < 0) // Fork error
        {
            perror("mysh");
        }
        else // Parent process
        {
            do
            {
                waitpid(pid, &status, WUNTRACED); // Wait for child process to finish
            } while (!WIFEXITED(status) && !WIFSIGNALED(status)); // Keep waiting if process is not exited or terminated
        }
        free(command); // Free memory allocated for command
    }
    return 0;
}