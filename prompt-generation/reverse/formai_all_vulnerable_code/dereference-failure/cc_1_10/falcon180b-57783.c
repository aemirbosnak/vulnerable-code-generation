//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/mman.h>

#define SIZE 1024

int main() {
    int fd[2];
    pid_t pid;
    char *ptr;
    char input[SIZE];
    int status;

    // Create pipe
    if (pipe(fd) < 0) {
        printf("Pipe failed\n");
        exit(1);
    }

    // Fork process
    pid = fork();

    if (pid < 0) { // Error occurred
        printf("Fork Failed\n");
        exit(1);
    } else if (pid == 0) { // Child process
        close(fd[0]); // Close reading end
        dup(fd[1]); // Duplicate writing end
        close(fd[1]);

        printf("Child: Sending message to parent...\n");
        write(fd[1], "Hello from child!", strlen("Hello from child!"));
        exit(0);
    } else { // Parent process
        close(fd[1]); // Close writing end
        dup(fd[0]); // Duplicate reading end
        close(fd[0]);

        printf("Parent: Waiting for message from child...\n");
        read(fd[0], input, SIZE);
        printf("Received message: %s\n", input);

        if (ptr = mmap(NULL, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd[0], 0)) {
            *(ptr + strlen("Hello from child! ")) = '\0';
            printf("Changed message to: %s\n", ptr);
            munmap(ptr, SIZE);
        } else {
            printf("Mmap failed\n");
        }

        wait(&status);
    }

    return 0;
}