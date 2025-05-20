//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NUM_COINS 10
#define MAX_VALUE 1000

int coins[MAX_NUM_COINS];
int num_coins;

void generate_coins(int n) {
    int i;

    for (i = 0; i < n; i++) {
        coins[i] = rand() % MAX_VALUE;
    }
}

int main() {
    int i, j, max_value, num_coins;

    printf("Enter the number of coins: ");
    scanf("%d", &num_coins);

    printf("Enter the maximum value: ");
    scanf("%d", &max_value);

    generate_coins(num_coins);

    printf("Coins: ");
    for (i = 0; i < num_coins; i++) {
        printf("%d ", coins[i]);
    }
    printf("\n");

    printf("Greedy algorithm result: %d\n", solve_greedy(max_value, num_coins, coins));

    return 0;
}

int solve_greedy(int max_value, int num_coins, int coins[]) {
    int i, j, value, min_coins = 0;

    for (i = num_coins - 1; i >= 0; i--) {
        value = coins[i];
        for (j = 0; j < i; j++) {
            if (coins[j] <= value) {
                value -= coins[j];
            }
        }
        if (value > 0) {
            break;
        }
    }

    for (i = 0; i <= i; i++) {
        min_coins += coins[i];
    }

    return min_coins;
}