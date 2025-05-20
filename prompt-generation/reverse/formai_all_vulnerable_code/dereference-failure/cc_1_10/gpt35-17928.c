//FormAI DATASET v1.0 Category: Educational ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define BUFFER_SIZE 100

typedef struct 
{
    char data[BUFFER_SIZE];
    int length;
} message;

pthread_mutex_t lock;
pthread_cond_t condition;

void* read_data(void* arg) {
    message* msg = NULL;

    while (!msg) {
        msg = (message*) malloc(sizeof(message));
        printf("Enter a message to send: ");
        fgets(msg->data, BUFFER_SIZE, stdin);
        msg->length = strlen(msg->data);
    }

    pthread_mutex_lock(&lock);
    pthread_cond_signal(&condition);
    pthread_mutex_unlock(&lock);

    return msg;
}

void* process_data(void* arg) {
    message* msg = (message*) arg;

    for (int i = msg->length - 1; i >= 0; i--) {
        printf("%c", msg->data[i]);
    }
    printf("\n");

    free(msg);

    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    int rc = pthread_mutex_init(&lock, NULL);
    if (rc) {
        printf("Error initializing mutex\n");
        return 1;
    }

    rc = pthread_cond_init(&condition, NULL);
    if (rc) {
        printf("Error initializing condition variable\n");
        return 1;
    }

    rc = pthread_create(&thread1, NULL, read_data, NULL);
    if (rc) {
        printf("Error creating thread1\n");
        return 1;
    }

    pthread_mutex_lock(&lock);
    pthread_cond_wait(&condition, &lock);
    pthread_mutex_unlock(&lock);

    rc = pthread_create(&thread2, NULL, process_data, (void*) thread1);
    if (rc) {
        printf("Error creating thread2\n");
        return 1;
    }

    pthread_join(thread2, NULL);

    pthread_cond_destroy(&condition);
    pthread_mutex_destroy(&lock);

    return 0;
}