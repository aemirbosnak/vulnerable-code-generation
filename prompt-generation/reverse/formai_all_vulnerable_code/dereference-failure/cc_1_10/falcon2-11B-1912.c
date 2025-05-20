//Falcon2-11B DATASET v1.0 Category: Basic Unix-like Shell ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    char *path_to_exec = ".";
    char **argv_to_exec = NULL;
    int status = 0;
    pid_t child_pid;
    int pipefd[2];
    int i;
    char *command = NULL;

    while (1) {
        printf("\n%s:~$ ", path_to_exec);
        if (fgets(command, 1024, stdin) == NULL) {
            break;
        }
        printf("%s\n", command);

        // execute the command
        for (i = 0; i < argc; i++) {
            if (strcmp(argv[i], "-c") == 0) {
                command = argv[i+1];
                i++;
            }
        }

        if (fork() == 0) {
            close(pipefd[0]);
            dup2(pipefd[1], STDOUT_FILENO);
            close(pipefd[1]);
            dup2(pipefd[1], STDIN_FILENO);
            close(pipefd[1]);
            execlp(path_to_exec, command, (char *)NULL);
        } else {
            close(pipefd[0]);
            close(pipefd[1]);
            waitpid(child_pid, &status, 0);
        }
    }

    return 0;
}