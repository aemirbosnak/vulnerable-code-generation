//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 10

int main() {
    int shmid;
    char *shm;
    key_t key;
    int i;

    // generate unique key
    key = ftok(".", 'a');

    // create shared memory segment
    shmid = shmget(key, SIZE * sizeof(char), IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    // attach to shared memory segment
    shm = shmat(shmid, NULL, 0);
    if (shm == (char *) -1) {
        printf("Error attaching to shared memory segment\n");
        exit(1);
    }

    // initialize shared memory segment
    for (i = 0; i < SIZE; i++) {
        shm[i] = 'a' + i;
    }

    // print shared memory segment
    printf("Shared memory segment:\n");
    for (i = 0; i < SIZE; i++) {
        printf("%c ", shm[i]);
    }
    printf("\n");

    // detach from shared memory segment
    if (shmdt(shm) == -1) {
        printf("Error detaching from shared memory segment\n");
        exit(1);
    }

    // delete shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        printf("Error deleting shared memory segment\n");
        exit(1);
    }

    return 0;
}