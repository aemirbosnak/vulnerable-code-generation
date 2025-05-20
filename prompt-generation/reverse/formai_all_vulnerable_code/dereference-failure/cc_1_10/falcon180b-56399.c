//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY 0x12345678
#define SHM_SIZE 1024

int main(int argc, char *argv[]) {
    int shmid;
    void *shmaddr;
    int *shmptr;
    pid_t childpid;

    // create shared memory segment
    shmid = shmget(SHM_KEY, SHM_SIZE, 0644 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget");
        return 1;
    }

    // attach shared memory segment to process address space
    shmaddr = shmat(shmid, NULL, 0);
    if (shmaddr == (void *) -1) {
        perror("shmat");
        return 1;
    }

    // initialize shared memory
    shmptr = (int *) shmaddr;
    *shmptr = 0;

    // fork child process
    childpid = fork();
    if (childpid == -1) {
        perror("fork");
        return 1;
    } else if (childpid == 0) {
        // child process
        sleep(1); // give parent process time to initialize shared memory
        *shmptr = 1;
        printf("Child process wrote 1 to shared memory.\n");
        exit(0);
    } else {
        // parent process
        sleep(2); // give child process time to write to shared memory
        if (*shmptr == 1) {
            printf("Parent process read 1 from shared memory.\n");
        } else {
            printf("Parent process read unexpected value from shared memory.\n");
        }
        exit(0);
    }

    return 0;
}