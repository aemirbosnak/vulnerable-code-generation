//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/msg.h>

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 1024

typedef struct {
    long mtype;
    char mtext[MAX_SIZE];
} message;

int main() {
    int fd, ret;
    key_t key = 1234;
    int msgid = msgget(key, 0666 | IPC_CREAT);

    if (msgid == -1) {
        printf("Error in msgget\n");
        exit(1);
    }

    char *msg = "This is a test message";
    message msg_buf;
    strcpy(msg_buf.mtext, msg);
    msg_buf.mtype = 1;

    ret = msgsnd(msgid, &msg_buf, strlen(msg_buf.mtext) + 1, 0);

    if (ret == -1) {
        printf("Error in msgsnd\n");
        exit(1);
    }

    printf("Message sent successfully\n");

    fd = shmget(key, sizeof(int), 0666 | IPC_CREAT);

    if (fd == -1) {
        printf("Error in shmget\n");
        exit(1);
    }

    int *shm = shmat(fd, NULL, 0);

    if ((void *)shm == (void *)-1) {
        printf("Error in shmat\n");
        exit(1);
    }

    *shm = 10;

    printf("Shared memory created successfully\n");
    return 0;
}