//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000
#define MAX_CATEGORIES 100

typedef struct {
    char *name;
    int quantity;
    int price;
    int category;
} Item;

typedef struct {
    char *name;
    int num_items;
} Category;

Item items[MAX_ITEMS];
Category categories[MAX_CATEGORIES];
int num_items = 0;
int num_categories = 0;

void read_items_from_file(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    char line[256];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        char *token = strtok(line, ",");
        if (token == NULL) {
            continue;
        }

        int category_index = -1;
        for (int i = 0; i < num_categories; i++) {
            if (strcmp(token, categories[i].name) == 0) {
                category_index = i;
                break;
            }
        }

        if (category_index == -1) {
            categories[num_categories].name = strdup(token);
            categories[num_categories].num_items = 0;
            num_categories++;
            category_index = num_categories - 1;
        }

        token = strtok(NULL, ",");
        items[num_items].name = strdup(token);
        items[num_items].quantity = 0;
        items[num_items].price = 0;
        items[num_items].category = category_index;
        num_items++;
    }

    fclose(fp);
}

void print_items_in_category(int category_index) {
    printf("Items in category %s:\n", categories[category_index].name);
    for (int i = 0; i < num_items; i++) {
        if (items[i].category == category_index) {
            printf("%s - %d in stock - $%d\n", items[i].name, items[i].quantity, items[i].price);
        }
    }
}

int main() {
    read_items_from_file("items.csv");

    int choice;
    while (1) {
        printf("1. Print items in category\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter category index: ");
            int category_index;
            scanf("%d", &category_index);
            print_items_in_category(category_index);
            break;

        case 2:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}