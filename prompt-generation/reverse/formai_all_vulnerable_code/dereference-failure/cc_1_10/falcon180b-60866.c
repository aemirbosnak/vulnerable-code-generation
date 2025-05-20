//Falcon-180B DATASET v1.0 Category: Data mining ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ITEMS 100
#define MAX_CATEGORIES 10

struct item {
    char name[20];
    int category;
    float price;
};

struct item items[MAX_ITEMS];
int num_items = 0;

void add_item(char* name, int category, float price) {
    if (num_items >= MAX_ITEMS) {
        printf("Error: Maximum number of items reached.\n");
        return;
    }

    strcpy(items[num_items].name, name);
    items[num_items].category = category;
    items[num_items].price = price;

    num_items++;
}

void print_items() {
    printf("Items:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s (%d) $%.2f\n", items[i].name, items[i].category, items[i].price);
    }
}

void generate_random_data() {
    srand(time(NULL));

    for (int i = 0; i < MAX_ITEMS; i++) {
        char name[20];
        sprintf(name, "Item %d", i + 1);
        add_item(name, rand() % MAX_CATEGORIES + 1, rand() % 100 + 1);
    }
}

int main() {
    generate_random_data();
    print_items();

    return 0;
}