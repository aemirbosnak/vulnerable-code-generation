//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: Romeo and Juliet
// Where storage blooms, a tale to unfold,
// Of Romeo, the lovestruck warehouse bold.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Warehouse's embrace, where goods reside,
// A lattice of shelves, where systems collide.
typedef struct {
    char *name;
    int quantity;
} Item;

// Romeo's gaze, upon the Juliet shelf,
// A digital lover, true to himself.
typedef struct {
    char *name;
    Item **items;
    int item_count;
} Shelf;

// Warehouse heart, a symphony of shelves,
// A labyrinth of goods, where commerce delves.
typedef struct {
    char *name;
    Shelf **shelves;
    int shelf_count;
} Warehouse;

// Speak, Romeo, to thy Juliet's ear,
// A query for goods, her secrets to hear.
int check_stock(Warehouse *warehouse, char *item_name) {
    for (int s = 0; s < warehouse->shelf_count; s++) {
        for (int i = 0; i < warehouse->shelves[s]->item_count; i++) {
            if (strcmp(item_name, warehouse->shelves[s]->items[i]->name) == 0) {
                return warehouse->shelves[s]->items[i]->quantity;
            }
        }
    }
    return 0;
}

// Romeo's heart, aflutter with despair,
// Juliet's goods are gone, beyond compare.
void remove_item(Warehouse *warehouse, char *item_name, int quantity) {
    for (int s = 0; s < warehouse->shelf_count; s++) {
        for (int i = 0; i < warehouse->shelves[s]->item_count; i++) {
            if (strcmp(item_name, warehouse->shelves[s]->items[i]->name) == 0) {
                if (warehouse->shelves[s]->items[i]->quantity >= quantity) {
                    warehouse->shelves[s]->items[i]->quantity -= quantity;
                } else {
                    printf("Insufficient quantity of %s\n", item_name);
                }
            }
        }
    }
}

// In fair Verona, a warehouse takes stage,
// Where Romeo and Juliet play their tragic page.
int main() {
    // Verona's warehouse, where all goods convene,
    Warehouse warehouse = {
        .name = "Verona's Emporium",
        .shelves = malloc(10 * sizeof(Shelf *)),
        .shelf_count = 0
    };

    // Juliet's shelf, where love's tale entwines,
    Shelf juliet_shelf = {
        .name = "Juliet's Balcony",
        .items = malloc(10 * sizeof(Item *)),
        .item_count = 0
    };

    // Romeo's goods, a treasure he does hold,
    Item potion = { .name = "Love Potion", .quantity = 5 };
    Item dagger = { .name = "Dagger of Despair", .quantity = 1 };

    // The shelf of love, where Juliet doth reside,
    warehouse.shelves[warehouse.shelf_count++] = &juliet_shelf;

    // Romeo's offerings, to Juliet's embrace,
    juliet_shelf.items[juliet_shelf.item_count++] = &potion;
    juliet_shelf.items[juliet_shelf.item_count++] = &dagger;

    // Romeo's plea, a message from his heart,
    int stock = check_stock(&warehouse, "Love Potion");

    // Fate's cruel hand, a tragic destiny,
    if (stock == 0) {
        printf("Alas, no love potions left to find.\n");
    } else {
        printf("A love potion awaits, thy Juliet shall be kind.\n");
    }

    // Love's despair, a dagger's fatal blow,
    remove_item(&warehouse, "Dagger of Despair", 1);

    // Farewell, dear Romeo, thy love is forevermore,
    free(warehouse.shelves);
    free(warehouse.name);
    free(juliet_shelf.items);
    free(juliet_shelf.name);
    free(potion.name);
    free(dagger.name);
    return 0;
}