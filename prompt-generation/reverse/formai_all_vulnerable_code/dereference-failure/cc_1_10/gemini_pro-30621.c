//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int day;
    int month;
    int year;
} Date;

typedef struct
{
    char *description;
    int amount;
    Date date;
} Transaction;

typedef struct
{
    int num_transactions;
    Transaction *transactions;
} Ledger;

void add_transaction(Ledger *ledger, char *description, int amount, Date date)
{
    Transaction transaction;
    transaction.description = description;
    transaction.amount = amount;
    transaction.date = date;
    ledger->transactions = realloc(ledger->transactions, sizeof(Transaction) * (ledger->num_transactions + 1));
    ledger->transactions[ledger->num_transactions] = transaction;
    ledger->num_transactions++;
}

void print_ledger(Ledger ledger)
{
    printf("Ledger:\n");
    for (int i = 0; i < ledger.num_transactions; i++)
    {
        Transaction transaction = ledger.transactions[i];
        printf("  %s %d %d/%d/%d\n", transaction.description, transaction.amount, transaction.date.day, transaction.date.month, transaction.date.year);
    }
}

int main()
{
    Ledger ledger;
    ledger.num_transactions = 0;
    ledger.transactions = NULL;

    add_transaction(&ledger, "Bought a loaf of bread", -10, (Date){1, 1, 1348});
    add_transaction(&ledger, "Sold a sword", 100, (Date){5, 1, 1348});
    add_transaction(&ledger, "Paid taxes", -50, (Date){10, 1, 1348});
    add_transaction(&ledger, "Received inheritance", 1000, (Date){15, 1, 1348});

    print_ledger(ledger);

    return 0;
}