//MISTRAL-7B DATASET v1.0 Category: Mortgage Calculator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_LENGTH 100
#define MIN_DOWN_PAYMENT 5
#define MAX_TERM 30
#define MAX_APR 30
#define MIN_CREDIT_SCORE 620

struct Mortgage {
    double principal;
    int term;
    double interest_rate;
    double monthly_payment;
};

void calculate_mortgage(struct Mortgage* mortgage) {
    mortgage->monthly_payment = mortgage->principal * pow(1 + mortgage->interest_rate / 12.0, mortgage->term * 12) / (pow(1 + mortgage->interest_rate / 12.0, mortgage->term * 12) - 1);
}

void print_mortgage(struct Mortgage* mortgage) {
    printf("Mortgage Details:\n");
    printf("------------------\n");
    printf("Principal: $%.2f\n", mortgage->principal);
    printf("Term: %d years\n", mortgage->term);
    printf("Interest Rate: %.2f%%\n", mortgage->interest_rate);
    printf("Monthly Payment: $%.2f\n", mortgage->monthly_payment);
}

int main(int argc, char** argv) {
    if (argc != 5) {
        printf("Usage: %s <principal> <term> <interest_rate> <credit_score>\n", argv[0]);
        return 1;
    }

    struct Mortgage mortgage;
    mortgage.principal = atof(argv[1]);
    mortgage.term = atoi(argv[2]);
    mortgage.interest_rate = atof(argv[3]) / 100.0;

    int credit_score = atoi(argv[4]);

    if (mortgage.term > MAX_TERM || mortgage.term < 1 || mortgage.interest_rate > MAX_APR || mortgage.interest_rate < 0 || mortgage.principal < MIN_DOWN_PAYMENT) {
        printf("Invalid input! Please check the values for principal, term, interest_rate.\n");
        return 1;
    }

    if (credit_score < MIN_CREDIT_SCORE) {
        printf("Credit score is too low. Minimum required credit score is %d.\n", MIN_CREDIT_SCORE);
        return 1;
    }

    calculate_mortgage(&mortgage);
    print_mortgage(&mortgage);

    return 0;
}