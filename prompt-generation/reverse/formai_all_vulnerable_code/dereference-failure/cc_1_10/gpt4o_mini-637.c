//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int weight;
} Item;

typedef struct {
    int num_items;
    Item* items;
} Knapsack;

void initializeKnapsack(Knapsack* knapsack, int num_items) {
    knapsack->num_items = num_items;
    knapsack->items = (Item*)malloc(num_items * sizeof(Item));
}

void freeKnapsack(Knapsack* knapsack) {
    free(knapsack->items);
}

void addItem(Knapsack* knapsack, int index, int value, int weight) {
    knapsack->items[index].value = value;
    knapsack->items[index].weight = weight;
}

float calculateProfitPerWeight(Item item) {
    return (float)item.value / (float)item.weight;
}

// Comparator function for sorting items by profit-to-weight ratio
int compare(const void* a, const void* b) {
    float r1 = calculateProfitPerWeight(*(const Item*)a);
    float r2 = calculateProfitPerWeight(*(const Item*)b);
    return (r1 > r2) ? -1 : (r1 < r2) ? 1 : 0;
}

void fractionalKnapsack(Knapsack knapsack, int capacity) {
    qsort(knapsack.items, knapsack.num_items, sizeof(Item), compare);

    float total_value = 0.0f;
    int i;

    printf("Items selected for the Knapsack:\n");
    for (i = 0; i < knapsack.num_items; i++) {
        if (knapsack.items[i].weight <= capacity) {
            capacity -= knapsack.items[i].weight;
            total_value += knapsack.items[i].value;
            printf("Full Item: Value = %d, Weight = %d\n", knapsack.items[i].value, knapsack.items[i].weight);
        } else {
            float fraction = (float)capacity / (float)knapsack.items[i].weight;
            total_value += knapsack.items[i].value * fraction;
            printf("Partial Item: Value = %d, Weight = %d, Taken = %.2f\n",
                   knapsack.items[i].value, knapsack.items[i].weight, fraction);
            break;
        }
    }

    printf("Total value in Knapsack: %.2f\n", total_value);
}

int main() {
    int capacity, num_items, i;

    printf("Enter the capacity of the Knapsack: ");
    scanf("%d", &capacity);
    printf("Enter the number of items: ");
    scanf("%d", &num_items);

    Knapsack knapsack;
    initializeKnapsack(&knapsack, num_items);
    
    for (i = 0; i < num_items; i++) {
        int value, weight;
        printf("Enter value and weight for item %d: ", i + 1);
        scanf("%d %d", &value, &weight);
        addItem(&knapsack, i, value, weight);
    }

    fractionalKnapsack(knapsack, capacity);
    
    freeKnapsack(&knapsack);
    return 0;
}