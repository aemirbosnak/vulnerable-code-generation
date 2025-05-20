//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY 0x12345678
#define SHM_SIZE 4096

int main() {
    int shmid;
    char *shm_addr;
    pid_t pid;

    // create shared memory segment
    shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // attach shared memory segment to process
    shm_addr = shmat(shmid, NULL, 0);
    if (shm_addr == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // fork child process
    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // child process writes to shared memory
        for (int i = 0; i < SHM_SIZE; i++) {
            *(shm_addr + i) = 'A' + i;
        }
        printf("Child wrote to shared memory\n");
    } else {
        // parent process reads from shared memory
        for (int i = 0; i < SHM_SIZE; i++) {
            printf("%c ", *(shm_addr + i));
        }
        printf("\n");
    }

    // detach and delete shared memory segment
    shmdt(shm_addr);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}