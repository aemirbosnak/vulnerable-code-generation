//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/msg.h>

#define SEM_KEY 0x1234
#define SEM_SIZE 10
#define SHM_KEY 0x5678
#define SHM_SIZE 100
#define MSG_KEY 0x9ABC
#define MSG_SIZE 50

int main() {
    int semid, shmid, msqid;
    int i, n;
    char *shm;
    struct msgbuf {
        long mtype;
        char mtext[MSG_SIZE];
    } msg;

    // Create a semaphore set
    semid = semget(SEM_KEY, SEM_SIZE, 0666 | IPC_CREAT);
    if (semid == -1) {
        printf("Error creating semaphore set\n");
        exit(1);
    }

    // Create a shared memory segment
    shmid = shmget(SHM_KEY, SHM_SIZE, 0666 | IPC_CREAT);
    if (shmid == -1) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }
    shm = (char *) shmat(shmid, 0, 0);

    // Initialize the shared memory segment
    for (i = 0; i < SHM_SIZE; i++) {
        shm[i] = 0;
    }

    // Create a message queue
    msqid = msgget(MSG_KEY, 0666 | IPC_CREAT);
    if (msqid == -1) {
        printf("Error creating message queue\n");
        exit(1);
    }

    // Send a message to the message queue
    msg.mtype = 1;
    strcpy(msg.mtext, "Hello, world!");
    if (msgsnd(msqid, &msg, MSG_SIZE, 0) == -1) {
        printf("Error sending message\n");
        exit(1);
    }

    // Receive a message from the message queue
    if (msgrcv(msqid, &msg, MSG_SIZE, 0, 0) == -1) {
        printf("Error receiving message\n");
        exit(1);
    }
    printf("Received message: %s\n", msg.mtext);

    // Remove the semaphore set, shared memory segment, and message queue
    if (semctl(semid, 0, IPC_RMID) == -1) {
        printf("Error removing semaphore set\n");
        exit(1);
    }
    if (shmdt(shm) == -1) {
        printf("Error detaching shared memory segment\n");
        exit(1);
    }
    if (msgctl(msqid, IPC_RMID, NULL) == -1) {
        printf("Error removing message queue\n");
        exit(1);
    }

    return 0;
}