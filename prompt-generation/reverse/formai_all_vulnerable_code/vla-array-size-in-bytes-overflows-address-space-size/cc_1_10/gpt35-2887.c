//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Sherlock Holmes
#include <stdio.h>

// Function to find the maximum element of the array
int max_element(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to find the minimum element of the array
int min_element(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

// Function to find the maximum profit
int max_profit(int prices[], int n) {
    int buy_price = prices[0];
    int sell_price = prices[0];
    int max_profit = 0;
    for (int i = 1; i < n; i++) {
        if (prices[i] > sell_price) {
            sell_price = prices[i];
        } else if (prices[i] < buy_price) {
            max_profit += sell_price - buy_price;
            buy_price = prices[i];
            sell_price = prices[i];
        }
    }
    max_profit += sell_price - buy_price;
    return max_profit;
}

int main() {
    // Prompt user for number of stocks
    printf("Welcome, Mr. Holmes! Please enter the number of stocks you wish to evaluate.\n");
    int n;
    scanf("%d", &n);

    // Prompt user for stock prices
    printf("Please enter the stock prices separated by spaces:\n");
    int prices[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &prices[i]);
    }

    // Determine if buying and selling stocks will produce a profit
    int min_price = min_element(prices, n);
    int max_price = max_element(prices, n);
    if (max_price <= min_price) {
        printf("Sorry, Mr. Holmes. It appears that no profit can be made with these stocks.\n");
    } else {
        int profit = max_profit(prices, n);
        printf("Congratulations, Mr. Holmes! You have made a profit of %d.\n", profit);
    }

    return 0;
}