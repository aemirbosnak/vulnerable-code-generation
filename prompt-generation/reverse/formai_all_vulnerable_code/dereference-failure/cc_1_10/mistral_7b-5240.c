//MISTRAL-7B DATASET v1.0 Category: Personal Finance Planner ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

typedef struct {
    char name[50];
    float amount;
    time_t date;
} Item;

int main() {
    int choice, option;
    int num_items = 0;
    Item *items = NULL;
    float total_income = 0, total_expenses = 0, net_worth = 0;

    while (true) {
        printf("\nPersonal Finance Planner\n");
        printf("1. Add item\n");
        printf("2. Display items\n");
        printf("3. Calculate totals\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                items = realloc(items, sizeof(Item) * (num_items + 1));
                printf("Enter item name: ");
                scanf("%s", items[num_items].name);
                printf("Enter item amount: ");
                scanf("%f", &items[num_items].amount);
                items[num_items].date = time(NULL);
                num_items++;
                break;

            case 2:
                printf("\nList of Items:\n");
                for (int i = 0; i < num_items; i++) {
                    printf("%d. %s: %.2f (%s)\n", i + 1, items[i].name, items[i].amount, ctime(&items[i].date));
                    if (items[i].amount > 0) {
                        total_income += items[i].amount;
                    } else {
                        total_expenses += items[i].amount;
                    }
                }
                break;

            case 3:
                net_worth = total_income - total_expenses;
                printf("\nTotal Income: %.2f\n", total_income);
                printf("Total Expenses: %.2f\n", total_expenses);
                printf("Net Worth: %.2f\n", net_worth);
                break;

            case 4:
                free(items);
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}