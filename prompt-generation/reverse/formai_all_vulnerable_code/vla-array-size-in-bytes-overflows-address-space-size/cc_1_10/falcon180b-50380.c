//Falcon-180B DATASET v1.0 Category: Data mining ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_CATEGORIES 10
#define MAX_CATEGORY_NAME_LENGTH 50

typedef struct {
    char name[MAX_CATEGORY_NAME_LENGTH];
    int count;
} Category;

typedef struct {
    char name[MAX_CATEGORY_NAME_LENGTH];
    int category;
    int quantity;
} Item;

void generate_random_data(Item items[], int num_items, Category categories[], int num_categories) {
    srand(time(NULL));

    for (int i = 0; i < num_items; i++) {
        strcpy(items[i].name, "Item ");
        items[i].name[7] = '0' + i;
        items[i].category = rand() % num_categories;
        items[i].quantity = rand() % 100;
    }

    for (int i = 0; i < num_categories; i++) {
        strcpy(categories[i].name, "Category ");
        categories[i].name[10] = '0' + i;
        categories[i].count = 0;
    }
}

void print_categories(Category categories[], int num_categories) {
    printf("Categories:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%s: %d items\n", categories[i].name, categories[i].count);
    }
}

void print_items_by_category(Item items[], int num_items, Category categories[], int num_categories) {
    printf("Items by category:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%s:\n", categories[i].name);
        for (int j = 0; j < num_items; j++) {
            if (items[j].category == i) {
                printf("- %s (%d)\n", items[j].name, items[j].quantity);
            }
        }
    }
}

int main() {
    int num_items, num_categories;

    printf("Enter the number of items: ");
    scanf("%d", &num_items);

    printf("Enter the number of categories: ");
    scanf("%d", &num_categories);

    Item items[num_items];
    Category categories[num_categories];

    generate_random_data(items, num_items, categories, num_categories);

    printf("Items:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s (%d) - Category: %s\n", items[i].name, items[i].quantity, categories[items[i].category].name);
    }

    print_categories(categories, num_categories);

    print_items_by_category(items, num_items, categories, num_categories);

    return 0;
}