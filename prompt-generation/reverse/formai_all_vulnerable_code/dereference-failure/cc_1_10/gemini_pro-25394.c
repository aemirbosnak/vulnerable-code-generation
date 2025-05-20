//GEMINI-pro DATASET v1.0 Category: Mortgage Calculator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Mortgage {
    double principal;
    double interest;
    int term;
    double payment;
    double balance;
} Mortgage;

Mortgage* create_mortgage(double principal, double interest, int term) {
    Mortgage* mortgage = malloc(sizeof(Mortgage));
    mortgage->principal = principal;
    mortgage->interest = interest;
    mortgage->term = term;
    mortgage->payment = 0;
    mortgage->balance = principal;
    return mortgage;
}

void free_mortgage(Mortgage* mortgage) {
    free(mortgage);
}

double calculate_payment(Mortgage* mortgage) {
    double rate = mortgage->interest / 12;
    double num_payments = mortgage->term * 12;
    return (rate * mortgage->principal) / (1 - pow(1 + rate, -num_payments));
}

void print_mortgage(Mortgage* mortgage) {
    printf("Principal: %.2f\n", mortgage->principal);
    printf("Interest: %.2f\n", mortgage->interest);
    printf("Term: %d\n", mortgage->term);
    printf("Payment: %.2f\n", mortgage->payment);
    printf("Balance: %.2f\n", mortgage->balance);
}

int main() {
    Mortgage* mortgage = create_mortgage(100000, 0.05, 30);

    mortgage->payment = calculate_payment(mortgage);

    print_mortgage(mortgage);

    for (int i = 0; i < mortgage->term * 12; i++) {
        double interest_paid = mortgage->balance * (mortgage->interest / 12);
        double principal_paid = mortgage->payment - interest_paid;
        mortgage->balance -= principal_paid;
        print_mortgage(mortgage);
    }

    free_mortgage(mortgage);

    return 0;
}