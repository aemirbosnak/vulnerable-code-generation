//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <string.h>

#define SIZE 1024

int main() {
    int shmid;
    char *shmaddr;
    int i;
    pid_t childpid;

    shmid = shmget(IPC_PRIVATE, SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    shmaddr = shmat(shmid, NULL, 0);
    if (shmaddr == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    for (i = 0; i < SIZE; i++) {
        shmaddr[i] = 'A' + i;
    }

    childpid = fork();

    if (childpid == 0) {
        for (i = 0; i < SIZE; i++) {
            shmaddr[i] = 'a' + i;
        }
        exit(0);
    } else {
        wait(NULL);
        for (i = 0; i < SIZE; i++) {
            if (shmaddr[i]!= 'A' + i) {
                printf("Error: Shared memory not updated correctly\n");
                exit(1);
            }
        }
        printf("Shared memory updated successfully\n");
    }

    shmdt(shmaddr);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}