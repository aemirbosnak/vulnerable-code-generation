//Falcon-180B DATASET v1.0 Category: Data mining ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000
#define MAX_CATEGORIES 100
#define MAX_ITEMS_PER_CATEGORY 100
#define MAX_CATEGORY_NAME_LENGTH 50

struct item {
    char name[MAX_CATEGORY_NAME_LENGTH];
    int category;
};

struct category {
    char name[MAX_CATEGORY_NAME_LENGTH];
    int num_items;
    struct item *items;
};

int main() {
    int num_items, num_categories;
    struct item *items;
    struct category *categories;

    // Read in the number of items and categories
    scanf("%d %d", &num_items, &num_categories);

    // Allocate memory for items and categories
    items = (struct item *)malloc(num_items * sizeof(struct item));
    categories = (struct category *)malloc(num_categories * sizeof(struct category));

    // Read in the items and their categories
    for (int i = 0; i < num_items; i++) {
        scanf("%s %d", items[i].name, &items[i].category);
    }

    // Sort the items by category
    for (int i = 0; i < num_items; i++) {
        for (int j = 0; j < num_categories; j++) {
            if (items[i].category == j) {
                categories[j].items = realloc(categories[j].items, (categories[j].num_items + 1) * sizeof(struct item));
                categories[j].items[categories[j].num_items] = items[i];
                categories[j].num_items++;
                break;
            }
        }
    }

    // Print out the categories and their items
    for (int i = 0; i < num_categories; i++) {
        printf("Category %d: %s\n", i, categories[i].name);
        for (int j = 0; j < categories[i].num_items; j++) {
            printf("\t%s\n", categories[i].items[j].name);
        }
    }

    return 0;
}