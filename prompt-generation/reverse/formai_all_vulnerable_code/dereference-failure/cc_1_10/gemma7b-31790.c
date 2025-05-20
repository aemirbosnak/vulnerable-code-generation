//Gemma-7B DATASET v1.0 Category: Performance-Critical Component ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

struct SBox {
    int num_items;
    struct Item** items;
};

struct Item {
    char* name;
    int item_id;
    struct SBox* box;
    struct Item* next;
};

struct SBox* create_sbox() {
    struct SBox* box = malloc(sizeof(struct SBox));
    box->num_items = 0;
    box->items = NULL;
    return box;
}

struct Item* create_item(char* name, int item_id) {
    struct Item* item = malloc(sizeof(struct Item));
    item->name = strdup(name);
    item->item_id = item_id;
    item->box = NULL;
    item->next = NULL;
    return item;
}

void add_item(struct SBox* box, struct Item* item) {
    item->box = box;
    box->items = realloc(box->items, box->num_items * sizeof(struct Item*) + 1);
    box->items[box->num_items++] = item;
}

void print_items(struct SBox* box) {
    for (int i = 0; i < box->num_items; i++) {
        printf("%s (%d)\n", box->items[i]->name, box->items[i]->item_id);
    }
}

int main() {
    struct SBox* box = create_sbox();
    struct Item* item1 = create_item("Sword", 1);
    struct Item* item2 = create_item("Shield", 2);
    struct Item* item3 = create_item("Potion", 3);

    add_item(box, item1);
    add_item(box, item2);
    add_item(box, item3);

    print_items(box);

    return 0;
}