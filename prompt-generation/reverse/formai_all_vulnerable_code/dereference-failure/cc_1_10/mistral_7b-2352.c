//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    char name[50];
    float amount;
} Expense;

int main(int argc, char *argv[]) {
    srand(time(NULL));

    int num_expenses = 10;
    Expense *expenses = malloc(num_expenses * sizeof(Expense));

    for (int i = 0; i < num_expenses; i++) {
        sprintf(expenses[i].name, "Expense %d", i + 1);
        expenses[i].amount = (rand() % 100) + 50.0;
    }

    printf("\x1b[1m\x1b[31m*** MISTERIOUS EXPENSE TRACKER ***\n");
    printf("\x1b[1m\x1b[32mWelcome, mysterious stranger!\n");
    printf("\x1b[1m\x1b[34mYou have %d expenses waiting for your attention:\n", num_expenses);

    for (int i = 0; i < num_expenses; i++) {
        printf("\x1b[1m\x1b[33m%s:\x1b[1m\x1b[31m %5.2f\n", expenses[i].name, expenses[i].amount);
    }

    char choice[3];
    int index;

    do {
        printf("\x1b[1m\x1b[36mEnter the name of the expense you'd like to remove (or 'exit' to quit):\n> ");
        scanf("%s", choice);

        for (int i = 0; i < num_expenses; i++) {
            if (strcmp(expenses[i].name, choice) == 0) {
                index = i;
                break;
            }
        }

        if (strcmp(choice, "exit") == 0) {
            printf("\x1b[1m\x1b[32mExiting the program...\n");
            break;
        } else if (index >= 0) {
            Expense *temp = &expenses[index];
            expenses[index] = expenses[--num_expenses];
            free(temp);

            printf("\x1b[1m\x1b[33m%s removed successfully.\n", choice);
            num_expenses--;
        } else {
            printf("\x1b[1m\x1b[31mInvalid expense name.\n");
        }

        printf("\x1b[1m\x1b[34mYou have %d expenses remaining.\n", num_expenses);
    } while (1);

    free(expenses);
    return 0;
}