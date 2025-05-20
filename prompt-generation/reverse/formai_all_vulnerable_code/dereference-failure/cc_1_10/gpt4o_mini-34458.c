//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAXLINE 1024
#define MAXARGS 128

void eval(char *cmdline);
int parseline(char *buf, char **argv);
void bgfg(char **argv);
int builtin_cmd(char **argv);

int main() {
    char cmdline[MAXLINE];

    while (1) {
        printf("myshell> ");
        fflush(stdout);

        if (!fgets(cmdline, MAXLINE, stdin)) {
            break;  // End of file (Ctrl+D)
        }

        eval(cmdline);
    }
    return 0;
}

void eval(char *cmdline) {
    char *argv[MAXARGS];  // Argument list
    char buf[MAXLINE];    // Holds modified command line
    int bg;              // Should the job run in bg or fg

    strcpy(buf, cmdline);
    bg = parseline(buf, argv);  // Parse the line
    if (argv[0] == NULL) {
        return;  // Ignore empty lines
    }

    if (!builtin_cmd(argv)) {
        pid_t pid = fork();  // Fork a child process
        if (pid == 0) { // Child process
            if (execvp(argv[0], argv) < 0) {
                printf("%s: Command not found\n", argv[0]);
                exit(0);
            }
        }

        // Parent process
        if (!bg) { // Wait for foreground job to complete
            int status;
            waitpid(pid, &status, 0);
        } else { // Background job
            printf("Job [%d] started in background\n", pid);
        }
    }
}

int parseline(char *buf, char **argv) {
    char *delim;             // Points to first space delimiter
    int bg;                 // False job by default

    buf[strlen(buf)-1] = ' '; // Replace newline with space
    while (*buf && (*buf == ' ')) {
        buf++;              // Ignore leading spaces
    }

    // Build the argv array
    int argc = 0;
    while ((delim = strchr(buf, ' '))) {
        argv[argc++] = buf; // Add the command to the argv list
        *delim = '\0'; // Null-terminate the command string
        buf = delim + 1; // Move to the next part of the string
        
        while (*buf && (*buf == ' ')) {
            buf++;  // Ignore spaces
        }
    }
    argv[argc] = NULL; // Null-terminate the argv array

    // Check if the job is a background job
    if (argc > 0 && strcmp(argv[argc - 1], "&") == 0) {
        bg = 1;
        argv[--argc] = NULL; // Remove the '&'
    } else {
        bg = 0;
    }
    return bg;
}

int builtin_cmd(char **argv) {
    if (strcmp(argv[0], "exit") == 0) {
        exit(0); // Exit the shell
    }

    if (strcmp(argv[0], "cd") == 0) {
        if (argv[1] == NULL) {
            fprintf(stderr, "cd: missing argument\n");
        } else if (chdir(argv[1]) != 0) {
            perror("cd error"); // Change the working directory
        }
        return 1; // Indicate a built-in command was executed
    }
    return 0; // Not a built-in command
}