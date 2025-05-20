//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY (1234)
#define SHM_SIZE (1024)

int main() {
    int shmid;
    char *shm;

    shmid = shmget(SHM_KEY, SHM_SIZE, 0666 | IPC_CREAT);
    if (shmid == -1) {
        printf("Error creating shared memory segment.\n");
        exit(1);
    }

    shm = shmat(shmid, NULL, 0);
    if (shm == (void *) -1) {
        printf("Error attaching to shared memory segment.\n");
        exit(1);
    }

    printf("Shared memory segment successfully created.\n");

    if (fork() == 0) {
        // Child process
        for (int i = 0; i < SHM_SIZE; i++) {
            shm[i] = 'a' + i;
        }
        printf("Child process wrote to shared memory.\n");
        exit(0);
    } else {
        // Parent process
        sleep(1);
        for (int i = 0; i < SHM_SIZE; i++) {
            if (shm[i]!= 'a' + i) {
                printf("Error: Shared memory not written correctly.\n");
                exit(1);
            }
        }
        printf("Parent process read from shared memory.\n");
        exit(0);
    }
}