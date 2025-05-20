//FormAI DATASET v1.0 Category: Interprocess communication ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <string.h>

#define SHM_SIZE 1024

int main() {
    key_t key = 1234;
    int shmid;
    char* shmaddr;
    char message[SHM_SIZE];

    // Creating shared memory segment
    if ((shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    // Attaching shared memory segment to process address space
    if ((shmaddr = shmat(shmid, NULL, 0)) == (char*) -1) {
        perror("shmat");
        exit(1);
    }

    // Start child process
    pid_t pid = fork();

    if (pid < 0) { // Error
        fprintf(stderr, "Fork failed\n");
        exit(1);
    } else if (pid == 0) { // Child process
        printf("Enter message: ");
        fgets(message, SHM_SIZE, stdin);
        strncpy(shmaddr, message, SHM_SIZE);
        exit(0);
    } else { // Parent process
        wait(NULL);
        printf("Message received from child: %s", shmaddr);
    }

    // Detaching and removing shared memory segment
    if (shmdt(shmaddr) == -1) {
        perror("shmdt");
        exit(1);
    }
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    return 0;
}