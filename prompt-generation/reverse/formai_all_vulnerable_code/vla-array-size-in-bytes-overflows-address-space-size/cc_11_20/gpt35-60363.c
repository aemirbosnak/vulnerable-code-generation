//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: puzzling
#include <stdio.h>

int main() {
    int num_items;
    printf("Enter the number of items: ");
    scanf("%d", &num_items);

    int values[num_items], weights[num_items];
    printf("Enter the values and weights of each item:\n");
    for (int i = 0; i < num_items; i++) {
        printf("Item %d: ", i+1);
        scanf("%d %d", &values[i], &weights[i]);
    }

    int max_weight;
    printf("Enter the maximum weight that the knapsack can hold: ");
    scanf("%d", &max_weight);

    float ratios[num_items];
    for (int i = 0; i < num_items; i++) {
        ratios[i] = (float) values[i] / weights[i];
    }

    int indexes[num_items];
    for (int i = 0; i < num_items; i++) {
        indexes[i] = i;
    }

    for (int i = 0; i < num_items - 1; i++) {
        for (int j = i + 1; j < num_items; j++) {
            if (ratios[i] < ratios[j]) {
                // Swap items to sort in descending order of ratios
                float temp = ratios[i];
                ratios[i] = ratios[j];
                ratios[j] = temp;

                int index_temp = indexes[i];
                indexes[i] = indexes[j];
                indexes[j] = index_temp;
            }
        }
    }

    int knapsack[num_items];
    for (int i = 0; i < num_items; i++) {
        knapsack[i] = 0;
    }

    int current_weight = 0, i = 0;
    while (i < num_items && current_weight + weights[indexes[i]] <= max_weight) {
        // Add items to knapsack as long as weight does not exceed max_weight
        knapsack[indexes[i]] = 1;
        current_weight += weights[indexes[i]];
        i++;
    }

    printf("Items in the knapsack:\n");
    for (int i = 0; i < num_items; i++) {
        if (knapsack[i] == 1) {
            printf("Item %d (Weight: %d, Value: %d)\n", i+1, weights[i], values[i]);
        }
    }

    printf("Total Value of the knapsack: ");
    int total_value = 0;
    for (int i = 0; i < num_items; i++) {
        if (knapsack[i] == 1) {
            total_value += values[i];
        }
    }
    printf("%d\n", total_value);

    return 0;
}