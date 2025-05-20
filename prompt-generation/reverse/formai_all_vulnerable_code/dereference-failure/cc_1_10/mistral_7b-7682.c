//MISTRAL-7B DATASET v1.0 Category: Mortgage Calculator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_LEN 1024
#define TRUE 1
#define FALSE 0

typedef struct {
    double principal;
    double annual_rate;
    int term;
    int payments;
    double monthly_payment;
    double total_payment;
} mortgage;

void validate_input(char *input, mortgage *mortgage) {
    char *token = strtok(input, " ");
    int i = 0;

    if (token == NULL || strcmp(token, "MORTGAGE") != 0) {
        printf("Invalid input. Use 'MORTGAGE <principal> <annual_rate> <term>'\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(NULL, " ");
    mortgage->principal = atof(token);

    if (token == NULL) {
        printf("Invalid input. Use 'MORTGAGE <principal> <annual_rate> <term>'\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(NULL, " ");
    mortgage->annual_rate = atof(token) / 100.0;

    if (token == NULL) {
        printf("Invalid input. Use 'MORTGAGE <principal> <annual_rate> <term>'\n");
        exit(EXIT_FAILURE);
    }

    mortgage->term = atoi(token);

    if (mortgage->term < 5 || mortgage->term > 30) {
        printf("Invalid term length. Use a term between 5 and 30 years.\n");
        exit(EXIT_FAILURE);
    }

    mortgage->payments = mortgage->term * 12;
    mortgage->monthly_payment = mortgage->principal * pow(1 + mortgage->annual_rate / 12.0, mortgage->payments) * mortgage->annual_rate / (12.0 * pow(1 + mortgage->annual_rate / 12.0, mortgage->payments));
    mortgage->total_payment = mortgage->payments * mortgage->monthly_payment;
}

int main(int argc, char *argv[]) {
    mortgage mortgage;
    char input[MAX_LEN];
    int i;

    if (argc != 2) {
        printf("Usage: %s <MORTGAGE <principal> <annual_rate> <term>>>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    strcpy(input, argv[1]);
    validate_input(input, &mortgage);

    printf("Principal: %f\n", mortgage.principal);
    printf("Annual Rate: %f (%.2f%%)\n", mortgage.annual_rate, mortgage.annual_rate * 100.0);
    printf("Term: %d years (%d payments)\n", mortgage.term, mortgage.payments);
    printf("Monthly Payment: %f\n", mortgage.monthly_payment);
    printf("Total Payment: %f\n", mortgage.total_payment);

    srand(time(NULL));

    for (i = 0; i < mortgage.payments; i++) {
        double current_balance = mortgage.principal - mortgage.monthly_payment * (i + 1);

        if (current_balance < 0) {
            printf("Error: Negative balance detected. Exiting program...\n");
            exit(EXIT_FAILURE);
        }

        printf("Payment %d: Principal: %f, Interest: %f, Balance: %f\n", i + 1, mortgage.monthly_payment * 0.017 * current_balance, mortgage.monthly_payment - mortgage.monthly_payment * 0.017 * current_balance, current_balance);
    }

    return EXIT_SUCCESS;
}