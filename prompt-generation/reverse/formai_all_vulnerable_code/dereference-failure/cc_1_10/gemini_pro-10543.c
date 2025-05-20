//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

// Shell shenanigans
#define SH_BUFSIZE 1024
#define SH_MAXARGS 32
#define SH_PROMPT "shell> "

// Built-in commands
#define SH_CMD_EXIT "exit"
#define SH_CMD_CD "cd"

// Function prototypes
int sh_exec(char **args);
void sh_prompt(void);
char **sh_split(char *line, int *argc);

int main(void)
{
    // Shell loop
    while (1) {
        // Prompt
        sh_prompt();

        // Get input
        char buf[SH_BUFSIZE];
        if (fgets(buf, SH_BUFSIZE, stdin) == NULL) {
            perror("fgets");
            exit(EXIT_FAILURE);
        }

        // Split input into args
        int argc;
        char **args = sh_split(buf, &argc);

        // Execute command
        if (args != NULL) {
            if (strcmp(args[0], SH_CMD_EXIT) == 0) {
                exit(EXIT_SUCCESS);
            } else if (strcmp(args[0], SH_CMD_CD) == 0) {
                if (chdir(args[1]) == -1) {
                    perror("chdir");
                }
            } else {
                if (sh_exec(args) == -1) {
                    perror("execvp");
                }
            }
        }

        // Free args
        free(args);
    }

    return 0;
}

int sh_exec(char **args)
{
    // Fork and execute
    pid_t pid = fork();
    if (pid == -1) {
        return -1;
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            return -1;
        }
    } else {
        // Wait for child
        int status;
        wait(&status);
    }

    return 0;
}

void sh_prompt(void)
{
    printf(SH_PROMPT);
}

char **sh_split(char *line, int *argc)
{
    // Allocate memory for args
    char **args = malloc(SH_MAXARGS * sizeof(char *));
    if (args == NULL) {
        return NULL;
    }

    // Split line into args
    int i = 0;
    char *arg = strtok(line, " ");
    while (arg != NULL && i < SH_MAXARGS) {
        args[i++] = arg;
        arg = strtok(NULL, " ");
    }

    // Update argc
    *argc = i;

    return args;
}