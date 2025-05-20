//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct item {
    char *name;
    int quantity;
    double price;
} item;

typedef struct warehouse {
    item **items;
    int num_items;
} warehouse;

warehouse *create_warehouse() {
    warehouse *w = malloc(sizeof(warehouse));
    w->items = malloc(sizeof(item *));
    w->num_items = 0;
    return w;
}

void destroy_warehouse(warehouse *w) {
    for (int i = 0; i < w->num_items; i++) {
        free(w->items[i]->name);
        free(w->items[i]);
    }
    free(w->items);
    free(w);
}

item *create_item(char *name, int quantity, double price) {
    item *i = malloc(sizeof(item));
    i->name = strdup(name);
    i->quantity = quantity;
    i->price = price;
    return i;
}

void destroy_item(item *i) {
    free(i->name);
    free(i);
}

void add_item_to_warehouse(warehouse *w, item *i) {
    w->items = realloc(w->items, (w->num_items + 1) * sizeof(item *));
    w->items[w->num_items++] = i;
}

item *find_item_in_warehouse(warehouse *w, char *name) {
    for (int i = 0; i < w->num_items; i++) {
        if (strcmp(w->items[i]->name, name) == 0) {
            return w->items[i];
        }
    }
    return NULL;
}

void print_warehouse(warehouse *w) {
    for (int i = 0; i < w->num_items; i++) {
        printf("%s: %d @ $%.2f\n", w->items[i]->name, w->items[i]->quantity, w->items[i]->price);
    }
}

int main() {
    warehouse *w = create_warehouse();

    add_item_to_warehouse(w, create_item("apple", 10, 0.50));
    add_item_to_warehouse(w, create_item("banana", 15, 0.75));
    add_item_to_warehouse(w, create_item("orange", 20, 1.00));

    print_warehouse(w);

    item *i = find_item_in_warehouse(w, "apple");
    if (i != NULL) {
        printf("Found item: %s\n", i->name);
    }

    destroy_warehouse(w);

    return 0;
}