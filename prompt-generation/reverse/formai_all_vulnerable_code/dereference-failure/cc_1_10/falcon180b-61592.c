//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/msg.h>

#define SIZE 10
#define BUFFER_SIZE 100

int main() {
    int fd;
    char *buffer = (char *)malloc(BUFFER_SIZE);
    char *tmp;

    // Create shared memory segment
    fd = shmget(IPC_PRIVATE, SIZE * sizeof(int), IPC_CREAT | 0644);
    if (fd == -1) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }
    int *shared_memory = (int *)shmat(fd, NULL, 0);

    // Initialize shared memory
    for (int i = 0; i < SIZE; i++) {
        shared_memory[i] = i * 10;
    }

    // Create semaphore
    int semid = semget(IPC_PRIVATE, 1, IPC_CREAT | 0644);
    if (semid == -1) {
        printf("Error creating semaphore\n");
        exit(1);
    }
    semctl(semid, 0, SETVAL, 0);

    // Create message queue
    int msgid = msgget(IPC_PRIVATE, IPC_CREAT | 0644);
    if (msgid == -1) {
        printf("Error creating message queue\n");
        exit(1);
    }

    // Fork child process
    pid_t pid = fork();
    if (pid == -1) {
        printf("Error forking child process\n");
        exit(1);
    } else if (pid == 0) {
        // Child process
        int count = 0;
        while (count < SIZE) {
            sem_wait(semid);
            tmp = (char *)malloc(BUFFER_SIZE);
            sprintf(tmp, "Child process: %d", shared_memory[count]);
            msgsnd(msgid, tmp, BUFFER_SIZE, 0);
            count++;
            sem_post(semid);
        }
        exit(0);
    } else {
        // Parent process
        while (1) {
            sem_wait(semid);
            msgrcv(msgid, buffer, BUFFER_SIZE, 0, 0);
            printf("Parent process: %s\n", buffer);
            sem_post(semid);
        }
    }

    return 0;
}