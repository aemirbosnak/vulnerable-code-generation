//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_THREADS 4

// Semaphore to protect shared data
sem_t mutex;

// Shared data structure to store expenses
typedef struct {
    int id;
    char *description;
    double amount;
} expense_t;

// Linked list to store expenses
struct node {
    expense_t expense;
    struct node *next;
};

struct node *head = NULL;

// Function to create a new expense
expense_t *create_expense(int id, char *description, double amount) {
    expense_t *expense = malloc(sizeof(expense_t));
    expense->id = id;
    expense->description = description;
    expense->amount = amount;
    return expense;
}

// Function to add an expense to the linked list
void add_expense(expense_t *expense) {
    // Lock the shared data
    sem_wait(&mutex);

    // Add the expense to the head of the linked list
    struct node *new_node = malloc(sizeof(struct node));
    new_node->expense = *expense;
    new_node->next = head;
    head = new_node;

    // Unlock the shared data
    sem_post(&mutex);
}

// Function to print the expenses in the linked list
void print_expenses() {
    // Lock the shared data
    sem_wait(&mutex);

    // Print the expenses
    struct node *current = head;
    while (current != NULL) {
        printf("Expense ID: %d, Description: %s, Amount: %.2f\n", current->expense.id, current->expense.description, current->expense.amount);
        current = current->next;
    }

    // Unlock the shared data
    sem_post(&mutex);
}

// Function to be executed by each thread
void *thread_function(void *arg) {
    // Get the thread ID
    int thread_id = *(int *)arg;

    // Create some expenses
    expense_t *expense1 = create_expense(thread_id, "Expense 1", 100.00);
    expense_t *expense2 = create_expense(thread_id, "Expense 2", 200.00);
    expense_t *expense3 = create_expense(thread_id, "Expense 3", 300.00);

    // Add the expenses to the linked list
    add_expense(expense1);
    add_expense(expense2);
    add_expense(expense3);

    // Print the expenses
    print_expenses();

    return NULL;
}

int main() {
    // Initialize the semaphore
    sem_init(&mutex, 0, 1);

    // Create the threads
    pthread_t threads[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        int *thread_id = malloc(sizeof(int));
        *thread_id = i;
        pthread_create(&threads[i], NULL, thread_function, thread_id);
    }

    // Join the threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy the semaphore
    sem_destroy(&mutex);

    return 0;
}