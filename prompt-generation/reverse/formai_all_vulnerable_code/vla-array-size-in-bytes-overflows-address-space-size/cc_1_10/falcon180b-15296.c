//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    int value;
    int weight;
} Item;

void calculateMaxValue(Item items[], int n, int capacity) {
    int maxValue = 0;
    int i = 0;
    while (i < n && maxValue < capacity) {
        int valuePerWeight = items[i].value / items[i].weight;
        if (valuePerWeight > maxValue) {
            maxValue = valuePerWeight;
        }
        i++;
    }
    printf("The maximum value per weight is: %d\n", maxValue);
}

void knapSack(Item items[], int n, int capacity) {
    int i = 0;
    int w = 0;
    while (i < n && w < capacity) {
        if (items[i].weight <= w) {
            w += items[i].weight;
            i++;
        } else {
            break;
        }
    }
    printf("The total value of the knapsack is: %d\n", w);
}

int main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    Item items[n];
    printf("Enter the details of the items:\n");
    for (int i = 0; i < n; i++) {
        printf("Enter the value and weight of item %d:\n", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    int capacity;
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    calculateMaxValue(items, n, capacity);
    knapSack(items, n, capacity);

    return 0;
}