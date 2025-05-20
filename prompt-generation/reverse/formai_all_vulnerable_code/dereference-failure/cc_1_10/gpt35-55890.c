//FormAI DATASET v1.0 Category: Expense Tracker ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct expense {
    char name[50];
    float amount;
};

int main() {
    int option = 0;
    int count = 0;
    float total = 0.0;
    struct expense *expenses = NULL;

    printf("Welcome to your Expense Tracker! \n");

    while (option != 4) {
        printf("\nPlease select an option: \n");
        printf("1. Add a new expense \n");
        printf("2. View all expenses \n");
        printf("3. View total expenses \n");
        printf("4. Exit \n");
        printf("Option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                expenses = (struct expense *) realloc(expenses, (count + 1) * sizeof(struct expense));
                printf("\nEnter expense name: ");
                scanf("%s", (expenses + count)->name);
                printf("Enter expense amount: ");
                scanf("%f", &(expenses + count)->amount);
                total += (expenses + count)->amount;
                count++;
                break;
            case 2:
                if (count == 0) {
                    printf("\nNo expenses added yet. \n");
                } else {
                    printf("\nAll expenses: \n");
                    for (int i = 0; i < count; i++) {
                        printf("%s: $%.2f\n", (expenses + i)->name, (expenses + i)->amount);
                    }
                }
                break;
            case 3:
                if (count == 0) {
                    printf("\nNo expenses added yet. \n");
                } else {
                    printf("\nTotal expenses: $%.2f\n", total);
                }
                break;
            case 4:
                printf("\nThank you for using your Expense Tracker! \n");
                break;
            default:
                printf("\nInvalid option. Please try again. \n");
                break;
        }
    }

    free(expenses);
    return 0;
}