//MISTRAL-7B DATASET v1.0 Category: Mortgage Calculator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024

struct mortgage {
    double principal;
    double annual_interest_rate;
    int loan_length_years;
};

struct monthly_payment {
    double monthly_interest_rate;
    int months;
    double total_payment;
};

void calculate_mortgage(struct mortgage*, struct monthly_payment*);

int main(void) {
    char line[MAX_LINE_LENGTH];
    char* token;
    struct mortgage mortgage;
    struct monthly_payment monthly_payment;

    printf("Enter Mortgage Principal: ");
    fgets(line, MAX_LINE_LENGTH, stdin);
    mortgage.principal = strtod(strtok(line, " "), NULL);

    printf("Enter Annual Interest Rate: ");
    fgets(line, MAX_LINE_LENGTH, stdin);
    mortgage.annual_interest_rate = strtod(strtok(line, " "), NULL);

    printf("Enter Loan Length (in years): ");
    fgets(line, MAX_LINE_LENGTH, stdin);
    mortgage.loan_length_years = atoi(strtok(line, " "));

    calculate_mortgage(&mortgage, &monthly_payment);

    printf("Monthly Payment: $%.2f\n", monthly_payment.total_payment);

    return EXIT_SUCCESS;
}

void calculate_mortgage(struct mortgage* mortgage, struct monthly_payment* monthly_payment) {
    monthly_payment->monthly_interest_rate = mortgage->annual_interest_rate / 100 / 12.0;
    monthly_payment->total_payment = 0;

    for (int i = 0; i < mortgage->loan_length_years * 12; i++) {
        double interest = mortgage->principal * monthly_payment->monthly_interest_rate;
        double payment = monthly_payment->total_payment + interest;
        double principal_payment = payment - interest;
        mortgage->principal -= principal_payment;
        monthly_payment->total_payment = payment;
    }
}