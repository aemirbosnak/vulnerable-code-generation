//Falcon2-11B DATASET v1.0 Category: Greedy Algorithms ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

// Function to solve the knapsack problem using a greedy algorithm
int* knapsack(int capacity, int* weights, int* values, int num_items) {
    // Initialize array to keep track of the index of the last item added to the knapsack
    int* indices = (int*)malloc(sizeof(int) * num_items);
    int i;

    // Add items to the knapsack greedily
    for (i = 0; i < num_items; i++) {
        int j;
        int max_value = 0;
        int max_weight = 0;

        // Find item with highest value-to-weight ratio
        for (j = 0; j < i; j++) {
            if (weights[j] <= capacity && values[j] > max_value) {
                max_value = values[j];
                max_weight = weights[j];
                indices[j] = i;
            }
        }

        // Add item to knapsack
        if (weights[i] <= capacity && values[i] > max_value) {
            indices[i] = i;
        } else {
            break;
        }
    }

    // Return the indices of the items added to the knapsack
    return indices;
}

int main() {
    int capacity = 5;
    int num_items = 4;
    int weights[4] = {2, 3, 5, 7};
    int values[4] = {10, 20, 30, 40};
    int* indices = knapsack(capacity, weights, values, num_items);

    printf("Indices of items added to the knapsack:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d ", indices[i]);
    }
    printf("\n");

    return 0;
}