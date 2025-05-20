//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: innovative
#include<stdio.h>

int main() {
    int n, i, j, temp, weight_sum = 0, profit_sum = 0;
    float capacity, ratio;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    int profits[n], weights[n];
    float ratios[n];

    // input profits and weights
    printf("Enter the profits and weights respectively:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &profits[i]);
        scanf("%d", &weights[i]);
    }

    // calculate ratios for items
    for(i = 0; i < n; i++) {
        ratios[i] = (float)profits[i] / (float)weights[i];
    }

    // sorting items in descending order of ratio
    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) {
            if(ratios[i] < ratios[j]) {
                ratio = ratios[i];
                ratios[i] = ratios[j];
                ratios[j] = ratio;

                temp = profits[i];
                profits[i] = profits[j];
                profits[j] = temp;

                temp = weights[i];
                weights[i] = weights[j];
                weights[j] = temp;
            }
        }
    }

    // input the maximum weight capacity of the knapsack
    printf("Enter the capacity of the knapsack: ");
    scanf("%f", &capacity);

    // filling the knapsack
    for(i = 0; i < n; i++) {
        if(weights[i] <= capacity) {
            weight_sum += weights[i];
            capacity -= weights[i];
            profit_sum += profits[i];
        }
        else {
            profit_sum += (int)(capacity * ratios[i]);
            break;
        }
    }

    printf("The maximum profit that can be obtained is: %d\n", profit_sum);

    return 0;
}