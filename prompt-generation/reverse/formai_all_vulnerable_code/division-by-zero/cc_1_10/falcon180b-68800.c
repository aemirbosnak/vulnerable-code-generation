//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_N 100
#define MAX_VALUE 1000

typedef struct {
    int value;
    int weight;
} item;

void swap(item* a, item* b) {
    item temp = *a;
    *a = *b;
    *b = temp;
}

int compare(const void* a, const void* b) {
    const item* itemA = a;
    const item* itemB = b;

    if (itemA->value / itemA->weight > itemB->value / itemB->weight) {
        return -1;
    } else if (itemA->value / itemA->weight < itemB->value / itemB->weight) {
        return 1;
    } else {
        return 0;
    }
}

int knapSack(int W, item arr[], int n) {
    int i, w;
    item* includedItems = malloc(n * sizeof(item));

    for (i = 0; i < n; i++) {
        includedItems[i] = arr[i];
    }

    qsort(includedItems, n, sizeof(item), compare);

    for (i = 0; i < n; i++) {
        if (W >= includedItems[i].weight) {
            W -= includedItems[i].weight;
            printf("Item %d included with value %d\n", i + 1, includedItems[i].value);
        } else {
            break;
        }
    }

    free(includedItems);

    return W;
}

int main() {
    int n, i, maxValue = 0;
    item arr[MAX_N];

    srand(time(0));

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the values and weights of the items:\n");

    for (i = 0; i < n; i++) {
        arr[i].value = rand() % MAX_VALUE;
        arr[i].weight = rand() % MAX_VALUE;

        if (arr[i].value > maxValue) {
            maxValue = arr[i].value;
        }
    }

    int capacity = rand() % (maxValue / 2) + 1;

    printf("The maximum value of an item is %d\n", maxValue);
    printf("The capacity of the knapsack is %d\n", capacity);

    int result = knapSack(capacity, arr, n);

    printf("The maximum value that can be obtained is %d\n", result);

    return 0;
}