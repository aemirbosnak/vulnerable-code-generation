//FormAI DATASET v1.0 Category: System administration ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_BUFF 1024

int main(int argc, char *argv[]) {
    pid_t pid;
    int status, fd;
    char *buff;
    char *filename;
    char *arg_list[] = {"cat", NULL};

    if (argc < 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(1);
    }

    filename = argv[1];
    fd = open(filename, O_RDONLY);

    if (fd == -1) {
        perror("open");
        exit(1);
    }

    /* allocate buffer for reading file */
    buff = malloc(MAX_BUFF * sizeof(char));

    if (buff == NULL) {
        fprintf(stderr, "Failed to allocate memory for buffer\n");
        exit(1);
    }

    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) { /* child process */
        close(STDIN_FILENO); /* redirect stdin to file descriptor for opened file */
        if (dup(fd) == -1) {
            perror("dup");
            exit(1);
        }
        close(fd);
        execvp(arg_list[0], arg_list); /* execute cat command */
        perror("execvp");
        exit(1);
    } else { /* parent process */
        wait(&status); /* wait for child process to finish */
        if (WIFEXITED(status)) {
            printf("Child exited with status %d\n", WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("Child terminated by signal %d\n", WTERMSIG(status));
        } else {
            printf("Child did not exit normally\n");
        }
    }

    free(buff);
    close(fd);
    return 0;
}