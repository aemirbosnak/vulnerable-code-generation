//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define BUFFER_SIZE 1024
#define FILE_MODE 0644
#define IPC_KEY 12345

typedef struct {
    long mtype;
    char mtext[BUFFER_SIZE];
} message_t;

int main() {
    int fd;
    key_t key = ftok(".", IPC_KEY);
    int msgid = msgget(key, 0644 | IPC_CREAT);

    if (msgid == -1) {
        printf("Error creating message queue: %s\n", strerror(errno));
        return 1;
    }

    printf("Message queue created with ID: %d\n", msgid);

    while (1) {
        fd = open("input.txt", O_RDWR | O_CREAT, FILE_MODE);

        if (fd == -1) {
            printf("Error opening file: %s\n", strerror(errno));
            return 2;
        }

        printf("File opened with FD: %d\n", fd);

        char buffer[BUFFER_SIZE];
        memset(buffer, 0, BUFFER_SIZE);

        while (fgets(buffer, BUFFER_SIZE, fd)!= NULL) {
            message_t msg;
            strncpy(msg.mtext, buffer, BUFFER_SIZE);
            msg.mtype = 1;

            if (msgsnd(msgid, &msg, BUFFER_SIZE, 0) == -1) {
                printf("Error sending message: %s\n", strerror(errno));
                return 3;
            }

            memset(buffer, 0, BUFFER_SIZE);
        }

        close(fd);
    }

    return 0;
}