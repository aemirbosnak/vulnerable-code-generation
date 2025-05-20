//MISTRAL-7B DATASET v1.0 Category: Mortgage Calculator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LEN 100

typedef struct {
    double principal;
    double annual_interest_rate;
    int loan_term_years;
    int loan_term_months;
} Mortgage;

void parse_args(int argc, char* argv[], Mortgage* mortgage) {
    if (argc != 4) {
        printf("Usage: %s <principal> <annual_interest_rate> <loan_term_years>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    mortgage->principal = atof(argv[1]);
    mortgage->annual_interest_rate = atof(argv[2]) / 100.0;
    mortgage->loan_term_years = atoi(argv[3]);
    mortgage->loan_term_months = mortgage->loan_term_years * 12;

    if (mortgage->principal <= 0.0 || mortgage->annual_interest_rate <= 0.0 || mortgage->loan_term_years <= 0) {
        printf("Invalid input. Principal, annual interest rate, and loan term must be positive numbers.\n");
        exit(EXIT_FAILURE);
    }
}

double calculate_monthly_payment(Mortgage mortgage) {
    double monthly_interest_rate = mortgage.annual_interest_rate / 12.0;
    double number_of_payments = mortgage.loan_term_months;

    double monthly_payment = pow(1 + monthly_interest_rate, number_of_payments) * monthly_interest_rate * mortgage.principal / (pow(1 + monthly_interest_rate, number_of_payments) - 1);

    return monthly_payment;
}

int main(int argc, char* argv[]) {
    Mortgage mortgage;
    double monthly_payment;

    parse_args(argc, argv, &mortgage);

    monthly_payment = calculate_monthly_payment(mortgage);

    printf("Monthly payment: $%.2f\n", monthly_payment);

    return EXIT_SUCCESS;
}