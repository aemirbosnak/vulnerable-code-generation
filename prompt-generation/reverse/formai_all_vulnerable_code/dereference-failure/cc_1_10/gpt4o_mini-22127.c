//GPT-4o-mini DATASET v1.0 Category: Threading Library Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define TOTAL_TICKETS 10 // Total Available Tickets

pthread_mutex_t mutex; // Mutex for synchronizing access to shared resources
int available_tickets = TOTAL_TICKETS; // Counter for available tickets

void* book_ticket(void* arg) {
    int customer_id = *(int*)arg;
    free(arg); // Free the dynamically allocated memory for customer_id
    
    pthread_mutex_lock(&mutex); // Lock the mutex to enter the critical section

    if (available_tickets > 0) {
        printf("Customer %d is booking ticket. Tickets left: %d\n", customer_id, available_tickets - 1);
        sleep(1); // simulate booking time
        available_tickets--; // Decrement the ticket count
        printf("Customer %d successfully booked a ticket. Tickets left: %d\n", customer_id, available_tickets);
    } else {
        printf("Customer %d tried to book a ticket, but none are available.\n", customer_id);
    }

    pthread_mutex_unlock(&mutex); // Unlock the mutex after leaving the critical section
    return NULL;
}

int main() {
    pthread_t threads[20]; // Array of thread identifiers
    pthread_mutex_init(&mutex, NULL); // Initialize the mutex

    printf("Ticket Booking System started. Total Tickets: %d\n", TOTAL_TICKETS);

    for (int i = 0; i < 20; i++) {
        int* customer_id = malloc(sizeof(int)); // Allocate memory for customer_id
        *customer_id = i + 1; // Assign a unique customer ID
        if (pthread_create(&threads[i], NULL, book_ticket, customer_id) != 0) {
            perror("Failed to create thread");
            free(customer_id); // Free memory in case of error
        }
    }

    // Join all threads before exiting the main program
    for (int i = 0; i < 20; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex); // Clean up the mutex
    printf("Ticket Booking System closed. Final Tickets available: %d\n", available_tickets);
    return 0;
}