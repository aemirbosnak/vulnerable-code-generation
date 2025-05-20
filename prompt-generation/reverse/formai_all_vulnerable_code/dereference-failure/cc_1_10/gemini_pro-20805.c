//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Item {
    int weight;
    int value;
} Item;

typedef struct Knapsack {
    int capacity;
    Item *items;
    int num_items;
} Knapsack;

int compare(const void *a, const void *b) {
    Item *item1 = (Item *) a;
    Item *item2 = (Item *) b;
    return (item2->value / item2->weight) - (item1->value / item1->weight);
}

Knapsack *create_knapsack(int capacity, int num_items) {
    Knapsack *knapsack = (Knapsack *) malloc(sizeof(Knapsack));
    knapsack->capacity = capacity;
    knapsack->num_items = num_items;
    knapsack->items = (Item *) malloc(sizeof(Item) * num_items);
    return knapsack;
}

void free_knapsack(Knapsack *knapsack) {
    free(knapsack->items);
    free(knapsack);
}

void generate_items(Knapsack *knapsack) {
    srand(time(NULL));
    for (int i = 0; i < knapsack->num_items; i++) {
        knapsack->items[i].weight = rand() % 100 + 1;
        knapsack->items[i].value = rand() % 100 + 1;
    }
}

void print_knapsack(Knapsack *knapsack) {
    printf("Capacity: %d\n", knapsack->capacity);
    printf("Items:\n");
    for (int i = 0; i < knapsack->num_items; i++) {
        printf("  Weight: %d, Value: %d\n", knapsack->items[i].weight, knapsack->items[i].value);
    }
}

int greedy_knapsack(Knapsack *knapsack) {
    qsort(knapsack->items, knapsack->num_items, sizeof(Item), compare);

    int total_value = 0;
    int remaining_capacity = knapsack->capacity;

    for (int i = 0; i < knapsack->num_items; i++) {
        if (remaining_capacity >= knapsack->items[i].weight) {
            total_value += knapsack->items[i].value;
            remaining_capacity -= knapsack->items[i].weight;
        } else {
            break;
        }
    }

    return total_value;
}

int main() {
    int capacity = 100;
    int num_items = 10;
    Knapsack *knapsack = create_knapsack(capacity, num_items);
    generate_items(knapsack);
    print_knapsack(knapsack);
    int total_value = greedy_knapsack(knapsack);
    printf("Total Value: %d\n", total_value);
    free_knapsack(knapsack);
    return 0;
}