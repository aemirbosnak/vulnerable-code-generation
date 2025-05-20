//GEMINI-pro DATASET v1.0 Category: Mortgage Calculator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double loan_amount;
    double interest_rate;
    int num_years;
    double monthly_payment;
} Mortgage;

Mortgage* create_mortgage(double loan_amount, double interest_rate, int num_years) {
    Mortgage* m = malloc(sizeof(Mortgage));
    m->loan_amount = loan_amount;
    m->interest_rate = interest_rate;
    m->num_years = num_years;
    m->monthly_payment = 0.0;
    return m;
}

void destroy_mortgage(Mortgage* m) {
    free(m);
}

double calculate_monthly_payment(Mortgage* m) {
    double r = m->interest_rate / 1200.0;
    int n = m->num_years * 12;
    double p = m->loan_amount;
    double payment = (p * r) / (1 - pow(1 + r, -n));
    return payment;
}

void print_mortgage(Mortgage* m) {
    printf("Loan amount: $%.2f\n", m->loan_amount);
    printf("Interest rate: %.2f%%\n", m->interest_rate * 100);
    printf("Loan term: %d years\n", m->num_years);
    printf("Monthly payment: $%.2f\n", m->monthly_payment);
}

int main() {
    double loan_amount = 200000.0;
    double interest_rate = 0.05;
    int num_years = 30;

    Mortgage* m = create_mortgage(loan_amount, interest_rate, num_years);
    m->monthly_payment = calculate_monthly_payment(m);
    print_mortgage(m);
    destroy_mortgage(m);
    return 0;
}