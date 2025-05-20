//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Item {
    int weight;
    int value;
} Item;

typedef struct Knapsack {
    int capacity;
    int num_items;
    Item *items;
} Knapsack;

// Function to create a new knapsack
Knapsack *knapsack_new(int capacity, int num_items) {
    Knapsack *knapsack = malloc(sizeof(Knapsack));
    assert(knapsack);
    knapsack->capacity = capacity;
    knapsack->num_items = num_items;
    knapsack->items = malloc(sizeof(Item) * num_items);
    assert(knapsack->items);
    return knapsack;
}

// Function to delete a knapsack
void knapsack_delete(Knapsack *knapsack) {
    free(knapsack->items);
    free(knapsack);
}

// Function to add an item to a knapsack
void knapsack_add_item(Knapsack *knapsack, Item item) {
    assert(knapsack->num_items < knapsack->capacity);
    knapsack->items[knapsack->num_items] = item;
    knapsack->num_items++;
}

// Function to sort items in a knapsack by value per weight
void knapsack_sort_items(Knapsack *knapsack) {
    for (int i = 0; i < knapsack->num_items; i++) {
        for (int j = i + 1; j < knapsack->num_items; j++) {
            if ((double)knapsack->items[i].value / knapsack->items[i].weight < (double)knapsack->items[j].value / knapsack->items[j].weight) {
                Item temp = knapsack->items[i];
                knapsack->items[i] = knapsack->items[j];
                knapsack->items[j] = temp;
            }
        }
    }
}

// Function to solve the knapsack problem using a greedy algorithm
int knapsack_greedy(Knapsack *knapsack) {
    int total_value = 0;
    int current_weight = 0;
    knapsack_sort_items(knapsack);
    for (int i = 0; i < knapsack->num_items; i++) {
        if (current_weight + knapsack->items[i].weight <= knapsack->capacity) {
            total_value += knapsack->items[i].value;
            current_weight += knapsack->items[i].weight;
        } else {
            break;
        }
    }
    return total_value;
}

// Function to print the items in a knapsack
void knapsack_print_items(Knapsack *knapsack) {
    for (int i = 0; i < knapsack->num_items; i++) {
        printf("Item %d: weight = %d, value = %d\n", i + 1, knapsack->items[i].weight, knapsack->items[i].value);
    }
}

// Main function
int main() {
    // Create a knapsack with a capacity of 10 and 5 items
    Knapsack *knapsack = knapsack_new(10, 5);

    // Add items to the knapsack
    knapsack_add_item(knapsack, (Item){2, 3});
    knapsack_add_item(knapsack, (Item){3, 4});
    knapsack_add_item(knapsack, (Item){4, 5});
    knapsack_add_item(knapsack, (Item){5, 6});
    knapsack_add_item(knapsack, (Item){6, 7});

    // Print the items in the knapsack
    knapsack_print_items(knapsack);

    // Solve the knapsack problem using a greedy algorithm
    int total_value = knapsack_greedy(knapsack);

    // Print the total value of the knapsack
    printf("Total value: %d\n", total_value);

    // Delete the knapsack
    knapsack_delete(knapsack);

    return 0;
}