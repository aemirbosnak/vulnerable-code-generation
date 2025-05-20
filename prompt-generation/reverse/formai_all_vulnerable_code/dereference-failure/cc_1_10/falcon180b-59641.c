//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function to find the maximum value in an array
int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to check if a coin is valid
int isValid(int coin, int denom[], int numDenoms, int currValue) {
    for (int i = 0; i < numDenoms; i++) {
        if (coin == denom[i]) {
            return 1;
        }
    }
    return 0;
}

// Greedy algorithm to find the minimum number of coins needed to make a given amount
int minCoins(int amount, int denom[], int numDenoms) {
    int currValue = 0;
    int coins = 0;
    while (currValue < amount) {
        int maxVal = findMax(denom, numDenoms);
        while (currValue < amount && denom[coins] <= maxVal) {
            currValue += denom[coins];
            coins++;
        }
        if (currValue < amount) {
            currValue = 0;
            coins++;
        }
    }
    return coins;
}

int main() {
    int denom[] = {1, 5, 10, 25};
    int numDenoms = sizeof(denom) / sizeof(denom[0]);
    int amount = 63;
    int numCoins = minCoins(amount, denom, numDenoms);
    printf("Minimum number of coins needed to make %d: %d\n", amount, numCoins);
    return 0;
}