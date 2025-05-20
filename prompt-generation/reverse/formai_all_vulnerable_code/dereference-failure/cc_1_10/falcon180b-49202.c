//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 50
#define ID 1234

int main() {
    int shmid;
    char *shmptr;
    char *buffer;
    pid_t pid;
    int status;

    shmid = shmget(ID, SIZE, IPC_CREAT | 0666);

    if (shmid < 0) {
        printf("Error creating shared memory\n");
        exit(1);
    }

    shmptr = shmat(shmid, NULL, 0);

    if (shmptr == (void *) -1) {
        printf("Error attaching shared memory\n");
        exit(1);
    }

    buffer = (char *) malloc(SIZE);

    if (buffer == NULL) {
        printf("Error allocating memory\n");
        exit(1);
    }

    pid = fork();

    if (pid == 0) {
        strcpy(buffer, "Child process");
        printf("Child: %s\n", buffer);
        shmdt(shmptr);
        exit(0);
    }

    wait(&status);

    strcpy(buffer, "Parent process");
    printf("Parent: %s\n", buffer);

    shmdt(shmptr);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}