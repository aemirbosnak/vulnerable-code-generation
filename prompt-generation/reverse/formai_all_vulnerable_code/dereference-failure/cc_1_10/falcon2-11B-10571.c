//Falcon2-11B DATASET v1.0 Category: Expense Tracker ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Expense {
    char* category;
    int amount;
    int date;
};

typedef struct Expense Expense;

int main() {
    Expense* expenses = malloc(100 * sizeof(Expense));

    if (expenses == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    int n = 0;
    int i = 0;
    int j = 0;

    while (1) {
        printf("Enter expense details (enter 0 to stop):\n");
        printf("Category: ");
        fgets(expenses[i].category, sizeof(expenses[i].category), stdin);
        expenses[i].category[strcspn(expenses[i].category, "\n")] = '\0';

        printf("Amount: ");
        scanf("%d", &expenses[i].amount);

        printf("Date (YYYY-MM-DD): ");
        scanf("%d", &expenses[i].date);

        i++;
        n++;

        if (i == 100) {
            printf("Maximum number of expenses reached.\n");
            break;
        }

        if (strcmp(expenses[i-1].category, expenses[i].category) == 0) {
            printf("Duplicate category detected.\n");
            free(expenses);
            return 1;
        }

        for (j = 0; j < i; j++) {
            if (expenses[i].date == expenses[j].date) {
                printf("Duplicate date detected.\n");
                free(expenses);
                return 1;
            }
        }
    }

    printf("Expenses:\n");
    for (i = 0; i < n; i++) {
        printf("%s: $%d (%04d-%02d-%02d)\n", expenses[i].category, expenses[i].amount, expenses[i].date / 10000, (expenses[i].date % 10000) / 100, (expenses[i].date % 10000) % 100);
    }

    free(expenses);

    return 0;
}