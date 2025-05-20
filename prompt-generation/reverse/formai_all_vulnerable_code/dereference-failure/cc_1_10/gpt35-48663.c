//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define NUM_ITEMS 5
#define MAX_WEIGHT 10

typedef struct {
    char* name;
    int value;
    int weight;
} Item;

Item* createItem(char* name, int value, int weight) {
    Item* item = malloc(sizeof(Item));
    item->name = name;
    item->value = value;
    item->weight = weight;
    return item;
}

void printItems(Item* items[]) {
    printf("Items:\n");
    for(int i=0; i<NUM_ITEMS; ++i) {
        printf("%s\tValue: %d\tWeight: %d\n", items[i]->name, items[i]->value, items[i]->weight);
    }
}

int cmp(const void* a, const void* b) {
    Item** item_a = (Item**) a;
    Item** item_b = (Item**) b;
    float val_a = (*item_a)->value / (float) (*item_a)->weight;
    float val_b = (*item_b)->value / (float) (*item_b)->weight;
    if(val_a > val_b) return -1;
    if(val_a < val_b) return 1;
    return 0;
}

void knapsack(Item* items[], int max_weight) {
    int total_weight = 0;
    int total_value = 0;
    bool picked[NUM_ITEMS];
    memset(picked, false, sizeof(picked));
    for(int i=0; i<NUM_ITEMS; ++i) {
        if(total_weight + items[i]->weight <= max_weight) {
            picked[i] = true;
            total_weight += items[i]->weight;
            total_value += items[i]->value;
        }
    }
    printf("Picked items:\n");
    for(int i=0; i<NUM_ITEMS; ++i) {
        if(picked[i]) {
            printf("%s\n", items[i]->name);
        }
    }
    printf("Total Value: %d\nTotal Weight: %d\n", total_value, total_weight);
}

int main() {
    Item* items[NUM_ITEMS] = {
        createItem("Gas Mask", 50, 2),
        createItem("Crowbar", 30, 3),
        createItem("Pistol", 100, 1),
        createItem("Food", 20, 5),
        createItem("Water", 15, 4)
    };
    printf("Welcome to the post-apocalyptic world!\nYou need to pack your backpack before going on your journey.\n\n");
    printItems(items);
    printf("\nSorting items by value-to-weight ratio...\n\n");
    qsort(items, NUM_ITEMS, sizeof(Item*), cmp);
    printItems(items);
    printf("\nFilling your backpack with as many items as possible...\n\n");
    knapsack(items, MAX_WEIGHT);
    return 0;
}