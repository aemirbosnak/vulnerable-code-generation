//GEMINI-pro DATASET v1.0 Category: System administration ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <time.h>

/* A custom function to handle errors */
void error(char *msg) {
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}

/*
 * A custom function to run a command with arguments in a child process.
 * It takes a command string, an array of arguments, and the number of arguments.
 */
int run_command(char *command, char **args, int num_args) {
    int pid, status;

    /* Create a child process */
    pid = fork();
    if (pid < 0) {
        error("fork");
    }

    /* Child process */
    if (pid == 0) {
        /* Replace the child process's image with the specified command */
        if (execvp(command, args) < 0) {
            error("execvp");
        }
    }

    /* Parent process */
    else {
        /* Wait for the child process to complete */
        waitpid(pid, &status, 0);

        /* Check the child process's exit status */
        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        } else {
            return -1;
        }
    }

    return 0;
}

int main(int argc, char **argv) {
    int i, status;
    char *args[] = {"ls", "-l", "/", NULL};

    /* Run the 'ls -l /' command in a child process */
    status = run_command("ls", args, 3);

    /* Check the exit status of the command */
    if (status == 0) {
        printf("The command 'ls -l /' ran successfully.\n");
    } else {
        fprintf(stderr, "The command 'ls -l /' failed with status %d.\n", status);
    }

    return 0;
}