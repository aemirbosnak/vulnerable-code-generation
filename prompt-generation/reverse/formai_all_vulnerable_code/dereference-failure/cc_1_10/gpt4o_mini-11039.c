//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    float value;
    float weight;
    float ratio; // ratio = value/weight
} Item;

typedef struct {
    Item* items;
    int size;
} ItemList;

void calculate_ratios(ItemList* itemList) {
    for (int i = 0; i < itemList->size; i++) {
        itemList->items[i].ratio = itemList->items[i].value / itemList->items[i].weight;
    }
}

int compare_items(const void* a, const void* b) {
    Item* item1 = (Item*)a;
    Item* item2 = (Item*)b;

    if (item1->ratio < item2->ratio) {
        return 1; // descending order
    } else if (item1->ratio > item2->ratio) {
        return -1; // ascending order
    }
    return 0;
}

void knapsack(ItemList* itemList, float capacity) {
    int i;
    float totalValue = 0.0;
    float totalWeight = 0.0;
    int count = 0;

    for (i = 0; i < itemList->size; i++) {
        if (totalWeight + itemList->items[i].weight <= capacity) {
            totalWeight += itemList->items[i].weight;
            totalValue += itemList->items[i].value;
            printf("Item %d: Taking whole item (Value: %.2f, Weight: %.2f)\n", 
                   itemList->items[i].id, 
                   itemList->items[i].value, 
                   itemList->items[i].weight);
        } else {
            float remainingCapacity = capacity - totalWeight;
            if (remainingCapacity > 0) {
                totalValue += itemList->items[i].value * (remainingCapacity / itemList->items[i].weight);
                totalWeight += remainingCapacity;
                printf("Item %d: Taking part of item (Value: %.2f, Weight: %.2f)\n", 
                       itemList->items[i].id, 
                       itemList->items[i].value * (remainingCapacity / itemList->items[i].weight), 
                       remainingCapacity);
            }
            break; // Knapsack is full
        }
    }
    printf("Total value in the knapsack: %.2f\n", totalValue);
    printf("Total weight in the knapsack: %.2f\n", totalWeight);
}

void free_items(ItemList* itemList) {
    free(itemList->items);
    free(itemList);
}

int main() {
    ItemList* itemList = (ItemList*)malloc(sizeof(ItemList));
    itemList->size = 5;
    itemList->items = (Item*)malloc(itemList->size * sizeof(Item));

    // Sample item data
    itemList->items[0] = (Item){.id = 1, .value = 60, .weight = 10};
    itemList->items[1] = (Item){.id = 2, .value = 100, .weight = 20};
    itemList->items[2] = (Item){.id = 3, .value = 120, .weight = 30};
    itemList->items[3] = (Item){.id = 4, .value = 150, .weight = 25};
    itemList->items[4] = (Item){.id = 5, .value = 200, .weight = 40};

    // Calculate the ratio of value to weight for each item
    calculate_ratios(itemList);

    // Sort items based on the ratio in descending order
    qsort(itemList->items, itemList->size, sizeof(Item), compare_items);

    // Set the capacity of the knapsack
    float capacity = 50;

    // Execute the knapsack algorithm
    printf("Knapsack Capacity: %.2f\n", capacity);
    knapsack(itemList, capacity);

    // Free allocated memory
    free_items(itemList);

    return 0;
}