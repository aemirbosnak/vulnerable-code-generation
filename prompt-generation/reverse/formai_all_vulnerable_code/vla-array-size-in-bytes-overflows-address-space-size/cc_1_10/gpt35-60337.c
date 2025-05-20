//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: happy
#include <stdio.h>

int main() {
    int n, total_price = 0;
    printf("Welcome to the HappyShop!\n");

   	printf("How many items do you want to purchase? ");
    scanf("%d", &n);

    int prices[n];
    for (int i=0; i<n; i++) {
        printf("Enter the price of item %d: ", i+1);
        scanf("%d", &prices[i]);
    }

    printf("\n");

    // Implementing the greedy algorithm
    while (n > 2) {
        int min_index = 0, max_index = 0;
        for (int i=0; i<n; i++) {
            if (prices[i] < prices[min_index]) {
                min_index = i;
            }
            if (prices[i] > prices[max_index]) {
                max_index = i;
            }
        }

        int discount = prices[min_index] / 2;
        total_price += (prices[min_index] + prices[max_index] - discount);

        // Removing the used items from the list
        for (int i=min_index; i<n-2; i++) {
            prices[i] = prices[i+1];
        }
        for (int i=max_index-1; i<n-2; i++) {
            prices[i] = prices[i+1];
        }

        n -= 2; // decrease the size of the array
    }

    // Adding the last two items (if any)
    if(n == 2) {
        total_price += prices[0] + prices[1];
    } else if(n == 1) {
        total_price += prices[0];
    }

    printf("Thank you for shopping at the HappyShop!\n");
    printf("Total price: %d", total_price);
    return 0;
}