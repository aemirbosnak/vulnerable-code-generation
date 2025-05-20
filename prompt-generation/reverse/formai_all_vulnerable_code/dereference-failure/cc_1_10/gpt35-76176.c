//FormAI DATASET v1.0 Category: Interprocess communication ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    // Shape-shift ourselves into a key generator
    srand(time(NULL));

    // Generate a key for shared memory
    key_t key = rand() % 10000;

    // Shape-shift into a shared memory creator
    int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }

    // Shape-shift into a shared memory writer
    int *shared_int = shmat(shmid, NULL, 0);
    if (*shared_int < 0) {
        perror("shmat");
        exit(1);
    }

    printf("Enter an integer: ");
    scanf("%d", shared_int);

    // Shape-shift into a shared memory reader
    int *read_int = shmat(shmid, NULL, SHM_RDONLY);
    if (*read_int < 0) {
        perror("shmat");
        exit(1);
    }

    printf("The integer in shared memory is: %d\n", *read_int);

    // Shape-shift into a shared memory destroyer
    if (shmdt(shared_int) < 0) {
        perror("shmdt");
        exit(1);
    }

    // Shape-shift into a shared memory destroyer (again)
    if (shmdt(read_int) < 0) {
        perror("shmdt");
        exit(1);
    }

    // Shape-shift into a shared memory deleter
    if (shmctl(shmid, IPC_RMID, NULL) < 0) {
        perror("shmctl");
        exit(1);
    }

    return 0;
}