//FormAI DATASET v1.0 Category: Interprocess communication ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int pipefd[2];
    pid_t pid;
    char buffer[BUFFER_SIZE];

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <message>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) { /* Child process */
        close(pipefd[1]); /* Close unused write end */

        if (read(pipefd[0], buffer, BUFFER_SIZE) == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        printf("%s\n", buffer);

        close(pipefd[0]);
        _exit(EXIT_SUCCESS);
    } else { /* Parent process */
        close(pipefd[0]); /* Close unused read end */

        if (write(pipefd[1], argv[1], strlen(argv[1])) == -1) {
            perror("write");
            exit(EXIT_FAILURE);
        }

        close(pipefd[1]); /* Reader will see EOF */
        wait(NULL); /* Wait for child */
        exit(EXIT_SUCCESS);
    }
}