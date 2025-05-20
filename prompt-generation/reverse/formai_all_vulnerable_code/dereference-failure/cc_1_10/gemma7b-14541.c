//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BAG_NUMBER 10

typedef struct Bag {
    char **items;
    int item_count;
    int weight;
} Bag;

void add_item(Bag *bag, char *item) {
    bag->items = realloc(bag->items, (bag->item_count + 1) * sizeof(char *));
    bag->items[bag->item_count++] = item;
    bag->weight += item_weight(item);
}

int item_weight(char *item) {
    switch (item[0]) {
        case 'A':
            return 5;
        case 'B':
            return 10;
        case 'C':
            return 15;
        default:
            return 0;
    }
}

int main() {
    Bag bags[MAX_BAG_NUMBER];
    int num_bags = 0;

    // Simulate baggage handling

    char *item_1 = "Apple";
    add_item(&bags[num_bags++], item_1);

    char *item_2 = "Banana";
    add_item(&bags[num_bags++], item_2);

    char *item_3 = "Coconut";
    add_item(&bags[num_bags++], item_3);

    char *item_4 = "Orange";
    add_item(&bags[num_bags++], item_4);

    int total_weight = 0;
    for (int i = 0; i < num_bags; i++) {
        total_weight += bags[i].weight;
    }

    printf("Total weight of baggage: %d", total_weight);

    return 0;
}