//GEMINI-pro DATASET v1.0 Category: Mortgage Calculator ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

typedef struct {
    double principal;
    double interest;
    int years;
    double monthlyPayment;
    double totalInterest;
    double totalPayments;
} Mortgage;

typedef struct {
    Mortgage *mortgage;
    int startMonth;
    int endMonth;
} ThreadArgs;

void *calculateMortgage(void *args) {
    ThreadArgs *threadArgs = (ThreadArgs *)args;
    Mortgage *mortgage = threadArgs->mortgage;
    int startMonth = threadArgs->startMonth;
    int endMonth = threadArgs->endMonth;

    double balance = mortgage->principal;
    double monthlyInterestRate = mortgage->interest / 1200;
    double monthlyPayment = mortgage->monthlyPayment;

    for (int month = startMonth; month <= endMonth; month++) {
        double interestPaid = balance * monthlyInterestRate;
        double principalPaid = monthlyPayment - interestPaid;
        balance -= principalPaid;

        mortgage->totalInterest += interestPaid;
        mortgage->totalPayments += monthlyPayment;
    }

    free(threadArgs);

    return NULL;
}

int main() {
    double principal;
    double interest;
    int years;
    double monthlyPayment;

    printf("Enter the principal amount: ");
    scanf("%lf", &principal);

    printf("Enter the annual interest rate: ");
    scanf("%lf", &interest);

    printf("Enter the loan term in years: ");
    scanf("%d", &years);

    printf("Enter the monthly payment: ");
    scanf("%lf", &monthlyPayment);

    Mortgage mortgage;
    mortgage.principal = principal;
    mortgage.interest = interest;
    mortgage.years = years;
    mortgage.monthlyPayment = monthlyPayment;
    mortgage.totalInterest = 0;
    mortgage.totalPayments = 0;

    int numThreads;
    printf("Enter the number of threads to use: ");
    scanf("%d", &numThreads);

    pthread_t threads[numThreads];
    ThreadArgs threadArgs[numThreads];

    int monthsPerThread = years * 12 / numThreads;
    for (int i = 0; i < numThreads; i++) {
        threadArgs[i].mortgage = &mortgage;
        threadArgs[i].startMonth = i * monthsPerThread + 1;
        threadArgs[i].endMonth = (i + 1) * monthsPerThread;
        pthread_create(&threads[i], NULL, calculateMortgage, &threadArgs[i]);
    }

    for (int i = 0; i < numThreads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Monthly payment: $%.2f\n", mortgage.monthlyPayment);
    printf("Total interest paid: $%.2f\n", mortgage.totalInterest);
    printf("Total payments made: $%.2f\n", mortgage.totalPayments);

    return 0;
}