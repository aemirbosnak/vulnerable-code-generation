//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    // From the void of nothingness, a shared memory segment emerged.
    int shmid = shmget(IPC_PRIVATE, 1024, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    // A portal into this enigmatic realm was crafted.
    void *shmaddr = shmat(shmid, NULL, 0);
    if (shmaddr == (void *)-1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    // Father Time, in all his majesty, entered the shared tapestry.
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // The child, a mischievous sprite, skipped into the shared memory.
        int *counter = shmaddr;
        for (int i = 0; i < 10000; i++) {
            *counter++;
        }
        exit(EXIT_SUCCESS);
    } else {
        // The parent, a watchful guardian, observed the child's antics.
        int *counter = shmaddr;
        for (int i = 0; i < 10000; i++) {
            printf("Counter: %d\n", *counter);
            sleep(1);
        }
        waitpid(pid, NULL, 0);
        shmdt(shmaddr);
        shmctl(shmid, IPC_RMID, NULL);
        exit(EXIT_SUCCESS);
    }

    return 0;
}