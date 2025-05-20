//FormAI DATASET v1.0 Category: Interprocess communication ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#define SHMSIZE 27

int main()
{
    pid_t pid;
    key_t key;
    int shmid;
    char *shmaddr, *s;

    // Generate a unique key
    key = ftok(".", 'S');

    // Create a shared memory segment
    shmid = shmget(key, SHMSIZE, IPC_CREAT | 0666);

    if (shmid < 0) {
        perror("Failed to create shared memory segment");
        exit(-1);
    }

    // Attach the shared memory segment to the address space of the process
    shmaddr = shmat(shmid, NULL, 0);

    if (shmaddr == (char *) -1) {
        perror("Failed to attach shared memory segment");
        exit(-1);
    }

    // Fork a child process
    pid = fork();

    if (pid < 0) {
        perror("Failed to fork");
        exit(-1);
    }

    // In the child process, write a message to the shared memory segment
    if (pid == 0) {
        s = shmaddr;

        for (char c = 'a'; c <= 'z'; c++) {
            *s++ = c;
            sleep(1);
        }

        *s = '\0';

        // Detach the shared memory segment
        shmdt(shmaddr);

        exit(0);
    }

    // In the parent process, read the message from the shared memory segment
    else {
        wait(NULL);
        printf("%s\n", shmaddr);

        // Detach the shared memory segment
        shmdt(shmaddr);

        // Delete the shared memory segment
        shmctl(shmid, IPC_RMID, NULL);
    }

    return 0;
}