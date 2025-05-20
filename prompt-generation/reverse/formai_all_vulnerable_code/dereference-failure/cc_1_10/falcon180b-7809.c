//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY 0x12345678
#define SHM_SIZE 1024

int main() {
    int shmid;
    char *shm;

    shmid = shmget(SHM_KEY, SHM_SIZE, 0666 | IPC_CREAT);
    if (shmid == -1) {
        printf("Error creating shared memory segment: %s\n", strerror(errno));
        exit(1);
    }

    shm = (char *) shmat(shmid, NULL, 0);
    if (shm == (char *) -1) {
        printf("Error attaching to shared memory segment: %s\n", strerror(errno));
        exit(1);
    }

    printf("Shared memory segment created and attached successfully.\n");

    strcpy(shm, "Hello, world!");

    printf("Shared memory segment initialized with 'Hello, world!'\n");

    sleep(5);

    strcpy(shm, "Interprocess communication is the future!");

    printf("Shared memory segment updated with 'Interprocess communication is the future!'\n");

    sleep(5);

    shmdt(shm);
    shmctl(shmid, IPC_RMID, NULL);

    printf("Shared memory segment detached and destroyed.\n");

    return 0;
}