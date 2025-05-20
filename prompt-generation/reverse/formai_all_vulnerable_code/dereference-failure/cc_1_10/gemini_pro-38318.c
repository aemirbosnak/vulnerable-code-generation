//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char *description;
    float amount;
} expense_t;

int main(void) {
    expense_t expenses[MAX_EXPENSES];
    int num_expenses = 0;

    char buf[1024];
    while (1) {
        printf("Enter an expense (or 'q' to quit): ");
        if (fgets(buf, sizeof(buf), stdin) == NULL) {
            break;
        }

        if (strcmp(buf, "q\n") == 0) {
            break;
        }

        char *description = strtok(buf, " ");
        char *amount = strtok(NULL, " ");
        if (description == NULL || amount == NULL) {
            printf("Invalid input\n");
            continue;
        }

        float amount_f = atof(amount);
        if (amount_f <= 0) {
            printf("Invalid amount\n");
            continue;
        }

        expenses[num_expenses].description = strdup(description);
        expenses[num_expenses].amount = amount_f;
        num_expenses++;
    }

    printf("\nYour expenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s: $%.2f\n", expenses[i].description, expenses[i].amount);
    }

    return 0;
}