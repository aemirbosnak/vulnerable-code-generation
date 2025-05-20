//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#define MAX_SIZE 100

int main()
{
    int fd[2];
    pid_t pid;

    // Create pipe
    if (pipe(fd) == -1)
    {
        printf("Pipe failed\n");
        exit(1);
    }

    // Fork process
    pid = fork();

    if (pid < 0) // Error occurred
    {
        printf("Fork Failed\n");
        exit(1);
    }
    else if (pid > 0) // Parent process
    {
        char buffer[MAX_SIZE];
        close(fd[0]); // Close reading end in parent

        // Write to pipe
        sprintf(buffer, "Hello from Parent!");
        write(fd[1], buffer, strlen(buffer));

        close(fd[1]); // Close writing end in parent
        wait(NULL); // Wait for child to send message
    }
    else // Child process
    {
        char buffer[MAX_SIZE];
        close(fd[1]); // Close writing end in child

        // Read from pipe
        read(fd[0], buffer, MAX_SIZE);
        printf("Message from parent: %s\n", buffer);

        close(fd[0]); // Close reading end in child
        exit(0);
    }

    return 0;
}