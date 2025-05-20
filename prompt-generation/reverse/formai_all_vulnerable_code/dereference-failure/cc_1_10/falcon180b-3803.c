//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/msg.h>

#define MAX_SHARED_MEMORY_SIZE 1024

#define SHM_KEY 0x1234
#define SEM_KEY 0x5678
#define MSG_KEY 0x9ABC

int main() {
    int shm_id, sem_id, msg_id;
    void *shm_addr;
    int sem_value = 0;
    struct msgbuf {
        long mtype;
        char mtext[MAX_SHARED_MEMORY_SIZE];
    } msg;

    // Create shared memory segment
    shm_id = shmget(SHM_KEY, MAX_SHARED_MEMORY_SIZE, IPC_CREAT | 0666);
    if (shm_id == -1) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    // Attach to shared memory segment
    shm_addr = shmat(shm_id, NULL, 0);
    if (shm_addr == (void *) -1) {
        printf("Error attaching to shared memory segment\n");
        exit(1);
    }

    // Initialize shared memory segment
    memset(shm_addr, 0, MAX_SHARED_MEMORY_SIZE);

    // Create semaphore
    sem_id = semget(SEM_KEY, 1, IPC_CREAT | 0666);
    if (sem_id == -1) {
        printf("Error creating semaphore\n");
        exit(1);
    }

    // Initialize semaphore
    semctl(sem_id, 0, SETVAL, sem_value);

    // Create message queue
    msg_id = msgget(MSG_KEY, IPC_CREAT | 0666);
    if (msg_id == -1) {
        printf("Error creating message queue\n");
        exit(1);
    }

    // Send message to message queue
    msg.mtype = 1;
    strcpy(msg.mtext, "Hello, world!");
    msgsnd(msg_id, &msg, sizeof(msg), 0);

    // Receive message from message queue
    int msg_size;
    msgrcv(msg_id, &msg, sizeof(msg), 0, 0);
    printf("Received message: %s\n", msg.mtext);

    // Delete shared memory segment
    shmdt(shm_addr);

    // Delete semaphore
    semctl(sem_id, 0, IPC_RMID);

    // Delete message queue
    msgctl(msg_id, IPC_RMID, NULL);

    return 0;
}