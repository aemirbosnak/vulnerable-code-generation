//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/sem.h>
#include <sys/shm.h>

#define MAX_SIZE 1024

// Structure for shared memory
struct shm_data {
    char data[MAX_SIZE];
};

// Structure for semaphore
struct sem_data {
    int count;
};

// Structure for message queue
struct msg_data {
    long msg_type;
    char msg_text[MAX_SIZE];
};

int main() {
    int shm_id, sem_id, msg_id;
    char *shm_addr;
    int i;

    // Create shared memory segment
    shm_id = shmget(IPC_PRIVATE, MAX_SIZE, IPC_CREAT | 0666);
    if (shm_id == -1) {
        printf("Error: shmget failed\n");
        exit(1);
    }

    shm_addr = shmat(shm_id, NULL, 0);
    if (shm_addr == (char *)-1) {
        printf("Error: shmat failed\n");
        exit(1);
    }

    // Initialize shared memory data
    for (i = 0; i < MAX_SIZE; i++) {
        ((char *)shm_addr)[i] = 'A' + i;
    }

    // Create semaphore
    sem_id = semget(IPC_PRIVATE, 1, IPC_CREAT | 0666);
    if (sem_id == -1) {
        printf("Error: semget failed\n");
        exit(1);
    }

    if (semctl(sem_id, 0, SETVAL, 1) == -1) {
        printf("Error: semctl failed\n");
        exit(1);
    }

    // Create message queue
    msg_id = msgget(IPC_PRIVATE, IPC_CREAT | 0666);
    if (msg_id == -1) {
        printf("Error: msgget failed\n");
        exit(1);
    }

    // Send message to the message queue
    struct msg_data msg;
    msg.msg_type = 1;
    strcpy(msg.msg_text, "Hello, World!");
    if (msgsnd(msg_id, &msg, strlen(msg.msg_text), 0) == -1) {
        printf("Error: msgsnd failed\n");
        exit(1);
    }

    printf("Message sent successfully\n");

    return 0;
}