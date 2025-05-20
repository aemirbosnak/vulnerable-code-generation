//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <time.h>
#include <string.h>
#include <errno.h>

#define SHM_SIZE 1024

int shmid;
char *shmaddr;

void read_shared_memory() {
    printf("Reading from shared memory...\n");
    sprintf(shmaddr, "Hello, World!");
    sleep(1);
    sprintf(shmaddr, "Interprocess communication is easy with C!");
}

void write_shared_memory() {
    printf("Writing to shared memory...\n");
    strcpy(shmaddr, "Hello, World!");
    sleep(1);
    strcpy(shmaddr, "Interprocess communication is easy with C!");
}

int main() {
    int pid;
    int status;

    shmid = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        fprintf(stderr, "shmget() failed with error: %d\n", errno);
        exit(1);
    }

    shmaddr = shmat(shmid, NULL, 0);
    if (shmaddr == (char *) -1) {
        fprintf(stderr, "shmat() failed with error: %d\n", errno);
        exit(1);
    }

    pid = fork();

    if (pid == 0) {
        read_shared_memory();
        exit(0);
    } else {
        wait(&status);
        write_shared_memory();
        exit(0);
    }
}