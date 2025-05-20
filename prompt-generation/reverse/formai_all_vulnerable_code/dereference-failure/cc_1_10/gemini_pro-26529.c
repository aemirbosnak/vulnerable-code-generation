//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define MAX_MSG_SIZE 256
#define MAX_MSG_NUM 10

typedef struct {
    long mtype;
    char mtext[MAX_MSG_SIZE];
} message_t;

int main(int argc, char* argv[])
{
    if (argc < 2) {
        printf("Usage: %s <mode> <message>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int msgid;
    key_t key;

    key = 1234;
    msgid = msgget(key, IPC_CREAT | 0666);

    if (msgid < 0) {
        perror("msgget");
        return EXIT_FAILURE;
    }

    message_t msg;
    msg.mtype = 1;

    if (strcmp(argv[1], "send") == 0) {
        strcpy(msg.mtext, argv[2]);
        if (msgsnd(msgid, &msg, sizeof(msg.mtext), 0) < 0) {
            perror("msgsnd");
            return EXIT_FAILURE;
        }

        printf("Message sent: %s\n", argv[2]);
    } else if (strcmp(argv[1], "receive") == 0) {
        if (msgrcv(msgid, &msg, sizeof(msg.mtext), 1, 0) < 0) {
            perror("msgrcv");
            return EXIT_FAILURE;
        }

        printf("Message received: %s\n", msg.mtext);
    } else {
        printf("Invalid mode: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}