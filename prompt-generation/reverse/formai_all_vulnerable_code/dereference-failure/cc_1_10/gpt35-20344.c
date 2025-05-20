//FormAI DATASET v1.0 Category: Interprocess communication ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <pthread.h>

#define SHM_SIZE 1024

// Structure for passing message between threads
typedef struct message {
    pid_t pid;
    char data[SHM_SIZE];
} message_t;

void *thread_func_read(void *args);
void *thread_func_write(void *args);

int main(void) {
    pthread_t read_thread, write_thread;
    key_t key = ftok(".", 'x');
    int shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);
    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }
    message_t *msg = (message_t *)shmat(shmid, NULL, 0);
    if ((void *)msg == (void *)-1) {
        perror("shmat");
        exit(1);
    }
    msg->pid = getpid();

    pthread_create(&read_thread, NULL, thread_func_read, msg);
    pthread_create(&write_thread, NULL, thread_func_write, msg);

    pthread_join(read_thread, NULL);
    pthread_join(write_thread, NULL);

    shmdt(msg);
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}

void *thread_func_read(void *args) {
    message_t *msg = (message_t *)args;
    while (1) {
        printf("Message received from PID %d: %s\n", msg->pid, msg->data);
        if (strcmp(msg->data, "quit") == 0) {
            break;
        }
        usleep(500000);
    }
    pthread_exit(NULL);
}

void *thread_func_write(void *args) {
    message_t *msg = (message_t *)args;
    char input[SHM_SIZE];
    while (1) {
        printf("Enter message to send ('quit' to exit): ");
        fgets(input, SHM_SIZE, stdin);
        strncpy(msg->data, input, SHM_SIZE);
        if (strcmp(msg->data, "quit\n") == 0) {
            break;
        }
        usleep(500000);
    }
    pthread_exit(NULL);
}