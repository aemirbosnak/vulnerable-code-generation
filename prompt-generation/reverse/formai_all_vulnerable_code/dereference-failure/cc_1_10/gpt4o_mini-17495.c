//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAXLINE 1024  // Maximum command line length
#define MAXARGS 128   // Maximum number of arguments

void eval(char *cmdline);
int parseline(const char *cmdline, char **argv);
void do_exit();
void list_jobs();
void change_directory(char *path);
void execute_command(char **argv);

int main() {
    char cmdline[MAXLINE]; // Command line
    while (1) {
        printf("myshell> ");  // Prompt for input
        if (fgets(cmdline, MAXLINE, stdin) == NULL) {
            // Handle end of input
            if (feof(stdin)) {
                exit(0); // Exit on EOF
            }
            continue;
        }
        eval(cmdline); // Evaluate the command line
    }
    return 0;
}

void eval(char *cmdline) {
    char *argv[MAXARGS]; // Argument list
    int bg; // Should the job run in bg or fg?

    // Parse the command line
    bg = parseline(cmdline, argv);
    if (argv[0] == NULL) {
        return; // Ignore empty lines
    }

    // Handle built-in commands
    if (strcmp(argv[0], "exit") == 0) {
        do_exit();
    } else if (strcmp(argv[0], "cd") == 0) {
        change_directory(argv[1]);
        return;
    } else if (strcmp(argv[0], "jobs") == 0) {
        list_jobs();
        return;
    }

    // Execute external command
    execute_command(argv);
}

int parseline(const char *cmdline, char **argv) {
    char *buf = strdup(cmdline); // Duplicate the command line
    char *delim; // Pointer for delimiting the command
    int bg; // Background job flag
    int argc = 0;

    // Start parsing
    buf[strlen(buf) - 1] = ' '; // Replace '\n' with space
    while (*buf) {
        // Skip spaces
        while (*buf == ' ') {
            buf++;
        }
        // Build the argument list
        delim = strchr(buf, ' ');
        if (delim) {
            *delim = '\0';
            argv[argc++] = buf;
            buf = delim + 1;
        } else {
            argv[argc++] = buf;
            break;
        }
    }
    argv[argc] = NULL; // Null-terminate the argument list

    // Check if it's a background job
    if (argc > 0 && strcmp(argv[argc - 1], "&") == 0) {
        bg = 1;
        argv[--argc] = NULL;
    } else {
        bg = 0;
    }
    free(buf); // Free memory allocated by strdup
    return bg;
}

void do_exit() {
    printf("Exiting the shell. Goodbye!\n");
    exit(0);
}

void change_directory(char *path) {
    if (path == NULL || strlen(path) == 0) {
        fprintf(stderr, "cd: missing argument\n");
        return;
    }
    
    if (chdir(path) != 0) {
        perror("cd"); // Print error if chdir fails
    }
}

void list_jobs() {
    // In this simplistic shell, we have no job control implemented,
    // just a demonstration of how you might list jobs.
    printf("No jobs to show in this simple shell implementation.\n");
}

void execute_command(char **argv) {
    pid_t pid; // pid of the child process
    if ((pid = fork()) == 0) {
        // Child process
        if (execvp(argv[0], argv) < 0) {
            perror("Command execution failed: ");
            exit(1);
        }
    }

    // Parent process waits for child
    int bg = strcmp(argv[strlen(argv) - 1], "&") == 0 ? 1 : 0;
    if (!bg) {
        waitpid(pid, NULL, 0); // Wait for foreground job to finish
    }
}