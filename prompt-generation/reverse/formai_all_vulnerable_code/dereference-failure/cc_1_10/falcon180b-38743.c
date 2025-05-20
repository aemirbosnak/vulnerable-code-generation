//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_NUM_TRANSACTIONS 1000

typedef struct {
    char description[MAX_LINE_LENGTH];
    float amount;
    char category[MAX_LINE_LENGTH];
} Transaction;

Transaction transactions[MAX_NUM_TRANSACTIONS];
int num_transactions = 0;

void read_transactions(FILE *fp) {
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        if (num_transactions >= MAX_NUM_TRANSACTIONS) {
            printf("Error: Maximum number of transactions exceeded.\n");
            exit(1);
        }
        char *token = strtok(line, ",");
        strcpy(transactions[num_transactions].description, token);
        token = strtok(NULL, ",");
        transactions[num_transactions].amount = atof(token);
        token = strtok(NULL, ",");
        strcpy(transactions[num_transactions].category, token);
        num_transactions++;
    }
}

void print_transactions() {
    printf("Transaction ID\tDescription\tAmount\tCategory\n");
    for (int i = 0; i < num_transactions; i++) {
        printf("%d\t%s\t%.2f\t%s\n", i+1, transactions[i].description, transactions[i].amount, transactions[i].category);
    }
}

void calculate_totals() {
    float total_income = 0.0;
    float total_expenses = 0.0;
    for (int i = 0; i < num_transactions; i++) {
        if (strcmp(transactions[i].category, "Income") == 0) {
            total_income += transactions[i].amount;
        } else if (strcmp(transactions[i].category, "Expense") == 0) {
            total_expenses += transactions[i].amount;
        }
    }
    printf("Total Income: $%.2f\n", total_income);
    printf("Total Expenses: $%.2f\n", total_expenses);
}

int main() {
    FILE *fp;
    fp = fopen("transactions.csv", "r");
    if (fp == NULL) {
        printf("Error: Could not open transactions file.\n");
        exit(1);
    }
    read_transactions(fp);
    fclose(fp);

    print_transactions();

    calculate_totals();

    return 0;
}