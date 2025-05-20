//FormAI DATASET v1.0 Category: Interprocess communication ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/mman.h>
#include <fcntl.h>

#define SHM_NAME "/mysharedmemory"
#define SIZE 1024

void sig_handler(int sig)
{
    if (sig == SIGUSR1)
    {
        printf("Received a SIGUSR1 signal\n");
    }
}

int main(int argc, char **argv)
{
    int shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    if (shm_fd == -1)
    {
        perror("shm_open");
        exit(EXIT_FAILURE);
    }

    if (ftruncate(shm_fd, SIZE) == -1)
    {
        perror("ftruncate");
        exit(EXIT_FAILURE);
    }

    void *shm_ptr = mmap(NULL, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (shm_ptr == MAP_FAILED)
    {
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();
    if (pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0)
    {
        // Child Process

        // Signal Handler for SIGUSR1
        struct sigaction sa;
        sa.sa_handler = sig_handler;
        sa.sa_flags = 0;
        sigemptyset(&sa.sa_mask);
        if (sigaction(SIGUSR1, &sa, NULL) == -1)
        {
            perror("sigaction");
            exit(EXIT_FAILURE);
        }

        // Asynchronous IPC with parent process
        while (1)
        {
            if (strcmp(shm_ptr, "PING") == 0)
            {
                sprintf(shm_ptr, "PONG"); // Write response to shared memory
                kill(getppid(), SIGUSR1); // Notify parent process
            }
        }

        munmap(shm_ptr, SIZE); // Unmap shared memory
        close(shm_fd); // Close shared memory file descriptor
    }
    else
    {
        // Parent Process

        // Asynchronous IPC with child process
        while (1)
        {
            sprintf(shm_ptr, "PING"); // Write command to shared memory
            kill(pid, SIGUSR1); // Notify child process

            pause(); // Wait for signal from child process
        }

        munmap(shm_ptr, SIZE); // Unmap shared memory
        close(shm_fd); // Close shared memory file descriptor
        shm_unlink(SHM_NAME); // Remove shared memory object from system
    }

    return 0;
}