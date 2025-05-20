//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: statistical
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int value; 
    int weight; 
    double ratio; 
} Item;

// Function to compare two Items based on their value-to-weight ratio
int compare(const void *a, const void *b) {
    Item *item1 = (Item *)a;
    Item *item2 = (Item *)b;
    return (item2->ratio - item1->ratio > 0) ? 1 : -1;
}

// Function to implement the Greedy Algorithm for Fractional Knapsack
void fractionalKnapsack(int capacity, Item items[], int n) {
    // Sort items based on value-to-weight ratio
    qsort(items, n, sizeof(Item), compare);
    
    double totalValue = 0.0;
    int i;
    
    printf("Items picked:\n");
    printf("Value\tWeight\tRatio\tFraction\n");
    
    for (i = 0; i < n; i++) {
        if (capacity <= 0) {
            break;
        }
        if (items[i].weight <= capacity) {
            // Whole item can be picked
            totalValue += items[i].value;
            capacity -= items[i].weight;
            printf("%d\t%d\t%.2f\t1.00\n", items[i].value, items[i].weight, items[i].ratio);
        } else {
            // Pick fraction of the remaining item
            double fraction = (double)capacity / items[i].weight;
            totalValue += items[i].value * fraction;
            printf("%d\t%d\t%.2f\t%.2f\n", items[i].value, items[i].weight, items[i].ratio, fraction);
            capacity = 0; // knapsack is full
        }
    }
    
    printf("Maximum value in Knapsack = %.2f\n", totalValue);
}

int main() {
    int n, capacity;
    
    printf("Enter the number of items: ");
    scanf("%d", &n);
    
    Item *items = (Item *)malloc(n * sizeof(Item));
    
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);
    
    for (int i = 0; i < n; i++) {
        printf("Enter value and weight for item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
        items[i].ratio = (double)items[i].value / items[i].weight;  // calculate value-to-weight ratio
    }
    
    fractionalKnapsack(capacity, items, n);
    
    // Free allocated memory
    free(items);
    
    return 0;
}