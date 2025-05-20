//GEMINI-pro DATASET v1.0 Category: Mortgage Calculator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    double principal;
    double interestRate;
    double termInYears;
    int paymentFrequency;
} MortgageParams;

typedef struct {
    double monthlyPayment;
    double totalInterestPaid;
    double totalCost;
} MortgageResults;

bool parseArgs(int argc, char **argv, MortgageParams *params) {

    if (argc != 5) {
        printf("Usage: %s principal interest term_in_years payment_frequency\n", argv[0]);
        return false;
    }

    params->principal = atof(argv[1]);
    params->interestRate = atof(argv[2]);
    params->termInYears = atof(argv[3]);
    params->paymentFrequency = atoi(argv[4]);

    if (params->principal <= 0 || params->interestRate <= 0 || params->termInYears <= 0 || params->paymentFrequency <= 0) {
        printf("Invalid input values\n");
        return false;
    }

    return true;
}

MortgageResults calculateMortgage(MortgageParams params) {

    MortgageResults results;

    double monthlyInterestRate = params.interestRate / 12;
    double numPayments = params.termInYears * params.paymentFrequency;
    double denominator = pow((1 + monthlyInterestRate), numPayments) - 1;

    results.monthlyPayment = (params.principal * monthlyInterestRate) / denominator;
    results.totalInterestPaid = results.monthlyPayment * numPayments - params.principal;
    results.totalCost = results.monthlyPayment * numPayments;

    return results;
}

void printResults(MortgageParams params, MortgageResults results) {

    printf("Mortgage Parameters:\n");
    printf("  Principal: %.2lf\n", params.principal);
    printf("  Interest Rate: %.2lf%%\n", params.interestRate);
    printf("  Term in Years: %.2lf\n", params.termInYears);
    printf("  Payment Frequency: %d\n", params.paymentFrequency);

    printf("\nMortgage Results:\n");
    printf("  Monthly Payment: %.2lf\n", results.monthlyPayment);
    printf("  Total Interest Paid: %.2lf\n", results.totalInterestPaid);
    printf("  Total Cost: %.2lf\n", results.totalCost);
}

int main(int argc, char **argv) {

    MortgageParams params;
    MortgageResults results;

    if (!parseArgs(argc, argv, &params)) {
        return EXIT_FAILURE;
    }

    results = calculateMortgage(params);
    printResults(params, results);

    return EXIT_SUCCESS;
}