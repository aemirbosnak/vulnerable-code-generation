//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define NUM_STOCKS 10
#define NUM_THREADS 4

// Stock data structure
typedef struct stock {
    char *symbol;
    float price;
} stock_t;

// Queue data structure
typedef struct queue {
    stock_t *data;
    int head;
    int tail;
    int size;
} queue_t;

// Queue functions
queue_t *queue_create(int size) {
    queue_t *queue = malloc(sizeof(queue_t));
    queue->data = malloc(sizeof(stock_t) * size);
    queue->head = 0;
    queue->tail = 0;
    queue->size = size;
    return queue;
}

void queue_push(queue_t *queue, stock_t *stock) {
    queue->data[queue->tail] = *stock;
    queue->tail = (queue->tail + 1) % queue->size;
    if (queue->tail == queue->head) {
        queue->head = (queue->head + 1) % queue->size;
    }
}

stock_t *queue_pop(queue_t *queue) {
    if (queue->head == queue->tail) {
        return NULL;
    }
    stock_t *stock = &queue->data[queue->head];
    queue->head = (queue->head + 1) % queue->size;
    return stock;
}

// Thread function
void *thread_func(void *arg) {
    queue_t *queue = (queue_t *)arg;
    while (1) {
        // Generate a random stock price
        stock_t stock;
        stock.symbol = malloc(sizeof(char) * 4);
        sprintf(stock.symbol, "%s%d", "STK", rand() % 100);
        stock.price = (float)(rand() % 1000) / 100;

        // Push the stock into the queue
        queue_push(queue, &stock);

        // Sleep for a random amount of time
        sleep(rand() % 10);
    }
    return NULL;
}

int main() {
    // Create a queue to store the stock data
    queue_t *queue = queue_create(100);

    // Create a thread pool
    pthread_t threads[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_func, queue);
    }

    // Loop forever, printing the stock data
    while (1) {
        // Pop a stock from the queue
        stock_t *stock = queue_pop(queue);
        if (stock != NULL) {
            printf("%s: $%.2f\n", stock->symbol, stock->price);
            free(stock->symbol);
        }

        // Sleep for a short amount of time
        usleep(100000);
    }

    // Join the threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Free the queue
    free(queue->data);
    free(queue);

    return 0;
}