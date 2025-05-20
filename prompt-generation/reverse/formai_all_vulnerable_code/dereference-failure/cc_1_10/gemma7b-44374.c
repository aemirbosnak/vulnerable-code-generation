//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_TRANSFERS 10

typedef struct Transfer {
    char *name;
    double amount;
    struct Transfer *next;
} Transfer;

Transfer *createTransfer(char *name, double amount) {
    Transfer *newTransfer = malloc(sizeof(Transfer));
    newTransfer->name = strdup(name);
    newTransfer->amount = amount;
    newTransfer->next = NULL;

    return newTransfer;
}

void addTransfer(Transfer *transfers, char *name, double amount) {
    Transfer *newTransfer = createTransfer(name, amount);

    if (transfers == NULL) {
        transfers = newTransfer;
    } else {
        transfers->next = newTransfer;
        transfers = newTransfer;
    }
}

double calculateTotalTransfers(Transfer *transfers) {
    double total = 0.0;

    for (Transfer *transfer = transfers; transfer != NULL; transfer = transfer->next) {
        total += transfer->amount;
    }

    return total;
}

int main() {
    Transfer *transfers = NULL;

    addTransfer(transfers, "John Doe", 50.0);
    addTransfer(transfers, "Jane Doe", 25.0);
    addTransfer(transfers, "Peter Pan", 75.0);

    double totalTransfers = calculateTotalTransfers(transfers);

    printf("Total transfers: %.2lf\n", totalTransfers);

    return 0;
}