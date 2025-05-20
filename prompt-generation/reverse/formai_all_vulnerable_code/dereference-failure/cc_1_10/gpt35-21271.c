//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// defining a struct for personal finance
typedef struct {
    char category[20];
    float amount;
} finance;

int main() {
    int i, numEntries;
    float balance = 0;

    // Prompt user for number of finance entries
    printf("Enter the number of finance entries: ");
    scanf("%d", &numEntries);

    // Creating a pointer for dynamically allocating the finance array
    finance *financeArray = (finance *)malloc(numEntries * sizeof(finance));

    // Prompt user for finance entries and dynamically allocating using the pointer
    for (i = 0; i < numEntries; i++) {
        printf("\nEnter the category of expense/income %d: ", i + 1);
        scanf("%s", financeArray[i].category);

        printf("Enter the amount for expense/income %d: ", i + 1);
        scanf("%f", &financeArray[i].amount);

        // Adding expense or Income amount
        if (financeArray[i].amount < 0) {
            balance += financeArray[i].amount;
            printf("You have spent %.2f on %s\n", -1 * financeArray[i].amount, financeArray[i].category);
        } else {
            balance += financeArray[i].amount;
            printf("You got paid %.2f for %s\n", financeArray[i].amount, financeArray[i].category);
        }
    }

    // Displaying balance
    printf("\nYour current balance is: $%.2f\n\n", balance);

    // Displaying all the entered finance entries
    printf("All the Entries:\n");
    for (i = 0; i < numEntries; i++) {
        printf("%s: $%.2f\n", financeArray[i].category, financeArray[i].amount);
    }

    // Freeing the dynamically allocated finance array
    free(financeArray);

    return 0;
}