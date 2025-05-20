//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Define a structure for items
struct Item {
    int value;
    int weight;
};

// Function to compare two items, used for sorting
int compare(const void *a, const void *b) {
    double r1 = (double)((struct Item *)a)->value / ((struct Item *)a)->weight;
    double r2 = (double)((struct Item *)b)->value / ((struct Item *)b)->weight;
    return (r1 < r2) ? -1 : (r1 > r2) ? 1 : 0;
}

// Greedy Knapsack function
double knapSack(int W, struct Item items[], int n) {
    // Sort items by value-to-weight ratio
    qsort(items, n, sizeof(items[0]), compare);

    double totalValue = 0.0;  // To store the total value in knapsack
    for (int i = 0; i < n; i++) {
        // If the item can be fully accommodated
        if (items[i].weight <= W) {
            W -= items[i].weight;
            totalValue += items[i].value;
            printf("Adding item with value: %d and weight: %d full!\n", items[i].value, items[i].weight);
        } else {
            // Item can't be fully accommodated, take fractional part
            double fraction = (double)W / items[i].weight;
            totalValue += items[i].value * fraction;
            printf("Adding item with value: %d and weight: %d partial! (Fraction: %.2f)\n", items[i].value, items[i].weight, fraction);
            break; // The knapsack is full!
        }
    }
    return totalValue;
}

int main() {
    printf("Welcome to the Knapsack Adventure!\n");
    
    int n, W;

    // Gather input
    printf("Enter number of items: ");
    scanf("%d", &n);
    struct Item items[n];

    printf("Enter maximum weight of the knapsack: ");
    scanf("%d", &W);

    for (int i = 0; i < n; i++) {
        printf("Enter value and weight for item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    // Calculate max value that can be achieved
    double maxValue = knapSack(W, items, n);

    // Show the final result
    printf("The maximum value in the knapsack is: %.2f\n", maxValue);
    printf("Thank you for joining the Knapsack Adventure! Till next time!\n");

    return 0; 
}