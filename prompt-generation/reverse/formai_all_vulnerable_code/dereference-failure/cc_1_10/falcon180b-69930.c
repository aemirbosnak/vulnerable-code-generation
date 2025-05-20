//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int value;
    int weight;
} Item;

int main() {
    int n, capacity;
    scanf("%d %d", &n, &capacity);

    // Initialize items array
    Item *items = (Item*) malloc(n * sizeof(Item));
    for (int i = 0; i < n; i++) {
        items[i].value = 0;
        items[i].weight = 0;
    }

    // Read in item values and weights
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    // Sort items by value/weight ratio in descending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (items[i].value * items[j].weight < items[j].value * items[i].weight) {
                Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }

    // Initialize the knapsack with the first item
    int knapsack[capacity + 1];
    knapsack[0] = 0;
    int index = 0;

    // Fill the knapsack using a greedy algorithm
    for (int i = 0; i < n; i++) {
        if (items[i].value > 0 && items[i].weight <= capacity - knapsack[index]) {
            knapsack[index + items[i].weight] = knapsack[index] + items[i].value;
            index += items[i].weight;
        }
    }

    // Print the maximum value that can be obtained
    printf("Maximum value: %d\n", knapsack[capacity]);

    return 0;
}