//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int stock;
} Item;

void print_menu() {
    printf("-------------------------------------------------\n");
    printf("|             Product Inventory System           |\n");
    printf("|                 Romeo & Juliet Version         |\n");
    printf("-------------------------------------------------\n");
    printf("| 1. List all items                            |\n");
    printf("| 2. Add new item                              |\n");
    printf("| 3. Remove item                              |\n");
    printf("| 4. Search for item                           |\n");
    printf("| 5. Exit                                      |\n");
    printf("-------------------------------------------------\n");
}

void list_items(Item items[], int size) {
    for (int i = 0; i < size; i++) {
        printf("| %d. %s - %d units                       |\n", i + 1, items[i].name, items[i].stock);
    }
}

Item* add_item(Item items[], int size, int* new_size) {
    Item new_item;
    printf("Enter item name: ");
    scanf("%s", new_item.name);
    printf("Enter stock: ");
    scanf("%d", &new_item.stock);

    *new_size = size + 1;
    Item* new_items = (Item*) realloc(items, sizeof(Item) * (*new_size));
    new_items[size] = new_item;
    return new_items;
}

void remove_item(Item items[], int size, int index) {
    for (int i = index; i < size; i++) {
        items[i] = items[i + 1];
    }
    items[size - 1].stock = 0;
}

Item* search_item(Item items[], int size, char name[]) {
    for (int i = 0; i < size; i++) {
        if (strcmp(items[i].name, name) == 0) {
            return &items[i];
        }
    }
    return NULL;
}

int main() {
    int size = 0;
    Item* items = NULL;

    while (1) {
        print_menu();
        int choice;
        scanf("%d", &choice);

        Item* temp_item = NULL;
        char search_name[50];
        int search_index = -1;

        switch (choice) {
            case 1:
                if (size == 0) {
                    printf("No items in inventory.\n");
                    break;
                }
                list_items(items, size);
                break;
            case 2:
                items = add_item(items, size, &size);
                break;
            case 3:
                if (size == 0) {
                    printf("No items in inventory.\n");
                    break;
                }
                printf("Enter index: ");
                scanf("%d", &search_index);
                if (search_index < 1 || search_index > size) {
                    printf("Invalid index.\n");
                    break;
                }
                remove_item(items, size, search_index - 1);
                break;
            case 4:
                printf("Enter item name: ");
                scanf("%s", search_name);
                temp_item = search_item(items, size, search_name);
                if (temp_item == NULL) {
                    printf("Item not found.\n");
                    break;
                }
                printf("Found item: %s - %d units\n", temp_item->name, temp_item->stock);
                break;
            case 5:
                free(items);
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}