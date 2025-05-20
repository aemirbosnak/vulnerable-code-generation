//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: multivariable
#include <stdio.h>

struct Item {
    int value;
    int weight;
};

int compare(struct Item a, struct Item b) {
    double ratio1 = (double)a.value / a.weight;
    double ratio2 = (double)b.value / b.weight;
    if (ratio1 > ratio2) return -1;
    else if (ratio1 < ratio2) return 1;
    else return 0;
}

double fractionalKnapsack(int capacity, struct Item items[], int count) {
    int i, j;
    double finalValue = 0.0;
    for (i = 0; i < count; i++) {
        for (j = i + 1; j < count; j++) {
            if (compare(items[i], items[j]) == -1) {
                struct Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
    for (i = 0; i < count; i++) {
        if (capacity - items[i].weight >= 0) {
            finalValue += items[i].value;
            capacity -= items[i].weight;
        } else {
            finalValue += (double) items[i].value / items[i].weight * capacity;
            break;
        }
    }
    return finalValue;
}

int main() {
    int capacity, n;
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);
    printf("Enter the number of items: ");
    scanf("%d", &n);
    struct Item items[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the value and weight of item %d: ", i+1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }
    double result = fractionalKnapsack(capacity, items, n);
    printf("The maximum value of items that can be carried in the knapsack is: %.2lf", result);
    return 0;
}