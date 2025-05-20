//Falcon2-11B DATASET v1.0 Category: Interprocess communication ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int shmid;
    char *shm_data;
    size_t shm_size;
    pid_t pid;
    int status;

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <shm_key> <shm_size>\n", argv[0]);
        return 1;
    }

    shm_size = atoi(argv[2]);
    shmid = shmget(atoi(argv[1]), shm_size, 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget");
        return 1;
    }

    shm_data = shmat(shmid, (void *)0, 0);
    if (shm_data == (void *)-1) {
        perror("shmat");
        return 1;
    }

    pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        // Child process
        for (int i = 0; i < shm_size; i++) {
            shm_data[i] = i % 10;
            printf("Child: %d (%d)\n", i, shm_data[i]);
            sleep(1);
        }
    } else {
        // Parent process
        for (int i = 0; i < shm_size; i++) {
            shm_data[i] = i % 10;
            printf("Parent: %d (%d)\n", i, shm_data[i]);
            sleep(1);
        }

        waitpid(pid, &status, 0);
        printf("Parent: Child process exited with status %d\n", status);

        shmdt(shm_data);
        shmctl(shmid, IPC_RMID, NULL);
    }

    return 0;
}