//Falcon2-11B DATASET v1.0 Category: Traffic Light Controller ; Style: decentralized
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdlib.h>

void* light_change(void* args) {
    int id = *(int*)args;
    int semaphore = 1;
    sem_wait(&semaphore);
    if (id == 1) {
        printf("Red light\n");
        sem_post(&semaphore);
        sleep(3);
        printf("Green light\n");
        sem_post(&semaphore);
        sleep(3);
        printf("Yellow light\n");
        sem_post(&semaphore);
        sleep(3);
    } else if (id == 2) {
        printf("Green light\n");
        sem_post(&semaphore);
        sleep(3);
        printf("Red light\n");
        sem_post(&semaphore);
        sleep(3);
        printf("Yellow light\n");
        sem_post(&semaphore);
        sleep(3);
    } else if (id == 3) {
        printf("Yellow light\n");
        sem_post(&semaphore);
        sleep(3);
        printf("Red light\n");
        sem_post(&semaphore);
        sleep(3);
        printf("Green light\n");
        sem_post(&semaphore);
        sleep(3);
    }
    return NULL;
}

int main() {
    int semaphore = 1;
    sem_init(&semaphore, 0, 1);
    pthread_t thread1, thread2, thread3;
    int id1 = 1, id2 = 2, id3 = 3;
    pthread_create(&thread1, NULL, light_change, &id1);
    pthread_create(&thread2, NULL, light_change, &id2);
    pthread_create(&thread3, NULL, light_change, &id3);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    return 0;
}