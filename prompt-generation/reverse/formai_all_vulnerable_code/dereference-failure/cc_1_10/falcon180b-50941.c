//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 100

int main() {
    int shmid;
    key_t key;
    char *shm;
    int i;

    key = 12345;
    shmid = shmget(key, SIZE, 0666);

    if (shmid == -1) {
        printf("Error: Cannot get shared memory\n");
        exit(1);
    }

    shm = (char *) shmat(shmid, NULL, 0);

    if (shm == (char *) -1) {
        printf("Error: Cannot attach shared memory\n");
        exit(2);
    }

    for (i = 0; i < SIZE; i++) {
        shm[i] = 'A' + i;
    }

    printf("Shared memory has been initialized.\n");

    if (fork() == 0) {
        printf("Child process started.\n");
        for (i = 0; i < SIZE; i++) {
            if (shm[i]!= 'A' + i) {
                printf("Error: Shared memory corrupted\n");
                exit(3);
            }
        }
        printf("Shared memory is correct.\n");
        exit(0);
    } else {
        wait(NULL);
        printf("Parent process finished.\n");
    }

    return 0;
}