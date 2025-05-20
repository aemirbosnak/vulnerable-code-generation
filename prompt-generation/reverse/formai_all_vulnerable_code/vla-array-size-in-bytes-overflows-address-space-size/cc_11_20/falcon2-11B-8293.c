//Falcon2-11B DATASET v1.0 Category: Expense Tracker ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char **argv) {
    int N;
    int expenses[N][100];
    int total_expenses = 0;
    int max_expenses = 0;
    int min_expenses = 1000000;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s N\n", argv[0]);
        exit(1);
    }

    N = atoi(argv[1]);
    if (N < 1) {
        fprintf(stderr, "Invalid number of days: %d\n", N);
        exit(1);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 100; j++) {
            expenses[i][j] = 0;
        }

        printf("Enter expenses for day %d: ", i + 1);
        for (int j = 0; j < 100; j++) {
            scanf("%d", &expenses[i][j]);
            total_expenses += expenses[i][j];
        }

        max_expenses = (expenses[i][0] > max_expenses)? expenses[i][0] : max_expenses;
        min_expenses = (expenses[i][0] < min_expenses)? expenses[i][0] : min_expenses;

        for (int j = 1; j < 100; j++) {
            if (expenses[i][j] > max_expenses) {
                max_expenses = expenses[i][j];
            }
            if (expenses[i][j] < min_expenses) {
                min_expenses = expenses[i][j];
            }
        }
    }

    printf("\nTotal expenses: %d\n", total_expenses);
    printf("Max expenses: %d\n", max_expenses);
    printf("Min expenses: %d\n", min_expenses);

    return 0;
}