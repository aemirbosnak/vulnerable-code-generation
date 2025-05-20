//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

#define FIFO_FILE "myfifo"

int main(int argc, char *argv[])
{
    int fd, status;
    int count = 0;
    pid_t pid;

    // Create a named pipe
    if (mkfifo(FIFO_FILE, 0666) < 0)
    {
        if (errno != EEXIST)
        {
            perror("mkfifo");
            exit(EXIT_FAILURE);
        }
    }

    // Fork a child process
    if ((pid = fork()) < 0)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    // Child process reads from the pipe
    if (pid == 0)
    {
        int n;
        char buf[1024];

        // Open the pipe for reading
        if ((fd = open(FIFO_FILE, O_RDONLY)) < 0)
        {
            perror("open");
            exit(EXIT_FAILURE);
        }

        // Read from the pipe until the end-of-file is reached
        while ((n = read(fd, buf, sizeof(buf))) > 0)
        {
            count += n;
        }

        // Close the pipe
        close(fd);

        // Print the number of bytes read
        printf("Child process read %d bytes from the pipe\n", count);

        exit(EXIT_SUCCESS);
    }

    // Parent process writes to the pipe
    else
    {
        int n;
        char buf[1024];

        // Open the pipe for writing
        if ((fd = open(FIFO_FILE, O_WRONLY)) < 0)
        {
            perror("open");
            exit(EXIT_FAILURE);
        }

        // Write to the pipe
        for (int i = 0; i < 100; i++)
        {
            n = snprintf(buf, sizeof(buf), "Hello from the parent process (%d)\n", i);
            if (write(fd, buf, n) < 0)
            {
                perror("write");
                exit(EXIT_FAILURE);
            }
        }

        // Close the pipe
        close(fd);

        // Wait for the child process to terminate
        wait(&status);

        // Print the exit status of the child process
        printf("Child process exited with status %d\n", WEXITSTATUS(status));

        // Delete the named pipe
        unlink(FIFO_FILE);
    }

    return EXIT_SUCCESS;
}