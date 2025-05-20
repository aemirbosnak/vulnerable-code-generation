//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define SHM_KEY 0x1234
#define SHM_SIZE 1024

int main() {

    int shmid;
    int fd;
    char *shm;
    pid_t pid;

    shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error creating shared memory\n");
        exit(1);
    }

    shm = (char *) shmat(shmid, NULL, 0);
    if (shm == (char *) -1) {
        printf("Error attaching to shared memory\n");
        exit(1);
    }

    fd = open("data.txt", O_RDONLY);
    if (fd == -1) {
        printf("Error opening file\n");
        exit(1);
    }

    pid = fork();

    if (pid == -1) {
        printf("Error forking\n");
        exit(1);
    } else if (pid == 0) {
        // Child process
        close(fd);
        read(0, shm, SHM_SIZE);
        shmdt(shm);
        exit(0);
    } else {
        // Parent process
        close(fd);
        wait(NULL);
        shmdt(shm);
        exit(0);
    }

    return 0;
}