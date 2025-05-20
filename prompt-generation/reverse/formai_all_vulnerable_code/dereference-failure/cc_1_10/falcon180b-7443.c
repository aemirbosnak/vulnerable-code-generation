//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

// Mutex for critical section
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Condition variable for signaling between threads
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

struct expense {
    char* description;
    float amount;
    time_t timestamp;
};

struct expense* expenses = NULL;
int num_expenses = 0;

void add_expense(char* desc, float amt) {
    struct expense* new_expense = malloc(sizeof(struct expense));

    if (new_expense == NULL) {
        printf("Error: Out of memory\n");
        return;
    }

    new_expense->description = desc;
    new_expense->amount = amt;
    new_expense->timestamp = time(NULL);

    pthread_mutex_lock(&mutex);
    expenses = realloc(expenses, sizeof(struct expense) * ++num_expenses);
    expenses[num_expenses - 1] = *new_expense;
    free(new_expense);
    pthread_mutex_unlock(&mutex);
}

void print_expenses() {
    pthread_mutex_lock(&mutex);
    for (int i = 0; i < num_expenses; i++) {
        printf("%s: $%.2f - %s\n", expenses[i].description, expenses[i].amount, ctime(&expenses[i].timestamp));
    }
    pthread_mutex_unlock(&mutex);
}

void* expense_thread(void* arg) {
    char input[1024];

    while (1) {
        printf("Enter expense description: ");
        fgets(input, sizeof(input), stdin);

        char* desc = strtok(input, "\n");
        float amt = atof(strtok(NULL, "\n"));

        add_expense(desc, amt);
    }

    return NULL;
}

int main() {
    pthread_t thread_id;

    expenses = malloc(sizeof(struct expense));
    if (expenses == NULL) {
        printf("Error: Out of memory\n");
        return 1;
    }

    pthread_create(&thread_id, NULL, expense_thread, NULL);

    while (1) {
        sleep(1);
        print_expenses();
    }

    pthread_join(thread_id, NULL);

    free(expenses);
    return 0;
}