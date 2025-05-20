//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_ITEMS 100
#define MAX_CATEGORY_NAME_LEN 50
#define MAX_ITEM_NAME_LEN 100
#define MAX_ITEM_VALUE_LEN 20

typedef struct {
    char name[MAX_CATEGORY_NAME_LEN];
    int numItems;
    struct item* items[MAX_ITEMS];
} category;

typedef struct {
    char name[MAX_ITEM_NAME_LEN];
    char value[MAX_ITEM_VALUE_LEN];
} item;

category* createCategory(char* name) {
    category* newCategory = (category*) malloc(sizeof(category));
    strcpy(newCategory->name, name);
    newCategory->numItems = 0;
    return newCategory;
}

item* createItem(char* name, char* value) {
    item* newItem = (item*) malloc(sizeof(item));
    strcpy(newItem->name, name);
    strcpy(newItem->value, value);
    return newItem;
}

void addItemToCategory(category* cat, item* item) {
    cat->items[cat->numItems++] = item;
}

void printCategory(category* cat) {
    printf("Category: %s\n", cat->name);
    printf("Number of items: %d\n", cat->numItems);
    for (int i = 0; i < cat->numItems; i++) {
        item* item = cat->items[i];
        printf("Item %d: %s - %s\n", i + 1, item->name, item->value);
    }
}

void printItem(item* item) {
    printf("Item name: %s\n", item->name);
    printf("Item value: %s\n", item->value);
}

int main() {
    category* cyberpunkStyle = createCategory("Cyberpunk Style");
    category* housing = createCategory("Housing");

    // Add items to Cyberpunk Style category
    item* cyberpunkClothing = createItem("Cyberpunk Clothing", "Neon leather jacket");
    item* cyberpunkTech = createItem("Cyberpunk Tech", "Brain implant");
    addItemToCategory(cyberpunkStyle, cyberpunkClothing);
    addItemToCategory(cyberpunkStyle, cyberpunkTech);

    // Add items to Housing category
    item* rent = createItem("Rent", "1000 credits");
    item* utilities = createItem("Utilities", "200 credits");
    addItemToCategory(housing, rent);
    addItemToCategory(housing, utilities);

    printCategory(cyberpunkStyle);
    printCategory(housing);

    return 0;
}