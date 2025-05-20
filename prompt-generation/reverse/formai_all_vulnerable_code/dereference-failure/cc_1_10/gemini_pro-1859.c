//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_TRANSACTIONS 100

typedef struct {
    char name[50];
    double amount;
} Transaction;

typedef struct {
    char name[50];
    Transaction transactions[MAX_TRANSACTIONS];
    int num_transactions;
} Category;

Category categories[MAX_CATEGORIES];
int num_categories = 0;

void add_category(char *name) {
    if (num_categories >= MAX_CATEGORIES) {
        printf("Error: Too many categories.\n");
        return;
    }

    strcpy(categories[num_categories].name, name);
    categories[num_categories].num_transactions = 0;
    num_categories++;
}

void add_transaction(char *category, double amount) {
    int i;

    for (i = 0; i < num_categories; i++) {
        if (strcmp(categories[i].name, category) == 0) {
            if (categories[i].num_transactions >= MAX_TRANSACTIONS) {
                printf("Error: Too many transactions in category %s.\n", category);
                return;
            }

            categories[i].transactions[categories[i].num_transactions].amount = amount;
            categories[i].num_transactions++;
            return;
        }
    }

    printf("Error: Category %s not found.\n", category);
}

void print_report() {
    int i, j;

    for (i = 0; i < num_categories; i++) {
        printf("%s:\n", categories[i].name);
        for (j = 0; j < categories[i].num_transactions; j++) {
            printf("  %f\n", categories[i].transactions[j].amount);
        }
        printf("\n");
    }
}

int main() {
    char input[100];
    char *command;
    char *arg1;
    char *arg2;

    while (1) {
        printf("> ");
        fgets(input, 100, stdin);

        command = strtok(input, " ");
        arg1 = strtok(NULL, " ");
        arg2 = strtok(NULL, " ");

        if (strcmp(command, "add_category") == 0) {
            add_category(arg1);
        } else if (strcmp(command, "add_transaction") == 0) {
            double amount = atof(arg2);
            add_transaction(arg1, amount);
        } else if (strcmp(command, "print_report") == 0) {
            print_report();
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}