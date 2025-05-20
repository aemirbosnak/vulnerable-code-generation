//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_ITEMS 100
#define MAX_CUSTOMERS 10
#define MAX_WORKERS 5

// Global variables
int num_items = 0;
int num_customers = 0;
int num_workers = 0;
int items[MAX_ITEMS];
int customers[MAX_CUSTOMERS];
int workers[MAX_WORKERS];

// Mutex and semaphore variables
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
sem_t sem;

// Function prototypes
void *customer(void *arg);
void *worker(void *arg);
void *monitor(void *arg);

int main() {
    int i;

    // Initialize semaphore
    sem_init(&sem, 0, MAX_CUSTOMERS);

    // Create customers
    for (i = 0; i < MAX_CUSTOMERS; i++) {
        pthread_create(&customers[i], NULL, customer, (void *)i);
    }

    // Create workers
    for (i = 0; i < MAX_WORKERS; i++) {
        pthread_create(&workers[i], NULL, worker, (void *)i);
    }

    // Create monitor
    pthread_create(&monitor, NULL, monitor, NULL);

    // Join all threads
    for (i = 0; i < MAX_CUSTOMERS; i++) {
        pthread_join(customers[i], NULL);
    }
    for (i = 0; i < MAX_WORKERS; i++) {
        pthread_join(workers[i], NULL);
    }
    pthread_join(monitor, NULL);

    return 0;
}

void *customer(void *arg) {
    int id = *(int *)arg;
    int item = rand() % MAX_ITEMS;

    pthread_mutex_lock(&mutex);
    num_items--;
    items[item]--;

    printf("Customer %d bought item %d\n", id, item);

    pthread_mutex_unlock(&mutex);

    sleep(2);

    sem_post(&sem);

    pthread_exit(NULL);
}

void *worker(void *arg) {
    int id = *(int *)arg;

    while (1) {
        pthread_mutex_lock(&mutex);
        if (num_items == 0 && num_customers == 0) {
            break;
        }
        if (num_items > 0) {
            int item = rand() % MAX_ITEMS;
            items[item]++;
            num_items++;
            printf("Worker %d restocked item %d\n", id, item);
        }
        pthread_mutex_unlock(&mutex);

        sleep(1);
    }

    pthread_exit(NULL);
}

void *monitor(void *arg) {
    while (1) {
        printf("Current number of customers: %d\n", num_customers);
        printf("Current number of workers: %d\n", num_workers);
        printf("Current number of items: %d\n", num_items);
        sleep(5);
    }

    pthread_exit(NULL);
}