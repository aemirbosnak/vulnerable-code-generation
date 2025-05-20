//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY (key_t)1234
#define SHM_SIZE 1024

// shared memory segment
typedef struct {
    int count;
} shared_data_t;

int main() {
    int shmid;
    void *shm;
    shared_data_t *data;

    // create shared memory segment
    shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error: could not create shared memory segment.\n");
        exit(1);
    }

    // attach shared memory segment
    shm = shmat(shmid, NULL, 0);
    if (shm == (void *)-1) {
        printf("Error: could not attach shared memory segment.\n");
        exit(1);
    }

    // initialize shared data
    data = (shared_data_t *)shm;
    data->count = 0;

    // detach shared memory segment
    if (shmdt(shm) == -1) {
        printf("Error: could not detach shared memory segment.\n");
        exit(1);
    }

    // delete shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        printf("Error: could not delete shared memory segment.\n");
        exit(1);
    }

    return 0;
}