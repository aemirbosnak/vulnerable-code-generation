//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SHM_KEY 1234
#define SHM_SIZE 1024

void child_process(int shmid) {
    char* shm_ptr = shmat(shmid, NULL, 0);
    if (shm_ptr == (void*)-1) {
        printf("Child process: shmat failed\n");
        exit(1);
    }

    char* str = shm_ptr;
    while (*str!= '\0') {
        printf("%c", *str);
        str++;
    }

    if (shmdt(shm_ptr) == -1) {
        printf("Child process: shmdt failed\n");
        exit(1);
    }

    exit(0);
}

int main() {
    int shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Parent process: shmget failed\n");
        exit(1);
    }

    char* shm_ptr = shmat(shmid, NULL, 0);
    if (shm_ptr == (void*)-1) {
        printf("Parent process: shmat failed\n");
        exit(1);
    }

    strcpy(shm_ptr, "Hello, world!");

    int pid = fork();
    if (pid == -1) {
        printf("Parent process: fork failed\n");
        exit(1);
    } else if (pid == 0) {
        child_process(shmid);
    } else {
        wait(NULL);
    }

    if (shmdt(shm_ptr) == -1) {
        printf("Parent process: shmdt failed\n");
        exit(1);
    }

    return 0;
}