//FormAI DATASET v1.0 Category: Interprocess communication ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>

#define MAX_MSG_LEN 100
#define MSG_TYPE_1 1
#define MSG_TYPE_2 2

typedef struct message
{
    long msg_type;
    char msg_data[MAX_MSG_LEN];
} Message;

void create_msg_queue(key_t key)
{
    int queue_id = msgget(key, IPC_CREAT|0666);
    if(queue_id == -1)
    {
        perror("msgget");
        exit(1);
    }
    printf("Message Queue ID = %d\n", queue_id);
}

void write_to_msg_queue(int queue_id, Message msg, int msg_len)
{
    int send_status = msgsnd(queue_id, &msg, msg_len, IPC_NOWAIT);
    if(send_status == -1)
    {
        perror("msgsnd");
        exit(1);
    }
}

void read_from_msg_queue(int queue_id, int msg_type)
{
    Message msg;
    int receive_status = msgrcv(queue_id, &msg, sizeof(Message), msg_type, IPC_NOWAIT);
    if(receive_status == -1)
    {
        if(errno != ENOMSG)
        {
            perror("msgrcv");
            exit(1);
        }
        else
        {
            printf("No message in the queue\n");
        }
    }
    else
    {
        printf("Received Message: %s\n", msg.msg_data);
    }
}

int main()
{
    key_t key = ftok(".", 'a');
    create_msg_queue(key);

    int queue_id = msgget(key, IPC_CREAT|0666);
    if(queue_id == -1)
    {
        perror("msgget");
        exit(1);
    }

    Message msg1, msg2;
    msg1.msg_type = MSG_TYPE_1;
    msg2.msg_type = MSG_TYPE_2;

    strcpy(msg1.msg_data, "Hello from Process 1 to Process 2!");
    write_to_msg_queue(queue_id, msg1, strlen(msg1.msg_data) + 1);

    read_from_msg_queue(queue_id, MSG_TYPE_1);

    strcpy(msg2.msg_data, "Hello from Process 2 to Process 1!");
    write_to_msg_queue(queue_id, msg2, strlen(msg2.msg_data) + 1);

    read_from_msg_queue(queue_id, MSG_TYPE_2);

    return 0;
}