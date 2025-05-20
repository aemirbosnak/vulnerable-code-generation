//FormAI DATASET v1.0 Category: Expense Tracker ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

typedef struct expense {
    struct tm date;
    float amount;
    char description[100];
} Expense;

typedef struct expense_node {
    Expense expense;
    struct expense_node *next;
} ExpenseNode;

ExpenseNode *head = NULL;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int addExpense(struct tm date, float amount, char description[]) {
    pthread_mutex_lock(&mutex);
    
    ExpenseNode *new_node = (ExpenseNode*) malloc(sizeof(ExpenseNode));
    new_node->expense.date = date;
    new_node->expense.amount = amount;
    strcpy(new_node->expense.description, description);
    new_node->next = head;
    head = new_node;
    
    pthread_mutex_unlock(&mutex);
    return 1;
}

float calculateTotalExpenses() {
    pthread_mutex_lock(&mutex);
    
    float total = 0;
    ExpenseNode *current_node = head;
    while (current_node != NULL) {
        total += current_node->expense.amount;
        current_node = current_node->next;
    }
    
    pthread_mutex_unlock(&mutex);
    return total;
}

void printExpenses(struct tm start_date, struct tm end_date) {
    pthread_mutex_lock(&mutex);
    
    printf("\nExpenses between %02d/%02d/%04d and %02d/%02d/%04d:\n", start_date.tm_mday, start_date.tm_mon+1, start_date.tm_year+1900, end_date.tm_mday, end_date.tm_mon+1, end_date.tm_year+1900);
    ExpenseNode *current_node = head;
    while (current_node != NULL) {
        if (difftime(mktime(&start_date), mktime(&current_node->expense.date)) <= 0 && difftime(mktime(&current_node->expense.date), mktime(&end_date)) <= 0) {
            printf("%02d/%02d/%04d - %s - $%.2f\n", current_node->expense.date.tm_mday, current_node->expense.date.tm_mon+1, current_node->expense.date.tm_year+1900, current_node->expense.description, current_node->expense.amount);
        }
        current_node = current_node->next;
    }
    
    pthread_mutex_unlock(&mutex);
}

void *addExpenseTask(void *arg) {
    int i;
    for (i = 0; i < *((int*) arg); i++) {
        struct tm date = *localtime(&(time_t) {time(NULL)});
        float amount = (rand() % 10000) / 100.0;
        char * descriptions[] = {"Grocery shopping", "Gas", "Restaurant", "Movie tickets", "Coffee", "Clothes shopping", "Gym membership", "Phone bill", "Rent", "Electricity bill"};

        addExpense(date, amount, descriptions[rand() % 10]);
        sleep(rand() % 4);
    }
    pthread_exit(NULL);
}

int main() {
    srand(time(NULL));
    
    pthread_t threads[10];
    int tasks[10];
    int i;
    for (i = 0; i < 10; i++) {
        tasks[i] = rand() % 5 + 1;
        
        if (pthread_create(&threads[i], NULL, addExpenseTask, &tasks[i])) {
            printf("Error creating thread %d", i+1);
            exit(-1);
        }
    }
    
    for (i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }
    
    struct tm start_date = {0, 0, 0, 1, 0, 121}; // 01/01/2021
    struct tm end_date = {0, 0, 0, 20, 2, 121}; // 20/03/2021
    
    printExpenses(start_date, end_date);
    printf("\nTotal expenses: $%.2f\n", calculateTotalExpenses());
    
    return 0;
}