//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 100
#define MAX_SIDES 1000

// Function to generate a random number between min and max (inclusive)
int randInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to roll a dice with n sides and return the result
int rollDice(int n) {
    return randInt(1, n);
}

// Function to roll multiple dice and return the sum of the results
int rollDiceSum(int n, int m) {
    int sum = 0;
    for (int i = 0; i < m; i++) {
        sum += rollDice(n);
    }
    return sum;
}

// Function to print a dice roll result
void printDiceRoll(int n, int m, int result) {
    printf("Rolling %d dice with %d sides each...\n", m, n);
    for (int i = 0; i < m; i++) {
        printf("%d ", result / n);
        result %= n;
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    // Prompt the user for the number of dice and sides
    int n, m;
    printf("How many dice do you want to roll? ");
    scanf("%d", &m);
    printf("How many sides do each dice have? ");
    scanf("%d", &n);

    // Roll the dice and print the results
    printDiceRoll(n, m, rollDiceSum(n, m));

    return 0;
}