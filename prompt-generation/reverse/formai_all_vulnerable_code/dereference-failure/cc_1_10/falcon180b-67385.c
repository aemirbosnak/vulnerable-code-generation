//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 10
#define TRUE 1
#define FALSE 0

int shmid;
char *shmaddr;

void main() {
    int i, pid, status;
    char *shmat_result;

    shmid = shmget(IPC_PRIVATE, SIZE * sizeof(char), IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Shared memory creation failed\n");
        exit(1);
    }

    shmat_result = (char *) shmat(shmid, NULL, 0);
    if ((int) shmat_result == -1) {
        printf("Shared memory attach failed\n");
        exit(2);
    }

    shmaddr = shmat_result;

    for (i = 0; i < SIZE; i++) {
        shmaddr[i] = 'A' + i;
    }

    printf("Shared memory created and initialized\n");

    pid = fork();
    if (pid == -1) {
        printf("Fork failed\n");
        exit(3);
    } else if (pid == 0) {
        printf("Child process started\n");
        sleep(2);
        printf("Child process writing to shared memory\n");
        for (i = 0; i < SIZE; i++) {
            shmaddr[i] = 'a' + i;
        }
        printf("Child process exiting\n");
        exit(0);
    } else {
        printf("Parent process waiting for child\n");
        wait(&status);
        printf("Child process terminated\n");
        sleep(2);
        printf("Parent process reading from shared memory\n");
        for (i = 0; i < SIZE; i++) {
            printf("%c ", shmaddr[i]);
        }
        printf("\n");
        exit(0);
    }
}