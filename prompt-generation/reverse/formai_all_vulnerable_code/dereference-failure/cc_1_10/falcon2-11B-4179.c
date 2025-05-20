//Falcon2-11B DATASET v1.0 Category: Expense Tracker ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

// Struct for an expense
typedef struct {
    int expense_id;
    char expense_name[50];
    double expense_amount;
} Expense;

// Global variables
sem_t expenses_mutex;
sem_t expenses_not_empty;
sem_t expenses_not_full;
Expense *expenses_array;
int expense_count = 0;

void* insert_expense_thread(void* arg) {
    Expense expense = {0};
    char expense_name[50];
    double expense_amount;

    while (1) {
        // Get the expense details from the user
        printf("Enter expense details: ");
        scanf("%d %s %lf", &expense.expense_id, expense_name, &expense_amount);

        // Lock the expenses mutex
        sem_wait(&expenses_mutex);

        // Check if there is space in the expenses array
        if (expense_count >= 10) {
            sem_post(&expenses_not_full);
        } else {
            // Add the expense to the array
            expenses_array[expense_count] = expense;
            sem_post(&expenses_not_empty);
        }

        // Unlock the expenses mutex
        sem_post(&expenses_mutex);

        // Sleep for 1 second before checking for new expenses
        sleep(1);
    }

    return NULL;
}

void* remove_expense_thread(void* arg) {
    while (1) {
        // Wait for an expense to be added
        sem_wait(&expenses_not_empty);

        // Lock the expenses mutex
        sem_wait(&expenses_mutex);

        // Remove the first expense from the array
        Expense temp = expenses_array[0];
        expenses_array[0] = expenses_array[expense_count];
        expense_count--;
        sem_post(&expenses_not_empty);

        // Unlock the expenses mutex
        sem_post(&expenses_mutex);

        // Print the removed expense
        printf("Removed expense: %d - %s - $%.2lf\n", temp.expense_id, temp.expense_name, temp.expense_amount);

        // Sleep for 1 second before checking for new expenses
        sleep(1);
    }

    return NULL;
}

int main() {
    // Create semaphores
    sem_init(&expenses_mutex, 0, 1);
    sem_init(&expenses_not_empty, 0, 0);
    sem_init(&expenses_not_full, 0, 0);

    // Allocate memory for the expenses array
    expenses_array = (Expense*) malloc(sizeof(Expense) * 10);

    // Create threads to insert and remove expenses
    pthread_t insert_expense_thread_id, remove_expense_thread_id;
    pthread_create(&insert_expense_thread_id, NULL, insert_expense_thread, NULL);
    pthread_create(&remove_expense_thread_id, NULL, remove_expense_thread, NULL);

    // Wait for the threads to finish
    pthread_join(insert_expense_thread_id, NULL);
    pthread_join(remove_expense_thread_id, NULL);

    // Free the expenses array
    free(expenses_array);

    // Destroy the semaphores
    sem_destroy(&expenses_mutex);
    sem_destroy(&expenses_not_empty);
    sem_destroy(&expenses_not_full);

    return 0;
}