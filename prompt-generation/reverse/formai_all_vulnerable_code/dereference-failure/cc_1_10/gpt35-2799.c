//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: authentic
/*
A C threading library implementation example program.
This program implements a simple multithreaded application that simulates a queue of customers waiting to use an ATM machine.
This program uses the pthread library for thread management.
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_CUSTOMERS 10

pthread_mutex_t queue_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t queue_condvar = PTHREAD_COND_INITIALIZER;
int num_waiting = 0;

void* atm_thread(void* arg) {
    int customer_id = *(int *)arg;
    printf("ATM: Serving customer %d\n", customer_id);
    sleep(2); // Simulate ATM usage time
    printf("ATM: Customer %d served\n", customer_id);
    pthread_exit(NULL);
}

void* customer_thread(void* arg) {
    int customer_id = *(int *)arg;
    printf("Customer %d waiting to use ATM\n", customer_id);
    pthread_mutex_lock(&queue_mutex);
    num_waiting++;
    pthread_cond_wait(&queue_condvar, &queue_mutex);
    pthread_mutex_unlock(&queue_mutex);
    printf("Customer %d using ATM\n", customer_id);
    int* atm_id = malloc(sizeof(int));
    *atm_id = customer_id;
    atm_thread((void*)atm_id);
    free(atm_id);
    pthread_exit(NULL);
}

int main() {
    pthread_t atm1, atm2;
    pthread_t customers[NUM_CUSTOMERS];
    int customer_ids[NUM_CUSTOMERS];

    pthread_create(&atm1, NULL, atm_thread, (void*)0);
    pthread_create(&atm2, NULL, atm_thread, (void*)1);

    for (int i = 0; i < NUM_CUSTOMERS; i++) {
        customer_ids[i] = i;
        pthread_create(&customers[i], NULL, customer_thread, (void*)&customer_ids[i]);
    }

    // Signal all customers waiting for ATM
    printf("ATMs are now available\n");
    pthread_mutex_lock(&queue_mutex);
    pthread_cond_broadcast(&queue_condvar);
    pthread_mutex_unlock(&queue_mutex);

    // Wait for customers to finish using ATM
    for (int i = 0; i < NUM_CUSTOMERS; i++) {
        pthread_join(customers[i], NULL);
    }

    // Wait for ATMs to finish serving customers
    pthread_join(atm1, NULL);
    pthread_join(atm2, NULL);

    printf("Simulation complete\n");

    return 0;
}