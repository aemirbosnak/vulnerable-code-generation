//MISTRAL-7B DATASET v1.0 Category: Greedy Algorithms ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#define MAX_ITEMS 100
#define MAX_CAPACITY 1000

typedef struct {
    int id;
    int weight;
    int value;
} Item;

void read_items(Item items[], int size);
int max(int a, int b);
int knapSack(int W, Item items[], int size);

int main() {
    int size, capacity;
    printf("Enter number of items: ");
    scanf("%d", &size);

    Item items[size];
    read_items(items, size);

    printf("Enter capacity of knapsack: ");
    scanf("%d", &capacity);

    int result = knapSack(capacity, items, size);
    printf("Maximum value that can be obtained: %d\n", result);

    return 0;
}

void read_items(Item items[], int size) {
    for (int i = 0; i < size; i++) {
        items[i].id = i + 1;
        printf("Enter weight, value for item %d: ", items[i].id);
        scanf("%d%d", &items[i].weight, &items[i].value);
    }
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapSack(int W, Item items[], int size) {
    int K[size + 1][W + 1];

    for (int i = 0; i <= size; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (items[i - 1].weight <= w)
                K[i][w] = max(items[i - 1].value + K[i - 1][w - items[i - 1].weight], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    return K[size][W];
}