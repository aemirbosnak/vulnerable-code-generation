//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/wait.h>
#include <sys/msg.h>

int main() {
    // Create shared memory segment
    key_t key = ftok("shared_memory.txt", 65);
    int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
    int *shm = (int *) shmat(shmid, NULL, 0);

    // Initialize shared memory
    *shm = 0;

    // Create semaphore
    int semid = semget(IPC_PRIVATE, 1, IPC_CREAT | 0666);
    struct sembuf sem_op;
    sem_op.sem_num = 0;
    sem_op.sem_op = -1;
    sem_op.sem_flg = SEM_UNDO;
    semctl(semid, 0, SETVAL, 1);

    // Create message queue
    int msgid = msgget(IPC_PRIVATE, IPC_CREAT | 0666);

    // Spawn child process
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        sleep(1);

        // Increment shared memory value
        int count = *shm;
        *shm += 1;

        // Send message to parent process
        msgsnd(msgid, &count, sizeof(int), 0);

        // Exit child process
        exit(0);
    } else {
        // Parent process
        sleep(2);

        // Wait for child process to send message
        int msg;
        msgrcv(msgid, &msg, sizeof(int), 0, 0);

        // Print updated shared memory value
        printf("Shared memory value: %d\n", *shm);

        // Exit parent process
        exit(0);
    }

    return 0;
}