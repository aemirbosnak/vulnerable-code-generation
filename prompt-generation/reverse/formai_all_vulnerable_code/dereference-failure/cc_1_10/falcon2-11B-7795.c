//Falcon2-11B DATASET v1.0 Category: Threading Library Implementation ; Style: Sherlock Holmes
#include <stdio.h>
#include <pthread.h>

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int queue[5];
int head = 0;
int tail = 0;
int items = 0;

void *enqueue(void *arg) {
    for (int i = 0; i < 5; i++) {
        queue[i] = *(int*)arg;
    }
    pthread_mutex_lock(&lock);
    items++;
    printf("Item %d enqueued\n", *(int*)arg);
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&lock);
    return NULL;
}

void *dequeue(void *arg) {
    while (items == 0) {
        pthread_cond_wait(&cond, &lock);
    }
    int *item = queue + head;
    pthread_mutex_lock(&lock);
    items--;
    printf("Item %d dequeued\n", *item);
    pthread_mutex_unlock(&lock);
    return item;
}

void *thread1(void *arg) {
    for (int i = 0; i < 10; i++) {
        printf("Thread 1: %d\n", i);
        enqueue(arg);
        pthread_mutex_lock(&lock);
        while (items == 0) {
            pthread_cond_wait(&cond, &lock);
        }
        printf("Thread 1: Item %d dequeued\n", *(int*)arg);
        pthread_mutex_unlock(&lock);
        dequeue(arg);
    }
}

void *thread2(void *arg) {
    for (int i = 0; i < 10; i++) {
        printf("Thread 2: %d\n", i);
        enqueue(arg);
        pthread_mutex_lock(&lock);
        while (items == 0) {
            pthread_cond_wait(&cond, &lock);
        }
        printf("Thread 2: Item %d dequeued\n", *(int*)arg);
        pthread_mutex_unlock(&lock);
        dequeue(arg);
    }
}

int main() {
    pthread_t t1, t2;
    int *data = malloc(sizeof(int) * 5);
    data[0] = 1;
    data[1] = 2;
    data[2] = 3;
    data[3] = 4;
    data[4] = 5;
    pthread_create(&t1, NULL, thread1, data);
    pthread_create(&t2, NULL, thread2, data);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    free(data);
    return 0;
}