//Falcon-180B DATASET v1.0 Category: Mortgage Calculator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <pthread.h>

#define MAX_MONTHS 360
#define MAX_THREADS 100

struct loan {
    int id;
    double principal;
    double interest_rate;
    int term;
    double monthly_payment;
};

struct loan loans[MAX_MONTHS];

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *calculate_monthly_payment(void *arg) {
    int id = *(int *) arg;
    struct loan *loan = &loans[id];

    loan->monthly_payment = loan->principal * pow(1 + loan->interest_rate / 12, 12 * loan->term) / (1 - pow(1 + loan->interest_rate / 12, -12 * loan->term));

    pthread_mutex_lock(&lock);
    printf("Monthly payment for loan %d: $%.2f\n", id, loan->monthly_payment);
    pthread_mutex_unlock(&lock);

    return NULL;
}

int main() {
    int num_loans;
    printf("Enter number of loans: ");
    scanf("%d", &num_loans);

    for (int i = 0; i < num_loans; i++) {
        printf("Enter loan %d details:\n", i + 1);
        printf("Principal: ");
        scanf("%lf", &loans[i].principal);
        printf("Interest rate: ");
        scanf("%lf", &loans[i].interest_rate);
        printf("Term (months): ");
        scanf("%d", &loans[i].term);
    }

    int num_threads = num_loans > MAX_THREADS? MAX_THREADS : num_loans;
    pthread_t threads[num_threads];

    for (int i = 0; i < num_threads; i++) {
        int id = i;
        pthread_create(&threads[i], NULL, calculate_monthly_payment, &id);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}