//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX_COINS 6
#define MAX_VALUES 100
#define MAX_ITEMS 20

typedef struct {
    int value;
    int weight;
} Item;

typedef struct {
    int index;
    int value;
    int weight;
} KnapSack;

int main() {
    int n, W;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    Item items[n];
    printf("Enter the value and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].value, &items[i].weight);
    }
    printf("Enter the weight capacity of the knapsack: ");
    scanf("%d", &W);
    KnapSack knapSack[n];
    for (int i = 0; i < n; i++) {
        knapSack[i].index = i;
        knapSack[i].value = 0;
        knapSack[i].weight = 0;
    }
    printf("Item\tValue\tWeight\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\n", i, items[i].value, items[i].weight);
    }
    for (int w = 0; w <= W; w++) {
        for (int i = 0; i < n; i++) {
            if (w >= items[i].weight) {
                if (knapSack[i].value < items[i].value + knapSack[i - 1].value) {
                    knapSack[i].value = items[i].value + knapSack[i - 1].value;
                    knapSack[i].weight = items[i].weight;
                }
            }
        }
    }
    printf("\nItem\tValue\tWeight\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\n", i, knapSack[i].value, knapSack[i].weight);
    }
    return 0;
}