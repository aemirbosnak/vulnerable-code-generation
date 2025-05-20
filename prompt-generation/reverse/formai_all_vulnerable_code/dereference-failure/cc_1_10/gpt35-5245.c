//FormAI DATASET v1.0 Category: Interprocess communication ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

#define MSG_KEY 42
#define MAX_MSG_LEN 256

typedef struct {
    long mtype;
    char mtext[MAX_MSG_LEN];
} msg_t;

int main() {
    int msqid;
    struct msqid_ds mstat;
    key_t key;
    pid_t pid = getpid();
    char snd_buff[MAX_MSG_LEN];
    char rcv_buff[MAX_MSG_LEN];
    msg_t snd_msg;
    msg_t rcv_msg;

    // Get the message queue ID
    key = ftok(".", 'm');
    msqid = msgget(MSG_KEY, 0666 | IPC_CREAT);

    if (msqid == -1) {
        printf("ERROR: msgget failed with error %d: %s\n", errno, strerror(errno));
        exit(EXIT_FAILURE);
    }

    printf("[%d] message queue created, id = %d\n", pid, msqid);

    //fork the process
    pid_t child_pid = fork();

    if (child_pid == -1) {
        printf("ERROR: fork failed with error %d: %s\n", errno, strerror(errno));
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0) {
        // Child process waits to receive messages from the message queue
        while(1) {
            if (msgrcv(msqid, &rcv_msg, MAX_MSG_LEN, pid, IPC_NOWAIT) == -1) {
                if (errno != ENOMSG) {
                    printf("ERROR: msgrcv failed with error %d: %s\n", errno, strerror(errno));
                    exit(EXIT_FAILURE);
                }
            } else {
                printf("[%d] received %s\n", pid, rcv_msg.mtext);
            }
        }
    } else {
        // Parent process sends messages to the message queue
        while(1) {
            // Get user input to send message
            printf("Enter message: ");
            fgets(snd_buff, MAX_MSG_LEN, stdin);
            snd_buff[strcspn(snd_buff, "\n")] = '\0';

            // Prepare the message to send
            strncpy(snd_msg.mtext, snd_buff, MAX_MSG_LEN);
            snd_msg.mtype = child_pid;

            // Send the message to child process
            if (msgsnd(msqid, &snd_msg, strlen(snd_msg.mtext) + 1, IPC_NOWAIT) == -1) {
                printf("ERROR: msgsnd failed with error %d: %s\n", errno, strerror(errno));
                exit(EXIT_FAILURE);
            } else {
                printf("[%d] sent %s\n", pid, snd_msg.mtext);
            }
        }
    }

    // Remove the message queue
    if (msgctl(msqid, IPC_RMID, &mstat) == -1) {
        printf("ERROR: msgctl failed with error %d: %s\n", errno, strerror(errno));
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}