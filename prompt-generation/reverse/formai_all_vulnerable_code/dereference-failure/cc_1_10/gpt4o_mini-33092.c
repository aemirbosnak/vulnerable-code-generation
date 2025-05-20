//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int weight;
    int value;
} Item;

typedef struct {
    Item *items;
    int size;
    int capacity;
} Knapsack;

// Function to compare two items based on value-to-weight ratio
int compare(const void *a, const void *b) {
    Item *itemA = (Item *)a;
    Item *itemB = (Item *)b;
    double ratioA = (double)itemA->value / itemA->weight;
    double ratioB = (double)itemB->value / itemB->weight;

    if (ratioA < ratioB) return 1;
    else if (ratioA > ratioB) return -1;
    else return 0;
}

// Function to create a knapsack
Knapsack createKnapsack(int capacity) {
    Knapsack knapsack;
    knapsack.capacity = capacity;
    knapsack.size = 0;
    knapsack.items = (Item *)malloc(sizeof(Item) * capacity);
    return knapsack;
}

// Function to add an item to the knapsack
void addItem(Knapsack *knapsack, int id, int weight, int value) {
    Item newItem = {id, weight, value};
    knapsack->items[knapsack->size++] = newItem;
}

// Function to solve the 0/1 Knapsack problem using a greedy approach
void greedyKnapsack(Knapsack knapsack) {
    // Sort items by value-to-weight ratio
    qsort(knapsack.items, knapsack.size, sizeof(Item), compare);

    int totalValue = 0;
    int totalWeight = 0;

    printf("Selected items for the knapsack:\n");
    for (int i = 0; i < knapsack.size; i++) {
        if (totalWeight + knapsack.items[i].weight <= knapsack.capacity) {
            totalWeight += knapsack.items[i].weight;
            totalValue += knapsack.items[i].value;
            printf("Item ID: %d, Weight: %d, Value: %d\n", 
                knapsack.items[i].id, knapsack.items[i].weight, knapsack.items[i].value);
        }
    }
    printf("Total weight in the knapsack: %d\n", totalWeight);
    printf("Total value of the knapsack: %d\n", totalValue);
}

// Free allocated memory for knapsack
void freeKnapsack(Knapsack *knapsack) {
    free(knapsack->items);
}

// Main function to demonstrate the greedy knapsack solution
int main() {
    int capacity = 50; // Maximum weight capacity of the knapsack

    Knapsack knapsack = createKnapsack(capacity);

    // Adding items (ID, Weight, Value)
    addItem(&knapsack, 1, 10, 60);
    addItem(&knapsack, 2, 20, 100);
    addItem(&knapsack, 3, 30, 120);
    addItem(&knapsack, 4, 15, 45);
    addItem(&knapsack, 5, 25, 90);

    printf("Knapsack capacity: %d\n", capacity);
    printf("Total number of items available: %d\n", knapsack.size);
    
    // Solve the knapsack problem using the greedy method
    greedyKnapsack(knapsack);

    // Free allocated memory
    freeKnapsack(&knapsack);
    
    return 0;
}