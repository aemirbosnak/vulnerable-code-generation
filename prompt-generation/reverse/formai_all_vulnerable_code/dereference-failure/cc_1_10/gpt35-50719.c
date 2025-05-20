//FormAI DATASET v1.0 Category: Interprocess communication ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define MAX 10

struct shared_memory {
    int buffer[MAX];
    int front;
    int rear;
};

int main()
{
    pid_t pid;
    int shmid, i;
    struct shared_memory *buffer;
    key_t key = ftok("shmfile", 65);

    shmid = shmget(key, sizeof(struct shared_memory), 0666|IPC_CREAT);

    buffer = (struct shared_memory*) shmat(shmid, (void*)0, 0);

    buffer->front = -1;
    buffer->rear = -1;

    pid = fork();

    if(pid == 0)
    {
        // Child process
        while(1)
        {
            if(buffer->front != -1)
            {
                printf("Consuming item %d from buffer\n", buffer->buffer[buffer->front]);
                buffer->front++;

                if(buffer->front > buffer->rear)
                {
                    buffer->front = -1;
                    buffer->rear = -1;
                }
            }
        }
    }
    else
    {
        // Parent process
        while(1)
        {
            if(buffer->rear < MAX - 1)
            {
                int item = rand() % 100;
                buffer->rear++;

                buffer->buffer[buffer->rear] = item;

                printf("Producing item %d and storing in buffer\n", item);
            }
            else
            {
                sleep(1);
            }
        }
    }

    shmdt(buffer);

    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}