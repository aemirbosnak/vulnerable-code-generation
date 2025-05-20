//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_SIZE 100

int main() {
    int fd[2]; // file descriptors for interprocess communication
    pid_t pid; // process id for child process
    char input[MAX_SIZE]; // buffer to hold input from user
    char message[MAX_SIZE]; // buffer to hold message from child process

    // create pipe for interprocess communication
    if (pipe(fd) == -1) {
        printf("Error creating pipe\n");
        exit(1);
    }

    // fork a child process
    pid = fork();

    if (pid == -1) { // error occurred
        printf("Error forking process\n");
        exit(1);
    } else if (pid == 0) { // child process
        close(fd[0]); // close reading end of pipe
        dup2(fd[1], STDOUT_FILENO); // duplicate writing end of pipe to stdout
        close(fd[1]); // close writing end of pipe

        // prompt user for input
        printf("Enter a message: ");
        fgets(input, MAX_SIZE, stdin);

        // send message to parent process
        write(fd[1], input, strlen(input));

        // exit child process
        exit(0);
    } else { // parent process
        close(fd[1]); // close writing end of pipe
        char c;

        // wait for child process to send message
        while (read(fd[0], &c, 1) > 0) {
            strcat(message, &c);
        }

        // close reading end of pipe
        close(fd[0]);

        // print message received from child process
        printf("Message from child process: %s\n", message);
    }

    return 0;
}