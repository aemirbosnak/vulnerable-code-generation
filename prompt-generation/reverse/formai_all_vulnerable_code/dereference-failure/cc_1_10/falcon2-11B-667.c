//Falcon2-11B DATASET v1.0 Category: Database querying ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>
#include <semaphore.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>

#define MAX_QUEUE_SIZE 100
#define MAX_BUFFER_SIZE 1000
#define SLEEP_TIME 1

pthread_mutex_t queue_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t queue_cond = PTHREAD_COND_INITIALIZER;

typedef struct {
    char buffer[MAX_BUFFER_SIZE];
    int buffer_size;
    int last_element_index;
    int num_elements;
} queue_element_t;

typedef struct {
    queue_element_t elements[MAX_QUEUE_SIZE];
    int queue_size;
} queue_t;

queue_t queue;

void* enqueue(void* arg) {
    queue_element_t* element = (queue_element_t*) malloc(sizeof(queue_element_t));
    memset(element, 0, sizeof(queue_element_t));

    int sleep_time = (int) ((double) rand() / RAND_MAX * SLEEP_TIME);
    usleep(sleep_time * 1000);

    pthread_mutex_lock(&queue_mutex);
    element->buffer[element->buffer_size] = '\0';
    sprintf(element->buffer, "Enqueued element: %d", (int) rand());
    element->buffer_size = strlen(element->buffer);
    element->last_element_index = element->buffer_size;
    element->num_elements = 1;
    queue.queue_size++;
    queue.elements[queue.queue_size - 1] = *element;

    pthread_cond_signal(&queue_cond);
    pthread_mutex_unlock(&queue_mutex);

    free(element);

    return NULL;
}

void* dequeue(void* arg) {
    queue_element_t* element = (queue_element_t*) malloc(sizeof(queue_element_t));
    memset(element, 0, sizeof(queue_element_t));

    pthread_mutex_lock(&queue_mutex);
    while (queue.queue_size == 0) {
        pthread_cond_wait(&queue_cond, &queue_mutex);
    }
    int sleep_time = (int) ((double) rand() / RAND_MAX * SLEEP_TIME);
    usleep(sleep_time * 1000);
    queue.queue_size--;
    element->buffer[element->buffer_size] = '\0';
    sprintf(element->buffer, "Dequeued element: %d", (int) rand());
    element->buffer_size = strlen(element->buffer);
    element->last_element_index = element->buffer_size;
    element->num_elements = 1;
    queue.elements[queue.queue_size] = *element;

    pthread_cond_signal(&queue_cond);
    pthread_mutex_unlock(&queue_mutex);

    free(element);

    return NULL;
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <num_threads>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int num_threads = atoi(argv[1]);
    queue_t* queue = &queue;

    for (int i = 0; i < num_threads; i++) {
        pthread_t thread;
        pthread_create(&thread, NULL, enqueue, NULL);
        pthread_join(thread, NULL);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_t thread;
        pthread_create(&thread, NULL, dequeue, NULL);
        pthread_join(thread, NULL);
    }

    printf("Queue size: %d\n", queue->queue_size);

    return 0;
}