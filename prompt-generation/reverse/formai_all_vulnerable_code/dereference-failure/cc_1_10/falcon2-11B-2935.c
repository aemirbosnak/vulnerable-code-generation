//Falcon2-11B DATASET v1.0 Category: Interprocess communication ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define MAX_MESSAGE_SIZE 1024
#define MAX_SHM_SIZE 4096

int main(int argc, char *argv[]) {
    int shmid, status;
    char *shm_data;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <message>\n", argv[0]);
        exit(1);
    }

    shmid = shmget(IPC_PRIVATE, MAX_SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    shm_data = (char *) shmat(shmid, NULL, 0);
    if (shm_data == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    status = write(1, argv[1], strlen(argv[1]));
    if (status < 0) {
        perror("write");
        exit(1);
    }

    status = read(0, shm_data, MAX_MESSAGE_SIZE);
    if (status < 0) {
        perror("read");
        exit(1);
    }

    status = shmdt(shm_data);
    if (status == -1) {
        perror("shmdt");
        exit(1);
    }

    status = shmctl(shmid, IPC_RMID, NULL);
    if (status == -1) {
        perror("shmctl");
        exit(1);
    }

    return 0;
}