//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *desc;
    double amount;
} trans_t;

typedef struct {
    char *name;
    trans_t *trans;
    int num_trans;
} account_t;

int main() {
    account_t account = {
        .name = "Checking",
        .trans = malloc(sizeof(trans_t) * 10),
        .num_trans = 0
    };

    // Get user input and add transactions
    while (1) {
        char buf[1024];
        printf("Enter a transaction (desc amount): ");
        if (fgets(buf, sizeof(buf), stdin) == NULL) {
            break;
        }

        char *desc = strtok(buf, " ");
        char *amount = strtok(NULL, " ");
        if (desc == NULL || amount == NULL) {
            printf("Invalid input.\n");
            continue;
        }

        trans_t trans = {
            .desc = strdup(desc),
            .amount = atof(amount)
        };
        account.trans[account.num_trans++] = trans;
    }

    // Print out transactions
    printf("\nTransactions for %s:\n", account.name);
    for (int i = 0; i < account.num_trans; i++) {
        printf("%s %f\n", account.trans[i].desc, account.trans[i].amount);
    }

    // Clean up
    for (int i = 0; i < account.num_trans; i++) {
        free(account.trans[i].desc);
    }
    free(account.trans);

    return 0;
}