//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: multi-threaded
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Shared data
struct expense {
    char* description;
    double amount;
};

struct expense_list {
    struct expense* expenses;
    int size;
};

struct expense_list* shared_list;

// Mutex to protect shared data
pthread_mutex_t mutex;

// Thread function
void* expense_tracker(void* arg) {
    // Get the expense to be tracked
    struct expense* expense = (struct expense*)arg;

    // Lock the mutex
    pthread_mutex_lock(&mutex);

    // Add the expense to the shared list
    shared_list->expenses = realloc(shared_list->expenses, (shared_list->size + 1) * sizeof(struct expense));
    shared_list->expenses[shared_list->size] = *expense;
    shared_list->size++;

    // Unlock the mutex
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main() {
    // Initialize shared data
    shared_list = malloc(sizeof(struct expense_list));
    shared_list->expenses = NULL;
    shared_list->size = 0;

    // Initialize mutex
    pthread_mutex_init(&mutex, NULL);

    // Create threads to track expenses
    pthread_t threads[10];
    for (int i = 0; i < 10; i++) {
        struct expense* expense = malloc(sizeof(struct expense));
        expense->description = "Expense";
        expense->amount = i * 10;
        pthread_create(&threads[i], NULL, expense_tracker, (void*)expense);
    }

    // Join threads
    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the shared list of expenses
    for (int i = 0; i < shared_list->size; i++) {
        printf("%s: %.2f\n", shared_list->expenses[i].description, shared_list->expenses[i].amount);
    }

    // Free shared data and mutex
    free(shared_list->expenses);
    free(shared_list);
    pthread_mutex_destroy(&mutex);

    return 0;
}