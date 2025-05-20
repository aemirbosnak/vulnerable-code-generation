//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum job {
    street_runner,
    hacker,
    rigger
} job_t;

typedef struct item {
    const char *name;
    int value;
    int weight;
    int quantity;
} item_t;

typedef struct backpack {
    int capacity;
    int n_items;
    item_t **items;
    int *selected;
} backpack_t;

void print_backpack(backpack_t *bp)
{
    printf("Backpack capacity: %d\n", bp->capacity);
    printf("Number of items: %d\n", bp->n_items);
    for (int i = 0; i < bp->n_items; i++) {
        printf("\t%s: value %d, weight %d, quantity %d, selected %d\n",
            bp->items[i]->name, bp->items[i]->value, bp->items[i]->weight, bp->items[i]->quantity, bp->selected[i]);
    }
}

int compare_items(const void *a, const void *b)
{
    item_t *ia = *(item_t **)a;
    item_t *ib = *(item_t **)b;
    return ((double)ia->value / ia->weight) - ((double)ib->value / ib->weight);
}

void greedy_knapsack(backpack_t *bp)
{
    // sort items by value-to-weight ratio
    qsort(bp->items, bp->n_items, sizeof(item_t *), compare_items);

    // initialize selected items to 0
    for (int i = 0; i < bp->n_items; i++) {
        bp->selected[i] = 0;
    }

    // iterate over items in sorted order
    for (int i = 0; i < bp->n_items; i++) {
        // if there's enough capacity left, add item to backpack
        if (bp->capacity >= bp->items[i]->weight * bp->items[i]->quantity) {
            bp->selected[i] = bp->items[i]->quantity;
            bp->capacity -= bp->items[i]->weight * bp->items[i]->quantity;
        }
        // if there's not enough capacity left, add as much of the item as possible
        else if (bp->capacity > 0) {
            bp->selected[i] = bp->capacity / bp->items[i]->weight;
            bp->capacity = 0;
        }
    }
}

int main(int argc, char *argv[])
{
    // define backpack with capacity of 100
    backpack_t bp = {
        .capacity = 100,
        .n_items = 5,
        .items = {
            &(item_t){.name = "Cyberdeck", .value = 2500, .weight = 5},
            &(item_t){.name = "Medkit", .value = 1000, .weight = 2},
            &(item_t){.name = "Laser Pistol", .value = 1500, .weight = 3},
            &(item_t){.name = "Kevlar Vest", .value = 1200, .weight = 4},
            &(item_t){.name = "Datachip", .value = 3000, .weight = 1}
        },
        .selected = calloc(bp.n_items, sizeof(int))
    };

    // print starting backpack
    printf("Starting backpack:\n");
    print_backpack(&bp);

    // run greedy knapsack algorithm
    greedy_knapsack(&bp);

    // print resulting backpack
    printf("\nResulting backpack:\n");
    print_backpack(&bp);

    return 0;
}