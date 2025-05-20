//FormAI DATASET v1.0 Category: Expense Tracker ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct expense {
    char title[50];
    float amount;
    char category[20];
};

int main() {
    int choice, count = 0, i;
    float total = 0;
    struct expense *expenses = NULL;

    while (1) {
        printf("1. Add Expense\n2. View Expenses\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            count++;
            expenses = realloc(expenses, count * sizeof(struct expense));

            printf("Enter expense title: ");
            scanf("%s", expenses[count - 1].title);

            printf("Enter expense amount: ");
            scanf("%f", &expenses[count - 1].amount);
            total += expenses[count - 1].amount;

            printf("Enter expense category: ");
            scanf("%s", expenses[count - 1].category);

            printf("Expense added successfully!\n");
        } else if (choice == 2) {
            printf("Total expenses: %d\n", count);
            printf("Total expenditure: $%.2f\n", total);
            printf("Title\tAmount\tCategory\n");

            for (i = 0; i < count; i++)
                printf("%s\t$%.2f\t%s\n", expenses[i].title, expenses[i].amount, expenses[i].category);
        } else {
            free(expenses);
            printf("Goodbye!");
            break;
        }
    }

    return 0;
}