//FormAI DATASET v1.0 Category: Interprocess communication ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    int fd;
    char *buffer;
    pid_t child_pid;

    fd = shm_open("/myshm", O_CREAT | O_RDWR, 0666);

    if(fd == -1)
    {
        perror("Failed to create shared memory segment");
        return 1;
    }
    else
    {
        ftruncate(fd, BUFFER_SIZE);

        buffer = mmap(NULL, BUFFER_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

        if(buffer == MAP_FAILED)
        {
            perror("Failed to map shared memory segment");
            return 1;
        }

        child_pid = fork();

        if(child_pid == -1)
        {
            perror("Failed to fork child process");
            return 1;
        }
        else if(child_pid == 0)
        {
            char *data_to_send = "Hello, parent process! This is the child process speaking.";
            memcpy(buffer, data_to_send, strlen(data_to_send) + 1);
            exit(0);
        }

        wait(NULL);

        printf("Received data from child process: %s\n", buffer);

        munmap(buffer, BUFFER_SIZE);
        close(fd);
        shm_unlink("/myshm");
    }

    return 0;
}