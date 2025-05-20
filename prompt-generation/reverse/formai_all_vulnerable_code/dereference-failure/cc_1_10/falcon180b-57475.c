//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/msg.h>

#define TRUE   1
#define FALSE  0
#define BUFFER_SIZE 1024

typedef struct msgbuf {
    long mtype;
    char mtext[BUFFER_SIZE];
} message;

int main() {
    int shmid, msqid;
    char *shmaddr;
    key_t key = 1234;
    int id = 0;
    pid_t pid;
    int status;
    message msg;

    shmid = shmget(key, BUFFER_SIZE, 0666 | IPC_CREAT);
    if (shmid == -1) {
        printf("Error creating shared memory segment.\n");
        exit(1);
    }

    shmaddr = (char *)shmat(shmid, NULL, 0);
    if (shmaddr == (char *)-1) {
        printf("Error attaching to shared memory segment.\n");
        exit(2);
    }

    memset(shmaddr, 0, BUFFER_SIZE);

    if ((pid = fork()) == 0) {
        sprintf(shmaddr, "Hello, my love. I am process %d.\n", id);
        id++;
        exit(0);
    } else {
        wait(&status);
        sprintf(shmaddr, "Hello, my love. I am process %d.\n", id);
        id++;
    }

    msqid = msgget(key, 0666 | IPC_CREAT);
    if (msqid == -1) {
        printf("Error creating message queue.\n");
        exit(3);
    }

    while (TRUE) {
        if (msgrcv(msqid, &msg, BUFFER_SIZE, 0, 0) == -1) {
            printf("Error receiving message.\n");
            exit(4);
        }

        printf("Message received: %s", msg.mtext);
    }

    return 0;
}