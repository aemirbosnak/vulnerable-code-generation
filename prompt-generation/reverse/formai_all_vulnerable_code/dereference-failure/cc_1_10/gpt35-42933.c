//FormAI DATASET v1.0 Category: Interprocess communication ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SHMSIZE 1024

void* server(void* arg);
void* client(void* arg);

typedef struct shared_memory {
    bool server_ready;
    char message[SHMSIZE];
} shared_memory;

shared_memory* shmem;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int main() {
    int shmid;
    key_t key = ftok("shmfile", 65);

    shmid = shmget(key, sizeof(shared_memory), IPC_CREAT | 0666);

    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }

    shmem = (shared_memory*) shmat(shmid, NULL, 0);

    if (shmem == (void*) -1) {
        perror("shmat");
        exit(1);
    }

    printf("Server ready\n");

    shmem->server_ready = true;

    pthread_t thread_id_client, thread_id_server;

    pthread_create(&thread_id_server, NULL, server, NULL);
    pthread_create(&thread_id_client, NULL, client, NULL);

    pthread_join(thread_id_client, NULL);
    pthread_join(thread_id_server, NULL);

    shmdt((void*) shmem);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}

void* server(void* arg) {
    while(!shmem->server_ready) {}

    printf("Client connected\n");

    while(true) {
        pthread_mutex_lock(&mutex);

        if (shmem->message[0] != '\0') {
            printf("Client: %s\n", shmem->message);

            memset(shmem->message, 0, SHMSIZE);
        }

        pthread_mutex_unlock(&mutex);
    }

    pthread_exit(NULL);
}

void* client(void* arg) {
    while(!shmem->server_ready) {}

    printf("Connected to server\n");

    while(true) {
        char buffer[SHMSIZE];

        fgets(buffer, SHMSIZE, stdin);
        buffer[strcspn(buffer, "\n")] = 0;

        pthread_mutex_lock(&mutex);

        strcpy(shmem->message, buffer);

        pthread_mutex_unlock(&mutex);
    }

    pthread_exit(NULL);
}