//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Node structure
typedef struct node {
    int data;
    struct node * next;
} node;

// Queue structure
typedef struct queue {
    struct node * head;
    struct node * tail;
} queue;

// Initialize queue
void init(queue * q) {
    q->head = NULL;
    q->tail = NULL;
}

// Enqueue
void enqueue(queue * q, int data) {
    struct node * tmp = malloc(sizeof(struct node));
    tmp->data = data;
    tmp->next = NULL;
    if(q->tail == NULL) {
        q->head = tmp;
        q->tail = tmp;
    } else {
        q->tail->next = tmp;
        q->tail = tmp;
    }
}

// Dequeue
int dequeue(queue * q) {
    if(q->head == NULL) {
        return -1;
    }
    int data = q->head->data;
    struct node * tmp = q->head;
    q->head = q->head->next;
    if(q->head == NULL) {
        q->tail = NULL;
    }
    free(tmp);
    return data;
}

// Print queue
void printQueue(queue * q) {
    struct node * tmp = q->head;
    while(tmp != NULL) {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

// Worker thread
void * worker(void * arg) {
    queue * q = (queue *) arg;
    while(1) {
        int data = dequeue(q);
        if(data == -1) {
            break;
        }
        printf("Worker %ld dequeued %d\n", pthread_self(), data);
        sleep(1);
    }
    return NULL;
}

int main() {
    // Initialize queue
    queue q;
    init(&q);

    // Enqueue some data
    for(int i = 0; i < 10; i++) {
        enqueue(&q, i);
    }

    // Create worker threads
    pthread_t threads[4];
    for(int i = 0; i < 4; i++) {
        pthread_create(&threads[i], NULL, worker, (void *) &q);
    }

    // Join worker threads
    for(int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}