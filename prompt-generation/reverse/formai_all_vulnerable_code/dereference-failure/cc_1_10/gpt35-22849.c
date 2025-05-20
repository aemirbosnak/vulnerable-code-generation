//FormAI DATASET v1.0 Category: Interprocess communication ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define MSGSZ 128 /* Message size */

typedef struct msgbuf
{
    long mtype;
    char mtext[MSGSZ];
} message;

int main()
{
    int msqid1, msqid2; /* IDs for message queues */
    key_t key1, key2; /* Keys for message queues */
    message msg1, msg2; /* Messages to be sent and received */

    /* Generate unique key for message queues */
    key1 = ftok(".", 'a');
    key2 = ftok(".", 'b');

    /* Create message queues */
    if ((msqid1 = msgget(key1, IPC_CREAT | 0666)) < 0)
    {
        perror("msgget");
        exit(1);
    }
    if ((msqid2 = msgget(key2, IPC_CREAT | 0666)) < 0)
    {
        perror("msgget");
        exit(1);
    }
    
    /* Send message from process 1 to process 2 */
    snprintf(msg1.mtext, MSGSZ, "Hello from process 1!");
    msg1.mtype = 1;
    if (msgsnd(msqid1, &msg1, strlen(msg1.mtext)+1, 0) < 0)
    {
        perror("msgsnd");
        exit(1);
    }

    /* Receive message from process 1 in process 2 */
    if (msgrcv(msqid1, &msg1, MSGSZ, 1, 0) < 0)
    {
        perror("msgrcv");
        exit(1);
    }
    printf("Process 2 received message: %s\n", msg1.mtext);

    /* Send message from process 2 to process 1 */
    snprintf(msg2.mtext, MSGSZ, "Hello from process 2!");
    msg2.mtype = 1;
    if (msgsnd(msqid2, &msg2, strlen(msg2.mtext)+1, 0) < 0)
    {
        perror("msgsnd");
        exit(1);
    }

    /* Receive message from process 2 in process 1 */
    if (msgrcv(msqid2, &msg2, MSGSZ, 1, 0) < 0)
    {
        perror("msgrcv");
        exit(1);
    }
    printf("Process 1 received message: %s\n", msg2.mtext);

    /* Delete message queues */
    msgctl(msqid1, IPC_RMID, NULL);
    msgctl(msqid2, IPC_RMID, NULL);

    return 0;
}