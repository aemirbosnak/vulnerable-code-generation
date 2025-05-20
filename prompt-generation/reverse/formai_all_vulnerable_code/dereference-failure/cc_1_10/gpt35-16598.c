//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_QUEUE_SIZE 100
#define MAX_PLANE_SIZE 10
#define NUM_CONVEYORS 4

pthread_mutex_t queue_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t con_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t queue_cond_full = PTHREAD_COND_INITIALIZER;
pthread_cond_t queue_cond_empty = PTHREAD_COND_INITIALIZER;
pthread_cond_t con_cond_empty = PTHREAD_COND_INITIALIZER;

typedef struct node {
    int value;
    struct node* next;
} node_t;

typedef struct {
    node_t* head;
    node_t* tail;
} queue_t;

queue_t queue;
queue_t con_queues[NUM_CONVEYORS];

int num_planes = 0;
int num_not_delivered = 0;
int time_elapsed = 0;

void enqueue(queue_t* q, int value) {
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    new_node->value = value;
    new_node->next = NULL;
    if (q->tail == NULL) {
        q->head = new_node;
    } else {
        q->tail->next = new_node;
    }
    q->tail = new_node;
}

int dequeue(queue_t* q) {
    if (q->head == NULL) {
        return -1;
    }
    node_t* node_to_return = q->head;
    int value_to_return = node_to_return->value;
    q->head = q->head->next;
    if (q->head == NULL) {
        q->tail = NULL;
    }
    free(node_to_return);
    return value_to_return;
}

void* worker(void* arg) {
    int id = *(int*)arg;
    while (1) {
        pthread_mutex_lock(&con_mutex);
        while (con_queues[id].head == NULL) {
            if (num_planes == 0) {
                pthread_mutex_unlock(&con_mutex);
                pthread_exit(NULL);
            }
            pthread_cond_wait(&con_cond_empty, &con_mutex);
        }
        int baggage = dequeue(&con_queues[id]);
        printf("Worker %d delivering baggage %d to plane %d\n", id, baggage, num_planes);
        num_not_delivered--;
        if (num_not_delivered == 0) {
            pthread_cond_signal(&queue_cond_full);
        }
        pthread_mutex_unlock(&con_mutex);
    }
}

void* sorter(void* arg) {
    while (1) {
        pthread_mutex_lock(&queue_mutex);
        while (queue.head == NULL) {
            pthread_cond_wait(&queue_cond_empty, &queue_mutex);
        }
        int baggage = dequeue(&queue);
        printf("Sorting baggage %d\n", baggage);
        num_not_delivered++;
        if (num_not_delivered == MAX_PLANE_SIZE) {
            num_planes++;
            for (int i = 0; i < NUM_CONVEYORS; i++) {
                pthread_cond_signal(&con_cond_empty);
            }
            pthread_cond_wait(&queue_cond_full, &queue_mutex);
        }
        pthread_mutex_unlock(&queue_mutex);
    }
}

int main() {
    pthread_t workers[NUM_CONVEYORS];
    for (int i = 0; i < NUM_CONVEYORS; i++) {
        con_queues[i].head = NULL;
        con_queues[i].tail = NULL;
    }
    pthread_t sorter_thread;
    pthread_create(&sorter_thread, NULL, sorter, NULL);
    int worker_ids[NUM_CONVEYORS];
    for (int i = 0; i < NUM_CONVEYORS; i++) {
        worker_ids[i] = i;
        pthread_create(&workers[i], NULL, worker, &worker_ids[i]);
    }
    while (1) {
        pthread_mutex_lock(&queue_mutex);
        srand(time(NULL) + time_elapsed);
        int random_baggage = rand() % MAX_QUEUE_SIZE + 1;
        enqueue(&queue, random_baggage);
        printf("Adding baggage %d to queue\n", random_baggage);
        pthread_cond_signal(&queue_cond_empty);
        pthread_mutex_unlock(&queue_mutex);
        time_elapsed++;
        sleep(1);
    }
    return 0;
}