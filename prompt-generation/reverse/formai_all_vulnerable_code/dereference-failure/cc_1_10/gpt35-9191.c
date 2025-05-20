//FormAI DATASET v1.0 Category: Interprocess communication ; Style: thoughtful
/* This C program demonstrates interprocess communication using shared memory. 
 * It creates two processes: a parent process and a child process. The child
 * process writes a string to the shared memory area and the parent process
 * reads the string from the shared memory area.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    int shmid;
    char *shmaddr, str[100];
    const int SIZE =1024;
    key_t key;
    pid_t pid;

    // Generate a unique key for the shared memory segment.
    key = ftok("ipcmem", 'R');

    // Create the shared memory segment.
    shmid = shmget(key, SIZE, 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach to the shared memory segment.
    shmaddr = (char *) shmat(shmid, NULL, 0);
    if (shmaddr == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // Create a child process.
    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) {
        // Child process. Write the string to the shared memory segment.
        printf("Enter a string:\n");
        fgets(str, sizeof(str), stdin);
        strcpy(shmaddr, str);
        exit(0);
    } else {
        // Parent process. Wait for the child to exit and read the string from the shared memory segment.
        wait(NULL);
        printf("The string read from the shared memory segment is:\n%s", shmaddr);

        // Detach from the shared memory segment and delete it.
        if (shmdt(shmaddr) == -1) {
            perror("shmdt");
            exit(1);
        }
        if (shmctl(shmid, IPC_RMID, 0) == -1) {
            perror("shmctl");
            exit(1);
        }
    }

    return 0;
}