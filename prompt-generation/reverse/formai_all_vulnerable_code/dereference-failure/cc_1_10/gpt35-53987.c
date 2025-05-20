//FormAI DATASET v1.0 Category: System administration ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_SIZE 1024

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s command\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char command[MAX_SIZE];
    memset(command, 0, sizeof(command));

    for (int i = 1; i < argc; ++i) {
        strncat(command, argv[i], strlen(argv[i]));
        if (i != argc - 1) {
            strncat(command, " ", 1);
        }
    }

    pid_t pid, wpid;
    int status;

    pid = fork();

    if (pid == 0) { // child process
        if (execl("/bin/bash", "/bin/bash", "-c", command, NULL) < 0) {
            perror("execl");
            exit(EXIT_FAILURE);
        }
    } else if (pid > 0) { // parent process
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
            if (wpid == -1) {
                perror("waitpid");
                exit(EXIT_FAILURE);
            }
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    } else { // error
        perror("fork");
        exit(EXIT_FAILURE);
    }

    return 0;
}