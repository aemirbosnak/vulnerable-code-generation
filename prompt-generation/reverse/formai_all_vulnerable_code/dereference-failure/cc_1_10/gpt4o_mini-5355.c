//GPT-4o-mini DATASET v1.0 Category: Threading Library Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

#define NUM_CUSTOMERS 5
#define NUM_SEATS 3
#define MAX_TIME 5  // seconds

pthread_mutex_t mutex;
pthread_cond_t cond_var;
int available_seats = NUM_SEATS;

void *customer(void *arg) {
    int customer_id = *((int *)arg);
    free(arg);  // Free the dynamically allocated memory for customer_id

    printf("Customer %d: Arrived at the barbershop.\n", customer_id);

    pthread_mutex_lock(&mutex);
    if (available_seats > 0) {
        available_seats--;
        printf("Customer %d: Seated. Available seats now: %d.\n", customer_id, available_seats);
    } else {
        printf("Customer %d: No seats available! Leaving the barbershop.\n", customer_id);
        pthread_mutex_unlock(&mutex);
        return NULL;
    }
    pthread_mutex_unlock(&mutex);

    sleep(rand() % MAX_TIME);

    pthread_mutex_lock(&mutex);
    printf("Customer %d: Getting a haircut!\n", customer_id);
    sleep(rand() % MAX_TIME);
    printf("Customer %d: Finished haircut, leaving the barbershop!\n", customer_id);
    available_seats++;
    printf("Customer %d: Leaves the seat. Available seats now: %d.\n", customer_id, available_seats);
    pthread_cond_signal(&cond_var); 
    pthread_mutex_unlock(&mutex);
    
    return NULL;
}

void *barber(void *arg) {
    while (1) {
        pthread_mutex_lock(&mutex);
        while (available_seats == NUM_SEATS) {
            printf("Barber: No customers. Sleeping...\n");
            pthread_cond_wait(&cond_var, &mutex);
        }
        pthread_mutex_unlock(&mutex);
        
        // The barber gets a customer
        pthread_mutex_lock(&mutex);
        available_seats++;
        printf("Barber: Cutting hair. Available seats now: %d.\n", available_seats);
        sleep(rand() % MAX_TIME);
        printf("Barber: Finished cutting hair.\n");
        pthread_mutex_unlock(&mutex);
    }

    return NULL;
}

int main() {
    pthread_t barber_thread;
    pthread_t customer_threads[NUM_CUSTOMERS];
    
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond_var, NULL);

    // Create the barber thread
    pthread_create(&barber_thread, NULL, barber, NULL);

    // Create customer threads
    for (int i = 0; i < NUM_CUSTOMERS; ++i) {
        int *customer_id = malloc(sizeof(int));
        *customer_id = i + 1; // Customer IDs start from 1
        pthread_create(&customer_threads[i], NULL, customer, (void *)customer_id);
        sleep(1);  // Stagger customer arrivals
    }

    // Wait for customer threads to finish
    for (int i = 0; i < NUM_CUSTOMERS; ++i) {
        pthread_join(customer_threads[i], NULL);
    }

    // Cleanup
    pthread_cancel(barber_thread);  // Stop barber thread when done
    pthread_join(barber_thread, NULL);
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond_var);
    return 0;
}