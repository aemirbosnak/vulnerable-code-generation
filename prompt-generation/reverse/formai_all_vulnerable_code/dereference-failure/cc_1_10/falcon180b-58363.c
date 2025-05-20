//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <sys/sem.h>
#include <sys/msg.h>

#define MAX_SIZE 100
#define SEM_ID 0
#define SHM_ID 1
#define MSG_ID 2

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
    struct seminfo *__buf;
};

int main() {
    int semid, shmid, msqid;
    int i, j, n;
    char *shmptr;
    char msgbuf[MAX_SIZE];

    semid = semget(SEM_ID, 1, 0666 | IPC_CREAT);
    if (semid == -1) {
        perror("semget");
        exit(1);
    }

    shmid = shmget(SHM_ID, MAX_SIZE, 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    shmptr = (char *) shmat(shmid, NULL, 0);
    if (shmptr == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    msqid = msgget(MSG_ID, 0666 | IPC_CREAT);
    if (msqid == -1) {
        perror("msgget");
        exit(1);
    }

    printf("Enter a message: ");
    scanf("%s", shmptr);

    for (i = 0; i < strlen(shmptr); i++) {
        msgbuf[i] = shmptr[i];
    }

    n = strlen(shmptr);
    msgbuf[n] = '\0';

    if (msgsnd(msqid, msgbuf, n+1, 0) == -1) {
        perror("msgsnd");
        exit(1);
    }

    printf("Message sent successfully\n");

    if (msgctl(msqid, IPC_RMID, NULL) == -1) {
        perror("msgctl");
        exit(1);
    }

    if (shmdt(shmptr) == -1) {
        perror("shmdt");
        exit(1);
    }

    if (semctl(semid, 0, IPC_RMID, NULL) == -1) {
        perror("semctl");
        exit(1);
    }

    return 0;
}