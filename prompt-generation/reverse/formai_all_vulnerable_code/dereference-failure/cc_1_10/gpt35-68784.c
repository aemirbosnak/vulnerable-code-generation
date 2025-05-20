//FormAI DATASET v1.0 Category: Interprocess communication ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <signal.h>

#define SHM_SIZE 4096

void signal_handler(int sig) {
    printf("Caught signal %d, cleaning up shared memory\n", sig);
}

int main() {
    int shmid;
    char *shm, *s;
    key_t key = 12345;

    signal(SIGINT, signal_handler);

    if ((shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    if ((shm = shmat(shmid, NULL, 0)) == (char *) - 1) {
        perror("shmat");
        exit(1);
    }

    // Write to shared memory
    s = shm;
    strcpy(s, "Hello");

    s = &shm[strlen("Hello")];
    *s = ' ';
    s++;

    strcpy(s, "World");

    while (*shm != '*') {
        sleep(1);
    }

    if (shmdt(shm) == -1) {
        perror("shmdt");
        exit(1);
    }

    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    printf("Done\n");

    return 0;
}