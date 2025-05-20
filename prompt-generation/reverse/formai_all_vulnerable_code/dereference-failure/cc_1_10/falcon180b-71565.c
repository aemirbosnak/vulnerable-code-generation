//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define SHM_KEY 5678
#define SHM_SIZE 1024

int shmid;
char *shmptr;

void init_shared_memory() {
    int shm_id;
    shm_id = shmget(SHM_KEY, SHM_SIZE, 0666 | IPC_CREAT);

    if (shm_id == -1) {
        fprintf(stderr, "Error: shmget() failed\n");
        exit(1);
    }

    shmid = shm_id;
    shmptr = (char *) shmat(shmid, NULL, 0);

    if ((int) shmptr == -1) {
        fprintf(stderr, "Error: shmat() failed\n");
        exit(1);
    }

    memset(shmptr, 0, SHM_SIZE);
}

void write_message(char *message) {
    strcpy(shmptr, message);
}

char *read_message() {
    return shmptr;
}

int main() {
    int fd[2];
    pid_t childpid;

    if (pipe(fd) == -1) {
        fprintf(stderr, "Error: pipe() failed\n");
        exit(1);
    }

    childpid = fork();

    if (childpid == -1) {
        fprintf(stderr, "Error: fork() failed\n");
        exit(1);
    } else if (childpid == 0) {
        // Child process
        close(fd[0]);
        init_shared_memory();
        write_message("Hello, World!");
        exit(0);
    } else {
        // Parent process
        close(fd[1]);
        char message[SHM_SIZE];
        read(fd[0], message, SHM_SIZE);
        printf("Received message: %s\n", message);
        exit(0);
    }

    return 0;
}