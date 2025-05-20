//Falcon2-11B DATASET v1.0 Category: Interprocess communication ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// Function to create a pipe
void createPipe()
{
    int fds[2];
    if (pipe(fds) == -1)
    {
        perror("Error creating pipe");
        exit(1);
    }
}

// Function to write to the pipe
void writeToPipe(int fd)
{
    char buffer[10];
    sprintf(buffer, "Hello, world! from parent process.");
    write(fd, buffer, strlen(buffer));
    close(fd);
}

// Function to read from the pipe
void readFromPipe(int fd)
{
    char buffer[10];
    read(fd, buffer, sizeof(buffer));
    printf("Received message: %s\n", buffer);
    close(fd);
}

int main()
{
    createPipe();
    int childFd = fork();
    if (childFd == 0)
    {
        writeToPipe(0);
        readFromPipe(1);
    }
    else if (childFd > 0)
    {
        readFromPipe(0);
        writeToPipe(1);
    }
    return 0;
}