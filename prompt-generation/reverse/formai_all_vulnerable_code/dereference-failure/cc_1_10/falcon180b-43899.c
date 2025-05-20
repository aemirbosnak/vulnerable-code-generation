//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX_SIZE 100

typedef struct {
    long mtype;
    char mtext[MAX_SIZE];
} message_t;

int main() {
    int msgid;
    key_t key = ftok("/tmp", 65);
    int shmid;
    char *shmaddr;

    if ((msgid = msgget(key, 0666 | IPC_CREAT)) == -1) {
        printf("Error creating message queue\n");
        exit(1);
    }

    if ((shmid = shmget(key, sizeof(message_t), 0666 | IPC_CREAT)) == -1) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    if ((shmaddr = shmat(shmid, NULL, 0)) == (char *)-1) {
        printf("Error attaching shared memory segment\n");
        exit(1);
    }

    message_t *msg = (message_t *)shmaddr;
    msg->mtype = 1;
    strcpy(msg->mtext, "Hello, World!");

    while (1) {
        if (msgsnd(msgid, msg, sizeof(message_t), 0) == -1) {
            printf("Error sending message\n");
            exit(1);
        }
        sleep(1);
    }

    return 0;
}