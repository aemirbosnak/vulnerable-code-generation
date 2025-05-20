//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 1024
#define SHM_KEY 0x12345678

void* shared_memory;

int main(int argc, char *argv[]) {
    int shmid;
    int pid;
    char *ptr;
    int i;

    shmid = shmget(SHM_KEY, SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error creating shared memory segment.\n");
        exit(1);
    }

    shared_memory = shmat(shmid, NULL, 0);
    if ((void*)-1 == shared_memory) {
        printf("Error attaching to shared memory segment.\n");
        exit(1);
    }

    for (i = 0; i < SIZE; i++) {
        ((char*)shared_memory)[i] = 0;
    }

    pid = fork();
    if (pid == -1) {
        printf("Error forking child process.\n");
        exit(1);
    } else if (pid == 0) {
        // Child process
        ptr = (char*)shared_memory;
        for (i = 0; i < SIZE; i++) {
            *ptr++ = 'A';
        }
        printf("Child process has written to shared memory.\n");
        exit(0);
    } else {
        // Parent process
        wait(NULL);
        ptr = (char*)shared_memory;
        for (i = 0; i < SIZE; i++) {
            printf("%c", *ptr++);
        }
        printf("\n");
        exit(0);
    }

    return 0;
}