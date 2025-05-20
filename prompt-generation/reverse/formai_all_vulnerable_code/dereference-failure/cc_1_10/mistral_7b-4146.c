//MISTRAL-7B DATASET v1.0 Category: Interprocess communication ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define PIPE_NAME "myfifo"

int main() {
    int fd[2];
    pid_t pid;
    char *random_string;
    char read_buffer[100];

    // create named pipe
    if (pipe(fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // fork a child process
    pid = fork();

    if (pid < 0) { // error occurred
        perror("fork");
        close(fd[0]);
        close(fd[1]);
        exit(EXIT_FAILURE);
    } else if (pid > 0) { // parent process
        // generate random string
        random_string = (char *) malloc(sizeof(rand()) % 50 + 1);
        memset(random_string, 'A' + (rand() % 26), sizeof(random_string) - 1);
        random_string[sizeof(random_string) - 1] = '\0';

        // write random string to named pipe
        if (write(fd[1], random_string, strlen(random_string)) == -1) {
            perror("write");
            close(fd[0]);
            close(fd[1]);
            free(random_string);
            exit(EXIT_FAILURE);
        }

        close(fd[0]);
        close(fd[1]);

        printf("Parent wrote: %s\n", random_string);
        free(random_string);
    } else { // child process
        // close writing end of pipe
        close(fd[1]);

        // read string from named pipe
        if (read(fd[0], read_buffer, sizeof(read_buffer) - 1) == -1) {
            perror("read");
            close(fd[0]);
            exit(EXIT_FAILURE);
        }

        read_buffer[sizeof(read_buffer) - 1] = '\0';

        // print received string
        printf("Child read: %s\n", read_buffer);
        close(fd[0]);
        exit(EXIT_SUCCESS);
    }

    return EXIT_SUCCESS;
}