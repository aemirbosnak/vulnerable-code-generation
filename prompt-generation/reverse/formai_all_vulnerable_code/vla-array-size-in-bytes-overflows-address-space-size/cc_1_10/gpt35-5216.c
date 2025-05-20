//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Introductory information
    printf("The Adventure of the Greedy Algorithms\n");
    printf("By Sherlock Holmes\n\n");

    // Get user inputs
    int n, i;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    int weights[n], values[n];
    printf("Enter the weight and the value of each item:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &weights[i], &values[i]);
    }
    int max_weight;
    printf("Enter the maximum weight capacity: ");
    scanf("%d", &max_weight);

    // Initialize variables
    int total_value = 0;
    int knapsack[n][max_weight+1];
    for (i = 0; i <= max_weight; i++) {
        knapsack[0][i] = 0;
    }
    for (i = 0; i < n; i++) {
        knapsack[i][0] = 0;
    }

    // Determine maximum value using dynamic programming
    for (i = 1; i <= n; i++) {
        int w;
        for (w = 1; w <= max_weight; w++) {
            if (weights[i-1] <= w) {
                knapsack[i][w] = (values[i-1] + knapsack[i-1][w-weights[i-1]]) > knapsack[i-1][w] ? values[i-1] + knapsack[i-1][w-weights[i-1]] : knapsack[i-1][w];
            } else {
                knapsack[i][w] = knapsack[i-1][w];
            }
        }
    }

    // Print results
    printf("\nThe maximum value that can be carried: %d\n", knapsack[n][max_weight]);

    // Conclusion
    printf("\nThus, my dear Watson, the algorithm has chosen the most profitable items\n");
    printf("to carry within the given weight limit. Another successful case solved!\n");

    return 0;
}