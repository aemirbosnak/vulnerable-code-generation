//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Item {
    char label[10];
    int weight;
};

typedef struct Item Item;

struct Baggage {
    int id;
    int total_weight;
    int num_items;
    Item items[10];
};

typedef struct Baggage Baggage;

Baggage* createBaggage(int id) {
    Baggage* baggage = malloc(sizeof(Baggage));
    baggage->id = id;
    baggage->total_weight = 0;
    baggage->num_items = 0;
    return baggage;
}

void addItem(Baggage* baggage, Item item) {
    baggage->items[baggage->num_items++] = item;
    baggage->total_weight += item.weight;
}

void printBaggage(Baggage* baggage) {
    printf("Baggage ID: %d\n", baggage->id);
    printf("Total Weight: %d kg\n", baggage->total_weight);
    printf("Items:\n");
    for(int i=0; i<baggage->num_items; i++) {
        printf(" - %s (%d kg)\n", baggage->items[i].label, baggage->items[i].weight);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    printf("Welcome to the Airport Baggage Handling Simulation!\n\n");

    const char* labels[5] = {"Laptop", "Shirt", "Shampoo", "Toothbrush", "Water Bottle"};
    int weights[5] = {2, 1, 0.5, 0.2, 1};

    Baggage* baggage1 = createBaggage(1);
    addItem(baggage1, (Item) {"Laptop", 2});
    addItem(baggage1, (Item) {"Shirt", 1});
    addItem(baggage1, (Item) {"Water Bottle", 1});

    Baggage* baggage2 = createBaggage(2);
    addItem(baggage2, (Item) {"Shampoo", 0.5});
    addItem(baggage2, (Item) {"Toothbrush", 0.2});
    addItem(baggage2, (Item) {"Shirt", 1});

    Baggage* baggage3 = createBaggage(3);
    addItem(baggage3, (Item) {"Laptop", 2});
    addItem(baggage3, (Item) {"Water Bottle", 1});

    Baggage* baggage4 = createBaggage(4);
    addItem(baggage4, (Item) {"Shampoo", 0.5});
    addItem(baggage4, (Item) {"Toothbrush", 0.2});

    Baggage* baggages[4] = {baggage1, baggage2, baggage3, baggage4};

    printf("Initial Baggage:\n\n");
    for(int i=0; i<4; i++) {
        printBaggage(baggages[i]);
    }

    // Sorting the baggage based on total weight
    for(int i=3; i>=0; i--) {
        for(int j=0; j<i; j++) {
            if(baggages[j]->total_weight > baggages[j+1]->total_weight) {
                Baggage* temp = baggages[j];
                baggages[j] = baggages[j+1];
                baggages[j+1] = temp;
            }
        }
    }

    printf("Final Baggage:\n\n");
    for(int i=0; i<4; i++) {
        printBaggage(baggages[i]);
    }

    return 0;
}