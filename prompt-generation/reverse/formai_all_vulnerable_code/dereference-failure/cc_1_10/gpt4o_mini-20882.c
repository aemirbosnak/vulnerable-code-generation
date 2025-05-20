//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int weight;
    int value;
    double ratio; // value-to-weight ratio
} Item;

// Function to compare two items based on their value-to-weight ratio
int compare(const void *a, const void *b) {
    Item *itemA = (Item *)a;
    Item *itemB = (Item *)b;

    if (itemA->ratio < itemB->ratio) return 1;
    else if (itemA->ratio > itemB->ratio) return -1;
    else return 0;
}

// Function to perform the Knapsack problem using a greedy approach
double knapsackGreedy(Item items[], int weightLimit, int n) {
    // Sort items by their value-to-weight ratio
    qsort(items, n, sizeof(Item), compare);

    double totalValue = 0.0;
    int currentWeight = 0;

    printf("=== Attempting to fill the Knapsack! ===\n");
    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= weightLimit) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
            printf("Adding full item: Weight = %d, Value = %d, Ratio = %.2f\n", 
                    items[i].weight, items[i].value, items[i].ratio);
        } else {
            int remainingWeight = weightLimit - currentWeight;
            double fraction = (double)remainingWeight / items[i].weight;
            totalValue += items[i].value * fraction;
            printf("Adding partial item: Weight = %d, Value = %.2f, Ratio = %.2f\n", 
                    remainingWeight, items[i].value * fraction, items[i].ratio);
            break; // No more weight can be added
        }
    }

    return totalValue;
}

int main() {
    int n, weightLimit;

    // Surprise! Let's enter the number of items and weight limit
    printf("Welcome to the Magical Knapsack Solver!\n");
    printf("Enter the number of items: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Oops! You need at least one item. Let's quit early!\n");
        return 1;
    }

    Item *items = (Item *)malloc(n * sizeof(Item));

    // Collect item details
    for (int i = 0; i < n; i++) {
        printf("Enter weight and value for item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);
        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    // Surprise! Get the weight limit from user
    printf("Enter the weight limit for the knapsack: ");
    scanf("%d", &weightLimit);

    if (weightLimit <= 0) {
        printf("What a twist! You can't carry negative or zero weight. Exiting!\n");
        free(items);
        return 1;
    }

    // Calculate the maximum value we can get
    double maxValue = knapsackGreedy(items, weightLimit, n);
    printf("\nThe maximum value we can obtain in the knapsack is: %.2f\n", maxValue);

    // Clean up
    free(items);
    printf("Thanks for playing with the Magical Knapsack Solver! Goodbye!\n");
    return 0;
}