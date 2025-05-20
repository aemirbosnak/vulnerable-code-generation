//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int weight;
    int value;
} Item;

typedef struct {
    Item items[MAX_SIZE];
    int size;
    int capacity;
} Knapsack;

Knapsack* knapsack_create(int capacity) {
    Knapsack* knapsack = (Knapsack*)malloc(sizeof(Knapsack));
    knapsack->size = 0;
    knapsack->capacity = capacity;
    return knapsack;
}

void knapsack_destroy(Knapsack* knapsack) {
    free(knapsack);
}

bool knapsack_is_full(Knapsack* knapsack) {
    return knapsack->size == knapsack->capacity;
}

void knapsack_add_item(Knapsack* knapsack, Item item) {
    if (!knapsack_is_full(knapsack)) {
        knapsack->items[knapsack->size++] = item;
    }
}

int knapsack_get_total_value(Knapsack* knapsack) {
    int total_value = 0;
    for (int i = 0; i < knapsack->size; i++) {
        total_value += knapsack->items[i].value;
    }
    return total_value;
}

int knapsack_get_total_weight(Knapsack* knapsack) {
    int total_weight = 0;
    for (int i = 0; i < knapsack->size; i++) {
        total_weight += knapsack->items[i].weight;
    }
    return total_weight;
}

bool knapsack_can_add_item(Knapsack* knapsack, Item item) {
    return knapsack->capacity >= knapsack_get_total_weight(knapsack) + item.weight;
}

Item* knapsack_get_best_item(Item items[], int size) {
    Item* best_item = NULL;
    for (int i = 0; i < size; i++) {
        if (best_item == NULL || (items[i].value / items[i].weight) > (best_item->value / best_item->weight)) {
            best_item = &items[i];
        }
    }
    return best_item;
}

Knapsack* knapsack_fill_greedy(Item items[], int size, int capacity) {
    Knapsack* knapsack = knapsack_create(capacity);
    while (!knapsack_is_full(knapsack)) {
        Item* best_item = knapsack_get_best_item(items, size);
        if (best_item == NULL) {
            break;
        }
        if (knapsack_can_add_item(knapsack, *best_item)) {
            knapsack_add_item(knapsack, *best_item);
        }
    }
    return knapsack;
}

int main(void) {
    Item items[] = {
        {10, 60},
        {20, 100},
        {30, 120},
        {40, 150},
        {50, 200}
    };
    int size = sizeof(items) / sizeof(items[0]);
    int capacity = 50;

    Knapsack* knapsack = knapsack_fill_greedy(items, size, capacity);

    printf("Total value: %d\n", knapsack_get_total_value(knapsack));
    printf("Total weight: %d\n", knapsack_get_total_weight(knapsack));

    knapsack_destroy(knapsack);

    return 0;
}