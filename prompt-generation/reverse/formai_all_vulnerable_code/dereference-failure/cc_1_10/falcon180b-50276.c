//Falcon-180B DATASET v1.0 Category: System administration ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 1024

int main() {
    int fd, shmid;
    char *shm;
    char *file_name = "my_file.txt";

    fd = open(file_name, O_RDWR);
    if (fd == -1) {
        printf("Error opening file!\n");
        exit(1);
    }

    ftruncate(fd, 0);

    shmid = shmget(IPC_PRIVATE, SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error creating shared memory segment!\n");
        exit(1);
    }

    shm = (char *) shmat(shmid, 0, 0);
    if (shm == (void *) -1) {
        printf("Error attaching to shared memory segment!\n");
        exit(1);
    }

    memset(shm, 0, SIZE);

    pid_t pid = fork();
    if (pid == 0) {
        printf("Child process started\n");
        dup2(fd, 0);
        dup2(fd, 1);
        dup2(fd, 2);
        execlp("vi", "vi", file_name, NULL);
        perror("execlp");
        exit(1);
    } else if (pid < 0) {
        printf("Error forking!\n");
        exit(1);
    } else {
        wait(NULL);
        printf("Child process terminated\n");
        close(fd);
        shmdt(shm);
        shmctl(shmid, IPC_RMID, NULL);
    }

    return 0;
}