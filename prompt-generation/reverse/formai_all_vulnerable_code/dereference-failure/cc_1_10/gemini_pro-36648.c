//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Mini version of Unix pipes
int pipex(int n, char *argv[]) {
    int fd[2];
    pid_t pid;

    pipe(fd);

    if ((pid = fork()) == 0) { // Child: Read from pipe
        dup2(fd[0], 0);
        close(fd[0]);
        close(fd[1]);
        execvp(argv[0], argv);
        _exit(1);
    }

    // Parent: Write to pipe
    dup2(fd[1], 1);
    close(fd[0]);
    close(fd[1]);
    execvp(n > 1 ? argv[1] : argv[n - 1], argv + 1);
    _exit(1);
}

int main() {
    char line[1024];
    char *argv[16];
    int n, i;

    while (1) {
        printf("mini-shell$ ");
        if (fgets(line, sizeof(line), stdin) == NULL) break;

        // Tokenize the line
        n = 0;
        argv[n] = strtok(line, " \n");
        while (argv[n] != NULL) {
            argv[++n] = strtok(NULL, " \n");
        }

        // Parse the first few words
        if (!strcmp(argv[0], "exit")) break;
        else if (!strcmp(argv[0], "cd")) {
            if (n > 1) chdir(argv[1]);
        } else if (!strcmp(argv[0], "|")) { // Pipe
            pipex(n - 1, argv + 1);
        } else { // Normal command
            if ((i = fork()) == 0) {
                execvp(argv[0], argv);
                _exit(1);
            }
            wait(NULL);
        }
    }

    return 0;
}