//FormAI DATASET v1.0 Category: Interprocess communication ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <stdbool.h>

#define SHM_SIZE 256

int main() {
    key_t key;
    int shmid;
    char *data;
    pid_t pid;

    key = ftok("ipc_program", 0);

    shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);

    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    data = shmat(shmid, NULL, 0);
    if (data == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        while (true) {
            if (*data != '\0') {
                printf("Received message: %s\n", data);
                *data = '\0';
            }
            sleep(1);
        }
    } else {
        printf("Enter message to send: ");
        fgets(data, SHM_SIZE, stdin);
        wait(NULL);
    }

    shmdt(data);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}