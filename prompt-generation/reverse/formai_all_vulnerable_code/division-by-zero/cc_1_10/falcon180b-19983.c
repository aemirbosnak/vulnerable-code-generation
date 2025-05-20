//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ITEMS 1000
#define MAX_CATEGORIES 100

typedef struct {
    char name[50];
    int quantity;
    float price;
    int category;
} Item;

typedef struct {
    char name[50];
    int num_items;
} Category;

Item items[MAX_ITEMS];
Category categories[MAX_CATEGORIES];
int num_items = 0, num_categories = 0;

void addItem(Item* item) {
    items[num_items++] = *item;
}

void addCategory(Category* category) {
    categories[num_categories++] = *category;
}

void generateItems() {
    srand(time(NULL));
    for (int i = 0; i < 100; i++) {
        Item item;
        strcpy(item.name, "Item ");
        item.quantity = rand() % 100;
        item.price = rand() % 1000 / 100;
        item.category = rand() % num_categories;
        addItem(&item);
    }
}

void generateCategories() {
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        Category category;
        strcpy(category.name, "Category ");
        category.num_items = rand() % 100;
        addCategory(&category);
    }
}

void printItems() {
    printf("Items:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s - Quantity: %d, Price: $%.2f, Category: %s\n", items[i].name, items[i].quantity, items[i].price, categories[items[i].category].name);
    }
}

void printCategories() {
    printf("Categories:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%s - Number of items: %d\n", categories[i].name, categories[i].num_items);
    }
}

int main() {
    generateItems();
    generateCategories();
    printItems();
    printCategories();
    return 0;
}