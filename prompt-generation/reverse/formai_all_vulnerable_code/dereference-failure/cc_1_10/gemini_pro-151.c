//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MSGKEY 12345

struct msgbuf {
    long mtype;
    char mtext[256];
};

int main() {
    int msqid;
    struct msgbuf msg;
    char *str;

    msqid = msgget(MSGKEY, IPC_CREAT | 0666);
    if (msqid == -1) {
        perror("msgget");
        return 1;
    }

    while (1) {
        printf("Enter a string to send to the receiver: ");
        str = malloc(BUFSIZ);
        fgets(str, BUFSIZ, stdin);
        str[strlen(str) - 1] = '\0';

        msg.mtype = 1;
        strcpy(msg.mtext, str);

        if (msgsnd(msqid, &msg, sizeof(msg), 0) == -1) {
            perror("msgsnd");
            free(str);
            return 1;
        }

        free(str);

        msgrcv(msqid, &msg, sizeof(msg), 2, 0);
        printf("Received message from receiver: %s\n", msg.mtext);
    }

    msgctl(msqid, IPC_RMID, NULL);

    return 0;
}