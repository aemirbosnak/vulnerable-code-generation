//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100
#define MAX_CAPACITY 1000

typedef struct {
    int weight;
    int value;
} Item;

void greedyAlgorithm(Item items[], int n, int capacity) {
    int i, j;
    int selected[n];
    int totalWeight = 0;
    int totalValue = 0;

    for (i = 0; i < n; i++) {
        selected[i] = 0;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (items[i].value / items[i].weight > items[j].value / items[j].weight &&
                totalWeight + items[i].weight <= capacity) {
                selected[i] = 1;
                totalWeight += items[i].weight;
                totalValue += items[i].value;
                break;
            }
        }
    }

    printf("Selected items: ");
    for (i = 0; i < n; i++) {
        if (selected[i]) {
            printf("%d ", i + 1);
        }
    }

    printf("\nTotal weight: %d\nTotal value: %d\n", totalWeight, totalValue);
}

int main() {
    int n, i;
    Item items[MAX_ITEMS];

    printf("Enter the number of items: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter the weight and value of item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);
    }

    int capacity;
    printf("Enter the maximum capacity: ");
    scanf("%d", &capacity);

    greedyAlgorithm(items, n, capacity);

    return 0;
}